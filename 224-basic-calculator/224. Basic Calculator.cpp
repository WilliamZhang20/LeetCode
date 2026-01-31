class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    int calculate(string s) {
        long long n = 0;
        int sign = 1;
        long long result = 0;
        stack<long long> st;
        for(char& c: s) {
            if(isDigit(c)) {
                n = n * 10 + (c - '0');
            } else if(c == '+' or c == '-') {
                result += sign * n;
                n = 0;
                sign = (c == '+') ? 1 : -1;
            } else if(c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if(c == ')') {
                result += sign * n;
                n = 0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        return (int)(result + sign * n);
    }
};