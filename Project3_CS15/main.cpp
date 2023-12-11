/*
 *  main.cpp
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Main function:
 *  runs program through a command loop
 *  that asks user for a word to search
 *  in given directory and prints results
 *  to given output file
 *
 */

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>

#include "HashElement.h"
#include "HashVector.h"
#include "HashTable.h"
#include "gerp.h"
#include "FSTree.h"
#include "DirNode.h"

using namespace std;

string strip(string s);

void commandLoop(bool insensitivity, gerp game, string outfilename);
void check_open(ofstream& file, string outfilename);

int main (int argc, char *argv[])
{
    string directory, outfilename;
    bool insensitivity = false;
    gerp game;

    // checks for correct usage, stores directory name if correct
    if (argc != 3) {
        cerr << "Usage: gerp inputDirectory outputFile" << endl;
        return EXIT_FAILURE;
    } else {
        directory = argv[1];
        outfilename = argv[2];
    }
    
    // traverses given directory's contents and initializes hash
    FSTree rootfolder(directory);
    game.traverseDirectory(rootfolder.getRoot(), directory);
    cout << "Query? ";
    commandLoop(insensitivity, game, outfilename);

    // closes output file and prints goodbye message
    cout << "Goodbye! Thank you and have a nice day." << endl;
    return 0;
}

// Purpose:      strips non-alphanumerical characters from
//               beginning and end of a word
// Parameters:   word to be stripped of non-alphanum chars
// Returns:      version of word stripped of non-alphanum chars
// Side effects: 
string strip(string s)
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


void commandLoop(bool insensitivity, gerp game, string outfilename)
{
    string queryword;
    ofstream output;
    output.open(outfilename);
    check_open(output, outfilename);
    // command loop: "@q" quits, "@f" opens new outputFile, and "@i" searches
    // for a word insensitively, otherwise searches given word sensitively
    while (cin >> queryword and (queryword != "@q" and queryword != "@quit")) {
        if (queryword == "@f") {
            cin >> queryword;
            output.close();
            output.open(queryword);
            check_open(output, outfilename);
        } else if (queryword == "@i" or queryword == "@insensitive") {
            insensitivity = true;
            cin >> queryword;
            game.findWord(strip(queryword), insensitivity, output);
        } else {
            game.findWord(strip(queryword), insensitivity, output);
        }
        insensitivity = false;
        cout << "Query? ";
    }
    output.close();
}

// Purpose:      checks if input file was opened correctly
// Parameters:   file to be checked and filename
// Returns:      bool value indicating if file was opened correctly
// Side effects: prints error message if not opened correctly
void check_open(ofstream& file, string outfilename)
{
        // if error in file opening
        if (not file.is_open()) {
            cerr << "Error: could not open file " << outfilename
                      << endl;
            exit(EXIT_FAILURE);
        }
}