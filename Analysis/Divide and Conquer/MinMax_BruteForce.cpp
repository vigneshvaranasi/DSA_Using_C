#include<iostream>
using namespace std;
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
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    cout << "\nThe Minimum Element is : " << min;
    cout << "\nThe Maximum Element is : " << max;
    return 0;
}