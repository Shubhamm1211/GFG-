//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<vector<int>>adj(n,vector<int>(n,1e8));
	    for(auto x:edges){
	        adj[x[0]][x[1]]=x[2];
	    }
	    for(int i=0;i<n;i++){
	        adj[i][i]=0;
	    }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(adj[i][i]<0)return 1;
	    }
	    return 0;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends