/*
 *  HashElement.cpp
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Implementation for HashElement:
 *  a struct that includes a word, its lowercase 
 *  form, the path of the file it appears in, and
 *  the line in the file it appears on
 *
 */

#include <iostream>
#include <string>
#include <cctype>

#include "HashElement.h"

using namespace std;

// Purpose:      constructs empty hash element
// Parameters:   
// Returns:      
// Side effects: 
HashElement::HashElement()
{
    key = "";
    original = "";
    // since element is empty, there is no instances of any word yet
    count = 0;
}

// Purpose:      constructs hash element with given line and path
// Parameters:   word itself, line it appears on, path to the file
// Returns:      
// Side effects: 
HashElement::HashElement(string neworiginal, int newline, string newpath)
{     
    // word is converted to lowercase for key in case of an insensitive search
    key = lowercase(neworiginal);
    original = neworiginal;
    line.push_back(newline);
    path.push_back(newpath);
    // since element is initialized, there is a single instance of this word
    count = 1;
}

// Purpose:      increments the count for elements for insensitive search
// Parameters:   line it appears on, path to the file
// Returns:      
// Side effects: increments count of a word
void HashElement::addLinePath(int newline, string newpath)
{
    // adds to the line and path vectors of a word in case it has already
    // been initialized
    line.push_back(newline);
    path.push_back(newpath);
    // another instance of the word has been added, so count incremented
    count++;
}

// Purpose:      gets line number where the hash element appears on
// Parameters:   the index determining which instance
//               of the word is desired
// Returns:      line given element appears on
// Side effects: 
int HashElement::getline(int index)
{
    return line[index];
}

// Purpose:      gets path where the hash element appears on
// Parameters:   the index determining which instance
//               of the word is desired
// Returns:      path given element appears on
// Side effects: 
string HashElement::getpath(int index)
{
    return path[index];
}

// Purpose:      gets number of instances of the given word
// Parameters:   
// Returns:      number of instances the given word appears
// Side effects: 
int HashElement::getcount()
{
    return count;
}

// Purpose:      gets the original form of the word with uppercase
//               and lowercase characters
// Parameters:   
// Returns:      the original form of the word
// Side effects: 
string HashElement::getoriginal()
{
    return original;
}

// Purpose:      gets the lowercase version of the word
// Parameters:   
// Returns:      lowercase version of the word
// Side effects: 
string HashElement::getkey()
{
    return key;
}

// Purpose:      prints contents of a specific hash element
//               useful for unit testing
// Parameters:   ostream for output to printed on
// Returns:      
// Side effects: 
void HashElement::print(ostream &output)
{
    output << "Key: " << key << endl;
    output << "Original version: " << original << endl;

    output << "Line(s): " << line[0];
    for (unsigned int i = 1; i < line.size(); i++) {
        output << ", " << line[i];
    }
    output << endl;

    output << "Path(s): " << path[0];
    for (unsigned int i = 1; i < path.size(); i++) {
        output << ", " << path[i];
    }
    output << endl << endl;
}

// Purpose:      turns each character in a string to lowercase
// Parameters:   a string to be converted to all lowercase
// Returns:      given string changed to all lowercase
// Side effects: 
string HashElement::lowercase(string a)
{
    string toreturn = "";
    // converts each character of the string one by one
    for (unsigned int i = 0; i < a.size(); i++) {
        // concatenates to empty string
        toreturn += tolower(a[i]);
    }
    return toreturn;
}