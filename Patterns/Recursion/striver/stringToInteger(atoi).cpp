class Solution {
public:
    int helper(const string& s, int i, int sign, long result) {
        if (i >= s.size() || !isdigit(s[i]))
            return sign * result;

        result = result * 10 + (s[i] - '0');
        
        if (sign * result >= INT_MAX) return INT_MAX;
        if (sign * result <= INT_MIN) return INT_MIN;

        return helper(s, i + 1, sign, result);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ') i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return helper(s, i, sign, 0);
    }
};
