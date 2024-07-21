//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        if(arr.size()==1) return arr[0];
        ll pro=1,neg=0,zero=0;
        int maxi=INT_MIN;
        for(ll i=0;i<arr.size();i++){
            if(arr[i]==0){
            zero++;
            continue;
            }
            
            if(arr[i]<0){
            neg++;
            maxi=max(maxi,arr[i]);
            }
            
            pro=(pro*arr[i])%1000000007;
        }
        if(zero==arr.size())return 0;
        if(neg== 1 && zero + neg == arr.size()) return 0;
        if(neg%2==1)return (pro/maxi)%1000000007;
        return pro%1000000007;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends