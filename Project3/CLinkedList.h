/*******************************************************************/
/*  Author:         Hamad Ahmed                                    */
/*  Major:          Computer Science                               */
/*  Creation Date:  February 28, 2022                              */
/*  Due Date:       March 10, 2022                                 */
/*  Course:         CSC 237                                        */
/*  Professor Name: Dr. Spiegel                                    */
/*  Assignment:     Project #3                                     */
/*  Filename:       CLinkedList.h                                  */
/*  Purpose:        This file contains class definitions and the   */ 
/*                  member implementations of the Circular Linked  */
/*                  List class and Clircular Linked List Iterator  */
/*                  class                                          */
/*******************************************************************/

/*!
*   \file CLinkedList.h
*   \brief This file contains class definitions and the member implementations of the Circular Linked List class and Clircular Linked List Iterator class
*/

/************************************************************************************************************/

#ifndef _CLinkedList_
#define _CLinkedList_
#include <assert.h>
#include <iostream>

using namespace std;

/*************************************************************************************************************/

// Need to prototype template classes if they are to be friends
template <typename eltType> class CLinkedList;
template <typename eltType> class ClistItr;

/*************************************************************************************************************/

/*!
*   \class Node
*   \brief Creates a node for the, CLinkedList and ClistItr, friend classes by creating the data and the next pointer
*/
template <typename eltType> class Node
{   
    private:
        /*!
        *   \fn Node
        *   \brief A constructor that sets the data to info and link to next
        *   \param eltType info
        *   \param Node *link
        *   \return none
        */
		Node(eltType info, Node* link = NULL ) : data(info), next(link) 
		{};
        
        // Create the data variable for the node
		eltType data;
        
        // Creates the next pointer variable for the node
		Node *next;  

    friend class CLinkedList<eltType>;
    friend class ClistItr<eltType>;
};

/********************************************************************************************************/

/*!
*   \class CLinkedList
*   \brief Creates functions to perform insertion and remove operations on the Circular Linked List
*/
template <typename eltType> class CLinkedList
{
	public:
        /*!
        *   \fn CLinkedList
        *   \brief A default contructor that construct an empty Circular Linked List
        *   \return none
        */
		CLinkedList();

        /*!
        *   \fn CLinkedList
        *   \brief Does deep copy of a list
        *   \param CLinkedList& A circular linked list as reference for deep copy
        *   \return none
        */
		CLinkedList(CLinkedList& c1);

        /*!
        *   \fn ~CLinkedList
        *   \brief A default deconstructor that destroys the Circular Linked List
        *   \return none
        */
		~CLinkedList();

        /*!
        *   \fn operator=
        *   \brief Overloads the assignment operator so that it assigns another CLinkedList to this CLinkedList
        *   \param eltType info
        *   \param Node *link
        *   \return none
        */
		CLinkedList& operator=(const CLinkedList& c1);

        /*!
        *   \fn empty
        *   \brief Checks whether the Circular Linked List is empty or not
        *   \return True or False
        */
		bool empty();

        /*!
        *   \fn find
        *   \brief Finds whether the x value in the Circular Linked Linked
        *   \param eltType x
        *   \return True or False
        */
		bool find(eltType x);

		// Ordered insert        
        /*!
        *   \fn orderedInsert
        *   \brief Inserts the x value in an ascending order into the Circular Linked List
        *   \param eltType x
        *   \return none
        */
		void orderedInsert(eltType x);

        // Remove
        /*!
        *   \fn remove
        *   \brief Removes the x value from the Circular Linked List
        *   \param eltType x
        *   \return none
        */
		void remove(eltType x);

	private:
		// linked list pointer
        /*!
           Node pointer for the last node in the circular linked list 
        */
		Node<eltType>* last;

		// Get a copy of a (deep) Node
        /*!
        *   \fn copy
        *   \brief Gets a deep of a Node
        *   \param eltType c1
        *   \return first
        */
		Node<eltType>* copy(Node<eltType> *c1);

		// Free Nodes of a linked list
        /*!
        *   \fn destroy
        *   \brief Frees Nodes of linked list
        *   \param eltType cListp
        *   \return none
        */
		void destroy(Node<eltType> *cListp);

	// Needed to use a list iterator
    friend class ClistItr<eltType>;
};

/******************************************************************************************************/

/*!
*   \fn operator<<
*   \brief displays the value of the node the iterator is pointing at.
*   \param ostream &os
*   \param const CLinkedList<eltType> &l
*   \return os
*/
template <typename eltType> ostream& operator<<(ostream &os, const CLinkedList<eltType> &l);

/******************************************************************************************************/

/*!
*   \class ClistItr
*   \brief Creates iterator and functions to traverse the Circular Linked List
*/
template <typename eltType> class ClistItr
{
    public:
        /*!
        *   \fn ClistItr
        *   \brief Assigns the linked list data member to the parameter
        *   \param CLinkedList& Takes in list for reference for the iterator
        *   \return none
        */
		ClistItr(const CLinkedList<eltType> &l);

        // sets the iterator to the first Node of the linked list
        // or sets 'curr' = 'last->next'
        /*!
        *   \fn begin
        *   \brief iterator starts at the beginning of circular linked list
        *   \return none
        */
		void begin(); 
                                    
		// Returns whether or not the wrapped linked list is empty.
        // or returns whether the last == NULL or not.
        /*!
        *   \fn begin
        *   \brief returns true if the circular linked list is empty
        *   \return if the list is empty, returns true
        */
		bool isEmpty(); 

        // Returns whether the present Node is the first Node Node
        // If the 'curr' == 'last->next'
        /*!
        *   \fn isFirstNode
        *   \brief returns true if iterator is pointing to first element
        *   \return if iterator is at first element, return true
        */
        bool isFirstNode();

        // Returns whether the present Node is the last Node Node
        // If the 'curr' == 'last'
        /*!
        *   \fn isLastNode
        *   \brief returns true if iterator is pointing to last element
        *   \return if iterator is at last element, return true
        */
        bool isLastNode();

        // Returns the data of the Node currently pointed at. 
        /*!
        *   \fn operator*
        *   \brief returns data from node where iterator is pointing at
        *   \return data from the node
        */
        eltType operator*()
        {
            return curr->data;
        }

        // Returns the data of the Node currently pointed at. 
        /*!
        *   \fn operator*
        *   \brief returns data from node where iterator is pointing at
        *   \return data from the node
        */
        eltType operator*() const
        {
            return curr->data;
        }

        // Post-increment operator advances the pointer to the next Node
        // in the list, if there is one 
        /*!
        *   \fn operator++
        *   \brief literator moves to the next, right node using post-incrementation
        *   \return ClistItr
        */
        ClistItr operator++()
        {
            curr = curr->next;
            return *this;
        }

        // Pre-increment operator advances the pointer to the next Node
        // in the list, if there is one 
        /*!
        *   \fn operator++
        *   \brief literator moves to the next, right node using pre-incrementation
        *   \return ClistItr
        */
        ClistItr operator++(int)
        {   
            ClistItr temp = *this;
            //curr = curr->next;
            //temp.curr = curr->next;
            ++(*this);
            return temp;
            //curr++;
        }

	private:

        /*!
            ClistItr iterator
        */
		const CLinkedList<eltType> &itr;

        /*!
            Current node
        */
		Node<eltType> *curr;
};

/*******************************************************************************************************/

/*****************************************************************************/

/* ***********************************************************************
   ************** Circular Linked List Implementations *******************
   **********************************************************************/

/*****************************************************************************/

// Construct empty LinkedList
template <typename eltType> CLinkedList<eltType>::CLinkedList() : last(NULL)
{}

/*******************************************************************************************************/

// Copy constructor. copy() does the deep copy
template <typename eltType> CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl)
{
    last = copy(cl.last);
}

/******************************************************************************************************/

// Free all Nodes
template <typename eltType> CLinkedList<eltType>::~CLinkedList()
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: ~CLinkedList                                           */
    /* Description:   Destroys list                                          */
    /* Parameters:    None                                                   */
    /* Return Value:  none                                                   */
    /*                                                                       */
    /*************************************************************************/
    destroy(last);
}

/*******************************************************************************************************/

// Assignment operator: copy() does the deep copy
template <typename eltType> CLinkedList<eltType> &CLinkedList<eltType>::operator=(const CLinkedList<eltType>& cl)
{	
    /*************************************************************************/
    /*                                                                       */
    /* Function name: operator=                                              */
    /* Description:   Starts deep copy                                       */
    /* Parameters:    cl, list to copy - import/export                       */
    /* Return Value:  none                                                   */
    /*                                                                       */
    /*************************************************************************/
    if (this != &cl)
	{	
        destroy(last);
		last = copy(cl.last);
	}

	return *this;
}

/******************************************************************************************************/

template <typename eltType> void CLinkedList<eltType>::orderedInsert(eltType x)
{	
    /*************************************************************************/
    /*                                                                       */
    /* Function name: orderedInsert                                          */
    /* Description:   Inserts element x in circular linked list in order     */
    /* Parameters:    x, element to insert - import                          */
    /* Return Value:  none                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Checks whether the Circular Linked List is empty or not
    if (empty())
    {
        // If empty, insert a new node that points to itself
        last = new Node<eltType>(x, last);
        last->next = last;
        //cout << "Inserts a new node" << endl;
    }
    // Checks whether there is only one node in the Circular Linked List
    else if (last->next == last)
    {   
        // If so, checks whether the new node should be inserted at the beginning or not
        // If yes, inserts the new node before the first node
        if (last->next->data >= x) // (x < last->next->data || x == last->next->data)
        {
           last->next = new Node<eltType>(x, last->next);
           //cout << "New node is inserted before the first node" << endl;
        }
        // If no, inserts the new node after the first node
        else
        {
           last->next = new Node<eltType>(x, last->next);
           last = last->next;
           //cout << "A node is inserted after the first node" << endl;
        }
    }
    // Checks whether the new node is to be inserted at the beginning
    // If yes, inserts the new node at the beginning
    else if (last->next->data >= x) // x < last->next->data || x == last->next->data
    {
        last->next = new Node<eltType>(x, last->next);
        //cout << "New node has been inserted at the beginning" << endl;
    }
    // Checks whether the new node is to be inserted at the last
    // If yes, inserts the new node at the end
    else if (last->data <= x) // x > last->data || x == last->data
    {
        last->next = new Node<eltType>(x, last->next);
        last = last->next;
        //cout << "New node has been inserted at the end" << endl;
    }
    // Finally, if the new node is to be inserted in between two existing nodes
    // If yes, inserts the new node in between the two nodes
    else
    {
        Node<eltType> *p = last->next;
        Node<eltType> *trailp = last;

        while (p->data <= x) // x > p->data || x == p->data
        {
            trailp = p;
            p = p->next;
        }
        
        trailp->next = new Node<eltType>(x, p);
    }

}

/**************************************************************************************************/

// Remove a Node in an ordered list
// Pre: Node will be found
template <typename eltType> void CLinkedList<eltType>::remove(eltType x)
{	
    /*************************************************************************/
    /*                                                                       */
    /* Function name: remove                                                 */
    /* Description:   Removes element x from circular linked list            */
    /* Parameters:    x, element to remove - import                          */
    /* Return Value:  none                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Creates two node pointers
    Node<eltType> *p = last->next;
    Node<eltType> *trailp = last;

    // Checks whether the list is empty or not
    // If yes, display a message saying that there is no node to delete
    if (empty())
    {
        cout << "This list is empty, there is no node to delete!" << endl; 
        return;
    }
    // If no, finds and deletes the node with the value x
    else
    {   
        // Iterates while x is not the data p is pointing at and p is not the last node
        // If yes, finds the node
        while (!(x == p->data) && !(p == last))
        {
            trailp = p;
            p = p->next;
        }

        // Checks whether the value is in the last node
        if (p == last)
        {
            trailp->next = last->next;
            last = trailp;
        }
        else
        {
            trailp->next = p->next;
        }
    }

    // Delete p in the end
    delete p;
}

/******************************************************************************************************/

// Is this element in the linked list?
template <typename eltType> bool CLinkedList<eltType>::find(eltType x)
{	
    /*************************************************************************/
    /*                                                                       */
    /* Function name: find                                                   */
    /* Description:   Returns true if element x has been found               */
    /* Parameters:    x, what to search for - import                         */
    /* Return Value:  bool                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Declares the 'p' pointer that points to the head
    Node<eltType> *p = last->next;

    // Traverse through the list to point to the 'x' value and returns the bool value
	while (p != NULL && p->data != x)
	    p = p->next;
	return (p != NULL && p->data == x);
}

/*****************************************************************************************************/

// Inline: Look into this.
template <typename eltType> inline bool CLinkedList<eltType>::empty()
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: empty                                                  */
    /* Description:   Returns true if list is empty                          */
    /* Parameters:    None                                                   */
    /* Return Value:  bool                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Returns whether the last node is equal to the NULL
    return (last == NULL);
}

/*****************************************************************************************************/

// Remove all Nodes in the linked list, starting at l
template <typename eltType> void CLinkedList<eltType>::destroy(Node<eltType> *cListp)
{	
    /*************************************************************************/
    /*                                                                       */
    /* Function name: destroy                                                */
    /* Description:   Recursively destoys circular linked list               */
    /* Parameters:    Node<eltType> *cListp - pointer to the node - import   */
    /* Return Value:  none                                                   */
    /*                                                                       */
    /*************************************************************************/

    // Destroys the node that 'cListp' is pointing at
    if (cListp != NULL)
    {
        Node<eltType> *doomed = cListp;
        cListp = cListp->next;
        delete doomed;
        destroy(cListp);
    }
}
/*****************************************************************************************************/

// The deep copy. Copy the source list l, one Node at a time

template <typename eltType> Node<eltType>* CLinkedList<eltType>::copy(Node<eltType> *cListp)
{	
    /*************************************************************************/
    /*                                                                       */
    /* Function name: copy                                                   */
    /* Description:   Deep copy from one list to another                     */
    /* Parameters:    cListp - import                                        */
    /* Return Value:  Node                                                   */
    /*                                                                       */
    /*************************************************************************/
    Node<eltType>* first = NULL;	// ptr to beginning of copied LinkedList
	Node<eltType>* last = NULL;	// ptr to last item insert in the copy

    // Returns a deep copy from one list to another
	if (cListp != NULL)
	{	
        first = last = new Node<eltType>(cListp->data, NULL);

		for (Node<eltType>* source=cListp->next; source!=NULL; source=source->next,last=last->next)
		{	
            last->next = new Node<eltType>(source->data,NULL);
			assert(last->next);
	 	}
     }
	
    return first;
}

/*****************************************************************************************************/

// Output a linked list, using a list iterator
template <typename eltType> ostream& operator<<(ostream &os,const CLinkedList<eltType> &list)
{	
    /******************************************************************************************/
    /*                                                                                        */
    /* Function name: operator<<                                                              */
    /* Description:   A stream insertion operator overloading                                 */
    /* Parameters:    ostreams &os - returns to the os - import/export                        */
    /*                const CLinkedList<eltType> &list - Circular linked list - import/export */
    /* Return Value:  ostream os                                                              */
    /*                                                                                        */
    /******************************************************************************************/
    ClistItr<eltType> itr(list);

    // Outputs the value that 'itr' is pointing at
    os << *itr << " ";

    return os;
}

/*****************************************************************************/

/* ****************************************************************
   ************** List Iterator Implementations *******************
   ****************************************************************/

/*****************************************************************************/

// Construct a list iterator. It consists of:
// a reference to a linked list object
// a pointer to the actual list, initially pointing to its head
template <typename eltType> ClistItr<eltType>::ClistItr(const CLinkedList<eltType> &list): itr(list), curr(list.last->next) 
{}

/*****************************************************************************/

// sets the iterator to the first Node of the linked list
// or sets 'curr' = 'last->next'
template <typename eltType> void ClistItr<eltType>::begin(void)
    /*************************************************************************/
    /*                                                                       */
    /* Function name: begin                                                  */
    /* Description:   Iterator will be set to first node                     */
    /* Parameters:    None                                                   */
    /* Return Value:  none                                                   */
    /*                                                                       */
    /*************************************************************************/
{
    curr = itr.last->next;
}

/*****************************************************************************/
// Returns whether or not the wrapped linked list is empty.
// or returns if the last == NULL or.

template <typename eltType> bool ClistItr<eltType>::isEmpty(void)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: isEmpty                                                */
    /* Description:   Returns true list is empty                             */
    /* Parameters:    None                                                   */
    /* Return Value:  bool                                                   */
    /*                                                                       */
    /*************************************************************************/
    return itr.last == NULL;
}

/*****************************************************************************/
// Returns whether the present Node is the first Node
// If the 'curr' == 'last->next'
template <typename eltType> bool ClistItr<eltType>::isFirstNode(void)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: isFirstNode                                            */
    /* Description:   Returns true if iterator is at first node              */
    /* Parameters:    None                                                   */
    /* Return Value:  bool                                                   */
    /*                                                                       */
    /*************************************************************************/
    return curr == itr.last->next;
}

/*****************************************************************************/

// Returns whether the present Node is the last Node Node
// If the 'curr' == 'last'
template <typename eltType> bool ClistItr<eltType>::isLastNode(void)
{
    /*************************************************************************/
    /*                                                                       */
    /* Function name: isLastNode                                             */
    /* Description:   Returns true if iterator is at last node               */
    /* Parameters:    None                                                   */
    /* Return Value:  bool                                                   */
    /*                                                                       */
    /*************************************************************************/
    return curr == itr.last;
}

#endif
