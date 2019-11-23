#include <iostream>
#include <cstring>

using namespace std;

void postorder(char *pre, char *mid, int size);

int main() {
    char preorder[1000]{'\0'}, midorder[1000]{'\0'};
    cin >> preorder >> midorder;

    postorder(preorder, midorder, strlen(preorder));

    return 0;
}

void postorder(char *pre, char *mid, int size){
    //size == 0 必须单独分出来，否则在else中会出现数组越界
    if(size == 0) return;
    //size == 1可以和else合并
    if(size == 1) {
        cout << *pre;
        return;
    }
    else{
        char head = *pre;
        int leftsize = 0;
        for(int i = 0; i < size; i++){
            if(head == mid[i]){
                leftsize = i;
                break;
            }
        }

        postorder(pre + 1, mid, leftsize);
        postorder(pre + leftsize + 1, mid + leftsize + 1, size - leftsize - 1);

        cout << *pre;
        return;
    }
}