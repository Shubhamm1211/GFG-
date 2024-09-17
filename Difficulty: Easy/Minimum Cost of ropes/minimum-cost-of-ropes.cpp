//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
       priority_queue<ll,vector<ll>,greater<ll>>pq(arr.begin(),arr.end());
        ll ans=0;
        while(pq.size()>1){
            ll temp1=pq.top();
            pq.pop();
            ll temp2=pq.top();
            pq.pop();
            
            ll sum=temp1+temp2;
            ans=ans+sum;
            pq.push(sum);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends