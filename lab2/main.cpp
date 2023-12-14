//This program tests various operation of a linked list
//Hello There Show White Bear Brown Black Green Hat C++ 

#include <iostream>                                 //Line 1
#include <string>                                   //Line 2
#include "unorderedLinkedList.h"                    //Line 3

using namespace std;                                //Line 4

int main()                                          //Line 5
{                                                   //Line 6
  unorderedLinkedList<int> myList;

  // Add elements to the list
  myList.insert(1);
  myList.insert(2);
  myList.insert(1);
  myList.insert(3);
  myList.insert(4);

  std::cout << "Original List: ";
  myList.display();

  myList.deleteSmallestNode();
  std::cout << "After deleting the smallest node: ";
  myList.display();

  myList.deleteAllOccurrences(0);
  std::cout << "After deleting all occurrences of smallest node: ";
  myList.display();

  return 0;	                            //Line 38		
}                                                   //Line 39
