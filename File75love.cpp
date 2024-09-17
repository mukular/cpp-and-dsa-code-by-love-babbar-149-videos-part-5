// Binary Search Tree
/*The tree in which for every node, data in left part(subtree) of that node is 
less than data of that node and data in right part(subtree) of that node is greater
than data of that node.
*/

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            
        }
    }

}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// Time Complexity of inserting a node in BST = O(log(n))
Node* insertIntoBST(Node* root, int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

Node* minVal(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node* temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

// deleting a node in BST
// Time Complexity = O(height of tree)
// Time Complexity(worst case) = O(n)
Node* deleteFromBST(Node* root, int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data == val)
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int main()
{
    Node* root = NULL;

    cout<<"Enter data to create BST"<<endl;

    // Input:-
    // 50 20 70 10 30 90 110 -1
    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    // Inorder of BST is sorted
    cout<<"Printing inorder "<<endl;
    inorder(root);

    cout<<endl<<"Printing preorder "<<endl;
    preorder(root);

    cout<<endl<<"Printing postorder "<<endl;
    postorder(root);

    cout<<endl<<"Min value is "<<minVal(root)->data<<endl;
    cout<<"Max value is "<<maxVal(root)->data<<endl;

    root = deleteFromBST(root, 30);

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing inorder "<<endl;
    inorder(root);

    cout<<endl<<"Printing preorder "<<endl;
    preorder(root);

    cout<<endl<<"Printing postorder "<<endl;
    postorder(root);

    cout<<endl<<"Min value is "<<minVal(root)->data<<endl;
    cout<<"Max value is "<<maxVal(root)->data<<endl;

    return 0;
}

/*
Q.1.There is a Binary Search Tree (BST) consisting of ‘N’ nodes. Each 
node of this BST has some integer data.
You are given the root node of this BST, and an integer ‘X’. Return true 
if there is a node in BST having data equal to ‘X’, otherwise return false.

A binary search tree (BST) is a binary tree data structure that has the 
following properties:

1. The left subtree of a node contains only nodes with data less than the 
node’s data.

2. The right subtree of a node contains only nodes with data greater than 
the node’s data.

3. The left and right subtrees must also be binary search trees.
Note:
It is guaranteed that all nodes have distinct data.
Sample Input 1:
7 8
4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
False
Explanation For Sample Input 1:
There is no node having data 8.
Sample Input 2:
4 1
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 2:
True
Explanation For Sample Input 2:
There is a left node, and it has data 1. Thus, we should print ‘True’. 
Constraints:
1 <= N <= 10000
0 <= X <= 10^9
0 <= DATA <=10^9

Where ‘N’ is the number of nodes in the BST, ‘X’ is a given integer and 
‘DATA’ is the data contained in each node of BST.

Time limit: 1 sec
*/

/*
// Solution of question 1:-

Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp = root;

    while(temp != NULL)
    {
        if(temp->data == x)
        {
            return true;
        }
        if(temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return false;
}
*/