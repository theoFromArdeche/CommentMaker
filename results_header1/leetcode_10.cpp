

class Solution {
private:
    vector<vector<bool>> cache;
    string s, p;
    bool aux(int index_s, int index_p) { 
        // This function checks if the given strings match according to the regular expression pattern.
        // It takes two indices as input: the current position in the string and the pattern.
        // The function returns true if the strings match, false otherwise.

        if (index_s==s.size()) {
            // If we've reached the end of the string, check if we've also reached the end of the pattern.
            if (index_p==p.size()) return true;
            for (int i=index_p+1; i<p.size(); i++) {
                // If there are '*' characters remaining in the pattern, return false as long as they're not part of a loop.
                if (p[i]!='*'&&p[i-1]!='*') return false;
             }
            return p.back()=='*';
         }

        if (index_s==s.size()||index_p==p.size()) return false;

        // If the current position in the string or pattern has been visited before, return false.
        if (cache[index_s][index_p]) return false; 

        cache[index_s][index_p]=true; // Mark this position as visited.


        if (p[index_p]=='*'&&index_p!=0) {
            // If we're looking at a '*' character in the pattern and it's not the start of the pattern, 
            // check if there are matching characters in the string or if the current character in the string matches '.'
            if (s[index_s]==p[index_p-1]||p[index_p-1]=='.') {
                // If we can loop here, recursively call this function and see if it matches.
                if (aux(index_s+1, index_p)) return true;
                // If not, try to exit the loop by moving forward in both strings.
                if (aux(index_s, index_p+1)) return true;
             } else {
                // If we've exited a previous loop, just move forward in the string and pattern.
                if (aux(index_s, index_p+1)) return true;
             }
            
         }

        if (s[index_s]==p[index_p]||p[index_p]=='.') {
            // If the current characters match or the pattern is '.', 
            // we can just move forward in both strings and see if they still match.
            if (aux(index_s+1, index_p+1)) return true;
         }

        if (index_p!=p.size()&&p[index_p+1]=='*') {
            // If there's a '*' character remaining in the pattern, but it's not part of this loop, 
            // we can just skip over it and see if the rest of the strings match.
            return aux(index_s, index_p+2);
         }

        return false;
     }
public:
    bool isMatch(string s, string p) { 
        // This function checks if a given string matches a regular expression pattern.
        // It initializes the cache and then calls the auxiliary function to do the actual matching.

        this->s=s; this->p=p;
        cache = vector<vector<bool>>(s.size(), vector<bool>(p.size()));
        return aux(0, 0);
     }
};

