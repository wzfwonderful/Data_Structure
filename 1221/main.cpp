#include "bst.hpp"
#include <string>

int main() {
    int n;
    cin >> n;

    bst A;
    string direction;
    for(int i = 0; i < n; i++){
        cin >> direction;
        if(direction == "insert") {
            int x;
            cin >> x;
            A.insert(x);
        }
        else if(direction == "find") {
            int x;
            cin >> x;
            A.find(x);
        }
        else if(direction == "find_ith") {
            int y;
            cin >> y;
            A.find_ith(y);
        }
        else if(direction == "delete") {
            int x;
            cin >> x;
            A.remove(x);
        }
        else if(direction == "delete_greater_than"){
            int x;
            cin >> x;
            A.delete_more_than(x);
        }
        else if(direction == "delete_less_than"){
            int x;
            cin >> x;
            A.delete_less_than(x);
        }
        else if(direction == "delete_interval"){
            int a, b;
            cin >> a >> b;
            A.delete_interval(a, b);
        }
    }
    return 0;
}