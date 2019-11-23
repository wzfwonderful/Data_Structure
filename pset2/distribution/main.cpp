#include "distribute.h"

int main() {
    // get input and initialize
    int T, N[300], M[300], order[300][1000];
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N[i] >> M[i];
        for(int j = 0; j < N[i]; j++) {
            cin >> order[i][j];
        }
    }

    // judgement flag
    bool flag[T];
    for(int i = 0; i < T; i++) {
        flag[i] = true;
    }

    // simulate the process
    for(int i = 0; i < T; i++) {
        station city(M[i]);

        //try for every car
        for(int No = 0, current = 0; No < N[i]; No++){
            // car in station go out first if possible
            while(!city.isEmpty() && city.top() == order[i][current]){
                city.pop();
                current++;
            }

            if(No == order[i][current]){
                //operation_3
                current++;
                if(No != N[i] - 1) continue;
            }else if(city.isFull()){
                flag[i] = false;
                break;
            }else {
                city.push(No);
            }

            if(No == N[i] - 1) {
                while(!city.isEmpty()) {
                    if(city.top() != order[i][current]){
                        flag[i] = false;
                        break;
                    }else{
                        city.pop();
                        current++;
                    }
                }
            }
        }
        if(!flag[i]) continue;
    }

    for(int i = 0; i < T; i++){
        if(flag[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}