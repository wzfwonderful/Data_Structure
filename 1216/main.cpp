#include "priorityQueue.hpp"
#include <cstring>

int main() {
    int M = 0;
    cin >> M;

    priority_queue A;
    char direction[10];
    char list[3][10]={"insert", "find", "decrease"};
    for(int i = 0; i < M; i++){
        cin >> direction;
        if(strcmp(direction,list[0]) == 0){
            int x;
            cin >> x;
            A.enQueue(x);
        }
        if(strcmp(direction,list[1]) == 0){
            int x;
            cin >> x;
            cout << A.find(x) << endl;
        }
        if(strcmp(direction,list[2]) == 0){
            int m, v;
            cin >> m >> v;
            A.decrease(m, v);
        }
    }
    return 0;
}