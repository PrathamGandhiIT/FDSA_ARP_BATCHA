
#include <iostream>
using namespace std;

int main() {
    int a[10];
    int n, x;

    for (int i = 0; i < 10; i++)
        a[i] = -1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        int pos = x % 10;
        int j = 0;

        while (j < 10 && a[(pos + j) % 10] != -1)
            j++;

        if (j < 10)
            a[(pos + j) % 10] = x;
        else
            cout << "Parking full for " << x << endl;
    }

    cout << "Parking slots: ";
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";

    return 0;
}
