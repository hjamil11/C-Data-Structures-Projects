/*******************************************************************/
/*  Author:         Hamad Ahmed                                    */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #3                                     */
/*  Filename:       WordCList.cpp                                  */
/*  Purpose:        WordCList class header file and function       */
/*                  implementations                                */
/*******************************************************************/

/*!
*   \author Hamad Ahmed
*   \file WordCList.cpp
*   \brief Function implementations for the WordCList subclass
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "WordCList.h"

using namespace std;
using namespace std::chrono;

// A default constructor
WordCList::WordCList() {}

void WordCList::parseIntoList(ifstream &inf)
{
    /********************************************************************/
    /*                                                                  */
    /* Function Name: parseIntoList                                     */
    /* Description:   parses the file and inserts strings to a Circular */ 
    /*                Linked List                                       */
    /* Parameters:    ifstream &inf - input file object - import/export */
    /* Return:        none                                              */
    /*                                                                  */
    /********************************************************************/

    // Records the function start time
    //printf("ths ran");
    auto begin = high_resolution_clock::now();

    // ClistItr<WordData> ListItr(CLList);

    // printf("this also ran");
    // bool duplicate = false;
    // string data = "";
    // printf("ths ran");
    // // // This while loop reads in the data from the file called 'inf'
    // while (inf >> data)
    // {   
    //     // Sets the iterator to the beginning of the list
    //     ListItr.begin();

    //     // Checks if the Circular Linked List is empty
    //     if (!ListItr.isEmpty())
    //     {   
    //         // Checks for the duplicates, and inserts the data into the list
    //         do
    //         {
    //             // Checks if there is a duplicate found in the list
    //             if (data == (*ListItr).getWord())
    //             {
    //                 // Sets the duplicate value to true
    //                 duplicate = true;
                    
    //                 // Creates a temp object of the WordData type
    //                 WordData temp(data, (*ListItr).getCount()+1);
                    
    //                 // Removes the Circular Linked iterator.
    //                CLList.remove(*ListItr);

    //                // Inserts the unique data into the list
    //                CLList.orderedInsert(temp);
    //                break;
    //             }
    //         } while(!ListItr++.isLastNode());
    //     }

    //     // Checks if the duplicate is not found
    //     if (!duplicate)
    //     {
    //         // Then, inserts the data into the circular linked list in order
    //         CLList.orderedInsert(WordData(data, 1));
    //     }
    //     else
    //     {
    //       // Otherwise, sets the duplicate to false
    //        duplicate = false;
    //     }
    // }

    // Declares a variable named 'data' that takes in a word from the input file.
    string data = "";

    // Reads in the data from the input file and insert it into the circular linked list
    while (inf >> data)
    {
        CLList.orderedInsert(WordData(data, 1));
    }

    // Rewinds the file to beginning
    inf.clear();
    inf.seekg(0);

    // Records the end time of the function
    auto end = high_resolution_clock::now();
    
    // Computes the duration
    auto ticks = duration_cast<microseconds>(end-begin);

    // Displays the duration time that it took to run the function
    cout << "\n\nWordCList parse into list function took " << ticks.count() << " microseconds to complete" << endl;
}

void WordCList::printIteratively()
{
    /********************************************************************/
    /*                                                                  */
    /* Function Name: printIteratively                                  */
    /* Description:   prints the Circular Linked List iteratively       */
    /* Parameters:    none                                              */
    /* Return:        none                                              */
    /*                                                                  */
    /********************************************************************/

    auto begin = high_resolution_clock::now();

    // Prints the format for this type of output
    cout << "Object Vector Iterative" << endl;
    cout << "WORDS" << "    :    " << "OCCURRENCES" << endl;

    // Declares a Circular Linked List iterator
    ClistItr<WordData> ListItr(CLList);

    // Prints the list
    for (ListItr.begin(); !ListItr.isLastNode(); ListItr++)
    {
        //printf("%-9s %10d\n", (*ListItr).getWord(), (*ListItr).getCount());
        cout << " " << *ListItr << endl;
    }

    auto end = high_resolution_clock::now();

    auto ticks = duration_cast<microseconds>(end-begin);

    cout << "\nThis took " << ticks.count() << " microseconds to run" << endl;
}

void WordCList::printRecursively()
{
    /********************************************************************/
    /*                                                                  */
    /* Function Name: printRecursively                                  */
    /* Description:   initiates the recursive print                     */
    /* Parameters:    none                                              */
    /* Return:        none                                              */
    /*                                                                  */
    /********************************************************************/

    // Records the start time of the function
    auto begin = high_resolution_clock::now();

    // Prints the format for this type of output
    cout << "Object Vector Recursively" << endl;
    cout << "WORDS" << "    :    " << "OCCURRENCES" << endl;

    // Declares a Circular Linked List Iterator
    ClistItr<WordData> ListItr(CLList);

    // Sets the iterator to the beginning
    ListItr.begin();

    // Calls the recursive print function that prints the list
    recursivePrint(ListItr);

    // Records the end time of the function
    auto end = high_resolution_clock::now();

    // Computes the duration from start to end in microseconds
    auto ticks = duration_cast<microseconds>(end-begin);

    // Displays the duration
    cout << "\nThis took " << ticks.count() << " microseconds to run" << endl; 
}

void WordCList::recursivePrint(ClistItr<WordData> CListItr) 
{   
    /*****************************************************************************************/
    /*                                                                                       */
    /* Function Name: recursivePrint                                                         */
    /* Description:   prints the Circular Linked List recursively                            */
    /* Parameters:    ClistItr<WordData> CListItr - a ciruclar linked list iterator - import */
    /* Return:        none                                                                   */
    /*                                                                                       */
    /*****************************************************************************************/

    // This base case checks whether the iterator is not equal to the last node
    if (!CListItr.isLastNode())
    {   
        // Prints the list
        cout << " " << *CListItr << endl;

        // Increments to the next node
        CListItr++;

        // Calls the function itself recursively
        recursivePrint(CListItr);
    }
}