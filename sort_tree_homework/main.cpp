#include "bTree.h"

int main() {
    int N;
    cin >> N;
    int **arr;
    arr = new int*[N];

    for(int i = 0; i < N; i++){
        arr[i] = new int[3];
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    bTree A;
    A.create_bTree(N, arr);

    A.preOrder();

    cout << endl;
    A.postOrder();

    cout << endl;
    A.levelOrder_recursion();

    //cout << endl;
    //A.levelOrder_deque();

    for(int i = 0; i < N; i++){
        delete []arr[i];
    }
    delete []arr;

    return 0;
}