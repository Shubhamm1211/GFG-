//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
    int n = arr.size();
    vector<int> vis(n, 0); 
    vector<vector<string>> ans; 
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) { 
            vector<string> temp;
            temp.push_back(arr[i]);
            vis[i] = 1;

            string ini = arr[i]; 
            sort(ini.begin(), ini.end());

            for (int j = i + 1; j < n; j++) {
                if (!vis[j]) {
                    string curr = arr[j];
                    sort(curr.begin(), curr.end());

                    if (ini == curr) { 
                        temp.push_back(arr[j]);
                        vis[j] = 1; 
                    }
                }
            }

            ans.push_back(temp); 
        }
    }

    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends