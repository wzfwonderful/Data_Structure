#include "bTree.h"

int main() {
    int N = 0;
    cin >> N;
    int **arr;
    arr = new int*[N];
    for(int i = 0; i < N; i++) {
        arr[i] = new int[2]{0};
    }

    for(int i = 0; i < N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    bTree A;
    A.create_bTree(arr, N);

    int result[1000000]{0};
    A.levelorder_check(result);

    bool flag = true;
    for(int i = 0; i < N; i++){
        if(result[i] == 0){
            flag = false;
            break;
        }
    }
    if(!flag) cout << "N";
    else cout << "Y";

    for(int i = 0; i < N; i++){
        delete arr[i];
    }
    delete []arr;
    return 0;
}