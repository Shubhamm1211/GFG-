//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    bool check(vector<int>&arr,int m,int page,int n){
        int totpage=0,stud=1;
        for(int i=0;i<n;i++){
            if(totpage+arr[i]<=page){
                totpage+=arr[i];
            }
            else{
                stud++;
                totpage=arr[i];
            }
        }
        if(stud<=m)return true;
        else return false;
    }
    long long findPages(int n, int arr2[], int m) {
        // code here
        if(n<m)return -1;
        vector<int>arr;
        for(int i=0;i<n;i++){
            arr.push_back(arr2[i]);
        }
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(arr,m,mid,n)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends