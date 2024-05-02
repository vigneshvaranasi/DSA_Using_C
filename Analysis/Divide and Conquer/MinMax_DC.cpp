#include<iostream>
using namespace std;
void minmax(int a[], int low, int high, int &min, int &max) {
    int mid, min1, max1;
    if (low == high) {
        min = a[low];
        max = a[low];
    } 
    else if (low == high - 1) {
        if (a[low] < a[high]) {
            min = a[low];
            max = a[high];
        } else {
            min = a[high];
            max = a[low];
        }
    } 
    else {
        mid = (low + high) / 2;
        minmax(a, low, mid, min, max);
        minmax(a, mid + 1, high, min1, max1);
        if (min > min1)
            min = min1;
        if (max < max1)
            max = max1;
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
    cout << "The Array Elements are:";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    int min = a[0];
    int max = a[0];
    minmax(a, 0, n - 1, min, max);
    cout << "\nThe Minimum Element is : " << min;
    cout << "\nThe Maximum Element is : " << max;
    return 0;
}