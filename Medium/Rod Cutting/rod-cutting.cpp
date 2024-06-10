//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int ind, int price[],vector<int>&len,int tar,vector<vector<int>>&dp){
        if(ind==0){
            if(len[0]<=tar){
                return (tar/len[ind])*price[ind];
            }
        else return 0;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int npick=solve(ind-1,price,len,tar,dp);
        int pick=INT_MIN;
        if(len[ind]<=tar){
            pick=price[ind]+solve(ind,price,len,tar-len[ind],dp);
        }
        return dp[ind][tar]=max(pick,npick);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int>len;
        for(int i=1;i<=n;i++){
            len.push_back(i);
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n-1,price,len,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends