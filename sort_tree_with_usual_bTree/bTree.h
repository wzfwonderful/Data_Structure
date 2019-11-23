//
// Created by ZefuWang on 2019-11-04.
//

#ifndef SORT_TREE_BTREE_H
#define SORT_TREE_BTREE_H

#include <iostream>

using namespace std;

class bTree{
    struct node{
        int data, order;// however order is not necessary
        node *left, *right, *parent;

        node(): order(0), data(0), left(nullptr), right(nullptr), parent(nullptr){}
        node(int O, int D, node * L = nullptr, node *R = nullptr):
            order(O), data(D), left(L), right(R), parent(nullptr){}
    };

    struct btstack{
        node *stack[200000]{nullptr};
        int top;

        btstack():top(-1){}

        bool isEmpty(){
            return top == -1;
        }

        void push(node *t){
            stack[++top] = t;
        }

        node* pop(){
            top--;
            return stack[top + 1];
        }
    };

    node *root;
public:
    ~bTree(){
        clear(root);
    }

    void create_bTree(int N, int **a){
        node *nodelist[100000];

        for(int i = 0; i < N; i++){
            nodelist[i] = new node(i + 1, a[i][2]);
        }

        for(int i = 0; i < N; i++){
            if(a[i][0] != 0){
                nodelist[i]->left = nodelist[a[i][0] - 1];
                nodelist[a[i][0] - 1]->parent = nodelist[i];
            }
            if(a[i][1] != 0){
                nodelist[i]->right = nodelist[a[i][1] - 1];
                nodelist[a[i][1] - 1]->parent = nodelist[i];
            }
        }

        //find root
        root = nodelist[0];
        while(root->parent != nullptr){
            root = root->parent;
        }
    }

    void levelOrder(){
        int depth = height(root);

        for(int i = 0; i < depth; i++){
            level_order_size_n(root, i + 1);
        }
    }

    void pre_order(){
        preOrder(root);
    }

    void post_order(){
        postOrder(root);
    }


private:
    void clear(node *t){
        if(t == nullptr) return;
        clear(t->left);
        clear(t->right);
        delete t;
        t = nullptr;
    }

    void level_order_size_n(node *t, int n){
        if(t == nullptr || n == 0) return;//n == 0 is necessary?
        if(n == 1) {
            cout << t->data << " ";
            return;
        }
        if(n > 1){
            level_order_size_n(t->left, n - 1);
            level_order_size_n(t->right, n - 1);
        }
    }

    int height(node *t){
        if(t == nullptr) return 0;
        else{
            int lh = height(t->left), rh = height(t->right);
            return 1 + (lh > rh ? lh : rh);
        }
    }

    void postOrder(node *t){
        if(t == nullptr) return;
        else{
            postOrder(t->left);
            postOrder(t->right);
            cout << t->data << " ";
        }
    }

    void preOrder(node *t){
        btstack s;
        s.push(t);

        node *current = nullptr;
        while(!s.isEmpty()){
            current = s.pop();
            cout << current->data << " ";
            if(current->right != nullptr){
                s.push(current->right);
            }
            if(current->left != nullptr){
                s.push(current->left);
            }
        }
    }
};

#endif //SORT_TREE_BTREE_H
