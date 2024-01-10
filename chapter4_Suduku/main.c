#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sudoku.h"
#include "solvingSudoku.h"



void showInfo();








int main(){
    system("clear");
    Sudoku *ps = createSudoku(9);
    initSudoku(ps);
    // showSudoku(ps);

    // destroySudoku(ps);
    SHOW_LINE;
    printf("欢迎来到数独游戏\n");
    printf("已经完成初始化\n");
    showSudoku(ps);
    int needExit=0;


    while(1){
        SHOW_LINE;
        showInfo();
        int choice;
        printf("请输入你的选择：");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                showInput(ps);
                break;
            case 2:
                showSudoku(ps);
                break;
            case 3:
                printf("电脑解决问题\n");
                solveSudoku(ps);
                break;
            case 4:
                printf("退出\n");
                needExit=1;
                break;
            default:
                printf("输入错误\n");
                break;
        }
        if (needExit)
        {
            break;
        }
        


    };
    
    destroySudoku(ps);


    return 0;

}


void showInfo(){
    printf("1. 输入初始值\n");
    printf("2. 显示数独\n");
    printf("3. 电脑解决问题\n");
    printf("4. 退出\n");
}




