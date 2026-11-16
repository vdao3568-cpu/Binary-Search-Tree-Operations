/**
 * Name: Vincent Dao
 * Made: 11/15/26
 * Last Modified: 11/15/26
 * Honor Clause: I have not used any AI without specifying or have plagorized any work without permission
 * AI Usage: GPT-5.6 Luna for implementation of testing and fulfilling assignment conditions
 */
#include "BinarySearchTree.h"
#include <iostream>

int main() {
    BinarySearchTree tree;

    // Insert 10 distinct integers.
    int values[] = {50, 30, 70, 20, 40, 60, 80, 65, 10, 35};

    for (int value : values) {
        tree.insert(value);
    }

    cout << "Initial inorder traversal: ";
    tree.inorder();
    // 10 20 30 35 40 50 60 65 70 80

    // Demostrate searching for one present key and one absent key.
    cout << boolalpha;
    cout << "Search for 40: " << tree.search(40) << '\n';
    cout << "Search for 99: " << tree.search(99) << '\n';

    // Remove a leaf node
    cout << "\nRemoving leaf node 10:\n";
    tree.remove(10);
    tree.inorder();
    // 20 30 35 40 50 60 65 70 80

    // Remove a node with one child
    // Node 60 has only one child: 65
    cout << "\nRemoving node with one child, 60:\n";
    tree.remove(60);
    tree.inorder();
    // 20 30 35 40 50 65 70 80

    // Remove a node with two children
    // Node 30 has two children: 20 and 40
    cout << "\nRemoving node with two children, 30:\n";
    tree.remove(30);
    tree.inorder();
    
    return 0;
    /**
     * Expected Output:
        Initial inorder traversal: 10 20 30 35 40 50 60 65 70 80
        Search for 40: true
        Search for 99: false

        Removing leaf node 10:
        20 30 35 40 50 60 65 70 80

        Removing node with one child, 60:
        20 30 35 40 50 65 70 80

        Removing node with two children, 30:
        20 35 40 50 65 70 80
     */
}