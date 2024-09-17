/*
Q.1. Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
In zig zag traversal starting from the first level go from left to right for odd-numbered levels and 
right to left for even-numbered levels.

Example 1:

Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
Output:
1 3 2 4 5 6 7
Explanation:
For level 1 going left to right, we get traversal as {1}.
For level 2 going right to left, we get traversal as {3,2}.
For level 3 going left to right, we get traversal as {4,5,6,7}.
Merging all this traversals in single array we get {1,3,2,4,5,6,7}

Example 2:

Input:
           7
         /   \
       9      7
     /  \    /   
    8   8   6     
   /  \
  10  9 
Output:
7 7 9 8 8 6 9 10 
Explanation:
For level 1 going left to right, we get traversal as {7}.
For level 2 going right to left, we get traversal as {7,9}.
For level 3 going left to right, we get traversal as {8,8,6}.
For level 4 going right to left, we get traversal as {9,10}.
Merging all this traversals in single array we get {7,7,9,8,8,6,9,10}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal()
which takes the root node of the Binary Tree as its input and returns a list containing the node values as 
they appear in the zig-zag level-order traversal of the tree.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 10^5
*/

/*
// Solution of question 1:-
// Time Complexity = O(n) where n is number of nodes
// Space Complexity = O(n) where n is number of nodes

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
        if(root == NULL)
        {
            return result;
        }

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            for(int i = 0; i < size(); i++)
            {
                Node* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if(frontNode->left)
                {
                    q.push(frontNode->left);
                }
                if(frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }

            leftToRight = !leftToRight;
            
            for(auto i : ans)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};
*/


/*
Q.2. Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach 
when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node
you could reach when you always travel preferring the right subtree over the left subtree. 
Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
Explanation:

As you can see we have not taken the right subtree. 

Your Task:
This is a function problem. You don't have to take input. Just complete the function boundary() that 
takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^5

*/

/*
// Solution of question 2:-

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:

    void traverseLeft(Node* root, vector<int> &ans)
    {
        if((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return ;
        }
        
        ans.push_back(root->data);

        if(root->left)
        {
            traverseLeft(root->left, ans);
        }
        else
        {
            traverseLeft(root->right, ans);
        }
    }

    void traverseLeaf(Node* root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node* root, vector<int> &ans)
    {
        if((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        if(root->right)
        {
            traverseRight(root->right, ans);
        }
        else
        {
            traverseRight(root->left, ans);
        }

        ans.push_back(root->data);
        
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }

        ans.push_back(root->data);

        traverseLeft(root->left, ans);

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        traverseRight(root->right, ans);

        return ans;
    }
};
*/

/*
Q.3. Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear 
in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6

Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() 
which takes the root node as input parameter and returns an array containing the vertical order traversal 
of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, 
they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 3*10^4
*/

/*
// Solution of question 3:-

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int> > > nodes;
        queue<pair<Node*, pair<int, int> > > q;
        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }

        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty())
        {
            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            }

            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
        }

        for(auto i: nodes)
        {
            for(auto j: i.second)
            {
                for(auto k: j.second)
                {
                    ans.push_back(k);
                }
            }
        }

        return ans;
    }
};
*/

/*
Q.4. Given below is a binary tree. The task is to print the top view of binary tree. 
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5   6     7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree 
and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. 
Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that 
takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10^5
1 ≤ Node Data ≤ 10^5
*/

/*
// Solution of question 4:-

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }

        map<int, int> topNode;
        queue<pair<Node*, int> > q;

        q.push(make_pair(root, 0));

        while(!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            if(topNode.find(hd) == topNode.end())
            {
                topNode[hd] = frontNode->data;
            }

            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left, hd-1));
            }

            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right, hd+1));
            }
        }

        for(auto i: topNode)
        {
            ans.push_back(i.second);
        }

        return ans;
    }

};
*/

/*
Q.5. Given a binary tree, return an array where elements represent the bottom view of the binary tree from 
left to right.

A node is included in the bottom view if it can be seen when we look at the tree from the bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /  \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, 
then the latter one in the level traversal is considered. For example, in the below diagram, 
3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5
*/

/*
// Solution of question 5:-

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }

        map<int, int> topNode;
        queue<pair<Node*, int> > q;

        q.push(make_pair(root, 0));

        while(!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            topNode[hd] = frontNode->data;

            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left, hd-1));
            }

            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right, hd+1));
            }
        }

        for(auto i: topNode)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};
*/

/*
Q.6. Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible 
when tree is visited from Left side. The task is to complete the function leftView(), which accepts 
root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \  /   \
  4     5  6     7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
0 <= Data of a node <= 1000
*/

/*
// Solution of question 6:-

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

void solve(Node* root, vector<int>& ans, int level)
{
    if(root == NULL)
    {
        return;
    }

    if(level == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);

}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);

   return ans;
}

*/

/*
Q.7. Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes 
visible when tree is viewed from right side. Return the right view as a list. 

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /  \
  4     5    6    7
    \
     8

Examples :

Input:
       1
    /    \
   3      2
Output: 1 2

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 10^5
0 ≤ Data of a node ≤ 10^5
*/

/*
// Solution of question 7:-

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


// Should return right view of tree
class Solution
{
    public:
    void solve(Node* root, vector<int>& ans, int level)
    {
        if(root == NULL)
        {
            return;
        }

        if(level == ans.size())
        {
            ans.push_back(root->data);
        }

        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }

    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root, ans, 0);

       return ans;
    }
};

*/