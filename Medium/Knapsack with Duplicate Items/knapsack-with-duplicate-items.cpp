//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int w,int wt[],int val[],vector<vector<int>>&dp){
        if(ind==0){
            if(wt[ind]<=w)return w/wt[0] * val[0];
            return 0;
        }
        if(ind<0)return 0;
        if(dp[ind][w]!=-1)return dp[ind][w];
        int notpick=solve(ind-1,w,wt,val,dp);
        int pick=INT_MIN;
        if(wt[ind]<=w){
            pick=val[ind]+solve(ind,w-wt[ind],wt,val,dp);
        }
        return dp[ind][w]=max(pick,notpick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends