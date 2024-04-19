#include <iostream>
#include <vector>
using namespace std;
bool place(vector<int>x, int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}
void nQueens(vector<int>x, int k, int n, int& count) {
    for (int i = 1; i <= n; i++) {
        if (place(x, k, i)) {
            x[k] = i;
            if (k == n) {
                cout << "Solution " << ++count << ": ";
                for (int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << endl;
            } 
            else
                nQueens(x, k + 1, n, count);
        }
    }
}
int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    vector<int> x(n); 
    int count = 0;
    nQueens(x, 1, n, count);
    if (count == 0)
        cout << "Not possible" << endl;
    return 0;
}