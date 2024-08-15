//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int tar, vector<int>& nums, vector<int>& dp) {
    if (tar == 0) return 0;
    if (tar < 0) return INT_MIN;
    if (dp[tar] != -1) return dp[tar];

    int maxCuts = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        int result = solve(tar - nums[i], nums, dp);
        if (result != INT_MIN) {
            maxCuts = max(maxCuts, 1 + result);
        }
    }
    
    return dp[tar] = maxCuts;
}

int maximizeTheCuts(int n, int x, int y, int z) {
    vector<int> nums = {x, y, z};
    vector<int> dp(n + 1, -1);

    int result = solve(n, nums, dp);
    return max(0, result);
}
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends