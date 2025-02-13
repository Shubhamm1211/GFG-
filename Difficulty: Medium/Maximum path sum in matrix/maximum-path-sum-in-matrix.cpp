//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int row, int col, vector <vector <int>> &mat, vector <vector <int>> &dp){
        int n = mat.size();
        int m = mat[0].size();
        if(row < 0 or col < 0 or row >= n or col >= m){
            return INT_MIN;
        }
        if(row == n - 1){
            return mat[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        int op1 = solve(row + 1, col - 1, mat, dp);
        int op2 = solve(row + 1, col, mat, dp);
        int op3 = solve(row + 1, col + 1, mat, dp);
        return dp[row][col] = mat[row][col] + max({op1, op2, op3});
        
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int maxi = INT_MIN;
        vector <vector <int>> dp(n + 1, vector <int>(m + 1, -1));
        for(int i = 0; i < m; i++){
            maxi = max(maxi, solve(0, i, mat, dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends