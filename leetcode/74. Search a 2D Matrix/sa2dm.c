/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int left = 0,right = matrixRowSize-1;
    int middle;
    if(matrixRowSize==0)
        return false;
    while(1){
        if(left>right)
            return false;
        middle = (left+right)/2;
        // printf("%d, %d\n",middle,matrixRowSize);
        if(matrix[middle][0]<= target && (middle == matrixRowSize-1 || target<matrix[middle+1][0]))
            break;
        if(matrix[middle][0]>target)
            right = middle-1;
        else
            left = middle+1;
    }
    left = 0; right = matrixColSize-1;
    int row = middle;
    while(1){
        if(left>right)
            return false;
        middle = (left+right)/2;
        // printf("matrix[%d][%d]==%d\n",row, middle,matrix[row][middle]);
        if(matrix[row][middle] == target)
           return true;
        if(matrix[row][middle]>target)
           right = middle - 1;
        else
           left = middle + 1;
    }

}
