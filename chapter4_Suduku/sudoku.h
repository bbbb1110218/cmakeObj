#ifndef SODOKU_H
#define SODOKU_H
#include <stdbool.h>

#define SHOW_LINE printf("--------------------------------------------------\n")

typedef struct {
    int **board;
    int m_size;
} Sudoku;

// const char * format=" %d "

Sudoku *createSudoku(int size);

void initSudoku(Sudoku *su);

void destroySudoku(Sudoku *su);

void showSudoku(Sudoku *su);

bool inputVaild(Sudoku *su, int row, int col, int num);

void showInput(Sudoku *su);




#endif