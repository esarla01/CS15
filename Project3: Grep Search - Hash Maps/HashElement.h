/*
 *  HashElement.h
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Interface for HashElement:
 *  a struct that includes a word, its lowercase 
 *  form, the path of the file it appears in, and
 *  the line in the file it appears on
 *
 */

#ifndef HASH_ELEMENT_H
#define HASH_ELEMENT_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class HashElement
{
public:
    HashElement();
    HashElement(string neworiginal, int newline, string newpath);
    void addLinePath(int newline, string newpath);
    void print(ostream &output);
    int getcount();
    int getline(int index);
    string getpath(int index);
    string getoriginal();
    string getkey();
    string lowercase(string a);

private:
    string key;   
    string original;
    vector <int> line;
    vector <string> path;
    int count;
};

#endif