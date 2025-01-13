//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // You need to complete this function
    void solve(int n, int from, int to, int aux, int &temp){
        if(n == 0){
            return ;
        }
        if(n == 1){
            temp++;
            return;
        }
        solve(n - 1, from, aux, to,temp);
        temp++;
        return solve(n - 1, aux, to, from,temp);
    }
    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        int temp = 0;
        solve(n,from,to,aux,temp);
        return temp;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T; // testcases
    while (T--) {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.towerOfHanoi(N, 1, 3, 2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends