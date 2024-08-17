//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#define ll long long 
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int cnt0=0;
        for(auto x:nums){
            if(x==0)cnt0++;
        }
        if(cnt0==0){
            ll pro=1;
            for(auto x:nums)pro=pro*x;
            vector<ll>ans;
            for(auto x:nums){
                ans.push_back(pro/x);
            }
            return ans;
        }
        else if(cnt0==1){
            ll pro=1;
            for(auto x:nums){
                if(x==0)continue;
                else{
                    pro=pro*x;
                }
            }
            vector<ll>ans(nums.size());
            for(ll i=0;i<nums.size();i++){
                if(nums[i]==0){
                    ans[i]=pro;
                }
                else ans[i]=0;
            }
            return ans;
        }
        else{
            vector<ll>ans(nums.size(),0);
            return ans;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends