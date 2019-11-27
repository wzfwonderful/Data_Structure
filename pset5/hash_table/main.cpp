#include "hashTable.hpp"

int main() {
    int p, m, n;
    cin >> p >> m >> n;

    int data;
    hashTable A(m, p);
    for(int i = 0; i < n; i++) {
        cin >> data;
        A.insert(data);
    }

    A.display();

    return 0;
}