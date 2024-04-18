#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[high + 1];
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } 
        else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void Mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        Mergesort(a, low, mid);
        Mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n;
    cout << "Enter Number of array Elements:";
    cin >> n;
    int a[n];
    cout << "Enter Array Elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "The Array Elements Before Sorting are:";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    int low = 0;
    int high = n - 1;

    Mergesort(a, low, high);

    cout << "\nThe Sorted Array is : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
