//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	void dfs(int row,int col,int index,string &word
   ,vector<vector<char> >& board,vector<vector<int>>&vis, vector<string>&ans){
        int n=board.size();
        int m=board[0].size();
       int len=word.size();
       if(index==len-1){
           ans.push_back(word);
           return ;
       }
       if(index>=len){
           return;
       }
       vis[row][col]=1;
       for(int i=-1;i<=1;i++){
           for(int j=-1;j<=1;j++){
               int nrow=row+i;
               int ncol=col+j;
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
               vis[nrow][ncol]==0 && board[nrow][ncol]==word[index+1]){
                   dfs(nrow,ncol,index+1,word,board,vis,ans);
               }
           }
       }
      vis[row][col]=0;
       return;
   }
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        int size=dictionary.size();
        vector<string>ans;
        for(int i=0;i<dictionary.size();i++){
            string word=dictionary[i];
            vector<vector<int>>vis(n,vector<int>(m,0));
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    if(vis[j][k]==0 && board[j][k]==word[0]){
                        dfs(j,k,0,word,board,vis,ans);
                    }
                }
            }
        }
        set<string>s;
        for(auto it:ans){
            s.insert(it);
        }
        vector<string>res;
        for(auto it:s){
            res.push_back(it);
        }
        
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends