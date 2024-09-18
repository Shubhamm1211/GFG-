//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(int i=0;i<x.size();i++){
            char c=x[i];
            if(c==')'){
                if(!st.empty() and st.top()=='('){
                    st.pop();
                }
                else return false;
            }
            else if(c=='}'){
                if(!st.empty() and st.top()=='{'){
                    st.pop();
                }
                else return false;
            }
            else if(c==']'){
                if(!st.empty() and st.top()=='['){
                    st.pop();
                }
                else return false;
            }
            else st.push(c);
        }
        if(!st.empty()) return false;
        else return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends