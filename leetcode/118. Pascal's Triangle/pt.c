/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **rets = (int **) malloc(sizeof(int *) * numRows);
    int i = 0, j;
    (*columnSizes) = (int *) malloc(sizeof(int) * numRows);
    for(; i< numRows; ++i){
        int * ret = (int *) malloc(sizeof(int) * (i+1));
        (*columnSizes)[i] = i+1;
        for(j=0;j<=i;j++)
            if(j == 0 || j == i)
                ret[j] = 1;
            else
                ret[j] = rets[i-1][j-1] + rets[i-1][j];
        rets[i] = ret;
    }
    return rets;
}
