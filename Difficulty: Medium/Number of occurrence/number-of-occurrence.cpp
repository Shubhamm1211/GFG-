//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int lb = lower_bound(arr, arr + n, x) - arr;
        int ub = upper_bound(arr, arr + n, x) - arr;
        int s = -1;
        int e = -1;

        if (lb>=0 and lb <= n && arr[lb] == x) s = lb;
        if (ub > 0 and ub<=n && arr[ub - 1] == x) e = ub - 1;

        if (s == -1 || e == -1) return 0; // If the target is not found
        return e - s + 1;

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends