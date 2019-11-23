#include "deque.hpp"

int main() {
    int N, **array;
    cin >> N;
    array = new int*[N - 1];
    for(int i = 0; i < N - 1; i++){
        array[i] = new int[2];
        array[i][1] = 0;
    }

    for(int i = 0; i < N - 1; i++){
        cin >> array[i][0];
    }

    deque q;
    q.enQueue(0);
    int flag;
    while(!q.isEmpty()){
        flag = 0;
        int tmp = q.deQueue();
        for(int i = 0; i < N - 1; i++){
            if(array[i][1] == 1) continue;
            if(tmp == array[i][0]){
                array[i][1] = 1;
                q.enQueue(i + 1);
                flag++;
            }
            if(flag == 2) break;
        }
        if(flag != 2) break;
    }

    int i = 0;
    for(; i < N - 1; i++){
        if(array[i][1] == 0) break;
    }
    if(i == N - 1) cout << "true";
    else cout << "false";

    for(int j = 0; j < N - 1; j++){
        delete []array[j];
    }
    delete []array;
    return 0;
}