//
// Created by ZefuWang on 2019-11-07.
//

#ifndef SORT_TREE_HOMEWORK_BTREE_H
#define SORT_TREE_HOMEWORK_BTREE_H

#include <iostream>

using namespace std;

class bTree{
    struct node{
        int weight;
        node *son, *bro, *parent, *leftbro;

        node():weight(0), son(nullptr), bro(nullptr), parent(nullptr){}
        explicit node(int w):weight(w), son(nullptr), bro(nullptr), parent(nullptr), leftbro(nullptr){}
    };

    struct btstack{
        int top;
        node *stack[100000];

        btstack():top(-1){}

        bool isEmpty(){
            return top == -1;
        }

        void push(node *t){
            stack[++top] = t;
        }

        node *pop(){
            top--;
            return stack[top + 1];
        }
    };

    struct btdeque{
        struct Node{
            node *data;
            Node *next;
        };

        Node *head, *rear;

        btdeque(){
            head = new Node;
            rear = head;
        }

        ~btdeque(){
            delete head;
        }

        void enqueue(node *t){
            Node *tmp = rear;
            rear = new Node;
            rear->data = t;
            tmp->next = rear;
        }

        node *dequeue(){
            Node *tmp = head;
            head = head->next;
            node *result = head->data;
            tmp->data = nullptr;
            delete tmp;
            return result;
        }

        bool isEmpty(){
            return head == rear;
        }
    };

    node *root;

public:
    ~bTree(){
        clear(root);
    }

    void create_bTree(int N, int ** a){
        node *nodelist[N];

        for(int i = 0; i < N; i++) {
            nodelist[i] = new node;
            nodelist[i]->weight = a[i][2];
        }

        for(int i = 0; i < N; i++) {
            if(a[i][0] != 0){
                nodelist[i]->son = nodelist[a[i][0] - 1];
                nodelist[a[i][0] - 1]->parent = nodelist[i];
            }
            if(a[i][1] != 0){
                nodelist[i]->bro = nodelist[a[i][1] - 1];
                nodelist[a[i][1] - 1]->leftbro = nodelist[i];
            }
        }

        root = nodelist[0];
        while(root->parent != nullptr || root->leftbro != nullptr){
            if(root->parent != nullptr) {
                root = root->parent;
            }else{
                root = root->leftbro;
            }
        }
    }

    void preOrder(){
        preorder(root);
    }

    void postOrder(){
        postorder(root);
    }

    //very important
    void levelOrder_recursion(){
        //cout << "height:" << height(root) << endl;
        int depth = height(root);

        for(int i = 0; i < depth; i++) {
            levelorder_r(root, i + 1);
        }
    }

    void levelOrder_deque(){
        levelorder_d(root);
    }

private:
    void clear(node *t){
        if(t == nullptr) return;
        clear(t->son);
        clear(t->bro);
        delete t;
        t = nullptr;
    }

    void preorder(node *t){
        btstack s;
        s.push(t);

        node *tmp = nullptr;
        while(!s.isEmpty()){
            tmp = s.pop();
            cout << tmp->weight << " ";

            // right way to deal with bro
            if(tmp->bro != nullptr){
                s.push(tmp->bro);
            }
            //wrong way as follow
            /*btstack brother;
            while(tmp->bro != nullptr){
                tmp = tmp->bro;
                brother.push(tmp);
            }
            while(!brother.isEmpty()){
                s.push(brother.pop());
            }*/

            if(tmp->son != nullptr){
                s.push(tmp->son);
            }
        }
    }

    void postorder(node *t){
        if(t == nullptr) return;
        else{
            postorder(t->son);
            cout << t->weight << " ";
            postorder(t->bro);
        }
    }

    int height(node *t){
        //difficult?
        if(t == nullptr) return 0;
        else{
            node *tmp = t;
            int max = -1;
            int h;
            while(tmp != nullptr){
                h = height(tmp->son);
                max = h > max ? h : max;
                tmp = tmp->bro;
            }
            return 1 + max;
        }
    }

    //use two way: recursion or none_recursion
    void levelorder_r(node *t, int height){
        if(t == nullptr || height == 0) return;
        else if(height == 1){
            while(t != nullptr){
                cout << t->weight << " ";
                t = t->bro;
            }
        }else{
            while(t != nullptr){
                levelorder_r(t->son, height - 1);
                t = t->bro;
            }
        }
    }

    void levelorder_d(node *t){
        btdeque d;
        d.enqueue(t);

        node *tmp;
        while(!d.isEmpty()){
            tmp = d.dequeue();
            while(tmp != nullptr){
                cout << tmp->weight << " ";
                if(tmp->son != nullptr){
                    d.enqueue(tmp->son);
                }
                tmp = tmp->bro;
            }
        }
    }
};

#endif //SORT_TREE_HOMEWORK_BTREE_H
