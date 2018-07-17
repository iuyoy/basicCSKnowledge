/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
// DP Looks ugly O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ug({1});
        vector<vector<int>> index({{0, 2}, {0,3}, {0,5}});

        while(ug.size() < n){
            if(index[0][1]<index[1][1] && index[0][1]<index[2][1]){
                if(index[0][1] != ug.back())
                    ug.push_back(index[0][1]);
                ++index[0][0];
                index[0][1] = ug[index[0][0]] * 2;
            }else if(index[1][1]<index[2][1]){
                if(index[1][1] != ug.back())
                    ug.push_back(index[1][1]);
                ++index[1][0];
                index[1][1] = ug[index[1][0]] * 3;
            }else{
                if(index[2][1] != ug.back())
                    ug.push_back(index[2][1]);
                ++index[2][0];
                index[2][1] = ug[index[2][0]] * 5;
            }
        }
        return ug.back();
    }
};

// More beautiful O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ug(n, 1);
        int i2=0, i3=0, i5=0;
        for(int i=1; i<n; ++i){
            int ug2 = ug[i2]*2;
            int ug3 = ug[i3]*3;
            int ug5 = ug[i5]*5;
            ug[i] = min(ug2, min(ug3, ug5));
            if(ug[i] == ug2) ++i2;
            if(ug[i] == ug3) ++i3;
            if(ug[i] == ug5) ++i5;
        }
        return ug.back();
    }
};
