//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto x : adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                dfs(x,adj,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> mat, int v) {
        // code here
        vector<vector<int>> adj(v);
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(mat[i][j] == 1 and i != j){
                    adj[i].push_back(j);
                    // adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(v + 1, 0);
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                ans++;
                dfs(i, adj, vis);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends