#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<string>> res; //存放结果

    void dfs(vector<string>& chessBoard, int row, int n) {
        if (row == n) {
            res.push_back(chessBoard);// 当row访问到n行的时候意味着棋盘已经符合条件了
        }

        // 开始遍历每一行，放置皇后Q
        for(int i = 0; i<n; i++) {
            if (isValid(chessBoard, i, row, n)) {
                chessBoard[row][i] = 'Q';
                dfs(chessBoard, row+1, n);
                chessBoard[row][i] = '.';
            }
        }
        return;
    }

    bool isValid(vector<string>& chessBoard, int col, int row, int& n) {
        
        // 判断每一列是否有皇后了
        for(int i = 0; i < row; i++) {
            if (chessBoard[i][col] == 'Q'){
                return false;
            } 
        }

        // 判断45度对角线是否有皇后
        for (int j = col-1, i = row-1;  j >=0 && i>=0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }

        // 判断135度对角线是否有皇后
        for (int j = col+1, i = row-1; j <n && i>=0; i--, j++) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> chessboard(n, string(n, '.'));
        printS(chessboard);
        dfs(chessboard, 0, n);
        return res;
    }

    void printS(vector<string> cb) {
        for (int i = 0; i< cb.size(); i++) {
            cout << cb[i] << endl;
        }
    }
};


void printV(vector<vector<string>> s) {
    for (int i = 0; i< s.size(); i++) {
        for (string c : s[i]) {
            cout << c << endl;
        }
        cout << "===================" << endl;
    }
}


int main() {

    int a = 4;
    Solution S ;

    vector<vector<string>> ans = S.solveNQueens(a);
    printV(ans);
    return 0;
}
