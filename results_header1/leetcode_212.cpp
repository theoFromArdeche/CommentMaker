


class Trie {
public:
    Trie* trie[26];
    bool isThisAWord=false;
    string word;
    int lettersUsed=0;

    // Initializes the trie data structure by setting up all pointers to null
    Trie() {
         for (int i=0; i<26; i++) this->trie[i]=nullptr;
     }
    
    void insert(string word) {
        // Inserts a given word into the trie data structure
        Trie* temp=this;
        for (auto x:word) {
            if (temp->trie[x-'a']==nullptr) {
                temp->trie[x-'a'] = new Trie();
                temp->lettersUsed++;
             }
            temp=temp->trie[x-'a'];
         }
        temp->isThisAWord=true;
        temp->word=word;
     }
};
class Solution {
private:
    vector<tuple<int,int>> directions = {make_tuple(1,0), make_tuple(-1,0), make_tuple(0,1), make_tuple(0,-1)}; // row,column
    vector<string> answer;

    bool aux(vector<vector<char>>& board, int row, int column, Trie* temp) {
        // Recursively searches for words in the given board starting from the given position
        if (temp->isThisAWord) {
            temp->isThisAWord=false;
            answer.push_back(temp->word);
         }
        if (temp->lettersUsed==0) {
            return true;
         }
        int max_row=board.size()-1, max_column=board[0].size()-1;
        int new_row, new_column;

        bool result;
        char temp_letter;
        for (auto direction:directions) {
            new_row = row+get<0>(direction); 
            new_column = column+get<1>(direction);
            if (new_row>=0&&new_row<=max_row&&new_column>=0&&new_column<=max_column
                 &&(board[new_row][new_column]!='.')
                 &&(temp->trie[board[new_row][new_column]-'a']!=nullptr)) {

                temp_letter=board[new_row][new_column];
                board[new_row][new_column]='.';
                result = aux(board, new_row, new_column, temp->trie[temp_letter-'a']);
                board[new_row][new_column]=temp_letter;
                if (result) {
                    temp->trie[board[new_row][new_column]-'a']=nullptr;
                    temp->lettersUsed--;
                    if (temp->lettersUsed==0) return true;
                 }
             }
         }
        return false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Finds all words in the given board that are present in the given list of words
        Trie* trie= new Trie();
        for (auto word:words) trie->insert(word);
        
        int max_row=board.size()-1, max_column=board[0].size()-1;
        bool result; char temp_letter;
        for (int row=0; row<=max_row; row++) {
            for (int column=0; column<=max_column; column++) {
                if (trie->trie[board[row][column]-'a']!=nullptr) {
                    temp_letter=board[row][column];
                    board[row][column]='.';
                    result = aux(board,row,column, trie->trie[temp_letter-'a']);
                    board[row][column]=temp_letter;
                    if (result) {
                        trie->trie[board[row][column]-'a']=nullptr;
                        trie->lettersUsed--;
                        if (trie->lettersUsed==0) return answer;
                     }
                 }
             }
         }
        return answer;
    }
};

