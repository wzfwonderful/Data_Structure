//
// Created by Zefu Wang on 2019-10-24.
// for Data_structure pset2

#ifndef DISTRIBUTION_DISTRIBUTE_H
#define DISTRIBUTION_DISTRIBUTE_H

#include <iostream>

using namespace std;

class station {
private:
    int room[1000];
    int currentsize;
    int maxsize;

public:

    explicit station(int roomsize) : maxsize(roomsize) {
        currentsize = 0;
    }

    bool push(int no) {
        room[currentsize] = no;
        currentsize++;
        return true;
    }

    void pop() {
        currentsize--;
    }

    int top() {
        return room[currentsize - 1];
    }

    bool isFull() {
        return (currentsize == maxsize);
    }

    bool isEmpty() {
        return (currentsize == 0);
    }

    /*bool operation_1(int no) {
        if (isFull()) {
            return false;
        } else {
            room[currentsize - 1] = no;
            currentsize++;
            return true;
        }
    }

    int operation_2() {
        if (isEmpty()) {
            return -1;
        } else {
            currentsize--;
            return room[currentsize];
        }
    }

    int operation_3(int no) {
        return no;
    }*/

};

#endif //DISTRIBUTION_DISTRIBUTE_H
