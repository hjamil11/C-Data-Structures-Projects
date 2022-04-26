/****************************************************************/
/* Author:         Dr. Spiegel (edited by Hamad Ahmed)          */
/* Filename:       WordList.h                                   */
/* Course:         CSC 237 Data Structures                      */
/* Assignment:     Project 3                                    */
/* Due Date:       March 31, 2022                               */
/* Purpose:        Base class header file for the functions that*/
/*                 WordDataList, WordVector, and WordCList will */
/*                 inherit and use.                             */
/****************************************************************/

/*!
*   \authors Dr. Spiegel, Hamad Ahmed
*   \file WordList.h
*   \brief Base class header file for the functions that WordDataList, WordVector, and WordCList will inherit and use.
*/

#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;

/*!
*   \class WordList
*   Parse-in and pure virtual print functions to be implemented by each container subclasses
*/

class WordList {
public:

  // Place the line of text into the data structure
  /*!
  *   \fn parseIntoList
  *   \brief reads data from a file and inserts it into the selected container
  *   \param ifstream &inf ifstream file objects
  *   \return none
  */
  virtual void parseIntoList(ifstream &inf)=0;

  // Print the data iteratively
  /*!
  *   \fn printIteratively
  *   \brief prints a container's data iteratively
  *   \param none
  *   \return none
  */
  virtual void printIteratively()=0;
  
  // Print the data recursively
  /*!
  *   \fn printRecursively
  *   \brief establishes the recursive print 
  *   \param none
  *   \return none
  */
  virtual void printRecursively()=0;

  /*!
  *   \fn recursivePrint
  *   \brief prints the data from container using an iterative pointer
  *   \param none
  *   \return none
  */
  virtual void recursivePrint() {}
  
  // Print the data recursively with a pointer
  /*!
  *   \fn printPtr
  *   \brief prints the Object Array container's data using pointers only
  */
  virtual void printPtr() {}   // not pure virtual; why?
  
};
  
#endif
