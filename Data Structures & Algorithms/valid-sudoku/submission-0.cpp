class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int i = 0 ; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] == '.') continue;

                if(row[i].count(board[i][j])) return false;
                
                row[i].insert(board[i][j]);

                if(col[j].count(board[i][j])) return false;

                col[j].insert(board[i][j]);

                int index = (i/3) * 3 + j/3;

                if(box[index].count(board[i][j])) return false;

                box[index].insert(board[i][j]);
            }
        }

        return true;
    }
};
