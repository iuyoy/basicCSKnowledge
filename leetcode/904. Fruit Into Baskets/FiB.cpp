/*
In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].
Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].
Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].
Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.
 

Note:

1 <= tree.length <= 40000
0 <= tree[i] < tree.length
*/

// write down the the current count of continues same type,
// and such two types. O(n)
class Solution {
public:
    int totalFruit(vector<int>& A) {
        int n = A.size();
        // if(n == 1) return 1;
        int ret = 0, types = 0;
        int type1, type2, cot = 0;
        int last_type, len = 0;
        for(int i=0; i<n; ++i){
            if(types == 0){
                type1 = A[i];
                types = 1;
                last_type = type1;
                cot = 1;
            }else if(A[i] == type1){
                ++cot;
            }else{
                if(types == 1){
                    ++types;
                    type2 = A[i];
                    ++cot;
                }else if(A[i] == type2){
                    ++cot;
                }else{
                    ret = max(ret, cot);
                    cot = len+1;
                    type1 = last_type;
                    type2 = A[i];
                }
            }
            if(A[i] == last_type)
                ++len;
            else{
                last_type = A[i];
                len = 1;
            }
            // cout<<A[i]<<" "<<cot<<endl; 
        }
        return max(ret, cot);
    }
};