/****************************************************************/
/*  Author:         Hamad Ahmed                                 */
/*  Major:          Computer Science                            */
/*  Creation Date:  February 14, 2022                           */
/*  Due Data:       February 24, 2022                           */
/*  Course:         CSC 237                                     */
/*  Professor Name: Dr. Spiegel                                 */
/*  Assignment:     Project #1                                  */
/*  Filename:       main.cpp                                    */
/*  Purpose:        This programm will accept a filename, and   */
/*                  prints unique strings and their occurrences */
/*                  in the file.                                */
/****************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "WordData.h"

using namespace std;

/*********************************************************************************/

// Function Prototypes

// Display Menu Function
void displayMenu();

// Parallel Array Functions
int read_pArray(fstream &dataFile, string word[], int count[]);

void pArray_Iterative(fstream &dataFile);
void output_pArray_iteratively(string word[], int count[], int elts);

void pArray_recursive(fstream &dataFile);
void output_pArray_recursively(string word[], int count[], int elts);

// Object Array Functions
int read_objArray(fstream &dataFile, WordData objArray[]);

void objArray_iterative(fstream &dataFile);
void output_objArray_iteratively(WordData objArray[], int elts);

void objArray_rescurive(fstream &dataFile);
void output_objArray_recursively(WordData objArray[], int elts);

void objArray_pointer(fstream &dataFile);
void output_objArray_pointer(WordData objArray[], int elts);

// Vector Implementation Functions
int read_Vector(fstream &dataFile, vector<WordData> &objVect);

void for_loop_vector(fstream &dataFile);
void output_for_loop_vector(vector<WordData> &objVect, int elts);

void iterator_vector(fstream &dataFile);
void output_iterator_vector(vector<WordData> &objVect);

/*********************************************************************************/

int main(int argc,char **argv)
{
    // Declares the 'dataFile' file object
    fstream dataFile;

    // Checks if the command line argument sub 1 is true,
    if (argv[1])
    {
        // Checks if the 'dataFile' has not successfully,
        if (dataFile.fail())
        {
            // Then, display an error message
            cout << "File did not open successfully!" << endl;
        }
        // Otherwise,
        else
        {
            // Open the 'dataFile' as the first argument and call all the required functions
            dataFile.open(argv[1]);

            pArray_Iterative(dataFile);
            pArray_recursive(dataFile);
            objArray_iterative(dataFile);
            objArray_rescurive(dataFile);
            objArray_pointer(dataFile);
            for_loop_vector(dataFile);
            iterator_vector(dataFile);

            return 0;
        }
    }

    // Declares the user's 'choice' variable
    int choice;

    // Declares a variable 'filename' to store the file name
    string filename;

    // Prompts the user for a file name and stores it in 'filename'
    cout << "Enter the file name: " << endl;
    cin >> filename;

    // Opens the file 'filename'
    dataFile.open(filename);

    // Checks if the 'dataFile' did not open successfully
    if (!dataFile)
    {
        // If the 'dataFile' did not open successfully, then print an error message and exit the program.
        cout << "Unable to open "<< filename <<", please try again!" << endl;
        return 0;
    }
    // If the 'dataFile' opened successfully
    else
    {
        // This do-while loop displays the menu, prompts the user for a menu choice, 
        // and calls the functions according to the user's choice.
        // It keeps repeating this process until the user choice is '8', which exits the programs.
        do
        {
            cout << endl;

            // Calls the displayMenu function that displays the menu options.
            displayMenu();

            // Prompts the user for the menu choice.
            cout << "Choose an option by typing the number 1-7 or 8 to exit:" << endl;
            cin >> choice;
            
            // Validates the user 'choice' input, if they enter a number less than 1 or greater than 8
            if (choice < 1 | choice > 8)
            {
                cout << "Invalid input, please try again!" << endl;
            }

            // Calls the appropriate function according to the user's choice or quits the program.
            switch(choice)
            {
                case 1:
                    // Parallel array iteratively
                    pArray_Iterative(dataFile);
                    break;
                case 2:
                    // Parallel array recursively
                    pArray_recursive(dataFile);
                    break;
                case 3:
                    // Object array iteratively
                    objArray_iterative(dataFile);
                    break;
                case 4:
                    // Object array recursively
                    objArray_rescurive(dataFile);
                    break;
                case 5:
                    // Object array pointer
                    objArray_pointer(dataFile);
                    break;
                case 6:
                    // Vector container for loop
                    for_loop_vector(dataFile);
                    break;
                case 7:
                    // Vector container iterator
                    iterator_vector(dataFile);
                    break;
                default:
                    cout << "Thank you for trying this program!" << endl;
                    break;
            }
        }
        // Keep displaying the menu options and prompting the user for choice,
        // until the user enter '8' to quit the program.
        while (choice != 8);
    }

    return 0;
}

/*********************************************************************************/

// DisplayMenu function displays the menu to the user
void displayMenu()
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: displayMenu                                            */
    /* Description:   Displays the menu options for the user                 */
    /* Parameters:    None                                                   */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Display the menu options
    cout << "Menu Options" << endl;
    cout << "1. Parallel Iterative" << endl;
    cout << "2. Parallel Recursive" << endl;
    cout << "3. Object Array Iterative" << endl;
    cout << "4. Object Array Recursive" << endl;
    cout << "5. Object Array Pointer" << endl;
    cout << "6. Vector For Loop" << endl;
    cout << "7. Vector Iterator" << endl;
    cout << "8. Exit" << endl;
}

/*********************************************************************************/

// Parallel Array Implementation
void pArray_Iterative(fstream &dataFile)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: pArray_Iterative                                       */
    /* Description:   Reads the 'dataFile', and outputs the string and their */ 
    /*                occurrences iteratively in the file                    */
    /* Parameters:    fstream &dataFile: file object - import/export         */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/
    
    // Declares an int variable 'elts' that will store the number of strings in the file.
    int elts;

    // Declares a const int variable 'MAXSIZE' that includes the maximum number of elements
    // that parallel array can have. 
    const int MAXSIZE = 10;

    // Declares a string 'word_array' array with a size of 'MAXSIZE' that will store 
    // 10 unique strings from the file.
    string word_array[MAXSIZE];

    // Declares an int 'count_array' array with a size of 'MAXSIZE' that will store
    // the occure
    int count_array[MAXSIZE];

    // Calls read_pArray() function that reads the strings from the file,
    // and checks for duplicate(s)
    elts = read_pArray(dataFile, word_array, count_array);

    // Calls the output_pArray_iteratively() function that outputs the result
    output_pArray_iteratively(word_array, count_array, elts);
}

int read_pArray(fstream &dataFile, string word[], int count[])
{
    /***********************************************************************************/
    /*                                                                                 */
    /* Function name: read_pArray                                                      */
    /* Description:   Reads the 'dataFile', and stores unique strings in               */
    /*                'word[]' and their occurrences in 'count[]'                      */
    /* Parameters:    fstream &dataFile: file object - import/export                   */
    /*                string word[]: array of strings in the 'dataFile' - import       */
    /*                int count[]: array of strings occurrences in 'dataFile' - import */
    /* Return Value:  int - number of strings in 'dataFile'                            */
    /*                                                                                 */
    /***********************************************************************************/

    // Declares the necessary variables needed
    bool duplicate = false;
    string data = "";
    int eltNum = 0;
    const int MAX_ELTS = 10;

    // This while loop reads the file and checks for any duplicates
    while (dataFile >> data)
    {  
        // This for loop keeps iterating if the counter 'i' is less than number of elements 'eltNum'
        // and the number of elements 'eltNum' is greater than 0 
        for (int i = 0; i < eltNum && eltNum > 0; i++)
        {
            // If the for loop statement is true,
            // Check if any elements in word[] array matches the 'data' in the file
            if (word[i] == data)
            {
                // If yes, 'duplicate' is found and set its value to true
                duplicate = true;

                // Also, icrement that word's occurrence
                count[i] = count[i] + 1;
            }
        }

        // Now, for the case, where a duplicate was not found
        if (!duplicate)
        {
            // Then, if the number of elements is less than the maximum elements limit
            if (eltNum < MAX_ELTS)
            {
                // If yes, then put the unique data in 'word[]' array
                word[eltNum] = data;

                // Morover, set the unique data's occurrence to 1
                count[eltNum] = 1;

                // Furthermore, icrement the number of elements in the parallel array
                eltNum++;
            }
        }
        // For the case, where a duplicate was found
        else
        {
            // Reset the value of duplicate to check for the next iteration data 
            duplicate = false;
        }
    }

    // Rewinds the file to beginning
    dataFile.clear();
    dataFile.seekg(0);

    return eltNum;
}

void output_pArray_iteratively(string word[], int count[], int elts)
{
    /*******************************************************************************/
    /*                                                                             */
    /* Function name: output_pArray_iteratively                                    */
    /* Description:   Takes the 'word[]' and 'count[]' and prints them iteratively */
    /* Parameters:    string word[]: dataFile  unique strings array - import       */
    /*                int count[]: dataFile unique strings occurrences - import    */
    /*                int elts: number of elements in string word[] array - import */
    /* Return Value:  None                                                         */
    /*                                                                             */
    /*******************************************************************************/

    // Displays out to the screen the output method used for this outputting
    cout << "Parallel Array Output Interatively" << endl;
    cout << "WORDS" << "    :    " << " Occurrences" << endl;

    // This for loop prints the words and their occurrences iteratively
    for (int i = 0; i < elts; i++)
    {
        printf("%-11s %10d\n", word[i].c_str(), count[i]);
    }
}

void pArray_recursive(fstream &dataFile)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: pArray_recursive                                       */
    /* Description:   Reads the 'dataFile', and outputs the string and their */ 
    /*                occurrences recursively in the file                    */
    /* Parameters:    fstream &dataFile: file object - import/export         */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Declares the necessary variables needed
    int elts;
    const int MAXSIZE = 10;
    string word_array[MAXSIZE];
    int count_array[MAXSIZE];

    // Calls read_pArray() function that reads the strings from the file,
    // and checks for duplicate(s)
    elts = read_pArray(dataFile, word_array, count_array);

    cout << "Output Parallel Array Recursively" << endl;
    cout << "WORDS" << "    :    " << " Occurrences" << endl;

    // Calls the output_pArray_iteratively() function that outputs the result
    output_pArray_recursively(word_array, count_array, elts);
}

void output_pArray_recursively(string word[], int count[], int elts)
{
    /*******************************************************************************/
    /*                                                                             */
    /* Function name: output_pArray_recursively                                    */
    /* Description:   Takes the 'word[]' and 'count[]' and prints them recursively */
    /* Parameters:    string word[]: dataFile  unique strings array - import       */
    /*                int count[]: dataFile unique strings occurrences - import    */
    /*                int elts: number of elements in string word[] array - import */
    /* Return Value:  None                                                         */
    /*                                                                             */
    /*******************************************************************************/

    // Declares a static int variable called 'idx' because 'idx' or the index does not reset
    // whenever this function is called recursively 
    static int idx = 0;

    // Checks to see if the 'idx' is less than the number of elements 'elts'
    if (idx < elts)
    {
        // If yes, output the words and their occurrences recursively
        printf("%-11s %10d\n", word[idx].c_str(), count[idx]);
        idx++;
        output_pArray_recursively(word, count, elts);
    }
    else
    {
        idx = 0;
    }
}

/*********************************************************************************/

// Object Array Implementation
int read_objArray(fstream &dataFile, WordData objArray[])
{
    /***********************************************************************************/
    /*                                                                                 */
    /* Function name: read_objArray                                                    */
    /* Description:   Reads the 'dataFile', and stores unique strings in 'objArray[]'  */
    /* Parameters:    fstream &dataFile: file object - import/export                   */
    /*                string word[]: array of strings in the 'dataFile' - import       */
    /*                int count[]: array of strings occurrences in 'dataFile' - import */
    /* Return Value:  int - number of strings in 'dataFile'                            */
    /*                                                                                 */
    /***********************************************************************************/

    // Declares the necessary variables needed
    bool duplicate = false;
    string data = "";
    int eltNum = 0;
    const int MAX_ELTS = 10;

    // This while loop reads the file and checks for any duplicates
    while (dataFile >> data)
    {
        // This for loop traverses the object array 'objArray' and finds any duplicate(s)
        for (int i = 0; i < MAX_ELTS && MAX_ELTS; i++)
        {
            // If there is a duplicate
            if (data == objArray[i].getWord())
            {
                // Then, sets the duplicate to be true because it was found
                duplicate = true;
                
                // Also, increments the occurrence of the duplicate
                objArray[i]++;
            }
        }

        // If there are not duplicates found
        if (!duplicate)
        {
            // Then, checks if the number of element 'eltNum' is less than the maximum elements limit 'MAX_ELTS'
            if (eltNum < MAX_ELTS)
            {
                // If yes, inserts the unique data and it's occurrence '1' into the object array 'objArray[]' 
                objArray[eltNum] = WordData(data, 1);

                // Also, increments the number of elements in the object array 'objArray[]'
                eltNum++;
            }
        }
        // If the duplicate is not found
        else
            {
                // resets the duplicate to false for the next iteration
                duplicate = false;
            }
    }

    // Rewinds the file to beginning
    dataFile.clear();
    dataFile.seekg(0);

    return eltNum;
}

void objArray_iterative(fstream &dataFile)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: objArray_iterative                                     */
    /* Description:   Reads the 'dataFile', and outputs the string and their */ 
    /*                occurrences iteratively in the file                    */
    /* Parameters:    fstream &dataFile: file object - import/export         */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Declares the necessary variables needed
    int elts;
    const int MAXSIZE = 10;
    WordData objArray[MAXSIZE];

    // Calls the read_objArray() function that reads the string from the file
    // and checks for duplicate(s)
    elts = read_objArray(dataFile, objArray);

    // Calls the output_objArray_iteratively() function that outputs the result
    output_objArray_iteratively(objArray, elts);
}

void output_objArray_iteratively(WordData objArray[], int elts)
{
    /**********************************************************************************/
    /*                                                                                */
    /* Function name: output_objArray_iteratively                                     */
    /* Description:   Takes the'objArray[]' and prints the word and count iteratively */
    /* Parameters:    WordData objArray[] - object array of wordData type - import    */
    /*                int elts: number of elements in string word[] array - import    */
    /* Return Value:  None                                                            */
    /*                                                                                */
    /**********************************************************************************/

    cout << "Object Array Output Iteratively" << endl;
    cout << "WORDS" << "    :    " << "OCCURENCES" << endl;

    // Displays the unique strings and their occurrences iteratively using a for loop 
    for (int i = 0; i < elts; i++)
    {
        //cout << objArray[i] << endl;
        printf("%-9s %10d\n", objArray[i].getWord().c_str(), objArray[i].getCount());
    }
}

void objArray_rescurive(fstream &dataFile)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: pArray_recursive                                       */
    /* Description:   Reads the 'dataFile', and outputs the string and their */ 
    /*                occurrences recursively in the file                    */
    /* Parameters:    fstream &dataFile: file object - import/export         */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/
    int elts;
    const int MAXSIZE = 10;
    WordData objArray[MAXSIZE];

    // Calls the read_objArray() function that reads the string from the file
    // and checks for duplicate(s)
    elts = read_objArray(dataFile, objArray);

    // Calls the output_objArray_recursively() function that outputs the result
    cout << "Object Array Output Recursively" << endl;
    cout << "WORDS" << "    :    " << "OCCURENCES" << endl;
    output_objArray_recursively(objArray, elts);
}

void output_objArray_recursively(WordData objArray[], int elts)
{
    /**********************************************************************************/
    /*                                                                                */
    /* Function name: output_objArray_recursively                                     */
    /* Description:   Takes the'objArray[]' and prints the word and count recursively */
    /* Parameters:    WordData objArray[] - object array of wordData type - import    */
    /*                int elts: number of elements in string word[] array - import    */
    /* Return Value:  None                                                            */
    /*                                                                                */
    /**********************************************************************************/

    // Declares a static int variable called 'idx' because 'idx' or the index does not reset
    // whenever this function is called recursively 
    static int idx = 0;

    // Checks if the index 'idx' is less than the number of elements 'elts'
    if (idx < elts)
    {
        // If yes, output the unique strings and their occurrences in the object array recursively
        //cout << objArray[idx] << endl;
        printf("%-9s %10d\n", objArray[idx].getWord().c_str(), objArray[idx].getCount());
        idx++;
        output_objArray_recursively(objArray, elts);
    }
    else
    {
        idx = 0;
    }
}

void objArray_pointer(fstream &dataFile)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: objArray_pointer                                       */
    /* Description:   Reads the 'dataFile', and outputs the string and their */ 
    /*                occurrences recursively in the file                    */
    /* Parameters:    fstream &dataFile: file object - import/export         */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/
    int elts;
    const int MAXSIZE = 10;
    WordData objArray[MAXSIZE];

    // Calls the read_objArray() function that reads the string from the file
    // and checks for duplicate(s)
    elts = read_objArray(dataFile, objArray);

    // Calls the output_objArray_pointer() function that outputs the result
    output_objArray_pointer(objArray, elts);
}

void output_objArray_pointer(WordData objArray[], int elts)
{
    /************************************************************************************/
    /*                                                                                  */
    /* Function name: output_objArray_pointer                                           */
    /* Description:   Takes the'objArray[]' and prints the word and count using pointer */
    /* Parameters:    WordData objArray[] - object array of wordData type - import      */
    /*                int elts: number of elements in string word[] array - import      */
    /* Return Value:  None                                                              */
    /*                                                                                  */
    /************************************************************************************/

    // Creates a object pointer 'objPtr' and assigns the objArray to it, since objArray is a constant array
     WordData *objPtr = objArray;

     // Prints the format of the pointer output
     cout << "Object Array Output Pointer" << endl;
     cout << "WORDS" << "    :    " << "OCCURENCES" << endl;

    // Prints the unique strings and their occurrences in the object array using a pointer
    for (int i = 0; i < elts; i++)
    {
        //cout << *objPtr << endl;
        printf("%-9s %10d\n", objPtr->getWord().c_str(), objPtr->getCount());
        objPtr++;
    }
}

/*********************************************************************************/

// Vector Implementation
int read_Vector(fstream &dataFile, vector<WordData> &objVect)
{
    /*****************************************************************************************/
    /*                                                                                       */
    /* Function name: read_Vector                                                            */
    /* Description:   Reads the 'dataFile', and stores unique strings in 'objVect'           */
    /* Parameters:    fstream &dataFile: file object - import/export                         */
    /*                vector<WordData> &objVect: vector of 'WordData' object - import/export */
    /* Return Value:  int - number of strings in 'dataFile'                                  */
    /*                                                                                       */
    /*****************************************************************************************/

    // Declares the necessary variables
    bool duplicate = false;
    int elt_Num = 0;
    string data = "";

    // This while loop reads in the data from the file called 'dataFile'
    while (dataFile >> data)
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
            objVect.push_back(WordData(data, 1));

            // Keeps track of the number of elements in the object vector 'objVect'
            elt_Num++;
        }
        // If there was a duplicate found
        else
        {
            // Resets the duplicate to false for the next iteration
            duplicate = false;
        }
    }

    // Rewinds the file to beginning
    dataFile.clear();
    dataFile.seekg(0);

    return elt_Num;
}

void for_loop_vector(fstream &dataFile)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: for_loop_vector                                        */
    /* Description:   Reads the 'dataFile', and outputs the string and their */ 
    /*                occurrences using a for loop in the file               */
    /* Parameters:    fstream &dataFile: file object - import/export         */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Declares an int variable called 'elts' that stores the number of elements in the object vector
    int elts;

    // Declares an object vector 'objVect' of the WordData type
    vector<WordData> objVect;

    // 'elts' store the number of elements in the objVect returned by the 'read_Vector' function
    // Also, calls the 'read_Vector()' function that reads the data from the file, and 
    // stores the unique strings and their occurrences in the object vector
    elts = read_Vector(dataFile, objVect);

    // Calls the output_for_loop_vector() that prints the unique strings and their occurrences
    // from the object vector 'objVect' using a for loop
    output_for_loop_vector(objVect, elts);
}

void output_for_loop_vector(vector<WordData> &objVect, int elts)
{
    /***************************************************************************************/
    /*                                                                                     */
    /* Function name: output_for_loop_vector                                               */
    /* Description:   Takes the'objArray[]' and prints the objVect words and count         */
    /*                using a for loop                                                     */
    /* Parameters:    vector<WordData> &objVect: object vector of WordData - import/export */
    /*                int elts: number of elements in string word[] array - import         */
    /* Return Value:  None                                                                 */
    /*                                                                                     */
    /***************************************************************************************/

    // Prints the format for this type of output
    cout << "For Loop Vector" << endl;
    cout << "WORDS" << "    :    " << "OCCURENCES" << endl;

    // Outputs the unique strings and their occurrences from the object vector 'objVect' using a for loop
    for (int i = 0; i < elts; i++)
    {
        //cout << objVect.at(i) << endl;
        printf("%-9s %10d\n", objVect.at(i).getWord().c_str(), objVect.at(i).getCount());
    }
}

void iterator_vector(fstream &dataFile)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: iterator_vector                                        */
    /* Description:   Reads the 'dataFile', and outputs the string and their */ 
    /*                occurrences iterator_vector in the file                */
    /* Parameters:    fstream &dataFile: file object - import/export         */
    /* Return Value:  None                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Declares an int variable called 'elts' that stores the number of elements in the object vector
    int elts;

    // Declares an object vector 'objVect' of the WordData type
    vector<WordData> objVect;

    // 'elts' store the number of elements in the objVect returned by the 'read_Vector' function
    // Also, calls the 'read_Vector()' function that reads the data from the file, and 
    // stores the unique strings and their occurrences in the object vector
    elts = read_Vector(dataFile, objVect);

    // Calls the output_for_loop_vector() that prints the unique strings and their occurrences
    // from the object vector 'objVect' using iterator
    output_iterator_vector(objVect);
}

void output_iterator_vector(vector<WordData> &objVect)
{
    /***************************************************************************************/
    /*                                                                                     */
    /* Function name: output_iterator_vector                                               */
    /* Description:   Takes the'objArray[]' and prints the objVect words and count         */
    /*                using a iterator                                                     */
    /* Parameters:    vector<WordData> &objVect: object vector of WordData - import/export */
    /*                int elts: number of elements in string word[] array - import         */
    /* Return Value:  None                                                                 */
    /*                                                                                     */
    /***************************************************************************************/

    // Prints the format for this type of output
    cout << "Vector Iterator" << endl;
    cout << "WORDS" << "    :    " << "OCCURENCES" << endl;

    // Declares an iterator called 'itr' that points to the beginning of the object vector 'objVect'
    vector<WordData>::iterator itr = objVect.begin();

    // Outputs the unique strings and their occurrences from the object vector 'objVect' using an iterator
    for (; itr != objVect.end(); itr++)
    {
        printf("%-9s %10d\n", itr->getWord().c_str(), itr->getCount());
    }
}