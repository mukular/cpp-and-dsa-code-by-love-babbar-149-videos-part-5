// Binary trees
// tree is a non-linear data structure.

/*
1. Binary tree :-  The tree which has less than or equal to two ( <= 2)child .
2. Root :- Top node of tree .

Example binary tree used in below terms:-
        1
       / \
      3   7
     / \   \
    4   9   8

3. children :- 9 is child of 3 .
4. Parent :- 3 is parent of 9 . Similarly, 7 is parent of 8 .
5. Siblings :- Those have same parent. Ex. 9 and 4 are siblings .
6. Ancestors :- 3 and 1 are ancestors of 4 .
7. Descendents :- 7 and 8 are descendents of 1 .
8. Leaf :- The node which does not have any child . Ex. 4, 9 and 8 are leaf node.

Traversal of binary tree:-

1. Inorder :- L N R
2. Preorder :- N L R
3. Postorder :- L R N

where L is left node, R is right node and N is node itself print. 

*/

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
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

void inorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    /*

    Input for this binary tree:-
    1
    3
    7
    -1
    -1
    11
    -1
    -1
    5
    17
    -1
    -1
    -1


        1
       / \
      3   5
     / \  /
    7  11 17

    */

    node* root = NULL;

    root = buildTree(root);

    // level order traversal
    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal is: ";
    inorder(root);

    cout<<endl<<"preorder traversal is: ";
    preorder(root);

    cout<<endl<<"postorder traversal is: ";
    postorder(root);

    /*
    Input for this:- 

    1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    */
    node* root1 = NULL;

    buildFromLevelOrder(root1);
    levelOrderTraversal(root1);

    return 0;
}


/*

Q.1. You are given a Binary tree. You have to count and return the number of leaf nodes present in it.

A binary tree is a tree data structure in which each node has at most two children, 
which are referred to as the left child and the right child

A node is a leaf node if both left and right child nodes of it are NULL.

Constraints:
1 <= T <= 100
1 <= N <=10^3
1 <= data <= 10^9

Time Limit : 1 sec
Sample Input 1:
3
1 -1 -1
1  2  3  -1 -1 -1 4 -1 -1
1  2 -1 -1 3 -1 4 -1 -1
Sample Output 1:
1
2
1
Explanation For Sample Input 1:
(i) 1 is the only node present in the tree, and hence it is the only leaf node.
(ii) 2 and 4 are two leaf nodes present in the tree; all other nodes have at least one child (1 has 2 and 3 and 3 has 4).
(iii) 4 is the only leaf node present in the tree as all other nodes have at least one child node (1 has 2, 2 has 3 and 3 has 4)
Sample Input 2:
3
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 2 -1 3 -1 -1
1 2 -1 3 4 5 6 7 8 -1 - 1 -1 -1 -1 -1 -1 -1
Sample Output 2:
4
1
4
Explanation For Sample Input 2:
(i) 4, 5, 6 and 7 are 4 leaf nodes present in the tree, all other nodes have at least one child (1 has 2 and 3, 2 has 4 and 5 and 3 has 6 and 7).
(ii) 3 is the only leaf node present in the tree as all other nodes have at least one child node (1 has 2 and 2 has 3)
(iii) 5, 6, 7 and 8 are 4 leaf nodes present in the tree, all other nodes have at least one child (1 has 2, 2 has 3 and 4, 3 has 5 and 6 and 4 has 7 and 8).

Following is the Binary Tree Node class structure:

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
    }
};

*/

/*
// Solution of question 1:-

void inorder(BinaryTreeNode<int> *root, int &count)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left, count);

    if(root->left == NULL && root->right == NULL)
    {
        count++;
    }

    inorder(root->right, count);

}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int cnt = 0;
    inorder(root, cnt);

    return cnt;

}

*/