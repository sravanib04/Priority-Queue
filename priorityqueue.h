/**------------------------------------------
    Project 5: Priority Queue
    An abstraction class that is similar to the structure
    used in a patient queue at a hospital
    Course: CS 251, Spring 2023.
    System: Windows 11 & C++
    Author: Sravani Bhamidipaty
 ---------------------------------------------**/

/// @file priorityqueue.h
///
///
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

#pragma once // used to not include header files multiple times

#include <iostream> // including to use functions like cout and cin statements
#include <sstream> // reads in string objects
#include <set> // including to use sets

using namespace std; // used to not type std::multiple times throughout the program

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE *parent;  // links back to parent
        NODE *link;  // links to linked list of NODES with duplicate priorities
        NODE *left;  // links to left child
        NODE *right;  // links to right child
    };
    NODE *root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE *curr;  // pointer to next item in pqueue (see begin and next)

    //
    // Double Equal Operator (Operator==) Conditions:
    //
    // A helper function for operator== function, which checks if two binary trees are equal
    // O(N)
    //
    bool doubleEqualOperatorConditions(NODE *value1, NODE *value2) const {
        // if both the trees are empty, return true
        if (value1 == nullptr && value2 == nullptr) {
            return true;
        }
        // if one of the tree is empty, and the other is not they are not the same, so return false
        else if (value1 == nullptr && value2 != nullptr) {
            return false;
        }
        // if both the trees do not have the same values, then they are not the same, so return false
        else if (value1->value != value2->value) {
            return false;
        }
        // if both the trees do not link to the same values, then they are not the same, so return false
        else if (doubleEqualOperatorConditions(value1->link, value2->link) == false) {
            return false;
        }
        // if both the trees do not have the same left child/children, then they are not the same, so return false
        else if (doubleEqualOperatorConditions(value1->left, value2->left) == false) {
            return false;
        }
        // if both the trees do not have the same right child/children, then they are not the same, so return false
        else if (doubleEqualOperatorConditions(value1->right, value2->right) == false) {
            return false;
        }
        // if nothing in the above conditions is returned, that means that both the trees are identical, so return true
        else {
            return true;
        }
    }

    //
    // Pre-order Traversal:
    //
    // A helper function for operator= function, which traverses through the binary tree in pre-order
    // Sets the nodes' values and priorities by using the enqueue function in the order of pre-order traversal
    // O(N)
    //
    void preOrderTraversal(NODE *root) {
        // if root is empty, we do not do anything, so empty return;
        if (root == nullptr) {
            return;
        }
        NODE *temp = root; // creating a temporary node
        // calling enqueue function to enqueue the value and the priority of contained in the temp node
        enqueue(temp->value, temp->priority);
        // if temp node does not have a link, we traverse through the left subtree and then the right subtree
        if (temp->link == nullptr) {
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
        // if temp node has a link, then we traverse through the linked list
        else if (temp->link != nullptr) {
            while (temp->link) {
                temp = temp->link;
                // calling enqueue function to enqueue the value and the priority of contained
                enqueue(temp->value, temp->priority);
            }
            // if current node does not have a link (leaf node), we traverse through the left subtree and then the right subtree
            if (temp->link == nullptr) {
                preOrderTraversal(root->left);
                preOrderTraversal(root->right);
            }
        }
    }

    //
    // String Parser:
    //
    // A helper function for toString function, which takes a reference to lines
    // Outputs the data: the priority and the value of the current node it is traversing
    // O(N)
    //
    void stringParser(NODE *root, stringstream &lines) {
        // if root is empty, we do not do anything, so empty return;
        if (root == nullptr) {
            return;
        }
        stringParser(root->left, lines); // calling itself for the left part of the tree
        // if the root is not empty, traverse through the tree
        if (root != nullptr) {
            NODE *temp = root; // creating a temporary node
            // while temp is not null, we output the priority and the value of each node
            while (temp != nullptr) {
                lines << temp->priority << " value: " << temp->value << endl;
                temp = temp->link; // updating the temporary node
            }
        }
        stringParser(root->right, lines); // calling itself for the right part of the tree
    }

    //
    // Post-order Traversal:
    //
    // A helper function for clear function, which traverses through the binary tree in post-order
    // Deletes each node in the binary tree
    // O(N)
    //
    void postOrderTraversal(NODE *root) {
        // if root is empty, we do not do anything, so empty return;
        if (root == nullptr) {
            return;
        }
        postOrderTraversal(root->left); // traverse through the left subtree
        postOrderTraversal(root->right); // traverse through the right subtree
        postOrderTraversal(root->link); // traverse through the linked list
        delete root; // after traversing, delete the node
    }

public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {
        root = nullptr; // there is nothing in the tree
        size = 0; // the size of the tree is 0
        curr = root; // the current node is the root of the tree
    }

    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue &operator=(const priorityqueue &other) {
        clear(); // clearing the "this" tree
        preOrderTraversal(other.root); // traverse through the other tree and enqueue each node into this tree
        return *this; // return the this tree which contains data from the other tree
    }

    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() {
        postOrderTraversal(root); // deleting all nodes in the existing tree
        root = nullptr; // setting root to be empty
        size = 0; // setting size to be 0
    }

    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {
        clear(); // calling the clear function to avoid memory errors and leaks
    }

    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number
    // of duplicate priorities
    //
    void enqueue(T value, int priority) {
        NODE *pCurr = root; // setting pCurr node to root
        NODE *prevNode = nullptr; // setting prevNode to nullptr
        bool duplicatePriorities = false; // setting duplicatePriorities to false
        //while pCurr is not empty, we traverse through the tree
        while (pCurr != nullptr) {
            // if a certain priority exist then that is a duplicatePriority, so we are updating duplicatePriority variables
            if (pCurr->priority == priority) {
                duplicatePriorities = true;
                pCurr->dup = true;
                break;
            }
            // traversing left if the current priority is greater than the initial priority
            else if (pCurr->priority > priority) {
                prevNode = pCurr;
                pCurr = pCurr->left;
            }
            // traversing right if the current priority is less than the initial priority
            else if (pCurr->priority < priority) {
                prevNode = pCurr;
                pCurr = pCurr->right;
            }
        }
        NODE *newNode = new NODE(); // creating a new node
        newNode->parent = prevNode; // the parent of the new node is the prevNode
        newNode->value = value; // the value of the new node is the existing value that is stored
        newNode->priority = priority; // the priority of the new node is the existing priority that is stored
        // if there are duplicate priorities, then we add the new node to the end of the list
        if (duplicatePriorities == true) {
            // traversing through the linked list
            while (pCurr->link != nullptr) {
                prevNode = pCurr;
                pCurr = pCurr->link;
            }
            // adding the new node at the end of the list
            if (pCurr->link == nullptr) {
                newNode->parent = pCurr;
                pCurr->link = newNode;
            }
        }
        // if there isn't a duplicate priority, traverse through the tree and add it where it belongs
        else {
            // if there is no previous node, the root node is the new node
            if (prevNode == nullptr) {
                root = newNode;
            }
            // if the priority of the previous node is greater than the priority, then add new node to the left of previous node
            else if (prevNode->priority > priority) {
                prevNode->left = newNode;
            }
            // if the priority of the previous node is less than the priority, then add new node to the right of previous node
            else if (prevNode->priority < priority) {
                prevNode->right = newNode;
            }
        }
        size++; // Because we are adding a new node, we are incrementing the size of the binary tree by one
    }

    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number
    // of duplicate priorities
    //
    T dequeue() {
        T valueOut; // a T variable named valueOut
        NODE *pCurr = root; // setting pCurr node to root
        NODE *prevNode = nullptr; // setting prevNode to nullptr
        // if the queue is empty, we return the default T();
        if (pCurr == nullptr) {
            cout << "empty" << endl;
            return T();
        }
        // if the root is not null, we traverse through the left side of the root
        else if(pCurr != nullptr) {
            while (pCurr->left != nullptr) {
                prevNode = pCurr;
                pCurr = pCurr->left; // leftmost node
            }
            if (pCurr->dup == false && pCurr == root) {
                root = pCurr->right; // root node is the right child of pCurr
                pCurr->parent = nullptr; // pCurr's parent is null
                valueOut = pCurr->value; // value is the value of pCurr, the node with the lowest priority
                delete pCurr; // deleting the lowest priority node that is found through traversing
            }
            // if the lowest priority node has a duplicate, valueOut is pCurr's value
            else if (pCurr->dup == true) {
                valueOut = pCurr->value;
                pCurr->link->right = pCurr->right;
                // if the link of the previous node is not null pointer, then there is a duplicate of that node
                if (pCurr->link->link != nullptr) {
                    pCurr->link->dup = true;
                }
                    // if the link of the previous node is a null pointer, then there isn't a duplicate of that node
                else if (pCurr->link->link == nullptr){
                    pCurr->link->dup = false;
                }
                pCurr->link->parent = prevNode;
                // if pCurr is the root node, root node would be pCurr->link
                if (pCurr == root) {
                    root = pCurr->link;
                }
                // if pCurr is not the root node, the left child of prevNode would be pCurr-link
                else if (pCurr != root){
                    prevNode->left = pCurr->link;
                }
                delete pCurr; // deleting the lowest priority node that is found through traversing
            }
            // if pCurr has a right child, we update the parent, left child, and valueOut
            else if (pCurr->right != nullptr) {
                pCurr->right->parent = prevNode; // prevNode would the parent of the right child of pCurr
                prevNode->left = pCurr->right; // The prevNode's left child would be pCurr's right child
                valueOut = pCurr->value; // updating valueOut with pCurr's value
                delete pCurr; // deleting the lowest priority node that is found through traversing
            }
            // if pCurr has no right node, then we update the left node and valueOut
            else if (pCurr->right == nullptr){
                prevNode->left = nullptr; // the left child of prevNode is set to null
                valueOut = pCurr->value; // updating valueOut with pCurr's value
                delete pCurr; // deleting the lowest priority node that is found through traversing
            }
            size--; // Because we are deleting a new node, we are decrementing the size of the binary tree by one
            return valueOut;
        }
    }


    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        return size; // returning the number of elements in the priority queue
    }

    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
        curr = root; // setting the current node to root
        // while curr has a left child, we traverse through the tree
        while (curr->left != nullptr) {
            curr = curr->left; // we update curr to the left child each time
        }
    }

    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T &value, int &priority) {
        // if the tree is empty, we return false
        if (curr == nullptr) {
            return false;
        }
        value = curr->value; // setting value to the curr's value
        priority = curr->priority; // setting value to the curr's value
        // if curr has duplicates, curr is now updated to curr's link node, and we return true
        if (curr->link != nullptr) {
            curr = curr->link;
            return true;
        }
        // if curr does not have duplicates, there are additional cases to consider
        else {
            while (curr->parent != nullptr && curr->priority == curr->parent->priority) {
                curr = curr->parent; // curr is now updated to it's parent
            }
            // if there is a right node, curr is updated to curr's right node
            if (curr->right != nullptr) {
                curr = curr->right;
                while (curr->left != nullptr) {
                    curr = curr->left; // curr is the leftmost node in the right subtree
                }
                return true;
            }
                // if there is no right node, we traverse up the tree
            else {
                while (curr->parent != nullptr && curr->parent->priority < curr->priority) {
                    curr = curr->parent; // curr is updated to curr's parent
                    if (curr->parent == nullptr) {
                        curr = nullptr;
                        return false;
                    }
                }
                // if curr is not the root node, we update curr to it's parent
                if (curr->parent != nullptr) {
                    curr = curr->parent;
                    return true;
                }
            }
            return true;
        }
    }

    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {
        stringstream lines; // creating a string stream object called lines
        stringParser(root, lines);
        return lines.str(); // returns the string stream object, lines as a string
    }

    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number
    // of duplicate priorities
    //
    T peek() {
        T valueOut; // a T variable named valueOut
        NODE *pCurr = root; // setting pCurr node to root
        while (pCurr->left != nullptr) {
            pCurr = pCurr->left; // updating pCurr to the left child
        }
        valueOut = pCurr->value; // updating valueOut with pCurr's value
        return valueOut;
    }

    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue &other) const {
        // checking if the sizes of both the root and the other trees are the same. If not return, false
        if (size != other.size) {
            return false;
        }
        // checking if both the root and other.root are both null pointers. If yes, return true
        if (root == nullptr && other.root == nullptr) {
            return true;
        }
        // checking if root is null pointer and other.root is not null pointer. If this is true, return false
        else if (root == nullptr && other.root != nullptr) {
            return false;
        }
        // checking if the value of root is not the same as the value of other.root. If yes, return false
        else if (root->value != other.root->value) {
            return false;
        }
        bool returnStatement = doubleEqualOperatorConditions(root, other.root); // a recursive function that checks above conditions as we traverse through the trees
        return returnStatement;
    }

    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void *getRoot() {
        return root;
    }
};