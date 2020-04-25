/*
 * File: display.cpp
 * Brief: A C++ program to display formulae and their derivatives in human readable form in the terminal.
 * The code uses classes and inheritence; creating a base formula class which is the parent class
 * to various specialised classes. 
 */



#include <iostream>
#include <cmath>

using namespace std;

class formula // parent class
{
    public:
        formula *l; // left of the operator
        formula *r; // right of the operator
        virtual void print() = 0; // function to display the formula in human readable form
        virtual void differentiate() = 0; // function to display the derivative of given formula in human readable form
        virtual string return_value() = 0; // used to differentiate between primary and non-primary formulae. is empty string for non primary formulae
};


class primary: public formula // primary formula with no operator
{
    private:
        string value;
    public:
        primary(string v) // constructor
        {
            value = v;
            l = NULL;
            r = NULL;
        }
        void print() // print the value straight away
        {
            cout << value;
        }
        string return_value() // for a primary formula, the only variable it takes to initialize is the return value
        {
            return value;
        }
        void differentiate() // only case when a differentiation would matter, in terms of printing is when the value is "x"
        {
            if(value == "x")
                cout << "1";
            else
                return;
        }
};


class Sum: public formula // formulae with operator "+"
{
    public:
        Sum(formula *l1, formula *r1) // constructor
        {
            l = l1;
            r = r1;
        }
        void print()
        {
            l->print(); // recursive call
            cout << " + "; // sepaerated by the "+" operator
            r->print(); // recursive call
        }
        void differentiate() // differentiation with the various base cases and a recursive call
        {
            if(l->return_value() == "x" && r->return_value() == "x") // (x+x)' = 2
            {
                cout << "2";
            }
            else if(l->return_value() == "x" && r->return_value() == "") // (x+r)' = 1+r'
            {
                cout << "1 + ";
                r->differentiate();
            }
            else if(l->return_value() == "x" && r->return_value() != "") // (x+2)' = 1
            {
                cout << "1";
            }
            else if(l->return_value() == "" && r->return_value() == "x") // (l+x)' = l'+1
            {
                l->differentiate();
                cout << " + 1";
            }
            else if(l->return_value() != "" && r->return_value() == "x") // (2+x)' = 1
            {
                cout << "1";
            }
            else if(l->return_value() != "" && r->return_value() == "") // (2+r)' = r'
            {
                r->differentiate();
            }
            else if(l->return_value() == "" && r->return_value() != "") // (l+2)' = l'
            {
                l->differentiate();
            }
            else // (r+l)' = r'+l'
            {
                l->differentiate();
                cout << " + ";
                r->differentiate();
            }
        }
        string return_value() // return value kept as null string to differentiate from primary formulae
        {
            return "";
        }
};


class Difference: public formula // formulae with operator "-", nearly the same as Sum class
{
    public:
        Difference(formula *l1, formula *r1) // constructor
        {
            l = l1;
            r = r1;
        }
        void print() // display
        {
            l->print();
            cout << " - ";
            r->print();
        }
        void differentiate() // display the derivative 
        {
            if(l->return_value() == "x" && r->return_value() == "x")
            {
                return;
            }
            else if(l->return_value() == "x" && r->return_value() == "")
            {
                cout << "1 - ";
                r->differentiate();
            }
            else if(l->return_value() == "x" && r->return_value() != "")
            {
                cout << "1";
            }
            else if(l->return_value() == "" && r->return_value() == "x")
            {
                l->differentiate();
                cout << " - 1";
            }
            else if(l->return_value() != "" && r->return_value() == "x")
            {
                cout << "-1";
            }
            else if(l->return_value() != "" && r->return_value() == "")
            {
                cout << "-";
                r->differentiate();
            }
            else if(l->return_value() == "" && r->return_value() != "")
            {
                l->differentiate();
            }
            else
            {
                l->differentiate();
                cout << " - ";
                r->differentiate();
            }
        }
        string return_value() // return empty string
        {
            return "";
        }
};


class Product: public formula // formulae with operator "*"
{
    public:
        Product(formula *l1, formula *r1) // constructor
        {
            l = l1;
            r = r1;
        }
        void print() // using brackets for accurate readability
        {
            cout << "(";
            l->print(); // recursive call
            cout << ")*(";
            r->print(); // recursive call
            cout << ")";
        }
        void differentiate() // handling the differentiation case with many base cases and recursive calls 
        {
            if(l->return_value() == "" && r->return_value() == "") // (l*r)' = l*r' + r*l' 
            {
                cout << "(";
                l->print();
                cout << ")*(";
                r->differentiate();
                cout << ") + (";
                r->print();
                cout << ")*(";
                l->differentiate();
                cout << ")";
            }
            else if(l->return_value() == "x" && r->return_value() == "x") // (x*x)' = 2*x
            {
                cout << "2*x";
            }
            else if(l->return_value() == "x" && r->return_value() == "") // (x*r)' = x*r' + r
            {
                cout << "(x)*(";
                r->differentiate();
                cout << ") + ";
                r->print();
            }
            else if(l->return_value() == "" && r->return_value() == "x") // (l*x)' = l + x*l'
            {
                l->print();
                cout << " + (x)*(";
                l->differentiate();
            }
            else if(l->return_value() != "" && r->return_value() == "x") // (2*x)' = 2
            {
                l->print();
            }
            else if(l->return_value() == "x" && r->return_value() != "") // (x*2)' = 2
            {
                r->print();
            }
            else if(l->return_value() != "" && r->return_value() == "") // (2*r)' = 2*r'
            {
                cout << "(";
                l->print();
                cout << ")*(";
                r->differentiate();
                cout << ")";
            }
            else if(l->return_value() == "" && r->return_value() != "") // (l*2)' = 2*l'
            {
                cout << "(";
                r->print();
                cout << ")*(";
                l->differentiate();
                cout << ")";
            }
            else if(l->return_value() != "" && r->return_value() != "") // (3*4)' = 0
                return;
        }
        string return_value()
        {
            return "";
        }
};


class Ratio: public formula // formulae with operator "/"
{
    public:
        Ratio(formula *l1, formula *r1) // constructor
        {
            l = l1;
            r = r1;
        }
        void print() // division isn't as clean while printing
        {
            cout << "(";
            l->print();
            cout << ")/(";
            r->print();
            cout << ")";
        }
        void differentiate()  // handling the differentiation case with many base cases and recursive calls
        {
            if(l->return_value() == "" && r->return_value() == "") // (l/r)' = (r*l' - l*r')/(r^2)
            {
                cout << "( (";
                r->print();
                cout << ")*(";
                l->differentiate();
                cout << ") - (";
                l->print();
                cout << ")*(";
                r->differentiate();
                cout << ") )/( (";
                r->print();
                cout << ")^2 )";
            }
            else if(l->return_value() == "x" && r->return_value() == "x") // (x/x)' = 0
            {
                return;
            }
            else if(l->return_value() == "" && r->return_value() == "x") // (l/x)' = (x*l' - l)/x^2
            {
                cout << "( (x)*(";
                l->differentiate();
                cout << ") - (";
                l->print();
                cout << ") )/( (x)^2 )";
            }
            else if(l->return_value() == "x" && r->return_value() == "") // (x/r)' = (r - x*r')/r^2
            {
                cout << "( ";
                r->print();
                cout << " - (x)*(";
                r->differentiate();
                cout << ") )/( (";
                r->print();
                cout << ")^2 )";
            }
            else if(l->return_value() == "" && r->return_value() != "") // (l/6)' = l'/6
            {
                cout << "(";
                l->differentiate();
                cout << ")/(";
                r->print();
                cout << ")";
            }
            else if(l->return_value() != "" && r->return_value() == "") // (4/r)' = -(4*r')/r^2
            {
                cout << " - ( (";
                l->print();
                cout << ")*(";
                r->differentiate();
                cout << ") )/( (";
                r->print();
                cout << ")^2 )";
            }
            else if(l->return_value() == "x" && r->return_value() != "") // (x/7)' = 1/7
            {
                cout << "1/(";
                r->print();
                cout << ")";
            }
            else if(l->return_value() != "" && r->return_value() == "x") // (3/x)' = -3/x^2
            {
                cout << " - (";
                l->print();
                cout << ")/( (x)^2 )";
            }
            else if(l->return_value() != "" && r->return_value() != "") // (7/5)' = 0
            {
                return;
            }
        }
        string return_value() // return empty string
        {
            return "";
        }
};


class Exponent: public formula // formulae with operator "^"
{
    public:
        Exponent(formula *l1, formula *r1) // constructor
        {
            l = l1;
            r = r1;
        }
        void print() // displayer function
        {
            cout << "(";
            l->print();
            cout << ")^(";
            r->print();
            cout << ")";
        }
        void differentiate() // displaying the derivative
        {
            if(l->return_value() == "x") // (x^r)' = r*x^(r-1)
            {
                cout << "(";
                r->print();
                cout << ")*( (";
                l->print();
                cout << ")^(";
                r->print();
                cout << "-1) )";
            }
            else if(l->return_value() != "x" && l->return_value() != "") // (4^r)' = 0
            {
                return;
            }
            else // (l^r)' = r*l^(r-1)*l'
            {
                cout << "(";
                r->print();
                cout << ")*( (";
                l->print();
                cout << ")^(";
                r->print();
                cout << "-1) )*(";
                l->differentiate();
                cout << ")";
            }
        }
        string return_value() // return empty string
        {
            return "";
        }
};


int main()
{
	// some examples
    cout << endl;
    Sum e(new Sum(new primary("1"), new Ratio(new primary("x"), new primary("n"))), new Ratio(new Difference(new primary("2"), new primary("x")), new Product(new primary("x"), new primary("a"))));
    e.print();
    cout << endl;
    cout << "Primary + Ratio + Composite Ratio\n";
    e.differentiate();
    cout << endl;

    cout << endl;
    Difference f(new Exponent(new Sum(new Product(new primary("x"), new primary("x")), new Exponent(new primary("x"), new primary("3"))), new primary("n")), new primary("c"));
    f.print();
    cout << endl;
    cout << "Composite Exponent - Primary \n";
    f.differentiate();
    cout << endl;

    cout << endl;
    Ratio g(new Sum(new Product(new primary("3"), new primary("x")), new primary("5")), new Difference(new primary("16"), new Exponent(new primary("x"), new primary("2"))));
    g.print();
    cout << endl;
    cout << "Composite Ratio\n";
    g.differentiate();
    cout << endl;

    cout << endl;
    Sum h(new Ratio(new primary("a"), new primary("b")), new Product(new Ratio(new Difference(new Ratio(new primary("x"), new primary("a")), new Exponent(new Sum(new Exponent(new primary("x"), new primary("2")), new primary("2")), new primary("n"))), new Sum(new Product(new primary("5"), new primary("x")), new primary("c"))), new Ratio(new primary("5"), new primary("x"))));
    h.print();
    cout << endl;
    cout << "Oh dear lord! What have I done ?!\n";
    h.differentiate();
    cout << endl;
    cout << endl;
}
