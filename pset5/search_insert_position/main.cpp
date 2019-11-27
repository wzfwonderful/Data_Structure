#include <iostream>
using namespace std;

int bin_search(int low, int high, int n, int* arr);

int main() {
    int size;
    cin >> size;

    int *array = new int[size];
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }

    int num;
    cin >> num;
    cout << bin_search(0, size - 1, num, array);
    return 0;
}


int bin_search(int low, int high, int n, int* arr) {

    if(low == high) {
        if(arr[low] < n) return low + 1;
        else return low;
    }

    int mid = (low + high) / 2;
    if(arr[mid] == n) {
        return mid;
    } else if(arr[mid] > n) {
        high = mid;
        return bin_search(low, high, n, arr);
    } else {
        if(low == mid) low++;
        else low = mid;
        return bin_search(low, high, n, arr);
    }
}
