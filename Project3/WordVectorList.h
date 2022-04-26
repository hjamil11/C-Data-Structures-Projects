/*******************************************************************/
/*  Author:         Hamad Ahmed                                    */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #3                                     */
/*  Filename:       WordVectorList.h                               */
/*  Purpose:        WordVector subclass header file that contains  */
/*                  function prototypes                            */
/*******************************************************************/

/*!
*   \author Hamad Ahmed
*   \file WordVectorList.h
*   \brief WordVector subclass header file that contains function implementations
*/

#ifndef WORDVECTORLIST_H
#define WORDVECTORLIST_H

#include <fstream>
#include <vector>
#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

/*!
*   \class WordVectorList
*   \brief Subclass functions used to insert into and print object vector list
*/

// Declare the subclass
class WordVectorList : public WordList
{
    public:
        // WordVector constructor
        /*!
        *   \fn WordVector
        *   \param none
        *   \return none
        */
        WordVectorList();

        // parseIntoList function parses file and inserts 
        // strings to a WordData vector
        /*!
        *   \fn parseIntoList
        *   \brief parses the file and inserts strings to a WordData vector
        *   \param ifstream &inf input file object as a reference
        */
        void parseIntoList(ifstream &inf);

        // printIteratively function prints the WordData vector iteratively
        // Prints the data iteratively
        /*!
        *   \fn printIteratively
        *   \brief prints the WordData vector iteratively
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

        // recursivePrint function prints the WordData vector recursively
        /*!
        *   \fn recursivePrint
        *   \brief prints the WordData vector recursively
        *   \param int n 
        *   \return none
        */
        void recursivePrint(vector<WordData> &objVect, vector<WordData>::iterator &itr);
    
    private:
        // WordData vector list declaration
        /*!
        *   Vector list of the WordData type
        */
        vector<WordData> objVect;
};

#endif