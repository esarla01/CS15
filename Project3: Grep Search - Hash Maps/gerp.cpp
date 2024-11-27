/*
 *  gerp.cpp
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Implementation for Gerp:
 *  a program that reads words in from a file
 *  and inserts them in a hash, then finds a 
 *  given word in the same hash, printing its
 *  address and the line it was in
 *
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>

#include "HashElement.h"
#include "HashVector.h"
#include "HashTable.h"
#include "gerp.h"
#include "DirNode.h"

using namespace std;

// Purpose:      finds word and prints its info depending on insensitivity
// Parameters:   word to look for, 
//               whether it is an insensitive search or not, 
//               the output stream to print to
// Returns:      
// Side effects: 
void gerp::findWord(string word, bool insensitivity, ostream& output)
{
    string message;
    // calculates hash index
    int h_ind = hash <string> {} (lowerCSase(word)) % dictionary.size();

    // if case insensitive, prints all sentences containing the word itself
    if (insensitivity == false) {
        message = " Not Found. Try with @insensitive or @i.";
        // look at originals (case sensitive) in vector of hash index
        for (int v_ind = 0; v_ind < dictionary.getSize(h_ind); v_ind++) {
            if (word == dictionary.getOriginalIn(h_ind, v_ind)){
                    printSentences(h_ind, v_ind, output);
                    message = "";
            }
        }
    }
    // otherwise, prints all sentences containing all versions of the word
    else if (insensitivity == true) {
        message = " Not Found.";
        // look at keys (case insensitive) in vector of hash index
        for (int v_ind = 0; v_ind < dictionary.getSize(h_ind); v_ind++) {
            if (lowerCSase(word) == dictionary.getKeyIn(h_ind, v_ind)){
                    printSentences(h_ind, v_ind, output);
                    message = "";
            }
        }
    } 
    // print appropriate error message if word is not found
    if (message != "")
        output << word << message << endl;
}

// Purpose:      prints instances of a given word
// Parameters:   index of hash table word is in,
//               index in the vector word is in, 
//               ostream for output to printed on
// Returns:      
// Side effects: 
void gerp::printSentences(int index, int number, ostream& output)
{
    //prints all sentences of a word in the given vector index and table index
    for (int i = 0; i < dictionary.getCountNum(index, number); i++){
        string path = dictionary.getPathIn(index, number, i);
        int line = dictionary.getLineIn(index, number, i);
        output << path << ":" << line << ": " << findSentence(path, line) 
               << endl;
    }
}

// Purpose:      opens file and finds the line the word appears on
// Parameters:   path leading to the word, line number word appears on
// Returns:      the contents of the line the word appears on
// Side effects: 
string gerp::findSentence(string path, int line)
{
    ifstream file;
    string sentence;

    // opens / attempts to open file in path
    file.open(path);
    if (not file.is_open()) {
        cerr << "Error: could not open file " << path << endl;
        return "";
    }

    // reads in each line until desired line comes
    for (int m = 0; m < line; m++) {
        getline(file, sentence);
    }
    
    // closes file
    file.close();
    // returns the last line as it stores is the desired line
    return sentence;
}

// Purpose:      traverses each directory to initialize hash
// Parameters:   root directory to start traversing from,
//               path to the directory
// Returns:      
// Side effects: 
void gerp::traverseDirectory (DirNode *rootFolder, string path)
{
    ifstream file;
    // if directory has no content in it, returns
    if (not rootFolder->hasSubDir() and not rootFolder->hasFiles()){
            return;
    } else {
        // if directory has files in it
        if (rootFolder->hasFiles()){
            // traverse through each file and call initialize hash function
            for (int i = 0; i < rootFolder->numFiles(); i++){
                string filename = rootFolder->getFile(i);
                // open file by adding the file to its path
                file.open(path + "/" + rootFolder->getFile(i));
                if (not file.is_open()) {
                    cerr << "Error: could not open file " << path << endl;
                    return;
                }                
                initializeHash(file, path + "/" + rootFolder->getFile(i));
                file.close();
            }
        }
        // if directory has subdirectories
        if (rootFolder->hasSubDir()){
            // recursively calls this function for each subdirectory
            // and updating each subdirectory's path
            for (int i = 0; i < rootFolder->numSubDirs(); i++){
                traverseDirectory(rootFolder->getSubDir(i), 
                        path + "/" + rootFolder->getSubDir(i)->getName());
            }
        }
    }
}

// Purpose:      initializes hash by reading contents of each file
// Parameters:   file to be read, path of the file to be read
// Returns:      
// Side effects: 
void gerp::initializeHash (ifstream &file, string path)
{
    string line;
    int lineNum = 1;

    // gets each line from given file and sends to sortWords to initialize hash
    while (getline(file, line) or not file.eof()){
       sortWords(line, lineNum, path);
       lineNum++;
    }
}

// Purpose:      gets each individual word from a line
// Parameters:   line itself, line number, path to the file
// Returns:      
// Side effects: 
void gerp::sortWords (string line, int lineNum, string path)
{
    string word = "";
    vector <string> wordList;
    // for all of the file
    for (unsigned int i = 0; i < line.size(); i++){
        // concatenates if character is not a space
        if (line[i] !=  ' '){
            word += line[i];
        // if character is a space and 
        // word is not empty and if word is not just a space
        } else if (word != "" and word != " "){
            // adds word to wordList after stripping non-alphanum chars
            wordList.push_back(stripNonAlphaNum(word));
            // if there's already the same word, pops it back
            for (unsigned int j = 0; j < wordList.size()-1; j++){
                if (stripNonAlphaNum(word) == wordList[j])
                    wordList.pop_back();
            }
            // clears contents of word to repeat for each new word
            word = "";
        }
    }
    // if last character was not a space and there is still a word stored
    if (word != "") {
        // adds word to wordList after stripping non-alphanum chars
        wordList.push_back(stripNonAlphaNum(word));
        // if there's already the same word, pops it back
        for (unsigned int j = 0; j < wordList.size()-1; j++){
            if (stripNonAlphaNum(word) == wordList[j]) {
                wordList.pop_back();
            }
        }
    }
    // put each to a hash element and insert to table
    for (unsigned int j = 0; j < wordList.size(); j++){
        HashElement a (wordList[j], lineNum, path);
        dictionary.inserttotable(a);
    }
}

// Purpose:      strips non-alphanumerical characters from
//               beginning and end of a word
// Parameters:   word to be stripped of non-alphanum chars
// Returns:      version of word stripped of non-alphanum chars
// Side effects: 
string gerp::stripNonAlphaNum(string s)
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

// Purpose:      turns a word to its lowercase version
// Parameters:   word to be changed to lowercase
// Returns:      word in its lowercase version
// Side effects: 
string gerp::lowerCSase(string word)
{
    string toreturn = "";

    // converts each character of the string one by one
    for (unsigned int i = 0; i < word.size(); i++) {
        // concatenates to empty string
        toreturn += tolower(word[i]);
    }
    return toreturn;
}