//
// Created by coral on 2021/5/6.
//
#include"GameOfLife.h"



int STEP;
int WIDTH;
int HEIGHT;
int CELLSIZE;
int INITNUM;

double DTIME;
void input(){
    printf("Please input the width:\n");
    scanf( "%i", &WIDTH);
    printf("\nPlease input the height:\n");
    scanf("%i", &HEIGHT);
    printf("\nPlease input the size of cell:\n");
    scanf("%i", &CELLSIZE);
    printf("\nPlease input the delay time:\n");
    scanf("%lf", &DTIME);
    printf("\nPlease input the init number of cell:\n");
    scanf("%i", &INITNUM);
}


int selectGame() {
    int select1, option1;
    while (0 == 0) {
        printf("Please input your selection:\n1.Create a new game by the document\n2.Load the old game\n3.Create a new game by input the parameter\n");
        scanf("%i", &select1);

        if (select1 == 1) {
            loadinit("init.txt");
            option1 = 0;
            return option1;


        } else if (select1 == 2) {
            loadinit("saveinit.txt");
            option1 = 1;
            return option1;
        } else if (select1==3){
            input();
            option1 = 0;
            return option1;

        }else{ printf("Wrong input! Please input the right number"); return -1;}
    }
}

int selectStep(){
    int select2, option2;

    while (0==0) {
        printf("Please choose the way to generation:\n1.Input steps\n2.Autorun\n");
        scanf("%i", &select2);
        if (select2 == 1) {
            printf("Please input the amount of step:\n");
            scanf("%i",&option2);
            STEP = option2;
            option2=0;
            return option2;
        }
        else if(select2 == 2){
            option2=1;
            return option2;
        }
        else {printf("Wrong input!Please input the right number");return -1;}
    }
}
