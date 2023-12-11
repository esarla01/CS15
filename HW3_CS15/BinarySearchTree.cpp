/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 * By Erin Sarlak
 * 
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

/*
 * name:      BinarySearchTree default constructor
 * purpose:   initialize an empty binary search tree
 * arguments: none
 * returns:   none
 * effects:   root is a nullptr
 */
BinarySearchTree::BinarySearchTree()
{
        root = nullptr;
}

 /*
 * name:      BinarySearchTree destructor
 * purpose:   recycles all heap-allocated data in the binary search tree
 * arguments: none
 * returns:   none
 * effects:   heap is cleared
 */
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  
                         
}

/*
 * name:      New_Node
 * purpose:   Creates a new node whose data is the given value, count is 1
 *            and children point at nullptr.
 * arguments: Value of the data member-variable of the new node
 * returns:   New node
 * effects:   none
 */
BinarySearchTree::Node *BinarySearchTree::new_Node(int value, int count) const{
        //allocate a new node on the heap   
        Node *new_node = new Node;
        //update its member variables
        new_node->data = value;
        new_node->count = count;
        new_node->left = nullptr;
        new_node->right = nullptr;
        //return the node
        return new_node;
}

/*
 * name:      Post_order_delete
 * purpose:   Recursively deletes all Nodes in the tree in a post-order fashion.
 * arguments: Starting node (root)
 * returns:   none
 * effects:   Empties the tree
 */
void BinarySearchTree::post_order_delete(Node *node)
{
        //returns if the tree is empty
        if (root == nullptr) {
                return;
        }
        //returns if the node is a leaf
        else if (node == nullptr) {
                return;
        }
        else {
                post_order_delete(node->left); //recurses through the left of the node
                post_order_delete(node->right); //recurses through the right of the node
                delete node; 
        }
}

/*
 * name:      Copy Constructor
 * purpose:   Use pre-order traversal to copy the tree.
 * arguments: An instance of a tree
 * returns:   none
 * effects:   none
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

/*
 * name:      Assignment Overload Operator
 * purpose:   Perform a deep copy of the tree that’s being copied.
 * arguments: An instance of a tree 
 * returns:   Updated instance of tree
 * effects:   Update the instance of tree
 */
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // check for self-assignment
        if (this == &source) {
                return *this;
        }
        else {
                // delete current tree if it exists
                post_order_delete(root);
                root = nullptr;
                // use pre-order traversal to copy the tree
                if (source.root != nullptr) {
                        root = pre_order_copy(source.root);
                }
                // return *this
                return *this;
        }
}

/*
 * name:      Pre_order_copy
 * purpose:   Recursively copies all Nodes in the tree in a pre-order fashion.
 * arguments: Root of the tree to be copied
 * returns:   A pointer to the root node of the copy-tree
 * effects:   none
 */
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{       
        if (node == nullptr) {
                return nullptr;
        }
        else {
                //create a copy of the node 
                Node *pointer = new_Node(node->data, node->count);
                pointer->left = pre_order_copy(node->left);
                pointer->right = pre_order_copy(node->right);
                return pointer;
        }
}

/*
 * name:      Find_min
 * purpose:   Returns the smallest value stored in the tree. Returns the largest
 *            possible integer if tree is empty
 * arguments: none
 * returns:   the smallest value in the tree
 * effects:   none
 */
int BinarySearchTree::find_min() const
{
        if (root == nullptr) {
                return numeric_limits<int>::max(); // INT_MAX
        }
        else {
                return find_min(root)->data;
        }
}

/*
 * name:      Find_min
 * purpose:   Returns the address of the Node with the smallest data value.
 * arguments: root of the tree
 * returns:   the address of the Node with the smallest data value
 * effects:   none
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        if (node->left == nullptr) {
                return node;
        }
        else {
                return find_min(node->left);
        }
       
}

/*
 * name:      Find_max
 * purpose:   Returns the largest value stored in the tree. Returns the smallest
 *            possible integer if tree is empty
 * arguments: none
 * returns:   largest value in tree
 * effects:   none
 */
int BinarySearchTree::find_max() const
{
        if (root == nullptr){
                return numeric_limits<int>::min(); // INT_MAX
        }
        else {
                return find_max(root)->data;
        }
}

/*
 * name:      Find_max
 * purpose:   Returns the address of the Node with the largest data value.
 * arguments: root of the tree 
 * returns:   address of the Node with the largest data value
 * effects:   none
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        if (node->right == nullptr) {
                return node;
        }
        else {
                return find_max(node->right);
        }
}

/*
 * name:      Contains
 * purpose:   Return true if the tree contains the given value, false otherwise
 * arguments: root of the tree
 * returns:   true if the tree contains the value and false otherwise
 * effects:   none
 */
bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

/*
 * name:      Contains
 * purpose:   Return true if the tree contains the given value, false otherwise
 * arguments: root of the tree and value to be searched
 * returns:   true if the tree contains the value and false otherwise
 * effects:   none
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
        if (node == nullptr) {
                return false;
        }
        else if (value == node->data) {
                return true;
        }
        else if (value < node->data) {
                return contains(node->left, value);
        }
        else {
                return contains(node->right, value);
        }
}
 
/*
 * name:      insert
 * purpose:   if the number is not in the tree inserts a node to the tree with
 *            the given value and count equal to 1 in the correct place but if
 *            the inserting value if already present in the tree, increases the
 *            count in that node
 * arguments: starting node (root)
 * returns:   none
 * effects:   empties the tree
 */
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

/*
 * name:      insert
 * purpose:   if the number is not in the tree inserts a node to the tree with
 *            the given value and count equal to 1 in the correct place but if
 *            the inserting value if already present in the tree, increases the
 *            count in that node
 * arguments: root  node, parent node, value to be inserted
 * returns:   none
 * effects:   empties the tree
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{       //if BST is empty, the root points at the inserted node
        if (root == nullptr){
                root = new_Node(value, 1);
                return;
        }
        //if node is a leaf, insert the new node  
        else if (node == nullptr){
                //insert the new node on the left of the  
                //parent if its value is less than the leaf
                if (value < parent->data){
                      parent->left = new_Node(value, 1);
                }
                //insert the new node on the right of the  
                //parent if its value is more than the leaf
                else if(value > parent->data){
                      parent->right = new_Node(value, 1);
                }
                return;
        }
        else if (value == node->data){ //if the data of the node matches the 
                node->count ++;        //value increment its count by one
                return;
        }
        
        else if (value < node->data){    //recurse through the left of the node
                insert(node->left, node, value);
        }
        else {                           //recurse through the right of the node
                insert(node->right, node, value);
        }  
}

/*
 * name:      remove
 * purpose:   Removes the node with the given value if such node exists within the tree and 
 *            returns true if an element was removed from the tree, false otherwise.
 * arguments: value to be removed
 * returns:   returns true if an element was removed from the tree, false otherwise
 * effects:   updates the tree
 */
bool BinarySearchTree::remove(int value)
{
        if (root == nullptr){  //doesn't remove anything 
              return false;    //if the tree is empty
        }
        else {
                return remove(root, nullptr, value);
        }
}


/*
 * name:      remove
 * purpose:   Removes the node with the given value if such node exists within the tree and 
 *            returns true if an element was removed from the tree, false otherwise.
 * arguments: root  node, parent node, value to be removed
 * returns:   returns true if an element was removed from the tree, false otherwise
 * effects:   updates the tree
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{       //case when the root points at the node with the given value
        if (root == node and node->data == value) {       
                remove_helper_rootnode(node);   
                return true;
        }
        //case when value doesn't exist in the tree
        else if (node == nullptr) {  //doesn't remove if the 
                return false;        //value is not in the tree    
        }
        //case when the node with the value is found more than once within 
        //the tree
        else if (node->data == value and node->count > 1) { 
              node->count --; //decreases the count of the node that is in          
              return true;     //the tree more than once and to be removed
        }
        //case when the node with the given value is a leaf
        else if (node->data == value and tree_height(node) == 0) { 
                remove_helper_0children(node, parent, value);
                return true;
        }
        //case when the node to be removed has one children
        else if ((node->left == nullptr or  node->right == nullptr) 
                                        and node->data == value) {
                remove_helper_1child(node, parent, value);
                return true;
        }
        //case when the node to be removed has two children
        else if (node->left != nullptr and node->right != nullptr 
                                        and node->data == value) {
                remove_helper_2children(node);
                return true;
        }
        else if (value < node->data){    //recurse through the left of the node
                return remove(node->left, node, value);
        }
        else {                           //recurse through the right of the node
                return remove(node->right, node, value);
        }
}

/*
 * name:      remove helper rootnode
 * purpose:   Removes the root node (count > 1 no child, 1 child, 2 children)
 * arguments: root  node
 * returns:   none
 * effects:   updates the tree
 */
void BinarySearchTree::remove_helper_rootnode(Node *node)
{
        if (node->count > 1){
                node->count --;
        }
        else if (tree_height(root) == 0) {
                root = nullptr;
                delete node;
        }
        else if (node->left != nullptr and node->right !=nullptr) {
                remove_helper_2children(node);
        }
        else if (node->left != nullptr or node->right != nullptr) {
                if (node->left != nullptr) {
                        root = node->left;
                }
                else {
                        root = node->right;
                }
                delete node;
        }

}

/*
 * name:      remove helper 0children
 * purpose:   Removes the node with the given value that has no children.
 * arguments: root  node, parent node, value to be removed
 * returns:   none
 * effects:   updates the tree
 */
void BinarySearchTree::remove_helper_0children(Node *node, Node *parent,
                                                                 int value)
{
         if (value < parent->data){ 
                        parent->left = nullptr; 
                } else {
                        parent->right = nullptr; 
                }         
                delete node;   
}

/*
 * name:      remove helper 1child
 * purpose:   Removes the node with the given value that has one only one child.
 * arguments: root  node, parent node, value to be removed
 * returns:   none
 * effects:   updates the tree
 */
void BinarySearchTree::remove_helper_1child(Node *node, Node *parent, 
                                                                int value)
{
        Node  *curr = node;
        if (value < parent->data and node->data == value){
                if (node->left == nullptr){
                         parent->left = curr->right;
                }
                else if(node->right == nullptr){
                        parent->left = curr->left;
                }
                        delete node;    
                }
        else if (value > parent->data and node->data == value){
                if (node->right == nullptr){
                        parent->right = curr->left;
                }
                else if(node->left == nullptr){
                        parent->right = curr->right;
                }
                        delete node; 
                }
}


/*
 * name:      remove helper 2children
 * purpose:   Removes the node with the given value that has two children.
 * arguments: root  node, parent node, value to be removed
 * returns:   none
 * effects:   updates the tree
 */
void BinarySearchTree::remove_helper_2children(Node *node)
{
        //finds the minimum value on the right 
        //subtree of the node to be removed
        int num = find_min(node->right)->data; 
        int count = find_min(node->right)->count;
        //removes the node of the minimum value
        int counter = 0;
        while(counter < count){
                counter++;
                remove(num);
        }
        //minimum value is copied to the node
        node->data = num;
        node->count = count;
}




/*
 * name:      Tree_height
 * purpose:   Returns the height of the root node, which is the length of the
 *            longest path to a leaf from.
 * arguments: none
 * returns:   the height of the root
 * effects:   none
 */
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

/*
 * name:      Tree_height
 * purpose:   Returns the height of the root node, which is the length of the
 *            longest path to a leaf from.
 * arguments: the root of the tree
 * returns:   the height of the root
 * effects:   none
 */
int BinarySearchTree::tree_height(Node *node) const
{
        if (node == nullptr){
                return -1;
        } else {
                return 1 + max(tree_height(node->left), 
                                                tree_height(node->right));
        }
}

/*
 * name:      Tree_height
 * purpose:   Returns the number of Nodes, which represents the number of
 *            distinct values in the tree.
 * arguments: none
 * returns:   the total number of nodes
 * effects:   none
 */
int BinarySearchTree::node_count() const
{       
        if (root == nullptr){
                return 0;
        }
        else {
                return node_count(root);
        }
}

/*
 * name:      Node_count
 * purpose:   Returns the number of Nodes, which represents the number of
 *            distinct values in the tree.
 * arguments: the root of the tree
 * returns:   the total number of nodes
 * effects:   none
 */
int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr){
                return 0;
        }
        else {
                return (1 + node_count(node->left) + node_count(node->right));
        }
}

/*
 * name:      Count_total
 * purpose:   Return the sum of all the node values (including duplicates)
 * arguments: none
 * returns:   the sum of all the node values
 * effects:   none
 */
int BinarySearchTree::count_total() const
{
        if (root == nullptr){
                return 0;
        }
        
        return count_total(root);  
        
}

/*
 * name:      Count_total
 * purpose:   Return the sum of all the node values (including duplicates)
 * arguments: the root of the tree
 * returns:   the sum of all the node values
 * effects:   none
 */
int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr){
                return 0;
        }     
        return ((node->data)*(node->count) + count_total(node->left) + 
                                                count_total(node->right));
}

/*
 * name:      Find_parent (given)
 * purpose:   Find the parent node and return a pointer to the parent node.
 * arguments: root node and child node
 * returns:   return a pointer to the parent node
 * effects:   none
 */
BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

/*
 * name:      Print_tree
 * purpose:   Print a visual representation of the instance of tree.
 * arguments: none
 * returns:   none
 * effects:   none
 */
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}
