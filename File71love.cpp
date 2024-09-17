/*
Q.1. Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any 
leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes 
will be considered.

Example 1:

Input: 
         4        
       /   \       
      2     5      
     / \   / \     
    7   1 2   3    
       /
      6
Output: 
13
Explanation:
The highlighted nodes (4, 2, 1, 6) above are part of the longest root to 
leaf path having sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 
11
Explanation:
Use path 1->3->7, with sum 11.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() 
which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^5
0 <= data of each node <= 10^4

*/

/*
// Solution of question 1:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(height) where height is tree height

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen)
    {
        if(root == NULL)
        {
            if(len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen)
            {
                maxSum = max(sum, maxSum);
            }
            return;
        }

        sum = sum + root->data;

        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = INT_MIN;

        solve(root, sum, maxSum, len, maxLen);

        return maxSum;
    }
};
*/

/*
Q.2. Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the 
lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the 
tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.

Example 2:

Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 

Example 3:

Input:
n1 = 5 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 5
Explanation:
LCA of 5 and 4 is 5. 

Your Task:
You don't have to read, input, or print anything. Your task is to complete the function lca() that takes 
nodes, n1, and n2 as parameters and returns the LCA node as output. 

Expected Time Complexity:O(N).
Expected Auxiliary Space:O(Height of Tree).

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^5
*/

/*
// Solution of question 2:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(height) where height is tree height

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root == NULL)
        {
                return NULL;
        }

        if(root->data == n1 || root->data == n2)
        {
                return root;
        }

        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);

        if(leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else
        {
            return NULL;
        }
    }
};
*/

/*
Q.3. Given a binary tree and an integer k, the task is to count the number of paths in the tree such that 
the sum of the nodes in each path equals k. A path can start from any node and end at any node and must be 
downward only.

Examples:

Input: Tree =  1  k = 3                               
             /   \                          
           2     3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3

Input: Tree = 8  k = 7 
            /  \
          4     5
         / \     \
       3    2     2                        
      / \    \                    
     3  -2    1       
Output: 3
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of Tree)

Constraints:
1 ≤ number of nodes ≤ 2*10^4
-10^5 ≤ node value ≤ 10^5
-10^9 ≤ k ≤ 10^9
*/

/*
// Solution of question 3:-

/*
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:

    void solve(Node* root, int k, int& count, vector<int> path)
    {
        if(root == NULL)
        {
            return ;
        }

        path.push_back(root->data);

        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        int size = path.size();
        int sum = 0;
        for(int i = size-1; i >= 0; i--)
        {
            sum += path[i];
            if(sum == k)
            {
                count++;
            }
        }

        path.pop_back();
    }

    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};
*/

/*
Q.4. Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function 
kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. 
If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

Example 1:
    1
   / \
  2   3
 / \
4   5

Input:
K = 2 Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.

Example 2:

Input:
k=1 
node=3
      1
    /   \
   2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Your Task:
You are asked to complete the function kthAncestor() which accepts root of the tree, k and node as input 
parameters, and returns the kth ancestor of Node which contains node as its value.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=10^5
1<= K <= 100
1 <= Node.data <= N
*/

/*
// Solution of question 4:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(height) where height is tree height

struct Node
{
	int data;
	struct Node *left, *right;
};

// your task is to complete this function

Node* solve(Node* root, int &k, int node)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == node)
    {
        return root;
    }

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k , node);

    if(ans == NULL || ans->data == node)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}

*/

/*
Q.5. Given a binary tree with a value associated with each node, we need to choose a subset of these nodes 
such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be 
directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents 
in consideration and vice versa.

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.

Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts 
root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
*/

/*
// Solution of question 5:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(height) where height is tree height

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.

    pair<int, int> solve(Node* root)
    {
        if(root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;

        res.first = root->data + left.second + right.second;

        res.second = max(left.first, left.second) + max(right.first, right.second);

        return res;

    }

    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);

        return max(ans.first, ans.second);
    }
};
*/