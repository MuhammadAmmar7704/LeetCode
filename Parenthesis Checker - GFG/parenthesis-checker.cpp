//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<char> t;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
            } else {
                if(!t.empty()) {
                    if(((s[i] == ')' && t.top() == '(' ) || (s[i] == ']' && t.top() == '[') || (s[i] == '}' && t.top() == '{')) ) {
                        t.pop();
                    } else {
                        return false;
                    }    
                } else {
                    return false;
                }
                
            }
        }
        if(t.empty()) {
            return true;
        } else {
            return false;
        }
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