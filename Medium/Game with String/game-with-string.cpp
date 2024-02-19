//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int power( int n){
        return n*n ; 
    }
public:
    int minValue(string s, int k){
        // code here
        vector<int>freq(26,0);
        priority_queue<int> pq ; 
        // priority queue of frequency 
        
        for(auto i: s)
        freq[i-'a']++; 
        
        // now put the freq in pq
        for( auto elem : freq)
        if(elem != 0)
        pq.push(elem); 
        
        
        while( k--)
        {
            int maxi= pq.top(); 
            pq.pop(); 
            maxi-=1 ; 
            pq.push(maxi); 
        }
        
        int ans =0; 
        while(!pq.empty())
        {
            ans+= power(pq.top());
            pq.pop();
        }
        return ans; 
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends