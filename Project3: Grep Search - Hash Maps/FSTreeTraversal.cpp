/*
 *  FSTreeTraversal.cpp
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  FSTree Traversal:
 *  from a given directory, traverses through its
 *  contents to print all possible paths taken
 *
 */

#include "FSTree.h"
#include "DirNode.h"
#include "stringProcessing.h"

#include <iostream>

using namespace std;

void FSTreeTraversal(DirNode *rootFolder, string path);

int main(int argv, char *argc[])
{
    string directory;
    
    // checks for correct usage, stores directory if so
    if (argv != 2){
        cerr << "Usage: ./treeTraversal Directory" << endl;
        return 1;
    } else {
        directory = argc[1];
    }
    
    // initializes an FSTree and traverses through given directory
    FSTree rootfolder(directory);
    FSTreeTraversal(rootfolder.getRoot(), directory);

    return 0;
}

void FSTreeTraversal(DirNode *rootFolder, string path)
{
    // if directory has no content in it, prints path
    if (not rootFolder->hasSubDir() and not rootFolder->hasFiles()){
            cout << path << endl;
    } else {
        // if directory has files in it
        if (rootFolder->hasFiles()){
            // prints paths to each file
            for (int i = 0; i < rootFolder->numFiles(); i++){
                cout << path << "/" << rootFolder->getFile(i) << endl;
            }
        }
        // if directory has subdirectories
        if (rootFolder->hasSubDir()){
            // recursively calls this function for each subdirectory
            // and updating each subdirectory's path
            for (int i = 0; i < rootFolder->numSubDirs(); i++){
                FSTreeTraversal(rootFolder->getSubDir(i), 
                            path + "/" + rootFolder->getSubDir(i)->getName());
            }
        }
    }
}