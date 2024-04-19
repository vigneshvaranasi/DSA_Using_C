#include <iostream>
#include <vector>
using namespace std;
void sumOfSub(vector<int>weights, int k, int s, int r, int m,vector<int>x) {
    x[k] = 1;
    if (s + weights[k] == m) {
        for (int i = 0; i <= k; ++i) {
            if (x[i] == 1)
                cout << weights[i] << " ";
        }
        cout << endl;
    } else {
        if (s + weights[k] + weights[k + 1] <= m) {
            sumOfSub(weights, k + 1, s + weights[k], r - weights[k], m, x);
        }
        if (s + r - weights[k] >= m && s + weights[k + 1] <= m) {
            x[k] = 0;
            sumOfSub(weights, k + 1, s, r - weights[k], m, x);
        }
    }
}
int main() {
    int n, m, val;
    cout << "Enter the number of objects and weight of Bag: ";
    cin >> n >> m;
    vector<int> weights(n);
    vector<int> x(n, 0);
     cout << "Enter the weights: ";
     for(int i=0;i<n;i++)
        cin>>weights[i];
         int r = 0;
    for (int i = 0; i < n; ++i)
        r += weights[i];
    cout << "Solution Vectors: "<<endl;
    sumOfSub(weights, 0, 0, r, m, x);
    return 0;
}