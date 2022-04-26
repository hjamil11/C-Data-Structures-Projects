/***************************************************************/
/*                                                             */
/* Author:     Dr. Spiegel (edited by Hamad Ahmed)             */
/* Filename:   WordDataList.cpp                                */
/* Course:     CSC 237 Data Structures                         */
/* Assignment: Project #3                                      */
/* Due Date:   March 31, 2022                                  */
/* Purpose:    This subclass header file contains the functions*/
/*             prototypes                                      */
/*                                                             */
/***************************************************************/

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

class WordDataList : public WordList {
public:

  /*!
  *   \fn WordDataList
  *   \brief a WordDataList default constructor
  *   \param none
  *   \return none
  */
  WordDataList();

  // parseIntoList function
  /*!
  *   \fn parseIntoList
  *   \brief Put a string of strings into the WordDataList object
  *   \param inf &inf input file object
  *   \return none
  */
  virtual void parseIntoList(ifstream &inf);

  // Print the data iteratively
  /*!
  *   \fn printIteratively
  *   \brief prints the WordDataList data iteratively
  *   \param none
  *   \return none
  */
  virtual void printIteratively();
  
  // Print the data recursively
  /*!
  *   \fn printRecursively
  *   \brief invokes the recursive print worker
  *   \param none
  *   \return none
  */
  virtual void printRecursively();
  
  // Print the data recursively with a pointer
  /*!
  *   \fn printPtr
  *   \brief prints the WordDataList data using pointers only
  *   \param none
  *   \return none
  */
  virtual void printPtr();

private:
  /*!
  *   object array of the WordData type
  */
  WordData TheWords[10];

  /*!
  *   holds the occurrences of the words
  */
  int numWords;

  // Look for a match and increment if found
  /*!
  *   \fn incMatch
  *   \brief increments the occurrences of the word
  *   \param string temp holds a temporary value to check for the duplicate
  *   \return bool
  */
  bool incMatch(string temp);
  
  // Function to actually perform recursive print
  /*!
  *   \fn printRecursiveWorker
  *   \brief helper function that actually performs the recursive print 
  *   \param int numWords holds the occurrences of the word
  *   \return none
  */
  void printRecursivelyWorker(int numWords);

  // Function to actually perform recursive print using pointer
  /*!
  *   \fn printPtrWorker
  *   \brief helper function that actually performs the pointer print
  *   \param int numWords holds the occurrences of the word
  *   \return none
  */
  void printPtrWorker(int numWords);
};
  
#endif
