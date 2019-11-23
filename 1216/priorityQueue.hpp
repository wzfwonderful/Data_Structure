//
// Created by ZefuWang on 2019-11-10.
//

#ifndef INC_1216_PRIORITYQUEUE_HPP
#define INC_1216_PRIORITYQUEUE_HPP

#include <iostream>

using namespace std;

class priority_queue {

    int *queue;
    int currentsize, maxsize;

public:

    explicit priority_queue(int capacity = 10) : maxsize(capacity + 1) {
        currentsize = 0;
        queue = new int[maxsize];
    }

    priority_queue(const int *data, int size) : maxsize(size + 1) {

        queue = new int[maxsize];
        for (int i = 0; i < size; i++) {
            queue[i + 1] = data[i];
        }

        currentsize = size;
    }

    void enQueue(int data) {

        currentsize++;
        if (currentsize == maxsize) doublespace();

        queue[currentsize] = data;
        for (int i = currentsize; i > 1 && data < queue[i / 2]; i /= 2) {
            queue[i] = queue[i / 2];
            queue[i / 2] = data;
        }
    }

    int find(int x) {
        int tmp = 0, num = 0;
        for (int i = 1; i <= currentsize; i++) {
            if (num == 0 && queue[i] > x) {
                num = i;
                tmp = queue[i];
            }
            if(num != 0 && queue[i] > x && queue[i] < tmp){
                num = i;
                tmp = queue[i];
            }
        }
        return num;
    }

    void decrease(int i, int v) {
        queue[i] -= v;

        int tmp = queue[i];
        for (int m = i; i > 1 && queue[i] < queue[i / 2]; i /= 2) {
            queue[i] = queue[i/2];
            queue[i/2] = tmp;
        }
    }

private:

    void doublespace() {
        int *tmp = queue;
        maxsize *= 2;

        queue = new int[maxsize];
        for (int i = 0; i < currentsize; i++) {
            queue[i + 1] = tmp[i + 1];
        }

        delete[]tmp;
    }


};

#endif //INC_1216_PRIORITYQUEUE_HPP
