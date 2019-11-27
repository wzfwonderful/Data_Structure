//
// Created by ZefuWang on 2019-11-27.
//

#ifndef BINARY_SEARCH_TREE_BST_HPP
#define BINARY_SEARCH_TREE_BST_HPP

#include <iostream>

using namespace std;

class bst{
    struct node{
        int key;
        node *left, *right;

        explicit node(int n):key(n), left(nullptr), right(nullptr){};
    };

    node *root;

public:

    bst(){
        root = nullptr;
    }

    ~bst(){
        clear_tree(root);
    }

    void insert(int x){
        insert(x, root);
    }

private:

    void clear_tree(node *t){
        if(t == nullptr) return;

        clear_tree(t->left);
        clear_tree(t->right);

        node* oldnode = t;
        delete oldnode;
        t = nullptr;
    }

    void insert(int x, node *&t){
        if(root == nullptr) {
            root = new node(x);
            cout << "-1" << endl;
            return;
        }

        if(t == nullptr) {
            t = new node(x);
            return;
        }

        if(x < t->key) {
            if(t->left == nullptr) cout << t->key << endl;
            insert(x, t->left);
        } else {
            if(t->right == nullptr) cout << t->key << endl;
            insert(x, t->right);
        }
    }
};

#endif //BINARY_SEARCH_TREE_BST_HPP
