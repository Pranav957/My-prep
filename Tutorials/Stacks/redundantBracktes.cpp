
#include <bits/stdc++.h>
using namespace std;
bool checkRedundantBrackets(string expression) {
    stack<char> s;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch == ')') {
            int operatorCount = 0;

            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                s.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorCount++;
                }
            }

            if (!s.empty()) s.pop(); // pop the '('

            if (operatorCount == 0) return true; // redundant
        } else {
            s.push(ch);
        }
    }

    return false;
}
