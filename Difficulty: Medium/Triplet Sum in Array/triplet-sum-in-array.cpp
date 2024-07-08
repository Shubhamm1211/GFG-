//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int A[], int n, int X) {
        // Your Code Here
        // sort(arr,arr+n);
        // for(int i=0;i<n;i++){
        //     if(i>0 and arr[i-1]==arr[i])continue;
        //     int j=i+1,k=n-1;
        //     while(j<k){
        //         int sum=arr[i]+arr[j]+arr[k];
        //         if(sum>x){
        //             k--;
        //         }
        //         else if(sum<x){
        //             j++;
        //         }
        //         else if(sum==k)return true;
        //     }
        // }
        // return false;
        sort(A, A+n);
        for(int i=0; i<n; i++){
            int low = 0;
            int high = n-1;
            int sum = 0;
            while(low < high){
                if(i==low){
                    low++;
                    continue;
                }else if(i==high){
                    high--;
                    continue;
                }
                
                sum = A[i] + A[low] + A[high];
                if(sum > X){
                    high--;
                }else if(sum < X){
                    low++;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends