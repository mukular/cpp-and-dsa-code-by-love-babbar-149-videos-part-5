/*
Q.1. You are given an array ARR of integers of length N.Your task is to 
find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the
right of that element which has a value strictly smaller than that element.
If for any array element the next smaller element does not exist, you should
print -1 for that array element. 

Constraints:-
1 <= T <= 10
1 <= N <= 10^5
0 <= ARR[i] <= 10^9

Sample Input 1:
2        // T
4        // N
2 1 4 3     // ARR
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1
Explanation For Sample Input 1:
For the first test case : 
1) For ARR [1] = 2 ,  the next smaller element is 1. 
2) For ARR [2] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
3) For ARR [3] = 4 ,  the next smaller element is 3.
4) For ARR [4] = 3 ,  the next smaller element is -1 as no element exists in the right of it.
Hence, we will return the array [ 1, -1, 3, -1] in this case.

For the second test case :
1) For ARR [1] = 1 ,  the next smaller element is -1 as no element in the array has value smaller than 1.
2) For ARR [2] = 3 ,  the next smaller element is 2.
3) For ARR [3] = 2 ,  the next smaller element is -1 as no element exists in the right of it.
Hence we will return the array [ -1, 2, -1 ] in this case.
Sample Input 2:
2
4
1 2 3 4
2
5 0
Sample Output 2:
-1 -1 -1 -1
 0 -1
*/

/*
// Time Complexity = O(n)

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1; i >=0; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
*/

/*
Q.2. Given an array of integers heights representing the histogram's bar 
height where the width of each bar is 1, return the area of the largest 
rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10

Example 2:
Input: heights = [2,4]
Output: 4
 
Constraints:
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

/*
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
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

    vector<int> prevSmallerElement(vector<int> arr, int n)
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

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
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
};
*/