#include "sudoku.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


Sudoku *createSudoku(int size){
    Sudoku *su = malloc(sizeof(Sudoku));
    su->m_size = size;
    su->board = malloc(sizeof(int *) * (su->m_size));
    for(int i = 0; i < size; i++){
        su->board[i] = malloc(sizeof(int) * (su->m_size));
    }
    return su;
}

void initSudoku(Sudoku *su){
    for(int i = 0; i < su->m_size; i++){
        for(int j = 0; j < su->m_size; j++){
            su->board[i][j] = 0;
        }
    }
}

void destroySudoku(Sudoku *su){
    for(int i = 0; i < su->m_size; i++){
        free(su->board[i]);
    }
    free(su->board);
    free(su);
}

void showSudoku(Sudoku *su){
    // for(int n=0;n<su->m_size;n++){
    //    if(!n)printf(" ");
    //     //显示第几行
    //     printf(" %2d",n+1);
    //     if(n==su->m_size-1)
    //           printf("\n");
       
    // }

    // for(int i = 0; i < su->m_size; i++){
    //     //显示第几列
    //     printf("%d ", i+1);
    //     for(int j = 0; j < su->m_size; j++){
    //         printf("%2d ", su->board[i][j]);
    //     }
    //     printf("\n");
    // }
        printf("    1  2  3    4  5  6    7  8  9 \n");
    // for(int n=0;n<su->m_size;n++){
    //     //显示第几行
    //     printf(" %2d",n+1);
    //     if(n==su->m_size-1)
    //         printf("\n");
    // }

    for(int i = 0; i < su->m_size; i++){
        //显示第几列
        printf("%2d ", i+1);
        for(int j = 0; j < su->m_size; j++){
            printf("%2d ", su->board[i][j]);
            if((j+1)%3 == 0 && j < su->m_size - 1) printf("| ");
        }
        printf("\n");
        if((i+1)%3 == 0 && i < su->m_size - 1) {
            printf("   ");
            for(int k = 0; k < su->m_size; k++){
                printf("---");
                if((k+1)%3 == 0 && k < su->m_size - 1) printf("+-");
            }
            printf("\n");
            
        }
    }
    printf("\n");

}

bool inputVaild(Sudoku *su, int row, int col, int num){

    //之前可能输入错了，重新输入
    if(su->board[row-1][col-1] != 0){
        printf("Update success\n");
        su->board[row-1][col-1] = num;
        return true;
    }
    
    //判断输入是否合法
    if(row <0 || col < 0 || num <0 || num > su->m_size || row > su->m_size || col > su->m_size){
        // printf("输入不合法\n");
        return false;
    }
    su->board[row-1][col-1] = num;
    // printf("输入成功\n");

    return true;
}

void showInput(Sudoku *su){
    // printf("输入行号,列号,数字，用空格隔开,退出清楚入0 0 0\n");
   
    while(1){
         printf("退出输入0 0 0,输入行号,列号,数字，用空格隔开,你的输入:");
        int row,col,num;
        scanf("%d %d %d",&row,&col,&num);
        if(!row & !col & !num){
            printf("结束输入\n");
            break;
        }else{
            if(inputVaild(su,row,col,num))
                printf("输入成功\n");
            else
                printf("输入不合法\n");
            showSudoku(su);
        }

    }
    
   

}