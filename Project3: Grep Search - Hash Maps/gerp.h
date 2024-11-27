/*
 *  gerp.h
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Interface for Gerp:
 *  a program that reads words in from a file
 *  and inserts them in a hash, then finds a 
 *  given word in the same hash, printing its
 *  address and the line it was in
 *
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>

#include "HashElement.h"
#include "HashVector.h"
#include "HashTable.h"
#include "DirNode.h"

using namespace std;

class gerp
{
public:
    void initializeHash (ifstream &file, string path);
    void sortWords (string line, int lineNum, string path);
    void traverseDirectory (DirNode *rootfolder, string path);
    void findWord(string word, bool insensitivity, ostream& output);
    void printSentences(int index, int number, ostream& output);
    string stripNonAlphaNum(string s);
    string findSentence(string path, int line);
    string lowerCSase(string word);
private:
    HashTable dictionary;
};