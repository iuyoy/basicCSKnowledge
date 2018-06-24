/*
On a table are N cards, with a positive integer printed on the front and back of each card (possibly different).

We flip any number of cards, and after we choose one card.

If the number X on the back of the chosen card is not on the front of any card, then this number X is good.

What is the smallest number that is good?  If no number is good, output 0.

Here, fronts[i] and backs[i] represent the number on the front and back of card i.

A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.

Example:

Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
Output: 2
Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good.


Note:

1 <= fronts.length == backs.length <= 1000.
1 <= fronts[i] <= 2000.
1 <= backs[i] <= 2000.
*/
// O(n^2) this method can be converted to the below one
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ret = INT_MAX;
        for(int i=0; i<fronts.size(); ++i)
            if(fronts[i] != backs[i]){
                int j = 0;
                for(; j<fronts.size(); ++j){
                    if(j!=i && fronts[j] == backs[i] && backs[j] == backs[i])
                        break;
                }
                if(j == fronts.size())
                    ret = min(ret, backs[i]);
                for(j=0; j<fronts.size(); ++j){
                    if(j!=i && fronts[j] == fronts[i] && backs[j] == fronts[i])
                        break;
                }
                if(j == fronts.size())
                    ret = min(ret, fronts[i]);
            }
        if(ret == INT_MAX)
           return 0;
        return ret;
    }
};
// HashSet O(n)
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ret = 3000;
        unordered_set<int> same;
        for(int i=0;i<fronts.size();++i)
            if(fronts[i] == backs[i])
                same.insert(fronts[i]);
        for(int i=0;i<fronts.size();++i){
            if(same.find(fronts[i]) == same.end())
                ret = min(ret, fronts[i]);
            if(same.find(backs[i]) == same.end())
                ret = min(ret, backs[i]);
        }
        if(ret == 3000)
           return 0;
        return ret;
    }
};
