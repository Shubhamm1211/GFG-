//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n);

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        int arr[n + 1];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> b;
        b = Smallestonleft(arr, n);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends


// vector<int> Smallestonleft(int arr[], int n) {
//     // Complete the function
//     vector <int> ans(n);
//     priority_queue <int> st;
//     for(int i = 0; i < n; i++){
//         if(st.empty()){
//             ans[i] = -1;
//             st.push(arr[i]);
//         }
//         else{
//             vector <int> temp;
//             while(!st.empty() and st.top() >= arr[i]){
//                 int alpha = st.top();
//                 temp.push_back(alpha);
//                 st.pop();
                
//             }
//             if(st.empty()) ans[i] = -1;
//             else ans[i] = st.top();
//             if(temp.size() != 0){
//                 for(auto it : temp){
//                     st.push(it);
//                 }
//             }
//             st.push(arr[i]);
//         }
//     }
//     return ans;
// }
vector<int> Smallestonleft(int arr[], int n) {
    
    vector<int> ans , lef;
     for(int i = 0; i < n; ++i) {
        auto p = lower_bound(lef.begin(), lef.end(), arr[i]);
        
        if (p == lef.begin()) {
            ans.push_back(-1); 
        } else {
            ans.push_back(*--p); 
        }
        
         lef.insert(upper_bound(lef.begin(),lef.end(),arr[i]),arr[i]);   
    }
    
    return ans;
    
}

