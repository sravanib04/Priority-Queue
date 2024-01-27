/**------------------------------------------
    Project 5: Priority Queue
    An abstraction class that is similar to the structure
    used in a patient queue at a hospital
    Course: CS 251, Spring 2023.
    System: Windows 11 & C++
    Author: Sravani Bhamidipaty and Srijita Banerjee
 ---------------------------------------------**/

/// @file tests.cpp
/// @date March 17, 2023

///
/// --------------------------------------------------------------------------------------------------------------------
/// -CS 251 PROGRAM 5-
///
/// This C++ file contains test cases (made in Catch 1.0 framework) to verify the correct implementation
/// of the class priorityqueue.h


/// Name: Sravani Bhamidipaty (sbham3@uic.edu)
/// UIN: 651960603

/// Collaborated with: Srijita Banerjee (sbane4@uic.edu)
/// UIN: 675443340
/// -------------------------------------------------------------------------------------------------------------------

/// Provided testing file to implement framework based tests in. The examples
/// below demonstrates a basic empty test in each framework with a single
/// assertion. The version uses the supplied catch.hpp file in starter code.
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

// Testing in CATCH Framework
// ---------------------------------------------------------------------------------------------------------------------

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "priorityqueue.h"
#include <iostream> // for input/output

using namespace std;

// dummy test
TEST_CASE("no tests")
{
    REQUIRE(true);
}

/// for int data type

// testing default constructor
TEST_CASE ("Testing default constructor - integer values in BST") {
    priorityqueue <int> obj;
    REQUIRE(obj.Size() == 0);

}

// testing default constructor - long long data type
TEST_CASE ("Testing default constructor - long long data type"){
    priorityqueue <long long> pq;
    REQUIRE (pq.Size() == 0);
}

// testing default constructor - short data type
TEST_CASE ("Testing default constructor - short data type"){
    priorityqueue <short> pq;
    REQUIRE (pq.Size() == 0);
}

// testing default constructor - string data type
TEST_CASE ("Testing default constructor - string data type"){
    priorityqueue <string> pq;
    REQUIRE (pq.Size() == 0);
}

// testing default constructor - char data type
TEST_CASE ("Testing default constructor - char data type"){
    priorityqueue <char> pq;
    REQUIRE (pq.Size() == 0);
}

// testing default enqueue - int data type
TEST_CASE ("default enqueue - int") {
    priorityqueue <int> pq;
    REQUIRE (pq.getRoot() == nullptr);
    REQUIRE(pq.Size() == 0);
}

// testing enqueue function in an empty BST - int data type
TEST_CASE("enqueuing in an empty BST - int") {
    priorityqueue <int> pq;
    pq.enqueue(29,5);
    REQUIRE (pq.Size() == 1);
}

// testing enqueue function - left traversal only - int data type
TEST_CASE("left enquiuing - int") {
    priorityqueue <int> pq;
    pq.enqueue (29,5);
    pq.enqueue(64,3);
    pq.enqueue(2,2);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - right traversal only - int data type
TEST_CASE ("right enquiuing - int") {
    priorityqueue <int> pq;
    pq.enqueue (29,1);
    pq.enqueue(54,3);
    pq.enqueue(45,7);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - duplicate priorities only - int data type
TEST_CASE ("enquiuing with duplicate priorities - int") {
    priorityqueue <int> pq;
    pq.enqueue (29,1);
    pq.enqueue (54,1);
    pq.enqueue (29,1);
    REQUIRE (pq.Size() == 3);
}

TEST_CASE ("overall enquiuing - int data type") {
    priorityqueue <int> pq;
    pq.enqueue (29,1);
    pq.enqueue (54,1);
    pq.enqueue (29,1);
    pq.enqueue (29,5);
    pq.enqueue (57,6);
    REQUIRE (pq.Size() == 5);
}

// testing dequeue with duplicates - int
TEST_CASE("testing dequeue function - int") {
    priorityqueue <int> pq;
    pq.enqueue (12,4);
    pq.enqueue(69,2);
    pq.enqueue(420,2);
    pq.enqueue(32,3);

    int ans = pq.dequeue();

    REQUIRE (ans == 69);
    REQUIRE (pq.Size() == 3);

}

// testing dequeue with duplicates at root - int
TEST_CASE("testing dequeue function duplicate roots- int") {
    priorityqueue <int> pq;
    pq.enqueue (12,4);
    pq.enqueue(69,4);
    pq.enqueue(420,2);
    pq.enqueue(32,3);

    int ans = pq.dequeue();

    REQUIRE (ans == 420);
    REQUIRE (pq.Size() == 3);

}

// testing dequeue with root being leftmost node - int
TEST_CASE("testing dequeue function leftmost node - int") {
    priorityqueue <int> pq;
    pq.enqueue (12,5);
    pq.enqueue(69,6);
    pq.enqueue(420,7);
    pq.enqueue(32,8);

    int ans = pq.dequeue();

    REQUIRE (ans == 12);
    REQUIRE (pq.Size() == 3);

}

// testing destructor - int data type
TEST_CASE ("testing destructor - int") {
    priorityqueue <int> pq1;
    // const priorityqueue <int> *address = &pq1;
    pq1.enqueue (1,1);
    pq1.enqueue (2,2);
    pq1.enqueue (4,4);
    pq1.enqueue (5,5);
    pq1.clear();
    REQUIRE (pq1.Size() == 0);
    REQUIRE(pq1.getRoot() == nullptr);
}

// testing clear function - int data type
TEST_CASE("clear function - int") {
    priorityqueue <int> pq;
    pq.clear();
    REQUIRE (pq.Size() == 0);
    REQUIRE(pq.getRoot() == nullptr);
}

// testing operator== function for a normal BST
TEST_CASE (" operator== (i) - int") {
    priorityqueue <int> pq1;
    priorityqueue <int> pq2;
    pq1.enqueue(1,1);
    pq1.enqueue(2,2);
    pq2.enqueue(3,3);
    pq2.enqueue(4,4);
    REQUIRE(pq1.Size()== 2);
    REQUIRE(pq2.Size() == 2);
    REQUIRE(false == (pq1 == pq2));
}

// testing operator== function for 2 empty BSTs
TEST_CASE ("operator== (ii) - int") {
    priorityqueue <int> pq1;
    priorityqueue <int> pq2;
    REQUIRE(pq1.Size() == 0);
    REQUIRE(pq2.Size() == 0);
    REQUIRE(true == (pq1 == pq2));
}

/*
// operator= function - int data type
TEST_CASE ("(20) testing operator= function - int") {
    priorityqueue <int> pq1;
    pq1.enqueue (1,1);
    pq1.enqueue (2,2);
    pq1.enqueue (4,4);
    pq1.enqueue(5,5);

    priorityqueue <int> pq2;
    pq2.enqueue (2,1);
    pq2.enqueue (3,2);
    pq2.enqueue (4,4);
    pq2.enqueue (5,5);

    REQUIRE (pq1.Size() == pq2.Size());
    REQUIRE (pq1 == pq2);

}
*/


// testing toString function with values of int data type
TEST_CASE("testing toString - int "){
    priorityqueue<int> pq1;
    REQUIRE(pq1.Size() == 0);
    pq1.enqueue(1,1);
    REQUIRE(pq1.Size() == 1);
    REQUIRE(pq1.toString() == "1 value: 1\n");
}

/// for double data type

// testing default constructor - double data type
TEST_CASE ("Testing default constructor - double data type"){
    priorityqueue <double> pq;
    REQUIRE (pq.Size() == 0);
}

TEST_CASE("enqueuing in an empty BST - double") {
    priorityqueue <double> pq;
    pq.enqueue(29.896,5);
    REQUIRE (pq.Size() == 1);
}

TEST_CASE("left enquiuing - double") {
    priorityqueue <double> pq;
    pq.enqueue (29.678,5);
    pq.enqueue(64.345,3);
    pq.enqueue(2.002,2);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - right traversal only - int data type
TEST_CASE ("right enquiuing - double") {
    priorityqueue <double> pq;
    pq.enqueue (29.67,1);
    pq.enqueue(54.90,3);
    pq.enqueue(45.002,7);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - duplicate priorities only - int data type
TEST_CASE ("enquiuing with duplicate priorities - double") {
    priorityqueue <double> pq;
    pq.enqueue (29.8679,1);
    pq.enqueue (54.456,1);
    pq.enqueue (29.09,1);
    REQUIRE (pq.Size() == 3);
}

TEST_CASE ("overall enquiuing - double data type") {
    priorityqueue <double> pq;
    pq.enqueue (29.874,1);
    pq.enqueue (54.90002,1);
    pq.enqueue (29.78,1);
    pq.enqueue (29.34,5);
    pq.enqueue (57.01,6);
    REQUIRE (pq.Size() == 5);
}

// testing dequeue with duplicates - double
TEST_CASE("testing dequeue function - double") {
    priorityqueue <double> pq;
    pq.enqueue (12.89,4);
    pq.enqueue(69.02,2);
    pq.enqueue(420.01,2);
    pq.enqueue(32.009,3);

    double ans = pq.dequeue();

    REQUIRE (ans == 69.02);
    REQUIRE (pq.Size() == 3);
}

// testing dequeue with duplicates at root - double
TEST_CASE("testing dequeue function root duplicates - double") {
    priorityqueue <double> pq;
    pq.enqueue (12.89,4);
    pq.enqueue(69.02,4);
    pq.enqueue(420.01,2);
    pq.enqueue(32.009,3);

    double ans = pq.dequeue();

    REQUIRE (ans == 420.01);
    REQUIRE (pq.Size() == 3);
}

// testing dequeue with root being leftmost node - double
TEST_CASE("testing dequeue function leftmost node - double") {
    priorityqueue <double> pq;
    pq.enqueue (12.89,5);
    pq.enqueue(69.007,6);
    pq.enqueue(420.67,7);
    pq.enqueue(32.02,8);

    double ans = pq.dequeue();

    REQUIRE (ans == 12.89);
    REQUIRE (pq.Size() == 3);
}

TEST_CASE ("testing destructor - double") {
    priorityqueue <double> pq1;
    // const priorityqueue <int> *address = &pq1;
    pq1.enqueue (1.9,1);
    pq1.enqueue (2.1,2);
    pq1.enqueue (4.5,4);
    pq1.enqueue (5.6,5);
    pq1.clear();
    REQUIRE (pq1.Size() == 0);
    REQUIRE(pq1.getRoot() == nullptr);
}

// testing clear function - double data type
TEST_CASE("clear function - double") {
    priorityqueue <double> pq;
    pq.clear();
    REQUIRE (pq.Size() == 0);
    REQUIRE(pq.getRoot() == nullptr);
}

// testing default enqueue - double data type
TEST_CASE ("default enqueue - double") {
    priorityqueue <double> pq;
    REQUIRE (pq.getRoot() == nullptr);
    REQUIRE(pq.Size() == 0);
}

// testing operator== function for a normal BST
TEST_CASE ("operator== (i) - double") {
    priorityqueue <double> pq1;
    priorityqueue <double> pq2;
    pq1.enqueue(1.2,1);
    pq1.enqueue(2.2,2);
    pq2.enqueue(3.4,3);
    pq2.enqueue(4.9,4);
    REQUIRE(pq1.Size()== 2);
    REQUIRE(pq2.Size() == 2);
    REQUIRE(false == (pq1 == pq2));
}

// testing operator== function for 2 empty BSTs
TEST_CASE ("operator== (ii) - double") {
    priorityqueue <double> pq1;
    priorityqueue <double> pq2;
    REQUIRE(pq1.Size() == 0);
    REQUIRE(pq2.Size() == 0);
    REQUIRE(true == (pq1 == pq2));
}

// testing toString function with values of double data type
TEST_CASE("testing toString - double "){
    priorityqueue<double> pq1;
    REQUIRE(pq1.Size() == 0);
    pq1.enqueue(1.2,1);
    REQUIRE(pq1.Size() == 1);
    REQUIRE(pq1.toString() == "1 value: 1.2\n");
}

// for float data type

// testing default constructor - float data type
TEST_CASE ("Testing default constructor - float data type"){
    priorityqueue <float> pq;
    REQUIRE (pq.Size() == 0);
}

// testing enqueue function in an empty BST - float data type
TEST_CASE("enqueuing in an empty BST - float") {
    priorityqueue <float> pq;
    pq.enqueue(29.5,5);
    REQUIRE (pq.Size() == 1);
}

// testing enqueue function - left traversal only - float data type
TEST_CASE("left enquiuing - float") {
    priorityqueue <float> pq;
    pq.enqueue (29.7,5);
    pq.enqueue(64.09,3);
    pq.enqueue(2.21,2);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - right traversal only - float data type
TEST_CASE ("right enquiuing - float") {
    priorityqueue <float> pq;
    pq.enqueue (29.7,1);
    pq.enqueue(54.03,3);
    pq.enqueue(45.01,7);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - duplicate priorities only - float data type
TEST_CASE ("enquiuing with duplicate priorities - float") {
    priorityqueue <float> pq;
    pq.enqueue (29.7,1);
    pq.enqueue (54.19,1);
    pq.enqueue (29.65,1);
    REQUIRE (pq.Size() == 3);
}

TEST_CASE ("overall enquiuing - float data type") {
    priorityqueue <float> pq;
    pq.enqueue (29.7,1);
    pq.enqueue (54.01,1);
    pq.enqueue (29.34,1);
    pq.enqueue (29.12,5);
    pq.enqueue (57.09,6);
    REQUIRE (pq.Size() == 5);
}

// testing dequeue with duplicates - float
TEST_CASE("testing dequeue function - float") {
    priorityqueue <float> pq;
    pq.enqueue (12.8,4);
    pq.enqueue(69.1,2);
    pq.enqueue(420.69,2);
    pq.enqueue(32.3,3);

    int ans = pq.dequeue();

    REQUIRE (ans == 69);
    REQUIRE (pq.Size() == 3);

}

// testing dequeue with duplicates at root - float
TEST_CASE("testing dequeue function duplicate roots- float") {
    priorityqueue <float> pq;
    pq.enqueue (12.8,4);
    pq.enqueue(69.01,4);
    pq.enqueue(420.69,2);
    pq.enqueue(32.31,3);

    int ans = pq.dequeue();

    REQUIRE (ans == 420);
    REQUIRE (pq.Size() == 3);

}

// testing dequeue with root being leftmost node - float
TEST_CASE("testing dequeue function leftmost node - float") {
    priorityqueue <float> pq;
    pq.enqueue (12.8,5);
    pq.enqueue(69.01,6);
    pq.enqueue(420.69,7);
    pq.enqueue(32.31,8);

    int ans = pq.dequeue();

    REQUIRE (ans == 12);
    REQUIRE (pq.Size() == 3);
}

// testing default enqueue - int data type
TEST_CASE ("default enqueue - float") {
    priorityqueue <float> pq;
    REQUIRE (pq.getRoot() == nullptr);
    REQUIRE(pq.Size() == 0);
}

// testing destructor - int data type
TEST_CASE ("testing destructor - float") {
    priorityqueue <float> pq1;
    // const priorityqueue <int> *address = &pq1;
    pq1.enqueue (1.3,1);
    pq1.enqueue (2.9,2);
    pq1.enqueue (4.2,4);
    pq1.enqueue (5.09,5);
    pq1.clear();
    REQUIRE (pq1.Size() == 0);
    REQUIRE(pq1.getRoot() == nullptr);
}

// testing clear function - float data type
TEST_CASE("clear function - float") {
    priorityqueue <float> pq;
    pq.clear();
    REQUIRE (pq.Size() == 0);
    REQUIRE(pq.getRoot() == nullptr);
}

// testing operator== function for a normal BST
TEST_CASE ("operator== (i) - float") {
    priorityqueue <float> pq1;
    priorityqueue <float> pq2;
    pq1.enqueue(1.5,1);
    pq1.enqueue(2.3,2);
    pq2.enqueue(3.0,3);
    pq2.enqueue(4.2,4);
    REQUIRE(pq1.Size()== 2);
    REQUIRE(pq2.Size() == 2);
    REQUIRE(false == (pq1 == pq2));
}

// testing operator== function for 2 empty BSTs
TEST_CASE ("operator== (ii) - float") {
    priorityqueue <int> pq1;
    priorityqueue <int> pq2;
    REQUIRE(pq1.Size() == 0);
    REQUIRE(pq2.Size() == 0);
    REQUIRE(true == (pq1 == pq2));
}

// testing toString function with values of float data type
TEST_CASE("testing toString - float "){
    priorityqueue<float> pq1;
    REQUIRE(pq1.Size() == 0);
    pq1.enqueue(1.2,1);
    REQUIRE(pq1.Size() == 1);
    REQUIRE(pq1.toString() == "1 value: 1.2\n");
}

// long data type

// testing default constructor - long data type
TEST_CASE ("Testing default constructor - long data type"){
    priorityqueue <long> pq;
    REQUIRE (pq.Size() == 0);
}

// testing enqueue function in an empty BST - long data type
TEST_CASE("enqueuing in an empty BST - long") {
    priorityqueue <long> pq;
    pq.enqueue(29,5);
    REQUIRE (pq.Size() == 1);
}

// testing enqueue function - left traversal only - long data type
TEST_CASE("left enquiuing - long") {
    priorityqueue <long> pq;
    pq.enqueue (29,5);
    pq.enqueue(64,3);
    pq.enqueue(2,2);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - right traversal only - long data type
TEST_CASE ("right enquiuing - long") {
    priorityqueue <long> pq;
    pq.enqueue (29,1);
    pq.enqueue(54,3);
    pq.enqueue(45,7);
    REQUIRE (pq.Size () == 3);
}

// testing enqueue function - duplicate priorities only - long data type
TEST_CASE ("enquiuing with duplicate priorities - long") {
    priorityqueue <long> pq;
    pq.enqueue (29,1);
    pq.enqueue (54,1);
    pq.enqueue (29,1);
    REQUIRE (pq.Size() == 3);
}

TEST_CASE ("overall enquiuing - long data type") {
    priorityqueue <long> pq;
    pq.enqueue (29,1);
    pq.enqueue (54,1);
    pq.enqueue (29,1);
    pq.enqueue (29,5);
    pq.enqueue (57,6);
    REQUIRE (pq.Size() == 5);
}

// testing dequeue with duplicates - long
TEST_CASE("testing dequeue function - long") {
    priorityqueue <long> pq;
    pq.enqueue (12,4);
    pq.enqueue(69,2);
    pq.enqueue(420,2);
    pq.enqueue(32,3);

    long ans = pq.dequeue();

    REQUIRE (ans == 69);
    REQUIRE (pq.Size() == 3);

}

// testing dequeue with duplicates at root - long
TEST_CASE("testing dequeue function duplicate roots- long") {
    priorityqueue <long> pq;
    pq.enqueue (12,4);
    pq.enqueue(69,4);
    pq.enqueue(420,2);
    pq.enqueue(32,3);

    long ans = pq.dequeue();

    REQUIRE (ans == 420);
    REQUIRE (pq.Size() == 3);

}

// testing dequeue with root being leftmost node - long
TEST_CASE("testing dequeue function leftmost node - long") {
    priorityqueue <long> pq;
    pq.enqueue (12,5);
    pq.enqueue(69,6);
    pq.enqueue(420,7);
    pq.enqueue(32,8);

    long ans = pq.dequeue();

    REQUIRE (ans == 12);
    REQUIRE (pq.Size() == 3);

}

// testing destructor - long data type
TEST_CASE ("testing destructor - long") {
    priorityqueue <long> pq1;
    // const priorityqueue <int> *address = &pq1;
    pq1.enqueue (1,1);
    pq1.enqueue (2,2);
    pq1.enqueue (4,4);
    pq1.enqueue (5,5);
    pq1.clear();
    REQUIRE (pq1.Size() == 0);
    REQUIRE(pq1.getRoot() == nullptr);
}

// testing clear function - long data type
TEST_CASE("clear function - long") {
    priorityqueue <long> pq;
    pq.clear();
    REQUIRE (pq.Size() == 0);
    REQUIRE(pq.getRoot() == nullptr);
}

// testing operator== function for a normal BST
TEST_CASE ("operator== (i) - long") {
    priorityqueue <long> pq1;
    priorityqueue <long> pq2;
    pq1.enqueue(1,1);
    pq1.enqueue(2,2);
    pq2.enqueue(3,3);
    pq2.enqueue(4,4);
    REQUIRE(pq1.Size()== 2);
    REQUIRE(pq2.Size() == 2);
    REQUIRE(false == (pq1 == pq2));
}

// testing operator== function for 2 empty BSTs
TEST_CASE ("operator== (ii) - long") {
    priorityqueue <long> pq1;
    priorityqueue <long> pq2;
    REQUIRE(pq1.Size() == 0);
    REQUIRE(pq2.Size() == 0);
    REQUIRE(true == (pq1 == pq2));
}

// testing toString function with values of long data type
TEST_CASE("testing toString - long "){
    priorityqueue<long> pq1;
    REQUIRE(pq1.Size() == 0);
    pq1.enqueue(1,1);
    REQUIRE(pq1.Size() == 1);
    REQUIRE(pq1.toString() == "1 value: 1\n");
}