#include "priorityqueue.hpp"

int main() {
    int a[11]{40,20,60,15,30,25,10,35,45,50,55};
    priority_queue<int> queue(a, 11);

    for(int i = 0; i < 11; i++){
        cout << queue.dequeue() << " ";
    }
    cout << endl;

    /*cout << "Levelorder:" << endl;
    queue.levelOrder();
    cout << endl;

    cout << "Gethead:" << endl;
    cout << queue.getHead() << endl;

    cout << "Dequeue min:"  << endl;
    cout << queue.dequeue() << endl;

    cout << "Leveloder after dequeue min:" << endl;
    queue.levelOrder();
    cout << endl;

    queue.enqueue(11);
    cout << "Levelorder after enqueue 11:" << endl;
    queue.levelOrder();
    */
    return 0;
}