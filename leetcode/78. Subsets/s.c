/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void resetPoints(int *points, int pointsSize){
    int point_i = 0;
    while(point_i <= pointsSize)
        points[point_i] = point_i++;
}
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    (*returnSize) = (int) pow(2, numsSize);
    (*columnSizes) = (int *) malloc(sizeof(int) * (*returnSize));
    int *points = (int *) malloc(sizeof(int) * numsSize);
    int **ret = (int**) malloc(sizeof(int *) * (*returnSize));
    int ret_i = 1;
    int point_count = 0;
    int point_i;
    ret[0] = (int*) malloc(sizeof(int));
    (*columnSizes)[0] = 0; // Must have a pair of bracket.
    while(point_count < numsSize){
        for(;points[point_count]<numsSize;points[point_count]++,ret_i++){
            int *set = (int *) malloc( sizeof(int) * (point_count + 1) );
            (*columnSizes)[ret_i] = point_count + 1;

            for(point_i=0; point_i<=point_count; point_i++){
                set[point_i] = nums[points[point_i]];
                // printf("%d ",set[point_i]);
            }
            // printf("\n");
            ret[ret_i] = set;
        }
        if(point_count > 0 && points[point_count-1] != points[point_count] - 1){
             for(point_i=0;point_i<point_count;point_i++){
                    points[point_i]++;
                }
            points[point_count] = points[point_count - 1] + 1;
        }
        else{
            resetPoints(points, ++point_count);
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
