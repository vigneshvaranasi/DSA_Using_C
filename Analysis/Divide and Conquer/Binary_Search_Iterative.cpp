#include <iostream>
using namespace std;

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
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (key > a[mid]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if (a[low] == key) {
        cout << "Element Found at index: " << low;
    } else {
        cout << "Element Not Found";
    }

    return 0;
}
