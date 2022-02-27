// Problem link :- https://leetcode.com/problems/sudoku-solver/

bool is_possible(int n, vector<vector<char>> board, int indx, int indy) {
    fo(i, 0, 8) {
        if (board[indx][i] == n) return false;
        if (board[i][indy] == n) return false;
        if (board[3*(indx)/3 + (i)/3][3*(indy)/3 + (i)%3] == n) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {

    fo(i, 0, 8) {
        fo(j, 0, 8) {
            if (board[i][j] == '.') {
                fo(k, 1, 9) {
                    if (is_possible(k, board, i, j)) board[i][j] = k;
                    if (solve(board) == true) return true;
                    else { board[i][j] = '.'; }
                }
            }
            return false;
        }
    }
    return true;

}

int main(){
  vector<vector<char>> board;
        fo(i, 0, 8) {
            fo(j, 0, 8) {
                int x; cin >> x;
                board.pb(x);
            }
        }
        if(solve(board)){
            fo(i,0,8){
                fo(j,0,8){
                    cout<<board[i][j];
                }
            }
        }
        cout << endl;
  return 0;
}
