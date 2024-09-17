//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=INT_MAX;
        sort(arr.begin(),arr.end());
        int diff=arr.back()-arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-k<0)continue;
            int maxi=max(arr[i-1]+k,arr[n-1]-k);
            int mini=min(arr[i]-k,arr[0]+k);
            diff=min(maxi-mini,diff);
        }
        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends