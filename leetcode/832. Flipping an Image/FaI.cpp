/*
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/
// Math O(m*n)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        if(m==0) return A;
        int n = A[0].size()-1;
        for(int i=0; i<m; ++i)
            for(int j=n/2; j>=0; --j){
                int temp = !A[i][j];
                A[i][j] = !A[i][n-j];
                A[i][n-j] = temp;
            }
        return A;
    }
};

// 更优雅
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ret;
        for(int start = 0, i = 0; i<=S.size(); ++i)
            if(i == S.size() || S[i] != S[start]){
                if(i-start>2)
                    ret.push_back({start, i-1});
                start = i;
            } 
        return ret;
    }
};

/*
"abbxxxxzzy"
"abc"
"abcdddeeeeaabbbcd"
"aaa"
*/