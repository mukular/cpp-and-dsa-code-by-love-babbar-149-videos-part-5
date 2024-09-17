/*
Q.1. A celebrity is a person who is known to all but does not 
know anyone at a party. If you go to a party of N people, find 
if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party 
such that if an element of row i and column j  is set to 1 it means 
ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)

Example 1:
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:
Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. 
Complete the function celebrity() which takes the 
matrix M and its size N as input parameters and 
returns the index of the celebrity. If no such 
celebrity is present, return -1.

Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(1)

Constraints:
2 <= N <= 3000
0 <= M[][] <= 1
*/

/*
// Time Complexity = O(n)

class Solution{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n)
    {
        if(M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public:
    int celebrity(vector<vector<int> >& M, int n)
    {
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while(s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if(knows(M,a,b,n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int candidate = s.top();
        bool rowCheck = false;
        int zeroCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(M[candidate][i] == 0)
            {
                zeroCount++;
            }
        }

        if(zeroCount == n)
        {
            rowCheck = true;
        }

        bool colCheck = false;
        int oneCount = 0;

        for(int i = 0; i < n; i++)
        {
            if(M[i][candidate] == 1)
            {
                oneCount++;
            }
        }

        if(oneCount == n-1)
        {
            colCheck = true;
        }

        if(rowCheck == true && colCheck == true)
        {
            return candidate;
        }
        else
        {
            return -1;
        }

    }
}
*/

/*
Q.2. Given a binary matrix M of size n X m. Find the maximum 
area of a rectangle formed only of 1s in the given matrix.

Example 1:
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8

Your Task: 
Your task is to complete the function maxArea which returns the maximum 
size rectangle area in a binary-sub-matrix with all 1’s. The function takes 
3 arguments the first argument is the Matrix M[ ] [ ] and the next two are 
two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1
*/

/*
// Time Complexity = O(n*m)
// Space Complexity = O(m)

class Solution{
    private:
    vector<int> nextSmallerElement(int *arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n-1; i >=0; i--)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int* arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int* heights, int n) {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        int area = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int l = heights[i];
            if(next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] -1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

    public:
    int maxArea(int M[max][max], int n, int )
    {
        int area = largestRectangleArea(M[0], m);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }

        return area;


    }
}
*/