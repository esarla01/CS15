/*
 * unit_tests.h

 *  Erin Sarlak
 *  January  28, 2022
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  Creating an array list.
 *
 */

#include "CharArrayList.h"
#include <cassert>
#include <string>
#include <stdexcept>
#include <iostream>
// ********************************************************************
// *                       CHAR ARRAY LIST TESTS                        *
// ********************************************************************

/* To give an example of thorough testing, we are providing
 * the unit tests below which test the insertAt function. Notice: we have
 * tried to consider all of the different cases insertAt may be
 * called in, and we test insertAt in conjunction with other functions!
 *
 * You should emulate this approach for all functions you define.
 */


// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() { 
                                   CharArrayList test_list;
                                   test_list.insertAt('a', 0);
                                   assert(test_list.size() == 1);
                                   assert(test_list.elementAt(0) == 'a');
                               
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
    
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
    
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
    
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
    
}

// Tests insertion into front, back, and middle of a larger list.
void insertAt_front_back_middle() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        // insertAt middle
        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() == "[CharArrayList of size 9 <<abczdefgh>>]");

        // insertAt front
        test_list.insertAt('y', 0);

        assert(test_list.size() == 10);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() == "[CharArrayList of size 10 <<yabczdefgh>>]");

        // insertAt back
        test_list.insertAt('x', 10);

        assert(test_list.size() == 11);
        assert(test_list.elementAt(10) == 'x');
        assert(test_list.toString() == "[CharArrayList of size 11 <<yabczdefghx>>]");
        
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
    
}

/*
 * constructor1 test 
 * Make sure no fatal errors/memory leaks in the default constructor and 
 * make sure no items exist in the list upon construction.
 */
void constructor_test() {
    CharArrayList list;
    assert(list.size() == 0);
}

/*
 * constructor2 test 
 * Make sure the array list has the size 1 and the first element is the given 
 * element.
 */
void constructor2_test() {
    CharArrayList list('a');
    assert(list.size() == 1);
    assert(list.first() == 'a');
}

/*
 * constructor3 test 
 * Make sure the array list has the elements and capacity of the argument 
 * array
 */
 void constructor3_test1() {
    char test_arr[3] = { 'a', 'b', 'c'};
    CharArrayList list(test_arr, 3);
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'c');
    assert(list.size() == 3);
 }



/*
 * (copy) constructor4 test1 
 * Make sure the array list porperly deep copies a nonempty array.
 */
void constructor4_test1(){
    char test_arr[3] = { 'a', 'b', 'c'};
    CharArrayList list_1st(test_arr, 3);
    CharArrayList list_2nd(list_1st);
    assert(list_2nd.elementAt(0) == 'a');
    assert(list_2nd.elementAt(1) == 'b');
    assert(list_2nd.elementAt(2) == 'c');
    assert(list_2nd.size() == 3);
}

/*
 * (copy) constructor4 test2
 * Make sure the array list properly deep copies an empty array list.
 */
void constructor4_test2(){
    CharArrayList list_1st;
    CharArrayList list_2nd(list_1st);
    assert(list_2nd.isEmpty() == true);
    assert(list_2nd.size() == 0);
}


/*
 * operator test1
 * Make sure that a deep copy of the instance on the right hand side is made
 * into the instance on the left hand side and the storage associated with 
 * the instance on the left of the assignment is recycled. This test is 
 * specifically for copying an empty list.
 */
void operator_test_1(){
    char test_arr[3] = { 'a', 'b', 'c'};
    CharArrayList list_1st(test_arr, 3);
    CharArrayList list_2nd;
    list_2nd = list_1st;
    assert(list_2nd.elementAt(0) == 'a');
    assert(list_2nd.elementAt(1) == 'b');
    assert(list_2nd.elementAt(2) == 'c');
    assert(list_2nd.size() == 3);
}   




/*
 * operator test2
 * Make sure that a deep copy of the instance om the right hand side is made
 * into the instance on the left hand side and the storage associated with 
 * the instance on the left of the aassignment is recycled. This test is 
 * specifically for copying an empty list.
 */
void operator_test_2(){
    CharArrayList list_1st;
    CharArrayList list_2nd('s');
    list_2nd = list_1st;
    assert(list_2nd.isEmpty() == true);
    assert(list_2nd.size() == 0);
}

/*
 * isEmpty test 
 * Tests if isEmpty function return true when array list is empty and false when not
 * when it is not.
 */
void isEmpty_test(){
    CharArrayList list_1st;
    CharArrayList list_2nd('a');
    assert(list_1st.isEmpty() == true);
    assert(list_2nd.isEmpty() == false);
}

/*
 * clear test 
 * Make sure that the array list is emptied after the function is called on an instance
 * of array list
 * when it is not.
 */
void clear_test1(){
    char test_arr[3] = { 'a', 'b', 'c'};
    CharArrayList list_1st(test_arr, 3);
    list_1st.clear();
    assert(list_1st.isEmpty() == true);
}

/*
 * clear test 
 * Make sure that the an empty array list stays empty after the function is called
 * when it is not.
 */
void clear_test2(){
    CharArrayList list_2nd;
    list_2nd.clear();
    assert(list_2nd.isEmpty() == true);
}

/*
 * size test 1
 * Tests if size function provides the correct size of the array.
 */
void size_test_1(){
    CharArrayList list('b');
    assert(list.size() == 1);
}

/*
 * size test 
 * Tests if size function works when the array list is empty.
 */
void size_test_2(){
    CharArrayList list;
    assert(list.size() == 0);
}


/*
 * first test 1
 * Tests if first function provides the first element of the array.
 */
void first_test_1(){
    CharArrayList list('c');
    assert(list.first() == 'c');
}


/*
 * first test 2
 * Tests if the function throws runtime error when it the array list is empty
 */
void first_test_2(){
    // var to track whether range_error is thrown
    bool runtime_error_thrown = false;
     // var to track any error messages raised
    std::string error_message = "";
    CharArrayList list;
    try{
        list.first();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty ArrayList");
}


/*
 * last test 
 * Tests if last function provides the last element of the array list.
 */
void last_test(){
    CharArrayList list('d');
    assert(list.last() == 'd');
}

/*
 * last test 2
 * Tests if the function throws runtime error when it the array list is empty
 */
void last_test_2(){
    // var to track whether range_error is thrown
    bool runtime_error_thrown = false;
    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList list;
    try{
        list.last();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot get last of empty ArrayList");
}



/*
 * elementAt test 1
 * Tests if elementAt function returns the correct element in the given index.
 */
void elementAt_test_nonempty_correct() {
    CharArrayList list('a');
    int element = list.elementAt(0);
    assert(element == 'a');
}

/*
 * elementAt test 2
 * Tests if elementAt function gives the right error message when it is called 
 * for a empty array list.
 */
void elementAt_test_empty_incorrect() {
    CharArrayList list;
    // var to track whether range_error is thrown
    bool range_error_thrown = false;
    // var to track any error messages raised
    std::string error_message = "";
    try{
        int element = list.elementAt(5);
    } 
    catch(const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
     assert(range_error_thrown);
    assert(error_message == "index (5) not in range [0..0)");
}


/*
 * elementAt test 3
 * Tests if elementAt function gives right error message when it is asked to 
 * return non-existant char out of index in array list. 
 */
void elementAt_test_nonempty_incorrect() {
    CharArrayList list('a');
    // var to track whether range_error is thrown
    bool range_error_thrown = false;
    // var to track any error messages raised
    std::string error_message = "";
    try{
        int element = list.elementAt(5);
    } 
    catch(const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
     assert(range_error_thrown);
    assert(error_message == "index (5) not in range [0..1)");
}


/*
 * pushAtBack test empty
 * Make sure that the function inserts given characters at the end of an empty 
 * array list and updates the size accordingly.
 */
void pushAtBack_test_empty(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
    assert(list_1st.elementAt(2) == 'c');
    assert(list_1st.size() == 3);
}

/*
 * pushAtBack test nonempty
 * Make sure that the function inserts given characters at the end of a nonempty 
 * array list and updates the size accordingly.
 */
void pushAtBack_test_nonempty(){
    CharArrayList list_1st('a');
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'a');
    assert(list_1st.elementAt(2) == 'b');
    assert(list_1st.elementAt(3) == 'c');
    assert(list_1st.size() == 4);
}


/*
 * pushAtFront test empty
 * Make sure that the function inserts given characters in front of an empty 
 * array list and updates the size accordingly.
 */
void pushAtFront_test_empty(){
    CharArrayList list_1st;
    list_1st.pushAtFront('c');
    list_1st.pushAtFront('b');
    list_1st.pushAtFront('a');
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
    assert(list_1st.elementAt(2) == 'c');
    assert(list_1st.size() == 3);
}

/*
 * pushAtFront test empty
 * Make sure that the function inserts given characters in front of a nonempty 
 * array list and updates the size accordingly.
 */
void pushAtFront_test_nonempty(){
    CharArrayList list_1st('a');
    list_1st.pushAtBack('c');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('a');
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'c');
    assert(list_1st.elementAt(2) == 'b');
    assert(list_1st.elementAt(3) == 'a');
    assert(list_1st.size() == 4);
}

/*
 * toString test empty
 * Make sure that the function returns the intended message when the array 
 * list is empty.
 */
void toString_test_empty(){
    CharArrayList list_1st;
    assert(list_1st.toString() == "[CharArrayList of size 0 <<>>]");
}

/*
 * toString test empty
 * Make sure that the function returns the intended message when the array 
 * list is nonempty (ordered string).
 */
void toString_test_nonempty(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    assert(list_1st.toString() == "[CharArrayList of size 3 <<abc>>]");

}

/*
 * toReverseString test empty
 * Make sure that the function returns the intended message when the array 
 * list is empty.
 */
void toReverseString_test_empty(){
    CharArrayList list_1st;
    assert(list_1st.toReverseString() == "[CharArrayList of size 0 <<>>]");
}

/*
 * toReverseString test empty
 * Make sure that the function returns the intended message when the array 
 * list is nonempty (reverse string).
 */
void toReverseString_test_nonempty(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    assert(list_1st.toReverseString() == "[CharArrayList of size 3 <<cba>>]");

}


/*
 * insertInOrder test empty first
 * Make sure that the specified characters are inserted into the array list in
 * alpahbetical order when the function is called and array list is empty.
 */
void insertInOrder_test_empty_first(){
    CharArrayList list_1st;
    list_1st.insertInOrder('c');
    list_1st.insertInOrder('a');
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'c');
}

/*
 * insertInOrder test nonempty
 * Make sure that the specified characters are inserted into the array list in
 * alpahbetical order when the function is called and array list is nonempty.
 */
void insertInOrder_test_nonempty_middle(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('d');
    list_1st.insertInOrder('c');
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
    assert(list_1st.elementAt(2) == 'c');
    assert(list_1st.elementAt(3) == 'd');
}


/*
 * insertInOrder test empty last
 * Make sure that the specified characters are inserted into the array list in
 * alpahbetical order when the function is called and array list is nonempty
 * Make sure that when the character is supposed to come after other character
*  the list, it is inserted to the end of the list.
 */
void insertInOrder_test_nonempty_last(){
    CharArrayList list_1st;
    list_1st.pushAtBack('A');
    list_1st.pushAtBack('B');
    list_1st.pushAtBack('D');
    list_1st.insertInOrder('f');
    assert(list_1st.elementAt(0) == 'A');
    assert(list_1st.elementAt(1) == 'B');
    assert(list_1st.elementAt(2) == 'D');
    assert(list_1st.elementAt(3) == 'f');
}

/*
 * popFromFront
 * Make sure that the function throws an error message when the array list
 * is empty because no element can to be removed exists in the list
 */
void popFromFront_empty(){
    CharArrayList list_1st;
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try{
        list_1st.popFromFront();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty ArrayList");
}


/*
 * popFromFront nonempty
 * Make sure that the function removes the first character from the array list 
 * when it is nonempty
 */
void popFromFront_nonempty(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    list_1st.popFromFront();
    list_1st.popFromFront();
    assert(list_1st.elementAt(0) == 'c');
}

/*
 * popFromFront empty
 * Make sure that the function throws an error message when the array list
 * is empty because no element can to be removed exists in the list
 */
void popFromBack_empty(){
    CharArrayList list_1st;
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try{
        list_1st.popFromBack();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty ArrayList");
}

/*
 * popFromFront nonempty
 * Make sure that the function removes the last character from the array list 
 * when it is nonempty
 */
void popFromBack_nonempty(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    list_1st.popFromBack();
    list_1st.popFromBack();
    assert(list_1st.elementAt(0) == 'a');
}

/*
 * removeAtTest_first 
 * Make sure that the function properly removes the first character from the 
 * array list (when index is 0)
 */
void removeAtTest_first(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.removeAt(0);
    assert(list_1st.elementAt(0) == 'b');
}

/*
 * removeAtTest_first 
 * Make sure that the function properly removes the last character from the 
 * array list (when index is numitems)
 */
void removeAtTest_last(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.removeAt(1);
    assert(list_1st.elementAt(0) == 'a');

}

/*
 * removeAtTest_first 
 * Make sure that the function properly removes the a character from the 
 * middle of the array list (when index is between 0 and numitems)
 */
void removeAtTest_middle(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    list_1st.removeAt(1);
    assert(list_1st.elementAt(0) == 'a');            
    assert(list_1st.elementAt(1) == 'c');
}

/*
 * replaceAt_test_front() 
 * Make sure that the function properly replaces a character in the specified
 * index with the given index (when the index is 0, numItems and between the 
 * those)
 */
void replaceAt_test_front(){ 
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    list_1st.pushAtBack('c');
    list_1st.replaceAt('Z',0);
    list_1st.replaceAt('Z',1);
    list_1st.replaceAt('Z',2);
    assert(list_1st.elementAt(0) == 'Z');            
    assert(list_1st.elementAt(1) == 'Z');
    assert(list_1st.elementAt(2) == 'Z');
}


/*
 * concanate test nonempty
 * Make sure that the list copies the characters of the second list to the 
 * first one when both lists are already popullated.
 */
void concanate_test_nonempty(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    CharArrayList list_2nd;
    list_2nd.pushAtBack('d');
    list_2nd.pushAtBack('e');
    CharArrayList *list_pointer;
    list_pointer = &list_2nd;
    list_1st.concatenate(list_pointer);
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
    assert(list_1st.elementAt(2) == 'd');
    assert(list_1st.elementAt(3) == 'e');
}

/*
 * concanate test empty
 * Make sure that the list copies the characters of the second list to the 
 * first one when the first list is empty but the second one is popullated
 */
void concanate_test_2(){
    CharArrayList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    CharArrayList list_2nd;
    CharArrayList *list_pointer;
    list_pointer = &list_2nd;
    list_1st.concatenate(list_pointer);
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
}

