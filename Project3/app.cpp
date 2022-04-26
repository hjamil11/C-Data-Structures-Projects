/*******************************************************************/
/*  Author:         Hamad Ahmed                                    */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #3                                     */
/*  Filename:       app.cpp                                        */
/*  Purpose:        This is a menu-driven test driver program that */
/*                  creates a WordList pointer and calls the       */
/*                  appropriate printing function.                 */
/*******************************************************************/

/*********************************************************************************/

/*!
*   \file app.cpp
*   \brief This menu-driven test driver program creates a WordList pointer and calls the appropriate printing function.
*/

/*********************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "WordList.h"
#include "WordDataList.h"
#include "WordCList.h"
#include "WordVectorList.h"

using namespace std;

/*********************************************************************************/

// Function Prototypes
/*!
    * \fn displayMenu
    * \brief Displays the menu on the screen
    * \return none
*/
void displayMenu();

/*!
    * \fn printEverything
    * \brief Takes in a sentence and sends it through every parsing and printing function
    * \param ifstream - &inf ifstream file object
    * \param WordList - *TheList pointer of the WordList type
    * \return none
*/
void printEverything(ifstream &inf, WordList *TheList);

/*********************************************************************************/

int main(int argc, char *argv[])
{
    // Creates an ifstream obj named 'inf'.
    ifstream inf;

    // Creates a pointer named 'TheList' of WordList type .
    WordList *TheList;
    // WordList *VectList;

    // Checks if the argc is greater than 1.
    if (argc > 1 )
    {
        // Opens the file given as the second command line argument using the 'inf' ifstream object.
        inf.open(argv[1]);

        // If the 'inf' file fails to open.
        if (inf.fail())
        {
            // Then, display an error message for that and terminate the program.
            cout << "Please try again, the file did not open successfully!" << endl;
            return 0;
        }

        // Calls the printEverything() function.
        printEverything(inf, TheList);
        return 0;
    }

    // Declares a variable named 'choice' that will store the menu option chosen by the user.
    char choice;

    // Declares a variable named 'filename' that will store the name of the file enter that the user wants to include.
    string filename;

    // Prompts the user for the file name, stores it in 'filename', and opens it.
    cout << "Please enter a file name: " << endl;
    getline(cin, filename);
    inf.open(filename.c_str());

    // This while loop will keep iterating as long as it's true.
    // This loop displays the menu, prompts the user to choose an appropriate option, and calls the appropriate printing function
    while (true)
    {
        // Calls the displayMenu() function that will display the menu
        displayMenu();

        // Prompts the user for the menu option
        cin >> choice;

        // This case-switch statement validates the menu option and invokes the appropriate printing function
        switch(choice)
        {
            case '1':
                // 1. Object Array Iterative
                TheList = new WordDataList;
                TheList->parseIntoList(inf);
                TheList->printIteratively();
                break;
            case '2':
                // 2. Object Array Recursive
                TheList = new WordDataList;
                TheList->parseIntoList(inf);
                TheList->printRecursively();
                break;
            case '3':
                // 3. Object Array Pointer Only
                TheList = new WordDataList;
                TheList->parseIntoList(inf);
                TheList->printPtr();
                break;
            case '4':
                // 4. Circular List Iterator
                TheList = new WordCList;
                TheList->parseIntoList(inf);
                TheList->printIteratively();
                break;
            case '5':
                // 5. Circular List Iterator Recursive
                TheList = new WordCList;
                TheList->parseIntoList(inf);
                TheList->printRecursively();
                break;
            case '6':
                // 6. Vector Iterator
                TheList = new WordVectorList;
                TheList->parseIntoList(inf);
                TheList->printIteratively();
                break;
            case '7':
                // 7. Vector Recursive
                TheList = new WordVectorList;
                TheList->parseIntoList(inf);
                TheList->printRecursively();
                break;
            case '8':
                // 8. Exit
                // If the user choice is 8. Then, displays a message and terminates a program.
                cout << "Thank you for trying this program!" << endl;
                return 0;
            default:
                // If the user choice is not valid, displays an error message.
                cout << "Invalid option chosen, please try again!" << endl;
                break;
        }
    }

    return 0;
}

/*********************************************************************************/
// displayMenu() Function
void displayMenu()
{
    /*********************************************************************/
    /*                                                                   */
    /*   Function Name: displayMenu()                                    */
    /*   Description:   Displays the menu on the screen.                 */
    /*   Parameter:     none                                             */
    /*   Return:        none                                             */
    /*                                                                   */
    /*********************************************************************/

    cout << endl;
    cout << "Choose a printing method option by typing it's associated number" << endl;
    cout << "1. Object Array Iterative" << endl;
    cout << "2. Object Array Recursive" << endl;
    cout << "3. Object Array Pointer Only" << endl;
    cout << "4. Circular List Iterator" << endl;
    cout << "5. Circular List Iterator Recursive" << endl;
    cout << "6. Vector Iterative" << endl;
    cout << "7. Vector Recursive" << endl;
    cout << "8. Exit" << endl;
}

/*********************************************************************************/
// printEverything() function
void printEverything(ifstream &inf, WordList *TheList)
{
    /*********************************************************************/
    /*                                                                   */
    /*   Function Name: printEverything                                  */
    /*   Description:   Takes in a sentence and sends it through every   */
    /*                  parsing and printing function                    */
    /*   Parameters:    string sentence - sent to every function         */
    /*                  WordDataList TheList - The array of object       */
    /*   Return:        None                                             */
    /*                                                                   */
    /*********************************************************************/

    // Calls all the 'WordDataList' functions to print the list
    TheList = new WordDataList;
    TheList->parseIntoList(inf);
    TheList->printIteratively();
    TheList->printRecursively();
    TheList->printPtr();

    // Calls all the 'WordVectorList' functions to print the list
    TheList = new WordVectorList;
    TheList->parseIntoList(inf);
    TheList->printIteratively();
    TheList->printRecursively();

    // Calls all the 'WordCList' functions to print the list
    TheList = new WordCList;
    TheList->parseIntoList(inf);
    TheList->printIteratively();
    TheList->printRecursively();    
}