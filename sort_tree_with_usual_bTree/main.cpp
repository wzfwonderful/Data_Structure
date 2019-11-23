#include "bTree.h"

int main() {
    int N;
    cin >> N;

    int **data = new int*[N];
    for(int i = 0; i < N; i++){
        data[i] = new int[3];
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    bTree A;
    A.create_bTree(N, data);

    A.pre_order();
    cout << endl;

    A.post_order();
    cout << endl;

    A.levelOrder();
    cout << endl;

    return 0;
}