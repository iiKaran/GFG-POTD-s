//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

int N = 1e9+7;
class Solution{
public:

    long long sequence(int n){
        // code here
        long long ans=0;
        long long cnt=1;
        for(int i=1;i<=n;i++){
            int val=i;
            int tmp=1;
            while(val--){
                tmp=(tmp*cnt)%N;
                cnt++;
            }
            ans=(ans+tmp)%N;
        }
        return ans;
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends