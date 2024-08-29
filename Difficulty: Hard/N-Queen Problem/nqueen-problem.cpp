//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(vector<vector<bool>>&board,int n)
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(board[i][j])
        for(int k=0;k<n;k++)
        if((k!=i && board[k][j]) || (k!=j && board[i][k]) || (k && i+k<n && j+k<n && board[i+k][j+k]) || (k && i-k>=0 && j-k>=0 && board[i-k][j-k]) || (k && i+k<n && j-k>=0 && board[i+k][j-k]) || (k && i-k>=0 && j+k<n && board[i-k][j+k]))
        return false;
        return true;
    }
    void solve(vector<vector<int>>&res,vector<vector<bool>>&board,vector<int>&pos,int r, int c, int n)
    {
        board[r][c]=true;
        if(!check(board,n))
        {
            board[r][c]=false;
            return;
        }
        
        pos[c] = r+1;
        
        if(c==n-1)
        {
            res.push_back(pos);
            board[r][c]=false;
            return;
        }
        
        for(int i=0;i<n;i++)
        solve(res,board,pos,i,c+1,n);
        
        board[r][c]=false;
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<vector<bool>> board(n,vector<bool>(n,false));
        vector<int>pos(n);
        for(int i=0;i<n;i++)
        solve(res,board,pos,i,0,n);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends