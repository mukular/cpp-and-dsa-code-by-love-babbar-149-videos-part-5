/*
Q.1. Given a binary tree, find its height.

Example 1:

Input:
     1
    /  \
   2    3
Output: 2

Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

Your Task:
You don't need to read input or print anything. Your task is to complete the function height() which 
takes root node of the tree as input parameter and returns an integer denoting the height of the tree. 
If the tree is empty, return 0. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^9
*/

/*
// Solution of question 1:-
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

class Solution{
    public:
    //Function to find the height of a binary tree.

    int height(struct Node* node){
        if(node == NULL)
        {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }
};
*/

/*
Q.2. The diameter of a tree (sometimes called the width) is the number of nodes on the longest path 
between two end nodes. 

Example 1:

Input:
       1
     /  \
    2    3
Output: 3

Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000
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

class Solution {
  public:

    // below function returns diameter and height in form of pair
    pair<int, int> diameterFast(Node* root)
    {
        if(root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        
        ans.first = max(op1, max(op2, op3));
        ans.second =  max(left.second, right.second) + 1;

        return ans;

    }

    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
*/

/*
Q.3. Given a binary tree, find if it is height balanced or not.  A tree is height balanced 
if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

Examples:

Input:
      1
    /
   2
    \
     3 
Output: 0

Explanation: The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height of left subtree and right subtree is 1. Hence balanced.

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^9

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree
*/

/*
// Solution of question 3:-
// Time Complexity = O(n) where n is number of nodes

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

class Solution{
    public:

    // below function returns tree is balanced or not and height of tree in form of pair
    pair<bool, int> isBalancedFast(Node* root)
    {
        if(root == NULL)
        {
            pair<bool , int> p = make_pair(true, 0);
            return p;
        }

        pair<int, int> left = isBalancedFast(root->left);
        pair<int, int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if(leftAns && rightAns && diff)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }

        return ans;
    } 

    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};
*/

/*
Q.4. Given two binary trees, the task is to find if both of them are identical or not.
Note: You need to return true or false, the printing is done by the driver code.

Example 1:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: 
Yes
Explanation: 
There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.

Example 2:

Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: 
No
Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function 
isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10^5
1 <=Data of a node <= 10^9

*/

/*
// Solution of question 4:-

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
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if(r1 == NULL && r2 != NULL)
        {
            return false;
        }
        if(r1 != NULL && r2 == NULL)
        {
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);

        bool value = r1->data == r2->data;

        if(left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
*/

/*
Q.5. Given a Binary Tree, return true if, for every node x in the tree other than the leaves, 
its value is equal to the sum of its left subtree's node values and its right subtree's node values. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
A leaf node is also considered a Sum Tree.

Examples :

Input:
    3
  /   \    
 1     2

Output: 1
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.

Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and 
sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)


Constraints:
1 ≤ number of nodes ≤ 10^4

1 ≤ node value ≤ 10^4
*/

/*
// Solution of question 5:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(height) where height is height of tree

struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:

    pair<bool, int> isSumTreeFast(Node* root)
    {
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        if(root->left == NULL && root->right == NULL)
        {
            pair<bool , int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);

        bool left = leftAns.first;
        bool right = rightAns.first;

        bool condn = root->data == leftAns.second + rightAns.second;

        pair<bool, int> ans;

        if(left && right && condn)
        {
            ans.first = true;
            ans.second = 2*root->data;
        }
        else
        {
            ans.first = false;
        }

        return ans;
    }

    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};
*/