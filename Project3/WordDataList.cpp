/***************************************************************/
/*                                                             */
/* Author:     Dr. Spiegel (edited by Hamad Ahmed)             */
/* Filename:   WordDataList.cpp                                */
/* Course:     CSC 237 Data Structures                         */
/* Assignment: Project #3                                      */
/* Due Date:   March 31, 2022                                  */
/* Purpose:    This subclass file contains the functions       */
/*             implementations                                 */
/*                                                             */
/***************************************************************/

#include <sstream>
#include <iostream>
#include <chrono>
#include "WordDataList.h"

using namespace std;
using namespace std::chrono;

WordDataList::WordDataList()
{ 
  /*************************************************************/
  /*                                                           */
  /* Function Name: WordDataList                               */
  /* Description:   A default constructor                      */
  /* Parameter:     none                                       */
  /* Return:        none                                       */
  /*                                                           */
  /*************************************************************/

  // Sets the 'numWords' to 0
  numWords=0; 
}

bool WordDataList::incMatch(string temp)
{ 
  /*******************************************************************************************/
  /*                                                                                         */
  /* Function Name: incMatch                                                                 */
  /* Description:   checks for duplicates and increments the occurrences of the word         */
  /* Parameter:     string temp - holds a temporary value to check for the duplicate - input */
  /* Return:        bool                                                                     */
  /*                                                                                         */
  /*******************************************************************************************/

  // Checks the each element for duplicates
  for(int i=0; i<numWords; i++) 
  {
    if (temp==TheWords[i].getWord()) 
    {
      // If found, increment their occurrences and returns true
      TheWords[i].incCount();
      return true;
    }
  }  
  return false;
}

void WordDataList::parseIntoList(ifstream &inf)
{
  /**************************************************************************/
  /*                                                                        */
  /* Function name: parseIntoList                                           */
  /* Description:   Reads the 'inf', and stores unique strings in 'TheWords'*/
  /* Parameter:     ifstream &inf: file object - import/export              */
  /* Return:        none                                                    */ 
  /*                                                                        */
  /**************************************************************************/

  // Rewinds the file to beginning
  // inf.clear();
  // inf.seekg(0);

  // Start timer to time parseIntoList function
  auto begin = high_resolution_clock::now();

  // Creates a temp variable
  string temp;

  // Reads the data from the file
  while (inf >> temp)
    // Checks for duplicates and inserts 10 unique words and increments their occurrences 
    if (!incMatch(temp) && numWords < 10) 
    {
        TheWords[numWords].setWord(temp);
        TheWords[numWords++].setCount(1);
    }

  // Rewinds the file to beginning
  inf.clear();
  inf.seekg(0);

  // End timer to time this function
  auto end = high_resolution_clock::now();

  auto ticks = duration_cast<microseconds>(end-begin);

  cout << "\n\nWordDataList parse into list function took " << ticks.count() << " microseconds to complete" << endl;
}

// Print the data iteratively
void WordDataList::printIteratively()
//  void printObjectArrayIterator(WordData TheWords[], int numWords)
{
  /**************************************************************/
  /*                                                            */
  /* Function name: printIteratively                            */ 
  /* Description:   prints the Circular Linked List iteratively */
  /* Parameter:     none                                        */
  /* Return:        none                                        */ 
  /*                                                            */
  /**************************************************************/

  // Start timer to time printIteratively function
  auto begin = high_resolution_clock::now();

  cout<<"--------------------------"<<endl;
  cout<<"|Object  Array  Iterative|"<<endl;
  cout<<"|Word         Occurences |"<<endl;  
  cout<<"--------------------------"<<endl;

  // This for loop prints the object array
  for(int i=0; i<numWords; i++)
    cout<<" "<<TheWords[i]<<endl;

  // End timer to time this function
  auto end = high_resolution_clock::now();
  
  // Computes the difference from between end and begin timings
  auto ticks = duration_cast<microseconds>(end-begin);

  // Displays the duration computed
  cout << "\n This took " << ticks.count() << " microseconds to run" << endl;
}


// Print the data recursively
void WordDataList::printRecursivelyWorker(int numWords)
//void printObjectArrayRecursive(WordData TheWords[], int numWords)
{
  /****************************************************************************/
  /*                                                                          */
  /* Function name: printRecursivelyWorker                                    */ 
  /* Description:   prints the Circular Linked List recursively               */
  /* Parameter:     int numWords - holds the occurrences of the word - import */
  /* Return:        none                                                      */ 
  /*                                                                          */
  /****************************************************************************/

  // Checks whether the 'numWords' is equal to 1
  if (numWords==1) 
  {
    // If yes, prints the word
    cout<<"--------------------------"<<endl;
    cout<<"|Object  Array  Recursive|"<<endl;
    cout<<"|Word         Occurences |"<<endl;  
    cout<<"--------------------------"<<endl;

    cout<<" "<<TheWords[numWords-1]<<endl;
    return;
  }

  // Calls the print recursive worker function
  printRecursivelyWorker(numWords-1);

  // Displays the words
  cout<<" "<<TheWords[numWords-1]<<endl;
}

// Call worker function to print the data recursively
void WordDataList::printRecursively()
{  
  /****************************************************************************/
  /*                                                                          */
  /* Function name: printRecursively                                          */ 
  /* Description:   invokes the recursive print                               */
  /* Parameter:     int numWords - holds the occurrences of the word - import */
  /* Return:        none                                                      */ 
  /*                                                                          */
  /****************************************************************************/

  // Records the start time
  auto begin = high_resolution_clock::now();

  // Calls the print recursive worker function
  printRecursivelyWorker(numWords); 

  // Records the end timer
  auto end = high_resolution_clock::now();

  // Computes the duration in microseconds
  auto ticks = duration_cast<microseconds>(end-begin);

  // Displays the duration
  cout << "\nThis took " << ticks.count() << " microseconds to run" << endl; 
}


// Print the data recursively with a pointer
void WordDataList::printPtrWorker(int numWords)
//void printObjectArrayPointerRecursive(WordData* TheWords, int numWords)
{
  /****************************************************************************/
  /*                                                                          */
  /* Function name: printPtrWorker                                            */ 
  /* Description:   invokes the print pointer worker                          */
  /* Parameter:     int numWords - holds the occurrences of the word - import */
  /* Return:        none                                                      */ 
  /*                                                                          */
  /****************************************************************************/

  // Checks if it is not 'numWords'
  if (!numWords)
  { cout<<"--------------------------"<<endl;
    cout<<"|Object  Array  Pointer  |"<<endl;
    cout<<"|Word         Occurences |"<<endl;  
    cout<<"--------------------------"<<endl;
    return;
  }

  // Calls the print pointer worker function
  printPtrWorker(numWords-1);

  // Prints the words.
  cout<<" "<<*(TheWords+(numWords-1))<<endl;
}

// Call worker function to print the data recursively
void WordDataList::printPtr()
{ 
  /****************************************************************************/
  /*                                                                          */
  /* Function name: printPtr                                                  */ 
  /* Description:   prints the object array using pointer                     */
  /* Parameter:     int numWords - holds the occurrences of the word - import */
  /* Return:        none                                                      */ 
  /*                                                                          */
  /****************************************************************************/

  // Records the start timer
  auto begin = high_resolution_clock::now();

  // Calls the print pointer worker function recursively
  printPtrWorker(numWords); 

  // Records the end timer
  auto end = high_resolution_clock::now();

  // Computes the duration in microseconds
  auto ticks = duration_cast<microseconds>(end-begin);

  // Displays the duration
  cout << "\nThis took " << ticks.count() << " microseconds to run" << endl;
}
