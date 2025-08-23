string removeOuterParentheses(string s) {
    string str;
    int cnt = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            if(cnt > 0) str += s[i];
            cnt++;
        } else {
            cnt--;
            if(cnt > 0) str += s[i];
        }
    }
    return str;
}
