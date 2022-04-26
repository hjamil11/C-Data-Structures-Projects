/*******************************************************************/
/*  Author:         Hamad Ahmed                                    */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #2                                     */
/*  Filename:       testll.cpp                                     */
/*  Purpose:        This is Test Driver program for the Circular   */
/*                  Linked List. It creates a circular linked list */
/*                  and permits inserting, removing, print forward */
/*                  and backward.                                  */
/*******************************************************************/

/*********************************************************************************/

/*!
*   \file testll.cpp
*   \brief This is Test Driver program for the Circular Linked List. It creates a circular linked list and permits inserting, removing, print forward and backward.
*/
#include <iostream>
#include <string>
#include "CLinkedList.h"
using namespace std;


/*********************************************************************************/


// Function Prototypes
/*!
*   \fn displayMenu
*   \brief Displays the Test Driver Circular Linked List menu options.
*   \return none
*/
void displayMenu();

/*!
*   \fn insertInteger
*   \brief Prompts and inserts an integer, in a ascending order, into the Circular Linked List
*   \param CLinkedList A circular linked list as a reference
*   \return none
*/
void insertInteger(CLinkedList<int> &list);

/*!
*   \fn removeInteger
*   \brief Prompts and removes an integer from the Circular Linked List
*   \param CLinkedList A circular linked list as a reference
*   \return none
*/
void removeInteger(CLinkedList<int> &list);

/*!
*   \fn forwardPrint
*   \brief Prints the Circular Linked List in an ascending order
*   \param CLinkedList A circular linked list as a reference
*   \return none
*/
void forwardPrint(const CLinkedList<int> &list);

/*!
*   \fn backwardPrint
*   \brief Prints the Circular Linked List in a descending order
*   \param ClistItr A circular linked list iterator
*   \return none
*/
void backwardPrint(ClistItr<int> lItr);

/*!
*   \fn reversePrint
*   \brief Points the iterator to print the Circular Linked List in a descending order
*   \param CLinkedList A circular linked list as a reference
*   \return none
*/
void reversePrint(CLinkedList<int> &list);


/*********************************************************************************/


/*!
*   \fn main
*   \brief Displays the Test Driver Linked List programs menu options, and calls the functions in an appropriate order
*   \return none
*/
int main()
{
    // Creates a circular singly linked list
    CLinkedList<int> l1;
    
    // Creates the choice variable for the user chosen menu option
    char choice;
    
    do
    {   
        // Displays the menu out to the user
        displayMenu();

        // Stores the user input into choice
        cin >> choice;
        
        // Checks the user's choice and invokes the proper function
        switch (tolower(choice))
        {
            case 'i':
                // Invokes the insertInteger function
                insertInteger(l1);
                break;
            case 'r':
                // Invokes removeInteger function
                removeInteger(l1);
                break;
            case 'f':
                // Invokes the forwardPrint function
                forwardPrint(l1);
                break;
            case 'b':
                // Invokes the reversePrint function
                reversePrint(l1);
                break;
            default:
                // Otherwise, display a message out to the user.
                cout << "Thank you for trying this program!" << endl;
                break;
        }
    }
    // Keeps iterating the while until the user enters the 'e' to exit the program
    while (tolower(choice) != 'e');

    return 0;
}

/*********************************************************************************/

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

    // Displays the menu options
    cout << "LinkedList Test Driver" << endl;
    cout << "I)nsert Integer" << endl;
    cout << "R)emove Integer" << endl;
    cout << "F)orward Print" << endl;
    cout << "B)ackwardPrint" << endl;
    cout << "E)xit" << endl;
}

/*********************************************************************************/

void insertInteger(CLinkedList<int> &list)
{
    /*******************************************************************************/
    /*                                                                             */
    /* Function name: insertInteger                                                */
    /* Description:   Prompts and inserts an integer, in a ascending order,        */
    /*                into the Circular Linked List                                */
    /* Parameters:    CLinkedList<int> &list: Circular Linked List - import/export */
    /* Return Value:  None                                                         */
    /*                                                                             */
    /*******************************************************************************/

    int x;

    // Prompts the user for an integer.
    cout << "Enter an integer: " << endl;
    cin >> x;

    // Calls the orderedInsert function to insert the 'x' integer.
    list.orderedInsert(x); 
}

/*********************************************************************************/

void removeInteger(CLinkedList<int> &list)
{
    /*******************************************************************************/
    /*                                                                             */
    /* Function name: removeInteger                                                */
    /* Description:   Prompts and removes an integer from the Circular Linked List */
    /* Parameters:    CLinkedList<int> &list: Circular Linked List - import/export */
    /* Return Value:  None                                                         */
    /*                                                                             */
    /*******************************************************************************/

    int x;

    // Prompts the user for an integer.
    cout << "Enter an integer: " << endl;
    cin >> x;

    // Calls the orderedInsert function to insert the 'x' integer.
    list.remove(x); 
}

/*********************************************************************************/

void forwardPrint(const CLinkedList<int> &list)
{
    /*************************************************************************************/
    /*                                                                                   */
    /* Function name: forwardPrint                                                       */
    /* Description:   Prints the Circular Linked List in an ascending order              */
    /* Parameters:    const CLinkedList<int> &list: Circular Linked List - import/export */
    /* Return Value:  None                                                               */
    /*                                                                                   */
    /*************************************************************************************/

    // Prints the printing method used to print the list
    cout << "Prints the list forward:" << endl;

    // Creates an iterator to traverse the 'list' Circular Linked List
    ClistItr<int> lItr(list);


    // Prints the list as long as the list is not empty
    if (!lItr.isEmpty())
    {   
        // Uses the for loop to print the list in an ascending order
        for (lItr.begin(); !lItr.isLastNode(); ++lItr)
            cout << *lItr << endl;
        
        cout << *lItr << endl;
    }
    // Display a message if the list is empty.
    else
    {
        cout << "The list contains no nodes to print at the moment" << endl;
    }
}

/*********************************************************************************/

void backwardPrint(ClistItr<int> lItr)
{
    /*************************************************************************************/
    /*                                                                                   */
    /* Function name: forwardPrint                                                       */
    /* Description:   PPrints the Circular Linked List in a descending order             */
    /* Parameters:    ClistItr<int> &lItr: Circular Linked List Iterator - import        */
    /* Return Value:  None                                                               */
    /*                                                                                   */
    /*************************************************************************************/

    // Checks if the iterator does not point to the last node of the list
    if (!lItr.isLastNode()) {
        // Increments the iterator position
        lItr++;

        // Calls the backwardPrint function
        backwardPrint(lItr);    
    } 
    // If the iterator is not point at the last node. Then,
    else 
    {   
        // Return nothing
        return;
    }

    // Prints the data that the iterator is pointing at. 
    cout << *lItr << endl;
}

/*********************************************************************************/

 void reversePrint(CLinkedList<int> &list)
 {
    /*************************************************************************************/
    /*                                                                                   */
    /* Function name: reversePrint                                                       */
    /* Description:   Points the iterator to print the Circular Linked List in a         */
    /*                descending order                                                   */
    /* Parameters:    CLinkedList<int> &list: Circular Linked List - import/export       */
    /* Return Value:  None                                                               */
    /*                                                                                   */
    /*************************************************************************************/
    
    // Displays the printing method being used to print the linked list
    cout << "Prints the list backwards:" << endl;

    // Declares an iterator of the Linked List
    ClistItr<int> lItr(list);

    // Points the iterator to the beginning of the linked list
    lItr.begin();
    
    // Calls the backwardPrint function
    backwardPrint(lItr);
    
    // Set the iterator position to the beginning of the list
    lItr.begin();

    // Prints the first node in the end
    cout << *lItr << endl;
 }