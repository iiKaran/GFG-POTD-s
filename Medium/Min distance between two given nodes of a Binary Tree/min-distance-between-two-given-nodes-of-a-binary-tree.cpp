//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    void print(vector<int> path)
    {
         for(auto i :path)
        cout<<i<<","; 
        
        cout<<endl; 
    }
    bool populatePath(Node * root , vector<int> & path , int target)
    {
        if(root==NULL)
        return false; 
        if(root -> data==target)
        {
            path.push_back(root->data); 
            return true; 
        }
        
        path.push_back(root->data);
        
        bool left= populatePath(root->left , path , target); 
        if(left)
        {
            return true; 
        }
        bool right = populatePath(root->right, path, target); 
        
        if(right)
        return true ; 
        
        if(!left && !right)
        {
            path.pop_back();
            return false ; 
        }
        
        return left|| right; 
        
        }
    int findDist(Node* root, int a, int b) {
        // Your code here
        vector<int> pathA ; 
        populatePath(root , pathA , a); 
         vector<int> pathB; 
        populatePath(root , pathB , b); 
        unordered_map< int, int> present;
        
      
        int n = pathA.size(),m = pathB.size(); 
        for(int i =0; i <n ; i++)
        present[pathA[i]]= i+1; 
        
        
        int ans = 0 ; 
        
        for(int i =0; i <m ; i++)
        {
            if(present[pathB[i]])
            ans = ((n-present[pathB[i]]) + (m-(i+1))); 
        }
        return ans ;  
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends