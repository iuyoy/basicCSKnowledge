/*
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 

Example 1:

Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
 

Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
*/
// max_heap and umap. O(lgn)-push O(1)-pop
class FreqStack {
public:
    unordered_map<int, int> umap;
    priority_queue<vector<int>> pq;
    int loc;
    FreqStack() {
        loc = 0;
    }
    
    void push(int x) {
        pq.push({++umap[x], loc++, x});
    }
    
    int pop() {
        auto ret = pq.top();
        pq.pop();
        umap[ret[2]] --;
        return ret[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */

// umap store count and stack. O(1)-push O(1)-pop
class FreqStack {
public:
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> order;
    int top;
    FreqStack() {
        top = 0;
    }
    
    void push(int x) {
        order[++count[x]].push(x);
        top = max(top, count[x]);
    }
    
    int pop() {
        int ret = order[top].top();
        order[top].pop();
        count[ret]--;
        if(order[top].empty()) --top;
        return ret;
    }
};