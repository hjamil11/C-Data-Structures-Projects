/***************************************
 *    File:    WordData.cpp            *
 *    Prepared by: Dr. Spiegel         *
 *                                     *
 ***************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

WordData::WordData(string wrd, int cnt)
{
	setWordData(wrd, cnt);	
}

void WordData::setWord(string wrd)
{
	word = wrd;
}

void WordData::setCount(int cnt)
{
	count = cnt;
}

void WordData::setWordData(string wrd, int cnt)
{
	setWord(wrd);
	setCount(cnt);
}

string WordData::getWord() const
{
	return(word);
}

int WordData::getCount() const
{
	return(count);
}

WordData& WordData::operator++()	// preincrement
{	setCount(getCount()+1);
	return(*this);
}

WordData WordData::operator++(int)	// postincrement
{	WordData temp;
	setCount(getCount()+1);
	return(temp);
}

ostream &operator<<(ostream &output,const WordData &word)
{
	//cout << left << word[i] << setw(10);
	output << left << word.getWord() << setw(15) << right << word.getCount(); 
	return output;	
}