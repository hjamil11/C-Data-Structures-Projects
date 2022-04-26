/*******************************************************************/
/*  Author:         Hamad Ahmed                                    */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #3                                     */
/*  Filename:       WordCList.h                                    */
/*  Purpose:        WordCList class header file and function       */
/*                  prototypes                                     */
/*******************************************************************/

/*!
*   \author Hamad Ahmed
*   \file WordCList.h
*   \brief WordCList class header file and function implementations
*/

#ifndef WORDCLIST_H
#define WORDCLIST_H

#include <fstream>
#include <string>
#include "WordList.h"
#include "CLinkedList.h"
#include "WordData.h"

// Declares the 'WordCList' subclass
class WordCList : public WordList
{
    public:
        // WordCList default constructor
        /*!
        *   \fn Constructor
        *   \brief A default constructor
        *   \param none
        *   \return none
        */
        WordCList();

        // parseIntoList function parses file and inserts 
        // strings to a Circular Linked List
        /*!
        *   \fn parseIntoList
        *   \brief parses the file and inserts strings to a Circular Linked List
        *   \param ifstream &inf input file object as a reference
        */
        void parseIntoList(ifstream &inf);

        // printIteratively function prints the Circular Linked List iteratively
        // Print the data iteratively
        /*!
        *   \fn printIteratively
        *   \brief prints the Circular Linked List iteratively
        *   \param none
        *   \return none
        */
        void printIteratively();

        // printRecursively function establishes the recursive print
        /*!
        *   \fn printRecursively
        *   \brief establishes the recursive print
        *   \param none
        *   \return none
        */
        void printRecursively();

        // recursivePrint function prints the Circular Linked List recursively
        /*!
        *   \fn recursivePrint
        *   \brief prints the circular linked list recursively
        *   \param CLinkedList<WordData> CListItr a circular linked list iterator used to print and increment
        *   \return none
        */
        void recursivePrint(ClistItr<WordData> CListItr);
    
    private:
        // Creates a circular linked list of 'WordData' type
        /*!
        * Circular Linked List of WordData type to store strings and their occurrences
        */
        CLinkedList<WordData> CLList;
};
#endif