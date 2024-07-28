//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution{
    public:
        long long required(long long arr[], long long n, long long k) {
        // Your code goes here
        ll ans=0;
        ll maxi=INT_MIN;
        for(ll i=0;i<n;i++){
            if(arr[i]>k){
                maxi=max(maxi,arr[i]-k);
            }
        }
        if(maxi==INT_MIN)return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (long long i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        cout << ob.required(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends