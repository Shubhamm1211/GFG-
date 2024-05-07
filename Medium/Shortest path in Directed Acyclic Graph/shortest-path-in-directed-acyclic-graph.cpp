//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<pair<int, int>> adj[], stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it.first]) {
                dfs(it.first, vis, adj, st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int node = edges[i][0];
            int dest = edges[i][1];
            int wt = edges[i][2];
            adj[node].push_back({dest, wt});
        }
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        vector<int> dist(N, 1e9);
        dist[0] = 0; // Assuming shortest path from 0 to itself is 0
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[v] > dist[node] + wt) {
                    dist[v] = dist[node] + wt;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends