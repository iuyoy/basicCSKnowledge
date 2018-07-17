/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
*/

// binary search O(nlogn + mlog(n))
// Sort the heaters first,
// For each house, find the first heater "a" before it and the first heater "b" after it.
// Take the min distance of these two Heaters.
// Take the max one of all those distances.
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(houses.size() == 0) return 0;
        sort(heaters.begin(), heaters.end());
        int ret = 0;
        const int n = heaters.size();
        for(int h:houses){
            int l = 0, r = n-1,flag = 1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(heaters[mid] == h){
                    flag = 0;
                    break;

                }
                if(heaters[mid] > h)
                    r = mid-1;
                else//heaters[mid]<h
                    if(mid<n-1 && heaters[mid+1]>h){
                        int re = min(heaters[mid+1] - h, h - heaters[mid]);
                        // cout<<re<<endl;
                        ret = max(ret, re);
                        flag = 0;
                        break;
                    }
                    else
                        l = mid+1;
            }
            // cout<<l<<" "<<r<<endl;
            if(flag){
               if(l<n && heaters[l]>h)
                ret = max(ret, heaters[l]-h);
                if(r>=0 && r<n && heaters[r]<h)
                    ret = max(ret, h - heaters[r]);
            }
        }
        // cout<<endl;
        return ret;
    }
};
