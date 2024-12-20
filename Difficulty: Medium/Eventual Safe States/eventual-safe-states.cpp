//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        int n = v;
        vector<vector<int>> adj2(n);
        for(int i = 0; i < v; i++){
            for(auto x : adj[i]){
                adj2[x].push_back(i);
            }
        }
        vector <int> ans;
        queue<int> q;
        vector<int>indeg(n,0);
        for(int i = 0; i < n; i++){
            for(auto x : adj2[i]){
                indeg[x]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto x : adj2[node]){
                indeg[x]--;
                if(indeg[x] == 0) q.push(x);
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends