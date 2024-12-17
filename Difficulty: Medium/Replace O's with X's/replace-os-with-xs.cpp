//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c, vector<vector<int>> &vis, vector<vector<char>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        vis[r][c] = 1;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,-1,1};
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and mat[nr][nc] == 'O'){
                dfs(nr,nc,vis,mat);
            }
        }
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0; i < m; i++){
            if(!vis[0][i] and mat[0][i] == 'O'){
                vis[0][i] = 1;
                dfs(0,i,vis,mat);
            }
            if(!vis[n - 1][i] and mat[n - 1][i] == 'O'){
                vis[n - 1][i] = 1;
                dfs(n - 1, i,vis,mat);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i][0] and mat[i][0] == 'O'){
                vis[i][0] = 1;
                dfs(i,0,vis,mat);
            }
            if(!vis[i][m - 1] and mat[i][m - 1] == 'O'){
                vis[i][m - 1] = 1;
                dfs(i,m - 1, vis, mat);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] and mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends