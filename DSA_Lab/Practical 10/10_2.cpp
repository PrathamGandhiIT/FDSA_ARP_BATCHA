
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a[10];
    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        int pos = x % 10;
        a[pos].push_back(x);
    }

    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        for (int x : a[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}