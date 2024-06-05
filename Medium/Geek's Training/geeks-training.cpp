//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>&p,int ind,int lastind,vector<vector<int>>&dp){
        int maxi=0;
        if(dp[ind][lastind]!=-1)return dp[ind][lastind];
        if(ind==0){
            for(int i=0;i<3;i++){
                if(i!=lastind){
                    maxi=max(p[0][i],maxi);
                }
            }
            return maxi;
        }
        for(int i=0;i<3;i++){
            if(i!=lastind){
                maxi=max(maxi,p[ind][i]+solve(p,ind-1,i,dp));
            }
        }
        return dp[ind][lastind]=maxi;
    }
    int maximumPoints(vector<vector<int>>&p, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(p,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends