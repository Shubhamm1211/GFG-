//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(int n, int a[]) {
        // code here
        int maxi=INT_MIN;
        int sum=0;
        int start=0,ansStart=-1,ansend=-1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            sum=sum+a[i];
            if(a[i]<0){
                start=i+1;
                sum=0;
                continue;
            }
            else if(sum>maxi){
                ansStart=start;
                ansend=i;
                maxi=sum;
            }
            else if(sum==maxi){
                if(i-start > ansend-ansStart){
                    ansStart=start;
                    ansend=i;
                }
            }
            
        }
        for(int i=ansStart;i<=ansend;i++){
            ans.push_back(a[i]);
        }
        if(ans.size()==0)return {};
        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends