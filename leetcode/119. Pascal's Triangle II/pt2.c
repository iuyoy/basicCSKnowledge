/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//SC O(k)
int* getRow(int rowIndex, int* returnSize) {
    (*returnSize) = rowIndex + 1;
    int* ret = (int*) malloc(sizeof(int)*(*returnSize));
    ret[0] = 1;
    ret[rowIndex] = 1;
    int i = 1;
    while(i<(*returnSize+1)/2){
        ret[i] = ((long)ret[i-1]*(rowIndex - i + 1))/i;
        ret[rowIndex-i] = ret[i++];
    }
    return ret;
}
