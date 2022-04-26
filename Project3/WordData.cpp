/*******************************************************************/
/*  Author:         Dr. Spiegel                                    */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #3                                     */
/*  Filename:       WordData.cpp                                   */
/*   Purpose:       The Only Addition i made to this file was      */ 
/*                  an overloading of the << operator.             */
/*******************************************************************/

/*!
*    \author Dr. Spiegel
*    \file WordData.cpp
*    \brief Function implementations of WordData class
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

WordData::WordData(string wrd, int cnt)
{
        /**************************************************************/
        /*                                                            */
        /* Function Name: WordDataList                                */
        /* Description:   A default constructor that calls the        */
        /*                setWordData to initialize a word and counter*/
        /* Parameter:     string wrd - a string data - import         */
        /*                int cnt - string data's counter - import    */
        /* Return Value:  none                                        */
        /*                                                            */
        /**************************************************************/

        // Calls the setWordData function that takes in 'wrd' and 'cnt' as arguements.
        setWordData(wrd, cnt);
}

void WordData::setWord(string wrd)
{
        /**************************************************************/
        /*                                                            */
        /* Function Name: setWord                                     */
        /* Description:   sets the object's string                    */
        /* Parameter:     string wrd - a string data - import         */
        /* Return Value:  none                                        */
        /*                                                            */
        /**************************************************************/

        // Sets the word's value
        word = wrd;
}

void WordData::setCount(int cnt)
{
        /**************************************************************/
        /*                                                            */
        /* Function Name: setCount                                    */
        /* Description:   sets the object's counter                   */
        /* Parameter:     int cnt - string data's counter - import    */
        /* Return Value:  none                                        */
        /*                                                            */
        /**************************************************************/
        
        // Sets the count value
        count = cnt;
}

void WordData::setWordData(string wrd, int cnt)
{
        /**************************************************************/
        /*                                                            */
        /* Function Name: setWordData                                 */
        /* Description:   initializes a word and counter              */
        /* Parameter:     string wrd - a string data - import         */
        /*                int cnt - string data's counter - import    */
        /* Return Value:  none                                        */
        /*                                                            */
        /**************************************************************/

        // Calls the setWord function that takes in 'wrd' as an argument
        setWord(wrd);

        // Calls the setCount function that takes in 'cnt' as an argument
        setCount(cnt);
}
string WordData::getWord() const
{
        /**************************************************************/
        /*                                                            */
        /* Function Name: getWord                                     */
        /* Description:   return a object's string                    */
        /* Parameter:                                                 */
        /* Return Value:  string                                      */
        /*                                                            */
        /**************************************************************/

        // Returns the word
        return(word);
}

int WordData::getCount() const
{
        /**************************************************************/
        /*                                                            */
        /* Function Name: getCount                                    */
        /* Description:   return a object's int                       */
        /* Parameter:                                                 */
        /* Return Value:  int                                         */
        /*                                                            */
        /**************************************************************/

        // Returns the count
        return(count);
}

void WordData::incCount(int inc)
{
        /**************************************************************/
        /*                                                            */
        /* Function Name: incCount                                    */
        /* Description:   increments the counter if a match is found  */
        /* Parameter:     int inc - string data increment - import    */
        /* Return Value:  none                                        */
        /*                                                            */
        /**************************************************************/
        
        // Increments the count by 'inc' numbers
        count+=inc;
}

ostream &operator<<(ostream& output, const WordData &words)
{
        /************************************************************************/
        /*                                                                      */
        /* Function Name: operator<<                                            */
        /* Description:   Outputs the word and it's occurrences                 */
        /* Parameter:     ofstream& output - for output - import/export         */
        /*                constWordData& word - WordData object - import/export */
        /* Return Value:  ofstream&                                             */
        /*                                                                      */
        /************************************************************************/

        // Outputs the word and it's count
        output<<words.getWord()<<"\t\t"<<words.getCount();

        // Returns the output
        return output;
}

// preincrement
WordData& WordData::operator++()	
{	
        /*************************************************************************/
        /*                                                                       */
        /* Function Name: operator++                                             */
        /* Description:   pre-increments the count of the word                   */
        /* Parameter:     none                                                   */
        /* Return Value:  this                                                   */
        /*                                                                       */
        /*************************************************************************/

        // Calls the SetCounts to increments count's value
        setCount(getCount()+1);
	return(*this);
}

// postincrement
WordData WordData::operator++(int)	
{	
        /*************************************************************************/
        /*                                                                       */
        /* Function Name: operator++                                             */
        /* Description:   post-increments the count of the word                  */
        /* Parameter:     none                                                   */
        /* Return Value:  WordData                                               */
        /*                                                                       */
        /*************************************************************************/

        // Increments the count
        WordData temp;
	setCount(getCount()+1);
	return(temp);
}

bool WordData::operator<(WordData &right)
{       
        /*************************************************************************************/
        /*                                                                                   */
        /* Function Name: operator<                                                          */
        /* Description:   less than operator to compare the word                             */
        /* Parameter:     WordData &right - holds the value to compare it to - import/export */
        /* Return Value:  bool                                                               */
        /*                                                                                   */
        /*************************************************************************************/

        // Returns the bool value of this comparison
        return (getWord() < right.getWord());
}

bool WordData::operator<(string right)
{       
        /***************************************************************************/
        /*                                                                         */
        /* Function Name: operator<                                                */
        /* Description:   less than operator to compare the word                   */
        /* Parameter:     string right - holds the value to compare it to - import */
        /* Return Value:  bool                                                     */
        /*                                                                         */
        /***************************************************************************/

        // Returns the bool value of this comparison
        return (getWord() < right);
}

bool WordData::operator<=(WordData &right)
{       
        /*************************************************************************************/
        /*                                                                                   */
        /* Function Name: operator<=                                                         */
        /* Description:   less than or equal to operator to compare the word                 */
        /* Parameter:     WordData &right - holds the value to compare it to - import/export */
        /* Return Value:  bool                                                               */
        /*                                                                                   */
        /*************************************************************************************/

        // Returns the bool value of this comparison
        return (getWord() <= right.getWord());
}

bool WordData::operator<=(string right)
{       
        /***************************************************************************/
        /*                                                                         */
        /* Function Name: operator<=                                               */
        /* Description:   less than or equal to operator to compare the word       */
        /* Parameter:     string right - holds the value to compare it to - import */
        /* Return Value:  bool                                                     */
        /*                                                                         */
        /***************************************************************************/

        // Returns the bool value of this comparison
        return (getWord() <= right);
}

bool WordData::operator==(WordData &p)
{       
        /*************************************************************************************/
        /*                                                                                   */
        /* Function Name: operator==                                                         */
        /* Description:   equal to operator to compare the word                              */
        /* Parameter:     WordData &p - holds the value to compare it to - import/export     */
        /* Return Value:  bool                                                               */
        /*                                                                                   */
        /*************************************************************************************/

        // Returns the bool value of this comparison
        return (getWord() == p.getWord());
}

bool WordData::operator>=(WordData &right)
{       
        /*************************************************************************************/
        /*                                                                                   */
        /* Function Name: operator>=                                                         */
        /* Description:   greater than or equal to operator to compare the word              */
        /* Parameter:     WordData &right - holds the value to compare it to - import/export */
        /* Return Value:  bool                                                               */
        /*                                                                                   */
        /*************************************************************************************/

        // Returns the bool value of this comparison
        return (getWord() >= right.getWord());
}

bool WordData::operator>=(string right)
{       
        /***************************************************************************/
        /*                                                                         */
        /* Function Name: operator>=                                               */
        /* Description:   greater than or equal to operator to compare the word    */
        /* Parameter:     string right - holds the value to compare it to - import */
        /* Return Value:  bool                                                     */
        /*                                                                         */
        /***************************************************************************/

        // Returns the bool value of this comparison
        return (getWord() >= right);
}