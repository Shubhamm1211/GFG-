//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector <pair <int,char>> v;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            v.push_back({arr[i],'a'});
            v.push_back({dep[i],'d'});
        }
        int cnt = 0;
        int maxi = 0;
        sort(begin(v), end(v));
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == 'a'){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else cnt--;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends