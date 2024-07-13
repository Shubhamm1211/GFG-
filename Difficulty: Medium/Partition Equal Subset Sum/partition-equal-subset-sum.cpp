//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int arr[],int ind,int tar,vector<vector<int>>&dp){
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        if(ind==0)return tar==arr[0];
        if(tar==0)return true;
        bool np=solve(arr,ind-1,tar,dp);
        bool p=false;
        if(arr[ind]<=tar){
            p=solve(arr,ind-1,tar-arr[ind],dp);
        }
        return dp[ind][tar]=p||np;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=accumulate(arr,arr+N,0);
        // cout<<sum<<endl;
        if(sum%2==1)return 0;
        vector<vector<int>>dp(N,vector<int>(sum/2+1,-1));
        bool flag=solve(arr,N-1,sum/2,dp);
        if(flag)return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends