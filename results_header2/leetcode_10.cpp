

class Solution {
private:
    vector<vector<bool>> cache;
    string s, p;

    bool aux(int index_s, int pIndex) { // check if the current pattern matches the current string
        /// Returns true if the pattern matches the string up to this point.

        if (index_s == s.size()) {
            /// If we have reached the end of the string and there are still characters in the pattern.
            if (pIndex == p.size()) return true;
            for (int i = pIndex + 1; i < p.size(); i++) { // check if the remaining pattern consists only of '*'s
                if (p[i] != '*' && p[i - 1] != '*') return false;
            }
            return p.back() == '*'; // If all characters in the pattern are '*', then it matches.
        }

        if (index_s == s.size() || pIndex == p.size()) return false; // If we have reached the end of either string or pattern, then it doesn't match.

        if (cache[index_s][pIndex]) return false; // If this state has already been visited, then there is no need to re-check.

        cache[index_s][pIndex] = true; // Mark this state as visited.

        if (p[pIndex] == '*' && pIndex != 0) { // If the current character in the pattern is '*', and it's not the first character.
            if (s[index_s] == p[pIndex - 1] || p[pIndex - 1] == '.') { // If the current character in the string matches the previous character in the pattern, or the previous character in the pattern is '.'.
                if (aux(index_s + 1, pIndex)) return true; // Try to match the rest of the string with the same pattern.
                if (aux(index_s, pIndex + 1)) return true; // Try to match the rest of the string with a different pattern.
            } else { // If the current character in the string doesn't match the previous character in the pattern.
                if (aux(index_s, pIndex + 1)) return true;
            }
        }

        if (s[index_s] == p[pIndex] || p[pIndex] == '.') { // If the current characters in the string and pattern match, or the current character in the pattern is '.'.
            if (aux(index_s + 1, pIndex + 1)) return true;
        }

        if (pIndex != p.size() - 1 && p[pIndex + 1] == '*') { // If there are more characters in the pattern and the next one is '*', then we can skip it.
            return aux(index_s, pIndex + 2);
        }

        return false; // If none of the above conditions match, then it doesn't match.
    }

public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        cache = vector<vector<bool>>(s.size(), vector<bool>(p.size()));
        return aux(0, 0);
    }
};

