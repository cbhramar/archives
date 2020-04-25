/* File: domino.h
 * Listing class declaration and function prototypes
 */

#ifndef _domino_h
#define _domino_h

#include<iostream>
#include<ios>
#include<string>

// Declaring Class
class Domino{
// Declaring Public Entities
public:
    // Constructors
    Domino();
    Domino(int n, int m);
    // toString Method
    std::string toString();
    // Getter Methods
    int getLeftDot();
    int getRightDot();
// Declaring Private Enities ( Instance Variables)
private:
    int left;
    int right;
};

std::ostream & operator<<(ostream & os, Domino dm);

#endif
