
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    string s, ans = "";
    stack<char> st;
    getline(cin, s);

    for (char c : s) {
        if (c == ' ')
            continue;
        else if (isalnum(c))
            ans += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << ans << endl;
    return 0;
}
