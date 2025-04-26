#include<bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
    int n = input.length();
    
    // If length is odd, impossible to balance
    if (n % 2 != 0) {
        return -1;
    }

    stack<char> s;
    
    for (int i = 0; i < n; i++) {
        if (input[i] == '{') {
            s.push('{');
        } else { // input[i] == '}'
            if (!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push('}');
            }
        }
    }

    int count = 0;
    while (!s.empty()) {
        char c1 = s.top(); s.pop();
        char c2 = s.top(); s.pop();
        
        if (c1 == c2) {
            count += 1;
        } else {
            count += 2;
        }
    }

    return count;
}
