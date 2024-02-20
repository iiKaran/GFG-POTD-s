//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
    bool solve(int curr,string s, int n , set<string> &dict)
    {
        if(curr==n) // full word get breaked down in subsequences in the list 
        return true ; 
        
        string formed; 
        for( int next= curr ; next<n ; next++)
        {
             formed += s[next]; 
             
             if(dict.find(formed) != dict.end())
             {
                 // means can be breaked down 
                 
                 if(solve(next+1, s, n , dict))
                 return 1 ;  // return true always if on current breakdown word for all others 
                                // sub sequences are also there
             }
        }
        return 0 ; 
    }
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        // use greedy approch break whenever see that the subsequence is in the list
        
        set<string> dict; 
        for(auto i : dictionary)
        dict.insert(i); 
        
        return solve(0,s,s.size(),dict);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends