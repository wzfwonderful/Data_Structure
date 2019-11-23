//
// Created by ZefuWang on 2019-11-15.
//

#ifndef INC_1221_BST_HPP
#define INC_1221_BST_HPP

#include <iostream>

using namespace std;

class bst{
    struct node{
        int data;
        node *left, *right;

        node():data(0), left(nullptr), right(nullptr){}
        explicit node(int d, node *l = nullptr, node *r = nullptr):data(d), left(l), right(r){}
    };

    node* root;

public:

    bst(){
        root = nullptr;
    }

    ~bst(){
        makeempty(root);
    }

    void find(int x){
        find(x, root);
    }

    void insert(int x){
        insert(x, root);
    }

    void remove(int x){
        remove(x, root);
    }

    void delete_less_than(int x){
        delete_less_than(x, root);
    }

    void delete_more_than(int x){
        delete_more_than(x, root);
    }

    void delete_interval(int a, int b){
        delete_interval(a, b, root);
    }

    void find_ith(int i){
        int array[5000];
        node *tmp;
        int j = 0;
        for(; j < i; j++){
            tmp = find_min(root);
            if(tmp == nullptr) {
                cout << "N";
                break;
            }
            array[j] = tmp->data;
            remove(tmp->data, root);//这里写tmp会错？？？？
        }
        for(int k = 0; k < j; k++){
            insert(array[k], root);
        }

        if(j == i) cout << array[i - 1] << endl;
    }

private:
    //node *&
    void makeempty(node *&t){
        if(t == nullptr) return;
        makeempty(t->left);
        makeempty(t->right);
        //delete t;
        //why after delete root doesn't change
        //important we have to use this way to delete t
        node *tmp = t;
        delete tmp;
        t = nullptr;
    }

    node *find(int x, node *t){
        if(t == nullptr || t->data == x) {
            if(t != nullptr) cout << "Y";
            else cout << "N";
            return t;
        }
        if(x < t->data) find(x, t->left);
        else find(x, t->right);
    }

    //node *&
    void insert(int x, node *t){
        if(t == nullptr) {
            t = new node(x);
            return;
        }
        if(x < t->data) insert(x, t->left);
        else insert(x, t->right);
    }

    //to operate on root, have to use node *&
    void remove(int x, node *&tt){
        if(tt == nullptr) return;
        if(x < tt->data) {
            remove(x, tt->left);
            return;
        }
        else if(x > tt->data) {
            remove(x, tt->right);
            return;
        }

        if(tt->right == nullptr && tt->left == nullptr){
            node *tmp = tt;
            delete tmp;
            tt = nullptr;
        }else if(tt->left != nullptr && tt->right != nullptr){
            node *tmp = tt->right;
            while(tmp->left != nullptr){
                tmp = tmp->left;
            }

            tt->data = tmp->data;
            remove(tmp->data, tmp);
        }else{
            node *tmp = tt;
            if(tt->left != nullptr){
                tt = tt->left;
            }else{
                tt = tt->right;
            }
            delete tmp;
        }
    }

    void delete_interval(int a, int b, node *&t){
        if(t == nullptr) return;
        if(t->data <= a){
            delete_interval(a, b, t->right);
        }
        else if(t->data >= b){
            delete_interval(a, b, t->left);
        }
        else if(t->data > a && t->data < b){
            delete_interval(a, t->data, t->left);
            delete_interval(t->data, b, t->right);
            //
            remove(t->data, t);
        }
    }

    node *find_min(node* t){
        if(t == nullptr) return t;
        while(t->left != nullptr){
            t = t->left;
        }
        return t;
    }

    void delete_more_than(int x, node *&t){
        if(t->data == x) makeempty(t->right);
        else if(t->data < x){
            delete_more_than(x, t->right);
        }
        else if(t->data > x){
            makeempty(t->right);
            delete_more_than(x, t->left);
            //don't forget to remove t;
            remove(x, t);
        }
    }

    void delete_less_than(int x, node *&t){
        if(t->data == x) makeempty(t->left);
        else if(t->data < x){
            makeempty(t->left);
            delete_less_than(x, t->right);
            //don't forget to remove t
            remove(t->data, t);
        }
        else if(t->data > x){
            delete_less_than(x, t->left);
        }
    }
};

#endif //INC_1221_BST_HPP
