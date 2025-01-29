//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
  public:
    double power(double b, int e) {
        // code here
        if(e == 0) return 1.0;
        double ans = 1;
        int temp = abs(e);
        while(temp > 0){
            if(temp % 2 == 0){
                b = b * b;
                temp /= 2;
            }
            else{
                ans = ans * b;
                temp--;
            }
        }
        
        if(e > 0){
            return ans;
        }
        else{
            return 1.0 / ans;
        }
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends