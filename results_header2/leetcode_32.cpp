

class Solution {
public:
    int longestValidParentheses(string s) { // Returns the length of the longest valid parentheses substring.
        stack<int> s_open;
        int count_open = 0, count_close = 0, answer = 0, bloc_start = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') { // Push the opening parenthesis index onto the stack.
                s_open.push(i);
                count_open++;
             } else {
                count_close++;
                if (!s_open.empty()) s_open.pop();
             }

            if (count_close > count_open) { // Reset the counter when there are more closing parentheses than opening ones.
                while(!s_open.empty()) s_open.pop();
                bloc_start = i + 1; count_close = 0; count_open = 0;
             }
            if (count_close == count_open) { // Update the answer when there are equal numbers of opening and closing parentheses.
                answer = max(answer, i - bloc_start + 1);
             }
        }
        int prev_top = s.size();
        while (!s_open.empty()) {
            answer = max(answer, prev_top - s_open.top() - 1); // Calculate the length of the longest valid parentheses substring ending at each popped opening parenthesis.
            prev_top = s_open.top();
            s_open.pop();
         }
        return answer;
    }
}; 