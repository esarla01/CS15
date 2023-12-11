/*
 *  CharLinkedList.h
 *  Erin Sarlak
 *  February 3, 2021
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  This file contains the definition of the CharLinkedList class.
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <string>

class CharLinkedList {


public:
    CharLinkedList();

    CharLinkedList(char c);

    CharLinkedList(char arr[], int size);

    CharLinkedList(const CharLinkedList &other);

    ~CharLinkedList();

    bool isEmpty() const;

    CharLinkedList &operator=(const CharLinkedList &other);

    void clear();

    int size () const;

    char first() const;

    char last() const;

    void pushAtFront(char c);

    void pushAtBack(char c);

    char elementAt(int index) const;

    void popFromFront();

    void popFromBack();

    void insertAt(char c, int index);

    void removeAt(int index);

    std::string toString() const;

    std::string toReverseString() const;

    void insertInOrder(char c);

    void replaceAt(char c, int index);

    void concatenate(CharLinkedList *other);
    


private:
    struct Node{
        char data;
        Node *next;
        Node *prev;
    };

    Node *front;
    Node *back;

    unsigned int list_length;

    Node *new_Node (char newData, 
                                Node *newNext, Node *newPrev);
    
    void recycleRecursive(Node *currNode);

    char recursiveElementAt(int index, Node *currNode) const;

    void recursivereplaceAt(char c, int index, Node *currNode);


};
#endif
