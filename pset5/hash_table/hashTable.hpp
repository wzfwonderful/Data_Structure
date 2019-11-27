//
// Created by ZefuWang on 2019-11-27.
//

#ifndef HASH_TABLE_HASHTABLE_HPP
#define HASH_TABLE_HASHTABLE_HPP

#include <iostream>

using namespace std;

class hashTable{

    int **array;
    int size, key;

public:

    hashTable(int s, int k):size(s), key(k){
        array = new int*[size];
        for(int i = 0; i < size; i++) {
            array[i] = new int[2];
            array[i][0] = -1;
            array[i][1] = 0;
        }
    }

    ~hashTable(){
        for(int i = 0; i < size; i++) {
            delete []array[i];
        }
        delete []array;
    }

    void insert(int x){
        int pos = hashfuction(x);

        int count = 1;
        while(array[pos][0] != -1){
            pos = (pos + 1) % size;
            count++;
        }

        array[pos][0] = x;
        array[pos][1] = count;
    }

    void display(){
        for(int i = 0; i < size; i++) {
            cout << i << " ";
        }
        cout << endl;

        for(int i = 0; i < size; i++) {
            cout << array[i][0] << " ";
        }
        cout << endl;

        for(int i = 0; i < size; i++) {
            cout << array[i][1] << " ";
        }
        cout << endl;
    }

private:

    int hashfuction(int x){
        return (x % key);
    }
};

#endif //HASH_TABLE_HASHTABLE_HPP
