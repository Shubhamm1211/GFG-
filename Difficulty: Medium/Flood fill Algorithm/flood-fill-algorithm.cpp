//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newc) {
        // Code here
        int n = image.size();
        int m = image[0].size();
        int org = image[sr][sc];
        if(org == newc) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector <vector<int>> ans = image;
        ans[sr][sc] = newc;
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        vector<vector<int>> vis(n,vector<int>(m, 0));
        vis[sr][sc] = 1;
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and image[nr][nc] == org){
                    vis[nr][nc] = 1;
                    ans[nr][nc] = newc;
                    q.push({nr,nc});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends