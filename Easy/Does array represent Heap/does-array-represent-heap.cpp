//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
    for(int i=0;i<n;i++)
    {
        int left=2*i+1;
        int right=2*i+2;
        if(left>=n&&right>=n)
        continue;
        else if(left>=n)
        {
            if(arr[i]<arr[right])
            return 0;
        }
        else
        {
            if(arr[i]<arr[left])
            return 0;
        }
    }
    return 1;
    }
};


//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends