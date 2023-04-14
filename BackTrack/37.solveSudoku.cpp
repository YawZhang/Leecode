#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool dfs(vector<vector<char>>& board) {
        // 要遍历每个格子，因此不需要截止吧？

        for(int i = 0; i<board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++ ) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num<='9'; num++) {
                        if (isValid(board, i, j, num)) {
                            
                            board[i][j] = num;
                            if (dfs(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
            
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // 当前行不存在相同数字
        for(int i = 0; i < 9; i++) {
            char bb = board[row][i];
            if (bb == num) {
                return false;
            }
        }
        // 当前列不存在相同数字
        for(int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }

        // 当前3x3矩阵中不存在相同数字
        int r_i = row / 3; // int r_j = row % 3;
        int c_i = col / 3; // int c_j = col % 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if (board[r_i*3 + i][c_i*3 + j] == num) return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);

    }
};

void pirntV(vector<vector<char>> a ) {
    for (int i = 0; i < a.size(); i++) {
        for (const char c : a[i]) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                            {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','.'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','5'},
                            {'.','.','.','.','8','.','.','7','9'}};

    pirntV(board);
    cout << "=========================" << endl;
    
    Solution S ;
    S.solveSudoku(board);
    pirntV(board);

    return 0;
}
