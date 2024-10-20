//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int calc(int i, int j1, int j2, vector<vector<int>> &grid, vector <vector<vector<int>>> &dp){
        int n = grid.size();
        int x = grid[0].size();
        if(i >= n or j1 >= x or j1 < 0 or j2 >= x or j2 < 0){
            return -1e5;
        }
        if(i == grid.size() - 1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e5;
        int dr[3] = {-1,0,1};
        int dc[3] = {-1,0,1};
        for(int m = 0; m < 3; m++){
            for(int k = 0; k < 3; k++){
                if(j1 == j2){
                    maxi = max(maxi, grid[i][j1] + calc(i + 1, j1 + dr[m], j2 + dc[k],grid,dp));   
                }
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + calc(i + 1, j1 + dr[m], j2 + dc[k],grid,dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector <vector<vector<int>>> dp(n ,vector<vector<int>>(m ,vector<int>(m ,-1)));
        return calc(0,0,m - 1, grid, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends