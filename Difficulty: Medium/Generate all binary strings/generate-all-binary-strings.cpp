//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> res;
    void helper(string  processed,int num,int c){
        if(c==num){
            res.push_back(processed);
            return;
        }
        if (processed[c-1]=='1'){
            helper(processed+'0',num,c+1);
        }else{
            helper(processed+'0',num,c+1);
            helper(processed+'1',num,c+1);
        }
    }
    vector<string> generateBinaryStrings(int num){
        helper("0",num,1);
        helper("1",num,1);
        return res;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends