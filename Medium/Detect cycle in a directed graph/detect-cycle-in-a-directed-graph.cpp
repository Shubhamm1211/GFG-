//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>indeg(v,0);
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        vector<int>topo;
        int cnt=0;
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // topo.push_back(node);
            cnt++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                q.push(it);
                }
            }
        }
        if(cnt==v)return false;
        else return true;
        
        
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends