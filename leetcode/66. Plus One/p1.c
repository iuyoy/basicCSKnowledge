/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int * ret = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(ret, 0, sizeof(int) * (digitsSize + 1));
    int i = digitsSize;
    for(;i>0&&digits[i-1]+1==10;--i)
        ret[i] = 0;
    ret[i] = digits[i-1] + 1;
    --i;
    for(;i>=0;--i)
        ret[i] = digits[i-1];
    if(ret[0]){
        (*returnSize) = digitsSize + 1;
        return ret;
    }
    (*returnSize) = digitsSize;
    return &ret[1];
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int * ret = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(ret, 0, sizeof(int) * (digitsSize + 1));
    int i = digitsSize - 1;
    ret[0] = 1;
    for(;i>=0;--i){
        if(digits[i]+ret[0]==10){
            ret[0] = 1;
            ret[i+1] = 0;
        }else{
            ret[i+1] = digits[i] + ret[0];
            ret[0] = 0;
        }
    }
    if(ret[0]){
        (*returnSize) = digitsSize + 1;
        return ret;
    }
    (*returnSize) = digitsSize;
    return &ret[1];
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int * ret = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(ret, 0, sizeof(int) * (digitsSize + 1));
    int i = digitsSize - 1;
    int *p = &ret[1];
    ret[0] = 1;
    for(;i>=0;--i){
        if(digits[i]+ret[0]==10){
            ret[0] = 1;
            p[i] = 0;
        }else{
            p[i] = digits[i] + ret[0];
            ret[0] = 0;
        }
    }
    if(ret[0]){
        (*returnSize) = digitsSize + 1;
        return ret;
    }
    (*returnSize) = digitsSize;
    return &ret[1];
}
