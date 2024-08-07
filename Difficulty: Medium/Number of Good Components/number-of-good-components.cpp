//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node,vector<int>adj[],vector<int>&vis,unordered_set<int>&st){
        vis[node]=1;
        st.insert(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,adj,vis,st);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edge) {
        // code here
        int n=edge.size();
        vector<int>adj[v+1];
        for(int i=0;i<e;i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        vector<int>vis(v+1,0);
        int ans=0;
        
        
        for(int i=1;i<=v;i++){
            if(!vis[i]){
            vis[i]=1;
            unordered_set<int>st;
            dfs(i,adj,vis,st);
            bool f=true;
            for(int n:st){
                    if(adj[n].size()!=st.size()-1){
                        f=0;
                        break;
                    }
                }
            if(f)ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends