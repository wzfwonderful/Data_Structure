//
// Created by ZefuWang on 2019-11-11.
//

#ifndef INC_4252_RIGHT_WAY_PRIORITYQUEUE_HPP
#define INC_4252_RIGHT_WAY_PRIORITYQUEUE_HPP

#include <iostream>
using namespace std;

class priority_queue{
    struct node{
        int num, order;
    };
    node *data;
    int currentsize, maxsize;

public:
    priority_queue(const int *a, const int *b, int size):maxsize(size + 1){
        currentsize = size;
        data = new node[maxsize];

        for(int i = 0; i < currentsize; i++){
            data[i + 1].num = a[i];
            data[i + 1].order = b[i];
        }

        buildheap();
    }

    ~priority_queue(){
        delete []data;
    }

    bool isEmpty(){
        return currentsize == 0;
    }

    void enQueue(int t, int o){
        currentsize++;
        if(currentsize == maxsize) doublespace();

        data[currentsize].num = t;
        data[currentsize].order = o;
        for(int i = currentsize; i > 1; i /= 2){
            if(data[i / 2].num > data[i].num){
                data[i].num = data[i / 2].num;
                data[i / 2].num = t;

                int tmp = data[i].order;
                data[i].order = data[i / 2].order;
                data[i / 2].order = tmp;
            }
        }
    }

    int deQueue(){
        int minItem = data[1].num, minOrder = data[1].order;
        data[1].num = data[currentsize].num;
        data[1].order = data[currentsize--].order;
        percolateDown(1);

        cout << minItem << " ";
        return minOrder;
    }

private:

    void buildheap(){
        for(int i = currentsize / 2; i > 0; i--){
            percolateDown(i);
        }
    }

    void percolateDown(int current){
        int child, tmp = data[current].num;

        for(; current * 2 <= currentsize; current = child){
            child = current * 2;
            if(child + 1 <= currentsize && data[child + 1].num < data[child].num){
                child++;
            }
            if(data[child].num < tmp){

                data[current].num = data[child].num;
                data[child].num = tmp;

                int t = data[current].order;
                data[current].order = data[child].order;
                data[child].order = t;
            }else break;
        }
    }

    void doublespace(){
        node *tmp = data;
        maxsize *= 2;
        data = new node[maxsize];

        for(int i = 0; i < currentsize; i++){
            data[i + 1].num = tmp[i + 1].num;
            data[i + 1].order = tmp[i + 1].order;
        }
        delete []tmp;
    }


};

#endif //INC_4252_RIGHT_WAY_PRIORITYQUEUE_HPP
