//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(int row, int col, vector<vector<int>> &mat,vector<vector<int>> &vis){
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < m; i++){
            vis[row][i] = 1;
            mat[row][i] = 0;
        }
        for(int i = 0; i < n; i++){
            vis[i][col] = 1;
            mat[i][col] = 0;
        }
    }
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<int> row, col;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i = 0; i < row.size(); i++){
            int ind = row[i];
            for(int j = 0; j < m; j++){
                mat[ind][j] = 0;
            }
        }
        for(int i = 0; i < col.size(); i++){
            int ind = col[i];
            for(int j = 0; j < n; j++){
                mat[j][ind] = 0;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends