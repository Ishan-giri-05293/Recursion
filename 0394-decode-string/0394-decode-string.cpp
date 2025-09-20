class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;  // (prev_string, repeat_count)
        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                // push state and reset
                st.push({curr, num});
                curr.clear();
                num = 0;
            }
            else if (c == ']') {
                auto [prevStr, count] = st.top();
                st.pop();
                string repeated = "";
                for (int i = 0; i < count; ++i) {
                    repeated += curr;
                }
                curr = prevStr + repeated;
            }
            else {
                // a letter
                curr.push_back(c);
            }
        }

        return curr;
    }
};
