/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
//Hash O(n) BinSearch avg O(logn)? Worst O(nlogn)
class Solution {
private:
    bool bSearch(vector<int>& numbers, int target, int start, int* end){
        if(start<=*end){
            int mid = start + (*end - start)/2;
            // cout<<start<<" "<<mid<<" "<<*end<<endl;
            if(numbers[mid] == target){
                *end = mid;
                return true;
            }
            if(numbers[mid] < target)
                return bSearch(numbers, target, mid+1, end);
            if(numbers[mid] > target){
                *end = mid - 1;
                return bSearch(numbers, target, start, end);

            }

        }
        return false;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        vector<int> ret;
        if(n>1){
            int i = 0, end = n-1;
            for(;i<n;++i){
                if(end<=i)
                    break;
                if(bSearch(numbers, target - numbers[i], i + 1, &end)){
                    ret.push_back(i+1);
                    ret.push_back(end+1);
                    break;
                }
            }
        }
        return ret;
    }
};
