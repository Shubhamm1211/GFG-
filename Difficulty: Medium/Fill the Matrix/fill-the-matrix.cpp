//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        vector<vector<int>>mat(n+1,vector<int>(m+1,0));
        mat[x-1][y-1]=1;
        queue< pair<int, pair<int,int> > >q;
        q.push({0,{x-1,y-1}});
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        vis[x-1][y-1]=1;
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        int mini=INT_MIN;
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int t=q.front().first;
            q.pop();
            mini=max(mini,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and mat[nr][nc]==0){
                    mat[nr][nc]=1;
                    q.push({t+1,{nr,nc}});
                }
            }
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends