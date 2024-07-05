//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(int n, int arr[]) {
        // code here
       int maxSum=INT_MIN;
    int sum=0;
    int start=0;
    int ansStart=-1;
    int ansEnd=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            sum=0;
            start=i+1;
            continue;
        }
        
        sum+=arr[i];
        
        if(sum>maxSum){
            maxSum=sum;
            ansStart=start;
            ansEnd=i;
        }
        
        else if(sum == maxSum)
	        {
	            if((i - start) > (ansEnd - ansStart))
	            {
	                ansStart = start;
	                ansEnd = i;
	            }
	        }
        
    }
    vector<int>v;
    for(int i=ansStart;i<=ansEnd;i++){
        v.push_back(arr[i]);
    }
    if(v.size()==0)return {-1};
    return v;
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