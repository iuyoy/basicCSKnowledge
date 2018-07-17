/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/
// TS O(n) CS O(k)
int leastInterval(char* tasks, int tasksSize, int n) {
    int counter[26] = {0};
    int i = 0;
    int max = 0;
    int same = 1;
    while(i<tasksSize)
        counter[tasks[i++]-'A'] ++;
    for(i=0;i<26;i++){
        if(counter[i]>max){
            max = counter[i];
            same = 1;
        }else if(counter[i] == max)
            same ++;
    }
    if(max>0 && (n+1)*(max-1) + same > tasksSize)
        return (n+1)*(max-1) + same;
    return tasksSize;
}
