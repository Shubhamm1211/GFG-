//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    // long long solve(int x,int y,string s){
    //   //code here
    //   char c1='p',c2='r';
    //   long long ans=0;
    //   if(x<y){
    //       swap(x,y);
    //       swap(c1,c2);
    //   }
    //   stack<char>st;
    //   for(int i=0;i<s.size();i++){
    //       if(!st.empty() and s[i]==c2 and st.top()==c1){
    //           st.pop();
    //           ans+=x;
    //       }
    //       else st.push(s[i]);
    //   }
    //   string left="";
    //   while(!st.empty()){
    //       left=left+st.top();
    //       st.pop();
    //   }
    //   reverse(left.begin(),left.end());
    //   swap(c1,c2);
    //   for(int i=0;i<left.size();i++){
    //       if(!st.empty() and s[i]==c2 and st.top()==c1){
    //           st.pop();
    //           ans=ans+y;
    //       }
    //       else st.push(s[i]);
    //   }
    //   return ans;
    // }
    long long solve(int x, int y, string s) {
    int n = s.length();
    long long ans = 0;
    stack<char> st;

    char firstChar = 'p';
    char secondChar = 'r';

    // Ensure x >= y for consistent logic
    if (x < y) {
        swap(x, y);
        swap(firstChar, secondChar);
    }

    // First pass to find pairs (firstChar, secondChar)
    for (int i = 0; i < n; ++i) {
        if (!st.empty() && s[i] == secondChar && st.top() == firstChar) {
            st.pop();
            ans += x;
        } else {
            st.push(s[i]);
        }
    }

    // Reconstruct the string from the stack
    string remainingStr = "";
    while (!st.empty()) {
        remainingStr += st.top();
        st.pop();
    }
    reverse(remainingStr.begin(), remainingStr.end());

    // Swap the characters for the second pass
    swap(firstChar, secondChar);

    // Second pass to find pairs (secondChar, firstChar)
    for (char ch : remainingStr) {
        if (!st.empty() && ch == secondChar && st.top() == firstChar) {
            st.pop();
            ans += y;
        } else {
            st.push(ch);
        }
    }

    return ans;
}
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends