//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    int right = 0, down = 0, left = 0, up = 0;
    
    // Move right
    if (j + 1 < m && matrix[i][j + 1] > matrix[i][j]) {
        right = 1 + solve(i, j + 1, matrix, dp);
    }
    
    // Move down
    if (i + 1 < n && matrix[i + 1][j] > matrix[i][j]) {
        down = 1 + solve(i + 1, j, matrix, dp);
    }
    
    // Move left
    if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
        left = 1 + solve(i, j - 1, matrix, dp);
    }
    
    // Move up
    if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
        up = 1 + solve(i - 1, j, matrix, dp);
    }
    
    return dp[i][j] = max({right, down, left, up, 1});
}

int longestIncreasingPath(vector<vector<int>>& matrix,int n,int m) {
    if (matrix.empty()) return 0;
    
   
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, solve(i, j, matrix, dp));
        }
    }
    
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends