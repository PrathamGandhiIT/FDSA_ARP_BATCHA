
#include <iostream>
using namespace std;

int main() {
    int a[10], n, x;

    for (int i = 0; i < 10; i++)
        a[i] = -1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        int h1 = x % 10;
        int h2 = 7 - (x % 7);
        int j = 0;

        while (j < 10 && a[(h1 + j * h2) % 10] != -1)
            j++;

        if (j < 10)
            a[(h1 + j * h2) % 10] = x;
        else
            cout << "Table full for " << x << endl;
    }

    cout << "Hash table: ";
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";

    return 0;
}