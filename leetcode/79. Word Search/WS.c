/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
//DFS O(m*n) O(m*n)
bool search(char** board, int boardRowSize, int boardColSize, int ri, int ci, char* word, int i, int* visited){
    // printf("board[%d][%d]=%c\n", ri, ci, board[ri][ci]);
    visited[ri*boardColSize+ci] = 1;
    if(
        word[i] != 0 && 
        (ri==boardRowSize-1 || board[ri+1][ci] != word[i] || visited[(ri+1)*boardColSize+ci] || search(board, boardRowSize, boardColSize, ri+1, ci, word, i+1, visited) == 0) &&
        (ri==0              || board[ri-1][ci] != word[i] || visited[(ri-1)*boardColSize+ci] || search(board, boardRowSize, boardColSize, ri-1, ci, word, i+1, visited) == 0) &&
        (ci==boardColSize-1 || board[ri][ci+1] != word[i] || visited[ri*boardColSize+ci+1]   || search(board, boardRowSize, boardColSize, ri, ci+1, word, i+1, visited) == 0) &&
        (ci==0              || board[ri][ci-1] != word[i] || visited[ri*boardColSize+ci-1]   || search(board, boardRowSize, boardColSize, ri, ci-1, word, i+1, visited) == 0)
    ){
        visited[ri*boardColSize+ci] = 0;
        return false;
    }
    return true;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int i = 0, j = 0;
    int *visited = (int *)malloc(sizeof(int)*(boardRowSize * boardColSize));
    memset(visited, 0, sizeof(int)*(boardRowSize * boardColSize));
    // printf("\n");
    for(;i<boardRowSize;++i)
        for(j=0;j<boardColSize;++j)
            if(board[i][j] == word[0] && search(board, boardRowSize, boardColSize, i, j, word, 1, visited))
                return true;
    return false;
}

