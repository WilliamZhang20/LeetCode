class Solution {
public:
    int calculate(string s) {
        long long n = 0;
        long long result = 0;
        int sign = 1;

        vector<long long> st;
        st.reserve(32); // avoids reallocs

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0');
            }
            else if (c == '+' || c == '-') {
                result += sign * n;
                n = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                st.push_back(result);
                st.push_back(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * n;
                n = 0;

                result *= st.back(); // sign
                st.pop_back();

                result += st.back(); // previous result
                st.pop_back();
            }
        }

        return (int)(result + sign * n);
    }
};