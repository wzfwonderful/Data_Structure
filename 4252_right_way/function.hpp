//
// Created by ZefuWang on 2019-11-11.
//

#ifndef INC_4252_RIGHT_WAY_FUNCTION_HPP
#define INC_4252_RIGHT_WAY_FUNCTION_HPP

#include <iostream>
using namespace std;

class function_f{
    int a, b, c;
    int mid, type, n;

public:

    function_f():n(0){}

    void create_function(int x, int y, int z){
        a = x;
        b = y;
        c = z;
        mid = (-1) * b / (2 * a);
        //c++负数取模：-7/4 = -1
        if(b > 0) mid -= 1;

        int value1 = a * mid * mid + b * mid + c;
        int value2 = a * (mid + 1) * (mid + 1) + b * (mid + 1) + c;

        if(value1 <= value2) type = 0;
        else type = 1;
    }

    int getNext(){
        int step = 0, next = 0;

        if(type == 0){
            if(n % 2 == 0) step = -1;
            else step = 1;

            next = getfuc(mid + ((n + 1) / 2) * step);
        }

        if(type == 1){
            if(n % 2 == 0) step = 1;
            else step = -1;

            next = getfuc(mid + 1 + ((n + 1) / 2) * step);
        }

        n++;
        return next;
    }

private:
    int getfuc(int x){
        return a * x * x + b * x + c;
    }
};

#endif //INC_4252_RIGHT_WAY_FUNCTION_HPP
