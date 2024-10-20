//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int val[], int wt[], int w, int ind,vector <vector<int>>&dp){
        if(w == 0){
            return 0;
        }
        if(ind == 0){
            if(wt[0] <= w){
                return (w / wt[0]) * val[0];
            }
            else return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int pick = 0;
        if(wt[ind] <= w){
            pick = val[ind] + solve(val, wt, w - wt[ind], ind,dp);
        }
        int notpick = solve(val,wt,w, ind - 1,dp);
        
        return dp[ind][w] = max(pick,notpick);
        
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector <vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        return solve(val, wt, w, n - 1, dp);
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