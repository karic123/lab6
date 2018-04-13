#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <sys/wait.h>

#define BSIZE 256

#define BASH_EXEC  "/bin/bash"
#define FIND_EXEC  "/usr/bin/find"
#define XARGS_EXEC "/usr/bin/xargs"
#define GREP_EXEC  "/bin/grep"
#define SORT_EXEC  "/usr/bin/sort"
#define HEAD_EXEC  "/usr/bin/head"

int main(int argc, char *argv[])
{
  int status;
  pid_t pid_1, pid_2, pid_3, pid_4;

int pipe1fd[2];
int pipe2fd[2];
int pipe3fd[2];
pipe(pipe1fd);
pipe(pipe2fd);
pipe(pipe3fd);


	//printf("so far so good homie\n");
  if (argc != 4) {
    printf("usage: finder DIR STR NUM_FILES\n");
    exit(0);
  }

  pid_1 = fork();
  if (pid_1 == 0) {
	  //printf("sprintf executed fork 1\n"); //DEBUGGING STUFF
	  /* First Child */
	//   close(pipe1fd[1]);
	dup2(pipe1fd[1], STDOUT_FILENO); //write data to pipe one

	  close(pipe2fd[1]);
	  close(pipe3fd[1]);
	  close (pipe1fd[0]);
	  close (pipe2fd[0]);
	  close (pipe3fd[0]);

	  char cmdbuf[BSIZE];
	  bzero(cmdbuf, BSIZE);
	  sprintf(cmdbuf, "%s %s -name \'*\'.[ch]", FIND_EXEC, argv[1]);
	  /* set up pipes */
	  //...
	 // close(pipe1fd[0]);//close read end of pipe one

	  //char* myArgs[] = {BASH_EXEC, "-c", cmdbuf, (char*) 0};
	  if( (execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0)) < 0){
		  fprintf(STDOUT_FILENO, "\nError execing find. ERROR#%d\n", errno);
		  return EXIT_FAILURE;
	  }
	  //printf("finished with fork 1 yo\n");
	  exit(0);
  }

  pid_2 = fork();
  if (pid_2 == 0) {
	  /* Second Child */
	  dup2(pipe1fd[0], STDIN_FILENO);//read in data from pipe 1
	  dup2(pipe2fd[1], STDOUT_FILENO);//write data to pipe 2

	  close(pipe1fd[1]);
	  close (pipe1fd[0]);
	  close (pipe2fd[0]);
	  close (pipe3fd[0]);


	  char cmdbuf[BSIZE];
	  bzero(cmdbuf, BSIZE);
	  sprintf(cmdbuf, "%s %s -c %s", XARGS_EXEC, GREP_EXEC, argv[2]);
	  /* set up pipes */
	 // ...
	// close(pipe2fd[0]);//close read end of pipe 2

	//  char* myArgs[] = {BASH_EXEC, "-c", cmdbuf, (char*) 0};
	  if( (execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0)) < 0){
		  fprintf(stderr, "\nError execing find. ERROR#%d\n", errno);
		  return EXIT_FAILURE;
	  }

	  exit(0);
  }

  pid_3 = fork();
  if (pid_3 == 0) {
	  /* Third Child */
	  dup2(pipe2fd[0], STDIN_FILENO);//read in data from pipe 2
	  dup2(pipe3fd[1], STDOUT_FILENO);//write data to pipe 3

	  close(pipe1fd[1]);
 	  close(pipe2fd[1]);
	  close (pipe1fd[0]);
	  close (pipe2fd[0]);
	  close (pipe3fd[0]);

	  char cmdbuf[BSIZE];
	  bzero(cmdbuf, BSIZE);
	  sprintf(cmdbuf, "%s -t : +1.0 -2.0 --numeric --reverse", SORT_EXEC);
	  /* set up pipes */
	 // ...

	// close(pipe3fd[0]);//close read end of pipe 3

	 // char* myArgs[] = {BASH_EXEC, "-c", cmdbuf, (char*) 0};
	  if( (execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0)) < 0){
		  fprintf(stderr, "\nError execing find. ERROR#%d\n", errno);
		  return EXIT_FAILURE;
	  }
	  exit(0);

  }

  pid_4 = fork();
  if (pid_4 == 0) {
	  /* Fourth Child */
	  dup2(pipe3fd[0], STDIN_FILENO);//read in data from pipe 3

	  close(pipe1fd[1]);
	  close(pipe2fd[1]);
	  close(pipe3fd[1]);
	  close (pipe1fd[0]);
	  close (pipe2fd[0]);
	  close (pipe3fd[0]);

	  char cmdbuf[BSIZE];
	  bzero(cmdbuf, BSIZE);
	  sprintf(cmdbuf, "%s --lines=%s", HEAD_EXEC, argv[3]);
	  /* set up pipes */
	 // ...

	 // char* myArgs[] = {BASH_EXEC, "-c", cmdbuf, (char*) 0};
	  if( (execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char*) 0)) < 0){
		  fprintf(stderr, "\nError execing find. ERROR#%d\n", errno);
		  return EXIT_FAILURE;
	  }
	  exit(0);
  }
  close(pipe1fd[1]);
  close(pipe2fd[1]);
  close(pipe3fd[1]);
  close (pipe1fd[0]);
  close (pipe2fd[0]);
  close (pipe3fd[0]);


  if ((waitpid(pid_1, &status, 0)) == -1) {
    fprintf(stderr, "Process 1 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_2, &status, 0)) == -1) {
    fprintf(stderr, "Process 2 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_3, &status, 0)) == -1) {
    fprintf(stderr, "Process 3 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_4, &status, 0)) == -1) {
    fprintf(stderr, "Process 4 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
}

  return 0;
}
