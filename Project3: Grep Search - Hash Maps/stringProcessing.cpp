/*
 *  stringProcessing.cpp
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  String Processing Function:
 *  strips a given word from non-alphanumerical
 *  characters and returns word
 *
 */

#include <iostream>
#include <cctype>

#include "stringProcessing.h"
#include "FSTree.h"
#include "DirNode.h"

// Purpose:      strips non-alphanumerical characters from
//               beginning and end of a word
// Parameters:   word to be stripped of non-alphanum chars
// Returns:      version of word stripped of non-alphanum chars
// Side effects: 
std::string stripNonAlphaNum(std::string s)
{
    int indexstart = 0;
    int indexfinish = 0;
    unsigned int i = 0;
    
    // finds and stores index of first alphanum character
    while (not isalnum(s[i]) and i < s.length()) {
        i++;
    }
    indexstart = i;

    // traverses rest of the word to find index of last alphanum character
    for (unsigned int j = i; j < s.length(); j++) {
        if (isalnum(s[j])) {
            indexfinish = j;
        }
    }

    // returns word without trailing non-alphanum characters
    return s.substr(indexstart, indexfinish-indexstart +1);
}