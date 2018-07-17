/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    int value;
    struct stack_node * next;
}Stack, *pStack;
pStack createNode(int value){
    pStack node = (pStack) malloc(sizeof(Stack));
    if(node){// Check malloc result
        node->next = NULL;
        node->value = value;
    }
    return node;
}
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

// int isFull(pStack stack){
//     return stack->top == stack->capacity - 1;
// }
int isEmpty(pStack stack){
    return stack == NULL;
}
pStack push(pStack stack, int value){
    pStack newnode = createNode(value);
    newnode->next = stack;
    stack = newnode;
    return stack;
}
pStack pop(pStack stack, int *top){
    if(isEmpty(stack))
        return NULL;
    *top = stack->value;
    pStack top_node = stack;
    stack = stack->next;
    free(top_node);
    return stack;
}
pStack removeTop(pStack stack){
    if(isEmpty(stack))
        return NULL;
    pStack top_node = stack;
    stack = stack->next;
    free(top_node);
    return stack;
}

typedef struct resultStack{
     pStack stack;
     int sum;
     int count;
 }*resStack;

void initResult(resStack rs){
    rs->stack = NULL;
    rs->sum = 0;
    rs->count = 0;
}

void endOfTrack(resStack rs, int* candidates, int candidatesSize, int i, int target, int*** ret, int** columnSizes, int* returnSize){
    void bt(resStack rs, int* candidates, int candidatesSize, int i, int target, int*** ret, int** columnSizes, int* returnSize);
    rs->stack = pop(rs->stack, &i);
    // printf("index：%d pop out of stack\n", i);
    while(i<candidatesSize&&candidates[i]==candidates[i+1])
        ++i;
    rs->sum -= candidates[i];
    --rs->count;
    return bt(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
}
void bt(resStack rs, int* candidates, int candidatesSize, int i, int target, int*** ret, int** columnSizes, int* returnSize){
    // printf("index：%d, candidates[%d]:%d,target:%d,rs->count:%d,rs.sum:%d",i,i,candidates[i],target,rs->count,rs->sum);
    if(i>0&&candidates[i-1]==candidates[i]&&(rs->count==0||candidates[rs->stack->value] != candidates[i])){
        // if(rs->count>0)
        // printf("%d %d\n",rs->stack->value, candidates[i]);
        return bt(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
    }
    if(i<candidatesSize&&candidates[i]<=target-rs->sum){
        // printf(" push into stack\n");
        rs->stack = push(rs->stack, i);
        rs->sum += candidates[i];
        ++rs->count;
        if(rs->sum > target){
            rs->stack = pop(rs->stack, &i);
            // printf("index：%d pop out of stack\n", i);
            rs->sum -= candidates[i];
            --rs->count;
            return bt(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
        }
        if(rs->sum == target){
            // printf("Find a soution:\n");
            (*columnSizes)[(*returnSize)] = rs->count;
            int* ret_column = (int *)malloc(sizeof(int) * rs->count);
            pStack top = rs->stack;
            for(int column_i = rs->count-1; column_i>=0; --column_i){
                ret_column[column_i] = candidates[top->value];
                printf("%d:%d ",top->value, candidates[top->value]);
                top = top->next;
            }
            printf("\n" );
            (*ret)[(*returnSize)++] = ret_column;
            // printf("remove:%d %d\n", candidates[i],candidates[rs->stack->value] );
            // while(candidates[i+1] == candidates[rs->stack->value])
            //     ++i;
            return endOfTrack(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
        }
        return bt(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
    }
    if(!rs->stack)
        return;
    return endOfTrack(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
    // rs->stack = pop(rs->stack, &i);
    // // printf("index：%d pop out of stack\n", i);
    // rs->sum -= candidates[i];
    // --rs->count;
    // return bt(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int** ret = (int**) malloc(sizeof(int *)*100000);
    int i = 0;
    resStack rs = (resStack) malloc(sizeof(struct resultStack));
    initResult(rs);
    quick_sort(candidates, candidatesSize);
    // printf("rs->count:%d\n",rs->count);
    (*columnSizes) = (int*) malloc(sizeof(int)* 100000);
    (*returnSize) = 0;
    bt(rs, candidates, candidatesSize, i, target, &ret, columnSizes, returnSize);
    // for(int i = 0;i<(*returnSize); i++){
    //     for(int j = 0; j<(*columnSizes)[i]; j++){
    //         printf("%d ", ret[i][j]);
    //     }
    //     printf("\n");
    // }
    return ret;
}

int main(int argc, char const *argv[]) {
    int candidates[] = {23,32,22,19,29,15,11,26,28,20,34,5,34,7,28,33,30,30,16,33,8,15,28,26,17,10,25,12,6,17,30,16,6,10,23,22,20,29,14,5,6,5,5,6,29,20,34,24,16,7,22,11,17,7,33,21,13,15,29,6,19,16,10,21,21,28,8,6};
    int target = 27;
    // int candidates[]={10, 1, 2, 7, 6, 1, 5};
    // int target = 8;
    // int candidates[] = {1,1,2, 2,2};
    // int target = 5;
    int i,j;
    int candidatesSize = sizeof(candidates)/sizeof(candidates[0]);
    printf("%d\n", candidatesSize);


    int *columnSizes;
    int returnSize;
    int **ret = combinationSum2(candidates,candidatesSize,target,&columnSizes,&returnSize);
    for(i=0;i<candidatesSize;++i)
        printf("%d ", candidates[i]);
    printf("\n");
    for(i = 0;i<returnSize;i++){
        for(j = 0; j<columnSizes[i]; j++){
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }


    return 0;
}
