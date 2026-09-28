#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int stack[100];
    int top = -1;

    int operations;
    cin >> operations;

    while (operations--) {
        string op;
        cin >> op;

        if (op == "place") {
            int tray;
            cin >> tray;

            if (top == n - 1) {
                cout << "Error: Stack Overflow\n";
            } else {
                stack[++top] = tray;
                cout << "Top: " << stack[top] << "\n";
            }
        } 
        else if (op == "take") {
            if (top == -1) {
                cout << "Error: Stack Underflow\n";
            } else {
                --top;
                if (top == -1)
                    cout << "Stack Empty\n";
                else
                    cout << "Top: " << stack[top] << "\n";
            }
        }
    }

    return 0;
}
