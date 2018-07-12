/*
Virtual User Accepted: 0
Virtual User Tried: 0
Virtual Total Accepted: 0
Virtual Total Submissions: 0
Difficulty: Medium
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1
*/
// O(n^4) O(1)
// calculate the overlap of each translation.
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int ret = 0;
        // Translate image
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j){
                // Calculate overlap
                // There are four cases: move to left-up, left-down, right-up, right-down.
                vector<int> rets(4);
                for(int x=0; x<n; ++x)
                    for(int y=0; y<n; ++y){
                        if(B[x][y] && A[(x+i)%n][(y+j)%n] == B[x][y])
                            if(x+i>=n)
                                if(y+j>=n)
                                    ++rets[0];
                                else
                                    ++rets[1];
                            else
                                if(y+j>=n)
                                    ++rets[2];
                                else
                                    ++rets[3];
                    }
                for(int r:rets)
                    ret = max(r, ret);
            }
        return ret;
    }
};

// Calculate all overlap for each 1. store the count in extra space
// O(n^4) O(n^2)
// Faster than above mathod 