


class Solution {
public:
    // This function determines the longest valid parentheses in a given string.
    int longestValidParentheses(string s) {
        stack<int> s_open;
        int count_open=0, count_close=0, answer=0, bloc_start=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(') {
                s_open.push(i);
                count_open++;
            } else {
                count_close++;
                if (!s_open.empty()) s_open.pop();
            }

            if (count_close>count_open) {
                while(!s_open.empty()) s_open.pop();
                bloc_start=i+1; count_close=0; count_open=0;
            }
            if (count_close==count_open) {
                answer=max(answer, i-bloc_start+1);
            }
        }
        int prev_top=s.size();
        while (!s_open.empty()) {
            answer=max(answer, prev_top-s_open.top()-1);
            prev_top=s_open.top();
            s_open.pop();
        }
        return answer;
    }
};