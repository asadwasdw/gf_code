#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<char, char> match;
    match[')'] = '(';
    match[']'] = '[';
    match['}'] = '{';
    match['>'] = '<';
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack<char> st;
        bool valid = true;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{' || c == '<') {
                st.push(c);
            } else if (match.find(c) != match.end()) {
                if (st.empty() || st.top() != match[c]) {
                    valid = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) {
            valid = false;
        }
        cout << (valid ? "YES" : "NO") << '\n';
    }
    return 0;
}