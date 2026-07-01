class Solution {
    void solve(int r, vector<string>b, vector<vector<string>>&ans, int n){

        if(r==n){
            ans.push_back(b);
            return;
        }
        for(int i = 0; i<n; ++i){
            if(safe (b,r,i)){
                b[r][i] = 'Q';
                solve(r+1,b, ans, n);
                b[r][i] = '.';
            }
        }
    }
    bool safe(vector<string> &b, int r, int c){
        int n = b.size();
        for(int i = r-1; i>=0; --i){
            if(b[i][c]=='Q') return false;
        } //vertical
        for(int i = r-1, j= c+1; i>=0 && j<n; i--, j++){
            if(b[i][j]=='Q') return false;
        }//right diagonal
        for(int i = r-1, j=c-1; i>=0 && j>=0; i--, j--){
            if(b[i][j]=='Q') return false;
        }
        return true;
    }
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n,string(n,'.'));
        solve(0,b, ans,n);
        return ans;
    }
};