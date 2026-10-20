
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> history;
    string page, op;
    int n;
    cin >> n;

    while (n--) {
        cin >> op;

        if (op == "visit") {
            cin >> page;
            history.push(page);
        } 
        else if (op == "back") {
            if (!history.empty())
                history.pop();
        }

        if (history.empty())
            cout << "No page\n";
        else
            cout << history.top() << "\n";
    }

    return 0;
}