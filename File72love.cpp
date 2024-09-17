// Time Complexity = O(n*log(n)) for both questions where n is number of nodes

/*
Q.1. Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. 
Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1

Example 2:
Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments
(inorder traversal array, preorder traversal array, and size of tree n) and returns the root 
node to the tree constructed. You are not required to print anything and a new line is added 
automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000
*/

/*
// Solution of question 1:-

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class Solution{
    public:

    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for(int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        if(index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = pre[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];

        root->left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, index, position+1, inorderEnd, n, nodeToIndex);

        return root;

    }

    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};
*/

/*
Q.2. Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays 
in[] and post[] respectively. The task is to construct a unique binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Note:- The inorder and postorder traversals contain unique values, and every value present in the 
postorder traversal is also found in the inorder traversal.

Examples:

Input: n = 8, in[] = [4, 8, 2, 5, 1, 6, 3, 7], post[] = [8, 4, 5, 2, 6, 7, 3, 1]
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and inorder traversal of tree the  resultant binary tree
will be
          1
       /    \
     2       3
   /  \     / \
  4   5    6   7
   \
    8
Input: n = 5, in[] = [9, 5, 2, 3, 4], post[] = [5, 9, 3, 4, 2]
Output: 2 9 5 4 3
Explanation: The  resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^3
1 <= in[i], post[i] <= 10^6
*/


/*
// Solution of question 2:-

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

    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for(int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }

    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        if(index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = post[index--];
        Node* root = new Node(element);
        int position = nodeToIndex[element];

        root->right = solve(in, post, index, position+1, inorderEnd, n, nodeToIndex);
        root->left = solve(in, post, index, inorderStart, position-1, n, nodeToIndex);

        return root;

    }

    Node* buildTree(int in[],int post[], int n)
    {
        int postOrderIndex = n-1;
        map<int, int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};
*/