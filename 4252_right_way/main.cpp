#include "priorityQueue.hpp"
#include "function.hpp"

int main() {
    int n, k, a[100000], b[100000], c[100000];
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    function_f *A;
    A = new function_f[n];

    for(int i = 0; i < n; i++){
        A[i].create_function(a[i], b[i], c[i]);
    }

    int *data = new int[n], *order = new int[n];
    for(int i = 0; i < n; i++){
        data[i] = A[i].getNext();
        order[i] = i;
    }

    priority_queue Q(data, order, n);
    int tmp;
    for(int i = 0; i < k; i++){
        tmp = Q.deQueue();
        Q.enQueue(A[tmp].getNext(), tmp);
    }
    delete []data;
    delete []order;
    delete []A;
    return 0;
}