#include <stdio.h>
#include <stdlib.h>
/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers->
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

//BackTrack 

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
    rs->sum -= candidates[i];
    --rs->count;
    return bt(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
}
void bt(resStack rs, int* candidates, int candidatesSize, int i, int target, int*** ret, int** columnSizes, int* returnSize){
    // printf("index：%d, candidates[%d]:%d,target:%d,rs->count:%d,rs.sum:%d",i,i,candidates[i],target,rs->count,rs->sum);
    if(i<candidatesSize){
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
            for(int column_i = 0; column_i<rs->count; ++column_i){
                ret_column[column_i] = candidates[top->value];
                // printf("%d\n", top->value);
                top = top->next;
            }
            (*ret)[(*returnSize)++] = ret_column;
            return endOfTrack(rs, candidates, candidatesSize, i, target, ret, columnSizes, returnSize);
        }
        return bt(rs, candidates, candidatesSize, i, target, ret, columnSizes, returnSize);
    }
    if(!rs->stack)
        return;
    return endOfTrack(rs, candidates, candidatesSize, i, target, ret, columnSizes, returnSize);
    // rs->stack = pop(rs->stack, &i);
    // // printf("index：%d pop out of stack\n", i);
    // rs->sum -= candidates[i];
    // --rs->count;
    // return bt(rs, candidates, candidatesSize, i+1, target, ret, columnSizes, returnSize);
}
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int** ret = (int**) malloc(sizeof(int *)*100000);
    int i = 0;
    resStack rs = (resStack) malloc(sizeof(struct resultStack));
    initResult(rs);
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
