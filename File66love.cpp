/*
Q.1. Given a Queue Q containing N elements. The task is to reverse the 
Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Example 1:

Input:
6
4 3 1 10 2 6
Output: 
6 2 10 1 3 4
Explanation: 
After reversing the given elements of the queue , the resultant queue 
will be 6 2 10 1 3 4.

Example 2:
Input:
4
4 3 2 1 
Output: 
1 2 3 4
Explanation: 
After reversing the given elements of the queue , the resultant queue will 
be 1 2 3 4.

Your Task: You need to complete the function rev that takes a queue as 
parameter and returns the reversed queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ N ≤ 10^5
1 ≤ elements of Queue ≤ 10^5
*/

/*
// Solution of question 1:-
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;

        while(!q.empty())
        {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        while(!s.empty())
        {
            int element = s.top();
            s.pop();
            q.push(element);
        }

        return q;
    }
};

*/

/*
Q.2. Given an array A[] of size N and a positive integer K, find the first 
negative integer for each and every window(contiguous subarray) of size K.

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 
Your Task:  
You don't need to read input or print anything. Your task is to complete 
the function printFirstNegativeInteger() which takes the array A[], its 
size N and an integer K as inputs and returns the first negative number in 
every window of size K starting from the first till the end. If a window does 
not contain a negative integer , then return 0 for that window.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 10^5
-10^5 <= A[i] <= 10^5
1 <= K <= N
*/

/*
// Solution of question 2:-

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;                  
    vector<long long> ans;
    for(int i = 0; i < K; i++)
    {
        if(A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if(dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for(int i = K; i < N; i++)
    {
        if(!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        if(A[i] < 0)
        {
            dq.push_back(i);
        }

        if(dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}
*/

/*
Q.3. Given an integer K and a queue of integers, we need to reverse the 
order of the first K elements of the queue, leaving the other elements in 
the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built 
functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

Example 2:
Input:
4 4
4 3 2 1
Output: 
1 2 3 4
Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.

Your Task:
Complete the provided function modifyQueue() that takes queue and K as 
parameters and returns a modified queue. The printing is done automatically 
by the driver code.

Expected Time Complexity : O(N)
Expected Auxiliary Space : O(K)

Constraints:
1 <= K <= N <= 10^5
*/

/*
// Solution of question 3:-
// Time Complexity = O(n)
// Space Complexity = O(k)

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;

        for(int i = 0; i < k; i++)
        {
            int val = q.front();
            q.pop();
            s.push(val);
        }

        while(!s.empty())
        {
            int val = s.top();
            s.pop();
            q.push(val);
        }

        int t = q.size()-k;
        while(t--)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }

        return q;
    }
};
*/

/*
Q.4. Given an input stream A of n characters consisting only of lower case 
alphabets. While reading characters from the stream, you have to tell which 
character has appeared only once in the stream upto that point. If there are 
many characters that have appeared only once, you have to tell which one of them 
was the first one to appear. If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every i you need to consider the 
string from starting position till ith position.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.
Example 2:

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
 
Your Task:
You don't need to read or print anything. Your task is to complete the 
function FirstNonRepeating() which takes A as input parameter and returns 
a string after processing the input stream.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
 
Constraints:
1 <= n <= 10^5
*/

/*
// Solution of question 4:-

class Solution{
    public:
        string FirstNonRepeating(string A)
        {
            unordered_map<char, int> count;
            queue<int> q;
            for(int i = 0; i < A.length(); i++)
            {
                char ch = A[i];
                count[ch]++;
                q.push(ch);

                while(!q.empty())
                {
                    if(count[q.front()] > 1)
                    {
                        q.pop();
                    }
                    else
                    {
                        ans.push_back(q.front());
                        break;
                    }
                }

                if(q.empty())
                {
                    ans.push_back('#');
                }
            }

            return ans;
        }
}
*/

/*
Q.5. Suppose there is a circle. There are N petrol pumps on that circle. 
You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete 
circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:
Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
Your Task:
Your task is to complete the function tour() which takes the required data 
as inputs and returns an integer denoting a point from where a truck will 
be able to complete the circle (The truck will stop at each petrol pump 
and it has infinite capacity). If there exists multiple such starting points, 
then the function must return the first one out of those. (return -1 otherwise)

Expected Time Complexity: O(N)
Expected Auxiliary Space : O(1)

Constraints:
2 ≤ N ≤ 10000
1 ≤ petrol, distance ≤ 1000
*/

/*
// Solution of question 5:-

The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
        int deficit = 0;
        int balance = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            balance += p[i].petrol - p[i].distance;
            if(balance < 0)
            {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if(deficit + balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};
*/