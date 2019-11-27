#include "bst.hpp"

int main() {
    int size;
    cin >> size;

    bst A;
    int keyword;
    for(int i = 0; i < size; i++){
        cin >> keyword;
        A.insert(keyword);
    }

    return 0;
}