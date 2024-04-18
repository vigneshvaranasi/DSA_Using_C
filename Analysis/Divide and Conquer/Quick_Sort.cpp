#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (a[i] <= pivot && i <= j)
            i++;
        while (a[j] > pivot && i <= j)
            j--;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void Quicksort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        Quicksort(a, low, j - 1);
        Quicksort(a, j + 1, high);
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

    Quicksort(a, low, high);

    cout << "\nThe Sorted Array is : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
