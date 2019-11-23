//
// Created by ZefuWang on 2019-11-12.
//

#ifndef INC_1043_DEQUE_HPP
#define INC_1043_DEQUE_HPP

#include <iostream>

using namespace std;

class deque{
    int array[1000000];
    int head, rear;
public:
    deque():head(0), rear(0){}

    void enQueue(int data){
        array[++rear] = data;
    }

    int deQueue(){
        head++;
        return array[head];
    }

    bool isEmpty(){
        return head == rear;
    }
};

#endif //INC_1043_DEQUE_HPP
