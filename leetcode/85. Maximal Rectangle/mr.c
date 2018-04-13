/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.

*/

#define max(a,b) ((a)>(b)?(a):(b))

int goRight(char** matrix, int mr, int mc, int cr, int cc){
    int w = 0;
    if(cr == mr)
        return 0;
    for(;cc < mc && matrix[cr][cc] == '1';++cc)
        ++w;
    return w;
}
int all(char** matrix, int mr, int mc, int cr, int cc,int w, int h, int flag){
    int temp_w = goRight(matrix, mr, mc, cr, cc);
    int ret = 0;
    while(1){

        while(temp_w == w){
            ++h;
            ++cr;
            temp_w = goRight(matrix, mr, mc, cr, cc);
        }
        // if(h==19)
        // printf("i:%d j:%d w:%d h:%d w*h:%d\n",cr,cc,w,h,w*h);
        // if(temp_w != 0)
        // if(flag){
        //     if(temp_w > w)
        //         return max(ret, (h+1)*w);
        //     else
        //         return max(ret, h*w);
        // }
        if(h*w > ret)
            ret = h*w;
        if(temp_w == 0)
            return ret;

        if(temp_w < w)
            if(flag == 0)
                return max(ret, all(matrix, mr, mc, cr+1, cc, temp_w, h+1, 0));
            else
                return ret;

        for(int diff = 0;flag==0&&diff< temp_w - w;++diff)
            ret = max(ret, all(matrix, mr, mc, cr+1, cc, temp_w-diff, 1, 1));
        temp_w = w;
    }
}
int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int ret = 0, temp = 0;
    int w = 0;
    int i = 0, j = 0;
    int flag = 0;
    for(;j<matrixColSize;++j){
        flag = 0;
        for(i=0;i<matrixRowSize;++i){
            w = goRight(matrix, matrixRowSize, matrixColSize, i, j);
            // printf("i:%d j:%d w:%d\n",i,j,w);
            if(w>0 && flag == 0){
                flag = 1;
                temp = all(matrix, matrixRowSize, matrixColSize, i + 1, j, w, 1, 0);
                if(temp>ret)
                    ret = temp;
            }else if(w==0) flag = 0;

        }
    }

    return ret;
}
