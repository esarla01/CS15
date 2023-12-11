 /* PROJ2
 * Tansu Erin Sarlak
 * 04/01/2022
 * Tests For DatumStack
 */

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include "Datum.h"
#include "DatumStack.h"

using namespace std;

//Test default constructor
void constructor1_test()
{
    DatumStack test;
    assert(test.size() == 0);
}


//Tests array constructor
void constructor2_test()
{
    Datum arr[] = { Datum(3), Datum("birds"), Datum(false) };
    DatumStack test(arr, 3);
    assert(test.size() == 3);
    //test.print();
}


//Tests isEmpty function on empty and non empty datumstacks
void isEmpty_test()
{   
    //check if isEmpty() works for empty datumstacks
    DatumStack test1;
    assert(test1.isEmpty() == true);

    //check if isEmpty() works for non_empty datumstacks
    DatumStack test2;
    Datum a(5);
    test2.push(a);
    assert(test2.isEmpty() == false);
}

//Tests clear function on nonempty and empty datumstacks 
void clear_test()
{
    //check if clear() works for empty datumstacks
    DatumStack test1;
    test1.clear();
    assert(test1.isEmpty() == true);

    //check if clear() works for non_empty datumstacks
    DatumStack test2;
    Datum a(5);
    test2.push(a);
    test2.clear();
    assert(test2.isEmpty() == true);
}


//Tests size function when datumstack is empty, when new datum are
//added and when existing datums are removed from the datumstack
void size_test()
{
    DatumStack test;
    Datum a(7);
    assert(test.size() == 0);
    test.push(a);
    assert(test.size() == 1);
    test.pop();
    assert(test.size() == 0);   
}


//Tests top function on empty datumstacks(expected to thorw an error) 
//on populated datumstacks (expected to return the datum on the top)
void top_test()
{
    //checks if top() thorws an error when datumstack is empty
    DatumStack test1;
    bool runtime_error_thrown = false;
    std::string error_message = "";

    try{
        test1.top();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown == true);
    assert(error_message == "empty_stack");
    
    //check if top() correctly returns the datum on top of the list
    DatumStack test2;
    Datum a(5);
    test2.push(a);
    assert(test2.top() == a);
}


//Tests top function on empty (expected to throw an error) and populated 
//datumstacks (expected to remove the element on top of the stack)
void pop_test()
{
    //checks if pop() thorws an error when datumstack is empty
    DatumStack test1;
    bool runtime_error_thrown = false;
    std::string error_message = "";

    try{
        test1.pop();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown == true);
    assert(error_message == "empty_stack");
    

    //check if pop() correctly removes the datum on top of the list
    DatumStack test2;
    Datum a(5);
    test2.push(a);
    test2.pop();
    assert(test2.size() == 0);   
}


//Test push function repeadetly
void push_test()
{
    DatumStack test;
    Datum a(5);
    Datum b(5);
    Datum c(5);
    test.push(a);
    test.push(b);
    test.push(c);
    //test.print();
    assert(test.size() == 3);  
}

    