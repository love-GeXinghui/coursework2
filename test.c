//
// Created by coral on 2021/5/6.
//
#include "GOL.h"
#include "GOl.c"
#include <stdio.h>
#include <stdlib.h>
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 100
#define G -1


int testSelectGame(int input);
int testSelectStep(int input);
void testLoadInit();
int testCreateBoard(int x, int y);



int testSelectGame(int input){
    if (selectGame(input)==1||selectGame(input)==2||selectGame(input)==3){
        printf("\n%d Pass the test of selectGame\n", input);
        return 1;
    }
    else {
        printf("\n%d Fail the test of selectGame\n", input);
        return  0;
    }
}


int testSelectStep(int input){
    if (selectGame(input)==1||selectGame(input)==2||selectGame(input)==3){
        printf("\n%d Pass the test of selectGame\n", input);
        return 1;
    }
    else {
        printf("\n%d Fail the test of selectGame\n", input);
        return  0;
    }
}

void testLoadInit(){
    if (loadinit("none.txt")==0){
        printf("\n\n\nthe loadinit pass the test successful when load an empty file\n\n\n");
    }
    else
    {
        printf("\n\n\nthe loadinit pass the test failed when load an empty file\n\n\n");
    }
}

int testCreateBoard(int x, int y){
    if (createBoard(x,y)==NULL){
        printf("\nthe input x=%d y=%d cannot create the board\n" ,x,y);
        return 0;
    }
    else{
        printf("\nthe input x=%d y=%d could create the board\n" ,x,y);
        return 1;}
}

int main(){
    int TSG=0,TSS=0,TCB=0;



    // test the select game
    TSG += testSelectGame(A);
    TSG += testSelectGame(B);
    TSG += testSelectGame(C);
    TSG += testSelectGame(D);
    TSG += testSelectGame(E);
    TSG += testSelectGame(F);
    TSG += testSelectGame(G);
    printf("\n\n\n\nThe result of selectGame we hope is 3.\n");
    printf("\n\n\n\nThe result of selectGame we test is %d \n",TSG);


    //test the select of game
    TSS += testSelectStep(A);
    TSS += testSelectStep(B);
    TSS += testSelectStep(C);
    TSS += testSelectStep(D);
    TSS += testSelectStep(E);
    TSS += testSelectStep(F);
    TSS += testSelectStep(G);
    printf("\n\n\n\nThe result of selectStep we hope is 2.\n");
    printf("\n\n\n\nThe result of selectStep we test is %d \n",TSS);


    //test the load a empty file
    testLoadInit();

    //test the value input whether create the board
    TCB+=testCreateBoard(A,B);
    TCB+=testCreateBoard(B,A);
    TCB+=testCreateBoard(B,C);
    TCB+=testCreateBoard(C,B);
    TCB+=testCreateBoard(A,G);
    TCB+=testCreateBoard(B,G);
    TCB+=testCreateBoard(G,G);
    printf("\n\n\n\nThe result of selectStep we hope is 2.\n");
    printf("\n\n\n\nThe result of selectStep we test is %d \n",TCB);

}

