//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool bs(vector <int> &v, int x){
        int low = 0, high = v.size() - 1;
        int mid = low + ((high - low) / 2);
        while(low <= high){
            if(v[mid] == x) return true;
            else if(v[mid] > x){
                high = mid - 1;
            }
            else if(v[mid] < x){
                low = mid + 1;
            }
            mid = low + ((high - low) / 2);
        }
        return false;
    }
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        for(int i = 0; i < mat.size(); i++){
            if(bs(mat[i],x)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends