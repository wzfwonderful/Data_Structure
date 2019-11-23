//
// Created by ZefuWang on 2019-11-08.
//

#ifndef INC_1111_BTREE_H
#define INC_1111_BTREE_H

#include <iostream>
#include <cstring>

using namespace std;

class bTree{
    char *arr[1000];
    int flag;

public:
    void createBtree(char *pre, char *mid, int n){
        for(int i = 0; i < 1000; i++){
            arr[i] = new char[5];
            arr[i][0] = '\0';
        }
        create_btree(pre, pre + n - 1, mid, mid + n - 1);
        for(int i = 0; i < 1000; i++){
            if(arr[i][0] == '\0'){
                arr[i][0] = 'N';
                arr[i][1] = 'U';
                arr[i][2] = 'L';
                arr[i][3] = 'L';
                arr[i][4] = '\0';
            }else{
                flag = i;
            }
        }
    }

    void print(){
        for(int i = 0; i <= flag; i++) {
            if (i != flag) cout << arr[i] << " ";
            else cout << arr[i];
        }
    }

private:
    void create_btree(char *prebegin, char *preend, char *midbegin, char *midend, int head = 1){
        //
        arr[head - 1][0] = prebegin[0];
        arr[head - 1][1] = '\0';
        if(prebegin == preend) return;

        //find root
        int pos = 0;
        for(int i = 0; i < strlen(midbegin); i++){
            if(midbegin[i] == prebegin[0]){
                pos = i;
                break;
            }
        }

        //create left tree
        if(pos != 0){
            char *leftprebegin, *leftpreend, *leftmidbegin, *leftmidend;
            leftprebegin = prebegin + 1;
            leftpreend = prebegin + pos;
            leftmidbegin = midbegin;
            leftmidend = midbegin + pos - 1;

            create_btree(leftprebegin, leftpreend, leftmidbegin, leftmidend, head*2);
        }

        //create right tree
        if(midbegin + pos != midend){
            char *rightprebegin, *rightpreend, *rightmidbegin, *rightmidend;
            rightprebegin = prebegin + pos + 1;
            rightpreend = preend;
            rightmidbegin = midbegin + pos + 1;
            rightmidend = midend;

            create_btree(rightprebegin, rightpreend, rightmidbegin, rightmidend, head*2 + 1);
        }
    }
};

#endif //INC_1111_BTREE_H
