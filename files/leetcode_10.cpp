class Solution {
private:
    vector<vector<bool>> cache;
    string s, p;
    bool aux(int index_s, int index_p) {
        if (index_s==s.size()) {
            if (index_p==p.size()) return true;
            for (int i=index_p+1; i<p.size(); i++) {
                if (p[i]!='*'&&p[i-1]!='*') return false;
            }
            return p.back()=='*';
        }
        if (index_s==s.size()||index_p==p.size()) return false;
        if (cache[index_s][index_p]) return false; // alreay visited
        cache[index_s][index_p]=true; // marked as visited


        if (p[index_p]=='*'&&index_p!=0) { 
            if (s[index_s]==p[index_p-1]||p[index_p-1]=='.') { // we can loop
                if (aux(index_s+1, index_p)) return true; // loop
                if (aux(index_s, index_p+1)) return true; // exit loop
            } else { // exited prev loop
                if (aux(index_s, index_p+1)) return true;
            }
            
        }


        if (s[index_s]==p[index_p]||p[index_p]=='.') { // we can continue
            if (aux(index_s+1, index_p+1)) return true;
        }

        if (index_p!=p.size()&&p[index_p+1]=='*') { // skip *
            return aux(index_s, index_p+2);
        }

        return false;
    }
public:
    bool isMatch(string s, string p) {
        this->s=s; this->p=p;
        cache = vector<vector<bool>>(s.size(), vector<bool>(p.size()));
        return aux(0, 0);
    }
};