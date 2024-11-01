//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector <int> temp;
        bool f = true;
        int i = 0, j = n - 1;
        for(int k = 0; k < n; k++){
            if(f){
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j--;
            }
            f = !f;
        }
        int ans = 0;
        // for(auto x : temp) cout << x << " ";
        // cout << endl;
        for(int i = 0; i < n - 1; i++){
            ans += abs(temp[i] - temp[i + 1]);
        }
        ans += abs(temp.back() - temp[0]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends