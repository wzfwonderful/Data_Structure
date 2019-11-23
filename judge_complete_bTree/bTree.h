//
// Created by ZefuWang on 2019-11-04.
//

#ifndef JUDGE_COMPLETE_BTREE_BTREE_H
#define JUDGE_COMPLETE_BTREE_BTREE_H

#include <iostream>
#include <queue>
using namespace std;

class bTree{
    struct node{
        node *left, *right, *parent;
        int num;

        node():num(0), left(nullptr), right(nullptr), parent(nullptr){}
        explicit node(int n, node *L = nullptr, node *R = nullptr):num(n), left(L), right(R), parent(nullptr){}
    };

    struct deque{
        struct Node{
            node *data;
            Node *next;

            Node():data(), next(nullptr){}
            explicit Node(node *t):data(t),next(nullptr){}//copy_constructor?
        };

        Node *head, *rear;

        deque(){
            head = rear = new Node;
        }

        ~deque(){
            while(head != rear){
                deQueue();
            }
            delete head;
        }

        bool is_Empty(){
            return head == rear;
        }

        void enQueue(node *t){
            Node *tmp = rear;
            rear = new Node(t);
            tmp->next = rear;
        }

        node* deQueue(){
            node *tmp1 = head->next->data;
            Node *tmp2 = head;
            head = head->next;
            delete tmp2;
            return tmp1;
        }
    };

    node *root;
public:
    ~bTree(){
        clear(root);
    }

    void create_bTree(int** a, int N){
        node *nodelist[100000];
        //如果这样写应该如何删除？
        //nodelist = new node*[N];
        for(int i = 0; i < N; i++){
            nodelist[i] = new node(i + 1);
        }

        //存在问题，如果爷爷结点先于（父亲指向儿子子节点）这个过程指向了父亲节点，那么根节点查找失败
        //root = nodelist[0];
        for(int i = 0; i < N; i++){
            /*if(a[i][0] == root->num || a[i][1] == root->num){
                root = nodelist[i];
            }*/

            if(a[i][0] == 0){
                nodelist[i]->left = new node(0);
            }else{
                nodelist[i]->left = nodelist[a[i][0] - 1];
                nodelist[a[i][0] - 1]->parent = nodelist[i];
            }
            if(a[i][1] == 0) {
                nodelist[i]->right = new node(0);
            }else{
                nodelist[i]->right = nodelist[a[i][1] - 1];
                nodelist[a[i][1] - 1]->parent = nodelist[i];
            }

            //cout << nodelist[i]->left->num << " " << nodelist[i]->right->num << endl;
        }

        //find root
        root = nodelist[0];
        while(root->parent != nullptr){
            root = root->parent;
        }
    }

    void levelorder_check(int *result){
        deque q;
        q.enQueue(root);
        node *tmp;
        int i = 0;

        while(!q.is_Empty()){
            tmp = q.deQueue();
            //cout << tmp->num << endl;
            result[i++] = tmp->num;
            if(tmp->left != nullptr){
                q.enQueue(tmp->left);
            }
            if(tmp->right != nullptr){
                q.enQueue(tmp->right);
            }
        }
    }

private:
    void clear(node *t){
        if(t == nullptr) return;
        clear(t->left);
        clear(t->right);
        delete t;
        t = nullptr;
    }
};


#endif //JUDGE_COMPLETE_BTREE_BTREE_H
