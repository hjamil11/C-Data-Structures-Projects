/**********************************************************************/
/*  Author:         Hamad Ahmed                                       */
/*  Major:          Computer Science                                  */
/*  Creation Date:  February 28, 2022                                 */
/*  Due Date:       March 10, 2022                                    */
/*  Course:         CSC 237                                           */
/*  Professor Name: Dr. Spiegel                                       */
/*  Assignment:     Project #3                                        */
/*  Filename:       WordVectorList.cpp                                */
/*  Purpose:        WordVectorList subclass header file that contains */
/*                  function implementations                          */
/**********************************************************************/

/*!
*   \author Hamad Ahmed
*   \file WordVectorList.cpp
*   \brief WordVectorList subclass header file that contains function implementation
*/

#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>
#include "WordVectorList.h"

using namespace std;
using namespace std::chrono;

// Word Vector Constructor
WordVectorList::WordVectorList() {}

// Word Parse into list function
void WordVectorList::parseIntoList(ifstream &inf)
{
    /**************************************************************************/
    /*                                                                        */
    /* Function name: parseIntoList                                           */
    /* Description:   Reads the 'inf', and stores unique strings in 'objVect' */
    /* Parameter:     ifstream &inf: file object - import/export              */
    /* Return:        none                                                    */ 
    /*                                                                        */
    /**************************************************************************/

    auto begin = high_resolution_clock::now();

    // Rewinds the file to beginning
    // inf.clear();
    // inf.seekg(0);
    

    // Declares the necessary variables needed
    bool duplicate = false;
    string data = "";

    // This while loop reads in the data from the file called 'inf'
    while (inf >> data)
    {
        // This for loop checks for any duplicates in the object vector 'objVect'
        for (int i = 0; i < objVect.size() && objVect.size() > 0; i++)
        {
            // If there is a duplicate found
            if (data == objVect.at(i).getWord())
            {
                // Sets the duplicate to true
                duplicate = true;
                
                // Also, icrements the occurrence of that duplicate string
                objVect.at(i)++;
            }
        }

        // In the case, if there is no duplicate found
        if (!duplicate)
        {
            // Pushes the unique strings and their occurrences in the back of the object vector 'objVect'
            objVect.push_back(WordData(data,1));
        }
        // If there was a duplicate found
        else
        {
            // Resets the duplicate to false for the next iteration
            duplicate = false;
        }
    }

    // Sorts the object vector
    sort(objVect.begin(), objVect.end());

    // Rewinds the file to beginning
    inf.clear();
    inf.seekg(0);

    auto end = high_resolution_clock::now();

    auto ticks = duration_cast<microseconds>(end-begin);

    cout << "\nWordVectorList parse into list function took " << ticks.count() << " microseconds to complete" << endl;
}


void WordVectorList::printIteratively()
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

    // Outputs the unique strings and their occurrences from the object vector 'objVect' using a for loop
    for (int i = 0; i < objVect.size(); i++)
    {
        printf("%-9s %10d\n", objVect.at(i).getWord().c_str(), objVect.at(i).getCount());
    }

    auto end = high_resolution_clock::now();

    auto ticks = duration_cast<microseconds>(end-begin);

    cout << "\nThis function took " << ticks.count() << " microseconds to run" << endl;
}

void WordVectorList::printRecursively()
{
    /********************************************************************/
    /*                                                                  */
    /* Function Name: printRecursively                                  */
    /* Description:   initiates the recursive print                     */
    /* Parameters:    none                                              */
    /* Return:        none                                              */
    /*                                                                  */
    /********************************************************************/
    
    auto begin = high_resolution_clock::now();

    // Prints the format for this type of output
    cout << "Object Vector Recursively" << endl;
    cout << "WORDS" << "    :    " << "OCCURRENCES" << endl;

    // Calls the recursivePrint() function
    //recursivePrint(0);
    vector<WordData>::iterator itr;
    
    itr = objVect.begin();

    recursivePrint(objVect, itr);

    auto end = high_resolution_clock::now();

    auto ticks = duration_cast<microseconds>(end-begin);

    cout << "\nThis function took " << ticks.count() << " microseconds to run" << endl;
}

void WordVectorList::recursivePrint(vector<WordData> &objVect, vector<WordData>::iterator &itr)
{   
    /************************************************************************/
    /*                                                                      */
    /* Function Name: recursivePrint                                        */
    /* Description:   prints the object vector recursively                  */
    /* Parameters:    int n - a counter for the object vector list - import */
    /* Return:        none                                                  */
    /*                                                                      */
    /************************************************************************/

    if (itr == objVect.end())
    {
        return;
    }

    cout << *itr << endl;
    itr++;
    recursivePrint(objVect, itr);
}