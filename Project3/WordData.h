/*******************************************************************/
/*  Author:         Dr. Spiegel (edited by Hamad Ahmed)            */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #3                                     */
/*  Filename:       WordData.h                                     */
/*   Purpose:       The Only Addition i made to this file was      */ 
/*                  an overloading of the << operator.             */
/*******************************************************************/

/*!
*    \author Dr. Spiegel
*    \file WordData.h
*    \brief WordData is a simple object that holds a string and an int.
*/

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

/*!
*    \class WordData
*    \brief This class holds a string and int to count the occurrences of a string
*/

class WordData {

public:
        //Constructor
        /*!
        *    \fn WordData
        *    \brief a default constructor
        *    \param string wrd a string data
        *    \param int cnt string data's counter
        *    \return none
        */
        WordData(string wrd = "", int cnt = 1);

        /*!
        *    \fn setWord
        *    \brief sets the object's string
        *    \param string wrd a string data
        *    \return none
        */
        void setWord(string wrd);

        /*!
        *    \fn setCount
        *    \brief sets the object's counter
        *    \param int cnt string data's counter
        *    \return none
        */
        void setCount(int cnt);

        //Set Whole WordData Object
        /*!
        *    \fn setWordData
        *    \brief sets the object's string and counter
        *    \param string wrd a string data
        *    \param int cnt string data's counter
        *    \return none
        */
        void setWordData(string,int);

        //Gets the word
        /*!
        *    \fn getWord
        *    \brief returns a string
        *    \param none
        *    \return string
        */
        string getWord() const;

        /*!
        *    \fn getCount
        *    \brief returns a counter
        *    \param none
        *    \return int
        */
        int getCount() const;

        //Increments the counter
        /*!
        *    \fn incCount
        *    \brief increments the counter if a match is found
        *    \param int inc icrements the counter
        *    \return none
        */
        void incCount(int inc = 1);

        // preincrement
        /*!
        *    \fn operator++
        *    \brief pre-increments the count of the word
        *    \param none
        *    \return none
        */
        WordData& operator++();	

        // postincrement
        /*!
        *    \fn operator++
        *    \brief post-increments the count of the word
        *    \param none
        *    \return none
        */
        WordData operator++(int);

        /*!
        *    \fn operator<
        *    \brief compares the count's value to the right
        *    \param WordData &right value to compare the count's value
        *    \return bool
        */
        bool operator<(WordData &right);

        /*!
        *    \fn operator<
        *    \brief compares the count's value to an int
        *    \param int right holds the int value to compare it to 
        *    \return bool
        */
        bool operator<(string right);

        /*!
        *    \fn operator==
        *    \brief compares the WordData value to an string
        *    \param WordData &p holds the value to compare it to
        *    \return bool 
        */
        bool operator==(WordData &p);
        
        /*!
        *    \fn operator<=
        *    \brief compares the WordData value to an string
        *    \param WordData &right holds the value to compare it to
        *    \return bool
        */
        bool operator<=(WordData &right);

        /*!
        *    \fn operator<=
        *    \brief compares the string value 'right' to the value
        *    \param string right holds the value to compare it to
        *    \return bool
        */
        bool operator<=(string right);

        /*!
        *    \fn operator>=
        *    \brief compares the WordData to the getWord function value
        *    \param WordData &right holds the value to compare it to
        *    \return bool
        */
        bool operator>=(WordData &right);

        /*!
        *    \fn operator>=
        *    \brief compares the string value 'right' to the value
        *    \param string right holds the value to compare it to
        *    \return bool
        */
        bool operator>=(string right);
private:
        //variables
        /*!
        *    word holds a string
        */
        string word;

        /*!
        *    count updates the occurrences of the word
        */
        int count;
};

// Stream inserts a word
/*!
*    stream inserts a word
*/
ostream &operator<<(ostream& output, const WordData &words);

#endif
