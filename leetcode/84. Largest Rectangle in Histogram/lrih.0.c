/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

// advanced DFS - O(n^2)
int largestRectangleArea(int* heights, int heightsSize) {
    int max = 0;
    int i = 0, height=0;
    int j, count;
    for(;i<heightsSize;++i){
        if(height!=heights[i]){
            count = 1;
            height = heights[i];
            for(j=i-1;j>=0&&heights[j]>=height;--j,++count);
            for(j=i+1;j<heightsSize&&heights[j]>=height;++j,++count);
            if(height*count > max)
                max = height*count;
        }
    }
    return max;
}

// BFS with stack - <=O(n^2)  LTE
typedef struct stack_node {
    int top;
    unsigned capacity;
    int * array;
}Stack, *pStack;

pStack createStack(unsigned capacity){
    pStack stack = (pStack) malloc(sizeof(Stack));
    if(stack){// Check malloc result
        stack->capacity = capacity;
        stack->top = -1;
        stack->array = (int *) malloc(sizeof(int) * capacity);
        if(stack->array) // Check malloc result
            return stack;
    }
    return NULL;
}
int isFull(pStack stack){
    return stack->top == stack->capacity - 1;
}
int isEmpty(pStack stack){
    return stack->top == -1;
}
int push(pStack stack, int item){
    if(isFull(stack))
        return 0;
    stack->array[++stack->top] = item;
    return 1;
}
int pop(pStack stack, int *top){
    if(isEmpty(stack))
        return 0;
    *top = stack->array[stack->top--];
    return 1;
}
void removeALL(pStack stack) {
    int temp;
    while(pop(stack, &temp));
}
void displayStack(pStack stack){
    int i = 0;
    for(i=0;i<=stack->top;i++){
        printf("%d->", stack->array[i]);
    }
    printf("top\n");
}

int largestRectangleArea(int* heights, int heightsSize) {
    int max = 0;
    int i = 0, j;
    int now;
    int* sign = (int *)malloc(sizeof(int)*heightsSize);
    memset(sign, 0, sizeof(int)*heightsSize);
    pStack stack = createStack(heightsSize);
    // printf("\n", i);
    while(i<heightsSize){
        // printf("%d:%d\n", i, heights[i]);
        now = heights[i];
        sign[i] = 1;
        push(stack, i);
        for(j=i+1;j<heightsSize&&heights[j]>0;++j){
               if(heights[j]<now){
                    if(now*(1+stack->top) > max)
                        max = now*(1+stack->top);
                    now = heights[j];
                    sign[j] = 1;
                    // printf("j:%d:%d\n", j, heights[j]);
                }
            push(stack, j);
        }
        if(now*(1+stack->top) > max)
            max = now*(1+stack->top);
        removeALL(stack);
        while(sign[i]){
            // printf("pass %d:%d\n",i,sign[i]);
            ++i;
        }

    }
    return max;
}

//Advanced BFS with stack - <=O(n^2) AC
typedef struct stack_node {
    int top;
    unsigned capacity;
    int * array;
}Stack, *pStack;

pStack createStack(unsigned capacity){
    pStack stack = (pStack) malloc(sizeof(Stack));
    if(stack){// Check malloc result
        stack->capacity = capacity;
        stack->top = -1;
        stack->array = (int *) malloc(sizeof(int) * capacity);
        if(stack->array) // Check malloc result
            return stack;
    }
    return NULL;
}
int isFull(pStack stack){
    return stack->top == stack->capacity - 1;
}
int isEmpty(pStack stack){
    return stack->top == -1;
}
int push(pStack stack, int item){
    if(isFull(stack))
        return 0;
    stack->array[++stack->top] = item;
    return 1;
}
int pop(pStack stack, int *top){
    if(isEmpty(stack))
        return 0;
    *top = stack->array[stack->top--];
    return 1;
}
void removeALL(pStack stack) {
    int temp;
    while(pop(stack, &temp));
}
void displayStack(pStack stack){
    int i = 0;
    for(i=0;i<=stack->top;i++){
        printf("%d->", stack->array[i]);
    }
    printf("top\n");
}

int largestRectangleArea(int* heights, int heightsSize) {
    int max = 0;
    int i1=0,i2=heightsSize-1, j;
    int now;
    int* sign = (int *)malloc(sizeof(int)*heightsSize);
    int* record = (int *)malloc(sizeof(int)*heightsSize);
    memset(sign, 0, sizeof(int)*heightsSize);
    pStack stack = createStack(heightsSize);
    // printf("\n", i);
    while(1){
        // printf("%d:%d\n", i, heights[i]);
        while(sign[i1]&&i1<=i2){
            // printf("pass %d:%d\n",i1,sign[i1]);
            ++i1;
        }
        if(i1>i2)
            break;
        now = heights[i1];
        sign[i1] = 1;
        push(stack, i1);
        for(j=i1+1;j<heightsSize&&heights[j]>0;++j){
               if(heights[j]<now){
                    if(now*(1+stack->top) > max)
                        max = now*(1+stack->top);
                    now = heights[j];
                    sign[j] = 1;
                    // printf("j:%d:%d\n", j, heights[j]);
                }else if(heights[j]==now)
                   sign[j] = 1;
            push(stack, j);
        }
        if(now*(1+stack->top) > max)
            max = now*(1+stack->top);
        removeALL(stack);
        while(sign[i2]==1&&i2>0) --i2;
        if(i2==-1) break;
        // printf("2\n");
        now = heights[i2];
        sign[i2] = 1;
        push(stack, i2);
        // printf("3\n");
        for(j=i2-1;j>=0&&heights[j]>0;--j){
            if(heights[j]<now){
                if(sign[j]==1)
                    break;
                if(now*(1+stack->top) > max)
                    max = now*(1+stack->top);
                now = heights[j];
                sign[j] = 1;
                // printf("j:%d:%d\n", j, heights[j]);
            }else if(heights[j]==now)
                sign[j] = 1;
            push(stack, j);
        }
        // printf("4\n");
        if(now*(1+stack->top) > max)
            max = now*(1+stack->top);
        removeALL(stack);
    }
    return max;
}
