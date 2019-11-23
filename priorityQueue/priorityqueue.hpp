//
// Created by ZefuWang on 2019-11-10.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_PRIORITYQUEUE_HPP

#include <iostream>

using namespace std;

template <class Type>
class priority_queue{

    Type *array;
    int currentsize;
    int maxsize;

public:

    explicit priority_queue(int capacity = 10):maxsize(capacity + 1){
        array = new Type[maxsize];
        currentsize = 0;
    }

    priority_queue(const Type data[], int size):maxsize(size + 10){
        array = new Type[maxsize];
        currentsize = size;

        for(int i = 0; i < size; i++) {
            array[i + 1] = data[i];
        }

        buildheap();
    }

    ~priority_queue(){
        delete []array;
    }

    void enqueue(Type t){

        currentsize++;
        if(currentsize == maxsize) doublespace();

        array[currentsize] = t;
        percolateUp(currentsize);
    }

    Type dequeue(){
        Type min = array[1];
        array[1] = array[currentsize--];

        percolateDown(1);

        return min;
    }

    Type getHead(){
        return array[1];
    }

    bool isEmpty(){
        return currentsize == 0;
    }

    void levelOrder(){
        for(int i = 0; i < currentsize; i++){
            cout << array[i + 1] << " ";
        }
    }
private:

    void buildheap(){
        for(int i = currentsize / 2; i > 0; i--) {
            percolateDown(i);
        }
    }

    void doublespace(){

        Type *tmp = array;
        array = new Type[2 * maxsize];

        for(int i = 0; i < maxsize; i++){
            array[i] = tmp[i];
        }

        maxsize *= 2;
    }

    void percolateDown(int current){
        int child, tmp = array[current];

        for(;current * 2 <= currentsize; current = child){
            child = current * 2;
            if(child != currentsize && array[child + 1] < array[child]){
                child++;
            }
            if(array[child] < tmp){
                array[current] = array[child];
            }else break;
        }

        array[current] = tmp;
    }

    void percolateUp(int current){

        int tmp = array[current];

        while(current / 2 > 0 && array[current / 2] > tmp){
            array[current] = array[current / 2];
            current /= 2;
        }

        array[current] = tmp;
    }
};

#endif //PRIORITYQUEUE_PRIORITYQUEUE_HPP
