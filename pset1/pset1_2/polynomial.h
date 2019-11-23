//
// Created by 王泽夫的小小笔记本 on 2019-10-02.
//

#ifndef PSET1_2_POLYNOMIAL_H
#define PSET1_2_POLYNOMIAL_H

#include <iostream>
using namespace std;

class polynomial{
    friend polynomial& operator+(const polynomial& a, const polynomial& b);

    int node[1000]{0};
    //lazy to new;if data too large, replace the array with a pointer and apply for enough space.
    int maxpower;
public:
    polynomial():maxpower(-1){}
    void add(int coeff, int power);
    //void check();
    void show();
};

polynomial& operator+(const polynomial& a, const polynomial& b){
    static polynomial c;
    int tmp = 0, coeff = 0;
    while(tmp <= a.maxpower || tmp <= b.maxpower){
        coeff = a.node[tmp] + b.node[tmp];
        c.add(coeff, tmp);
        tmp++;
    }
    //c.check();
    return c;
}

void polynomial::add(int coeff, int power){
    maxpower = (power > maxpower ? power : maxpower);
    node[power] += coeff;
}
/*
void polynomial::check(){
    static int i = 0;
    for(; i < maxpower; i++){
        if(abs(node[i]) >= 10){
            node[i+1] = node[i] / 10;
            node[i] = node[i] % 10;
        }
    }
    if(node[maxpower + 1] != 0){
        maxpower++;
        check();
    }
    else return;
}*/

void polynomial::show(){
    bool flag = false;
    for(int i = maxpower; i >= 0; i--){
        if(node[i] != 0){
            cout << node[i] << " " << i << " ";
            flag = true;
        }
    }
    if(!flag) cout << "0 0";
}

#endif //PSET1_2_POLYNOMIAL_H
