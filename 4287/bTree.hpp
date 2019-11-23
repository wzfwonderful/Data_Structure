//
// Created by ZefuWang on 2019-11-14.
//

#ifndef INC_4287_BTREE_HPP
#define INC_4287_BTREE_HPP

#include <iostream>
#include <cstring>

using namespace std;

class bTree{
    struct node{
        char data;
        node *left, *right;

        node():data('\0'), left(nullptr), right(nullptr){}
        explicit node(char d):data(d), left(nullptr), right(nullptr){}
    };

    node *root;

public:

    void recreate_a_btree(char *pre, int prehead, int prerear, char *mid, int midhead, int midrear){
        if()
    }
};



#endif //INC_4287_BTREE_HPP
