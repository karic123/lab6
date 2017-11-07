
#include "tests.h"

 //DONT WORRY ABOUT IMPROPER INPUT!
 //ints have max and min value which will be tested by complier.
 //check to see if user can delete when there are 0 items in list.
 //check to make sure correct values are added when doing addback and addfront


tests::tests()
{
//LinkedListOfInts<int> list;
}

void tests::RunTests()
{
  std::string P = "PASSED! \n";
  std::string F = "FAILED! \n";


  std::cout<<"TEST 1: the linkedlist is empty upon creation using isEmpty(): ";
  if (test1()==true)
    {
      std::cout<<P;
    }
  else
    {
      std::cout<<F;
    }

  std::cout<<"TEST 2: size = 0 when a new list is created: ";
  if (test2()==true)
    {
      std::cout<<P;
    }
  else
    {
      std::cout<<F;
    }

    std::cout<<"TEST 3: adds 3 nodes using addFront. Size returns correct value: ";
    if (test3()==true)
      {
        std::cout<<P;
      }
    else
      {
        std::cout<<F;
      }

      std::cout<<"TEST 4: adds 3 nodes using addBack. Size returns correct value: ";
      if (test4()==true)
        {
          std::cout<<P;
        }
      else
        {
          std::cout<<F;
        }

        std::cout<<"TEST 5: adds 3 nodes. Removes one node using removeFront. Size returns correct value: ";
        if (test5()==true)
          {
            std::cout<<P;
          }
        else
          {
            std::cout<<F;
          }

          std::cout<<"TEST 6: adds 3 nodes. Removes one node using removeBack. Size returns correct value: ";
          if (test6()==true)
            {
              std::cout<<P;
            }
          else
            {
              std::cout<<F;
            }

          std::cout<<"TEST 7: makes linkedlist using addFront with values 5,6,7 and uses search to see if 6 is in the list: ";
          if (test7()==true)
            {
              std::cout<<P;
            }
          else
            {
              std::cout<<F;
            }

            std::cout<<"TEST 8: makes linkedlist using addFront with values 5,6,7 and uses search to see if 9 is NOT in the list: ";
            if (test8()==false)
              {
                std::cout<<P;
              }
            else
              {
                std::cout<<F;
              }

              std::cout<<"TEST 9: Checks to see if first value in list is 3 after using addFront(3): ";
              if (test9()==true)
                {
                  std::cout<<P;
                }
              else
                {
                  std::cout<<F;
                }

              std::cout<<"TEST 10: Checks to see if last value in list is 9 after using addBack(9): ";
              if (test10()==true)
                {
                  std::cout<<P;
                }
              else
                {
                  std::cout<<F;
                }

              std::cout<<"TEST 11: makes linkedlist using addBack with values 5,6,7 and uses search to see if 6 is in the list: ";
              if (test11()==true)
                {
                  std::cout<<P;
                }
              else
                {
                  std::cout<<F;
                }

                std::cout<<"TEST 12: makes linkedlist using addBack with values 5,6,7 and uses search to see if 9 is NOT in the list: ";
                if (test12()==false)
                  {
                    std::cout<<P;
                  }
                else
                  {
                    std::cout<<F;
                  }
                std::cout<<"TEST 13: removes back* and checks to see that the value in the new back position is correct: ";
                if (test13()==true)
                  {
                    std::cout<<P;
                  }
                else
                  {
                    std::cout<<F;
                  }

                  std::cout<<"TEST 14: removes front and checks if new front is correct: ";
                  if (test14()==true)
                    {
                      std::cout<<P;
                    }
                  else
                    {
                      std::cout<<F;
                    }
                    std::cout<<"TEST 15: removes back and searches if its value is gone from the linked list: ";
                    if (test15()==true)
                      {
                        std::cout<<F;
                      }
                    else
                      {
                        std::cout<<P;
                      }
                      std::cout<<"TEST 16: removes front and searches if its value is gone from the linked list: ";
                      if (test16()==true)
                        {
                          std::cout<<F;
                        }
                      else
                        {
                          std::cout<<P;
                        }

}

bool tests::test1()
{
  LinkedListOfInts mylist;
  return mylist.isEmpty();
}

bool tests::test2()
{
  LinkedListOfInts mylist;
  if (mylist.size() == 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool tests::test3()
{
  LinkedListOfInts mylist;
  mylist.addFront(1);
  mylist.addFront(2);
  mylist.addFront(3);

  if(mylist.size() == 3)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool tests::test4()
{
  LinkedListOfInts mylist;
  mylist.addBack(1);
  mylist.addBack(2);
  mylist.addBack(3);

  if(mylist.size() == 3)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool tests::test5()
{
  LinkedListOfInts mylist;
  mylist.addBack(1);
  mylist.addBack(2);
  mylist.addBack(3);
  mylist.removeFront();

  if(mylist.size() == 2)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool tests::test6()
{
  LinkedListOfInts mylist;
  mylist.addBack(1);
  mylist.addBack(2);
  mylist.addBack(3);
  mylist.removeBack();

  if(mylist.size() == 2)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool tests::test7()
  {
    LinkedListOfInts mylist;
    mylist.addFront(5);
    mylist.addFront(6);
    mylist.addFront(7);

    return(mylist.search(6));
  }

  bool tests::test8()
    {
      LinkedListOfInts mylist;
      mylist.addFront(5);
      mylist.addFront(6);
      mylist.addFront(7);

      return(mylist.search(9));
    }

  bool tests::test9()
  {
    LinkedListOfInts mylist;
    mylist.addFront(1);
    mylist.addFront(2);
    mylist.addFront(3);
    std::vector<int> myVector = mylist.toVector();
    if (myVector.at(0) == 3)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool tests::test10()
  {
    LinkedListOfInts mylist;
    mylist.addFront(1);
    mylist.addFront(2);
    mylist.addFront(3);
    mylist.addBack(9);
    std::vector<int> myVector = mylist.toVector();
    if (myVector.at(3) == 9)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool tests::test11()
    {
      LinkedListOfInts mylist;
      mylist.addBack(5);
      mylist.addBack(6);
      mylist.addBack(7);

      return(mylist.search(6));
    }

    bool tests::test12()
      {
        LinkedListOfInts mylist;
        mylist.addBack(5);
        mylist.addBack(6);
        mylist.addBack(7);

        return(mylist.search(9));
      }

      bool tests::test13()
      {
        LinkedListOfInts mylist;
        mylist.addFront(1);
        mylist.addFront(2);
        mylist.addFront(3);
        mylist.removeBack();

        std::vector<int> myVector = mylist.toVector();
        if (myVector.at(1) == 2)
        {
          return true;
        }
        else
        {
          return false;
        }
      }

      bool tests::test14()
      {
        LinkedListOfInts mylist;
        mylist.addFront(1);
        mylist.addFront(2);
        mylist.addFront(3);
        mylist.removeFront();

        std::vector<int> myVector = mylist.toVector();
        if (myVector.at(0) == 2)
        {
          return true;
        }
        else
        {
          return false;
        }
      }
      bool tests::test15()
        {
          LinkedListOfInts mylist;
          mylist.addBack(5);
          mylist.addBack(6);
          mylist.addBack(7);
          mylist.removeBack();

          return(mylist.search(7));
        }

        bool tests::test16()
          {
            LinkedListOfInts mylist;
            mylist.addBack(5);
            mylist.addBack(6);
            mylist.addBack(7);
            mylist.removeFront();

            return(mylist.search(5));
          }
