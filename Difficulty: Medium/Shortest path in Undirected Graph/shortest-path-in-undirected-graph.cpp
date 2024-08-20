//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
    //     vis[node]=1;
    //     for(auto it:adj[node]){
    //         if(!vis[it]){
    //             dfs(it,vis,adj,st);
    //         }
    //     }
    //     st.push(node);
    // }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        vector<int>vis(N,0);
        queue<int>q;
        q.push(src);
        vector<int>dist(N,1e9);
        
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[it]>dist[node]+1){
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9)dist[i]=-1;
        }
        return dist;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends