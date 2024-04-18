#include <iostream>
using namespace std;

int binarysearch(int a[], int low, int high, int key) {
    if (low == high) {
        if (a[low] == key)
            return low;
        else
            return -1;
    } 
    else {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return binarysearch(a, low, mid - 1, key);
        else
            return binarysearch(a, mid + 1, high, key);
    }
}

int main() {
    int n;
    cout << "Enter Number of Elements in an array: ";
    cin >> n;
    int a[n];
    cout << "\nEnter Elements of The Array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "\nThe Elements of Array are: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    int key;
    cout << "\nEnter Element to Search: ";
    cin >> key;

    int low = 0;
    int high = n - 1;
    int res = binarysearch(a, low, high, key);
    if (res != -1) {
        cout << "Element Found at index: " << res;
    } else {
        cout << "Element Not Found";
    }

    return 0;
}
