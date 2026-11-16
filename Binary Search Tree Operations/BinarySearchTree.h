/**
 * Name: Vincent Dao
 * Made: 11/15/26
 * Last Modified: 11/15/26
 * Honor Clause: I have not used any AI without specifying or have plagorized any work without permission
 * AI Usage: GPT-5.6 Luna for usage of a Node in a private part of BinarySearchTree
 */
#include <algorithm>
#include <iostream>

using namespace std;

class BinarySearchTree {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;

            explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
        };

        Node* root = nullptr;

        static Node* insert(Node* node, int value) {
            if (node == nullptr) {
                return new Node(value);
            }

            if (value < node -> data) {
                node -> left = insert (node -> left, value);
            }

            else if (value > node -> data) {
                node -> right = insert (node -> right, value);
            }

            return node; 
        }

        static bool search(const Node* node, int value) {
            if (node == nullptr) {
                return false;
            }

            if (value == node -> data) {
                return true;
            }

            return value < node -> data ? search (node -> left, value) : search (node -> right, value);
        }

        static Node* findMin(Node* node) {
            if (node == nullptr) {
                return nullptr;
            }

            while (node -> left != nullptr) {
                node = node -> left;
            }

            return node;
        }

        static Node* remove(Node* node, int value) {
            if (node == nullptr) {
                return nullptr;
            }

            if (value < node -> data) {
                node -> left = remove (node -> left, value);
            }

            else if (value > node -> data) {
                node -> right = remove (node -> right, value);
            }

            else {
                if (node -> left == nullptr && node -> right == nullptr) {
                    delete node;
                    return nullptr;
                }

                if (node -> left == nullptr) {
                    Node* child = node -> right;
                    delete node;
                    return child;
                }

                if (node -> right == nullptr) {
                    Node* child = node -> left;
                    delete node;
                    return child;
                }

                Node* successor = findMin(node -> right);
                node -> data = successor -> data;
                node -> right = remove(node -> right, successor -> data);
            }

            return node;
        }

        static void inorder (const Node* node) {
            if (node == nullptr) {
                return;
            }

            inorder(node -> left);
            cout << node -> data << ' ';
            inorder(node -> right);
        }

        static void preorder (const Node* node) {
            if (node == nullptr) {
                return;
            }

            cout << node -> data << ' ';
            preorder(node -> left);
            preorder(node -> right);
        }

        static void postorder (const Node* node) {
            if (node == nullptr) {
                return;
            }

            postorder(node -> left);
            postorder(node -> right);
            cout << node -> data << ' ';
        }

        static int height (const Node* node) {
            if (node==nullptr) return -1;
            return 1 + max(height(node->left),height(node->right));
        }

        static void clear(Node* node) {
            if (node == nullptr) return;
            clear(node -> left);
            clear(node -> right);
            delete node;
        }

        public:
            BinarySearchTree() = default;
            ~BinarySearchTree() {
                clear(root);
            }

            BinarySearchTree(const BinarySearchTree&) = delete;
            BinarySearchTree& operator=(const BinarySearchTree&) = delete;

            void insert(int value) {
                root = insert(root, value);
            }

            bool search(int value) const {
                return search(root, value);
            }

            void remove (int value) {
                root = remove (root, value);
            }

            void inorder() const {
                inorder(root);
                cout << '\n';
            }

            void preorder() const {
                preorder(root);
                cout << '\n';
            }

            void postorder() const {
                postorder(root);
                cout << '\n';
            }

            int height() const {
                return height(root);
            }
};