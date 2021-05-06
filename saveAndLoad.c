//
// Created by coral on 2021/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <time.h>
#include "GameOfLife.h"


int loadinit(FILE *file){

    FILE *fp;
    fp = fopen(file, "r");
    if(fp==NULL){
        printf("Open file error!");

        return 0;
    }
    fscanf(fp, "WORD_WIDTH %d", &WIDTH);

    fscanf(fp, "\nWORD_HEIGHT %d", &HEIGHT);

    fscanf(fp, "\nCELLSIZE %d", &CELLSIZE);

    fscanf(fp, "\nDELTATIME %lf", &DTIME);

    fscanf(fp, "\nINITCELLNUM %d", &INITNUM);
    fclose(fp);
}

void savearray(){
    FILE *fp;
    fp = fopen("savearray.txt", "w");
    if(fp==NULL){
        printf("Open file error!");
        exit(1);
    }
    for(int i=0; i<WIDTH*HEIGHT/CELLSIZE/CELLSIZE; i++){
        fprintf(fp, "%d ", (current->box)[i]);
    }
    fclose(fp);
}

void saveinit(){
    char c;
    FILE *fpin;
    FILE *fpout;
    fpin = fopen("init.txt", "r");
    fpout = fopen("saveinit.txt", "w");
    if(fpin==NULL){
        printf("Open file error!");
        exit(1);
    }
    if(fpout==NULL){
        printf("Open file error!");
        exit(1);
    }
    while((c=fgetc(fpin))!=EOF)
        fputc(c,fpout);
    fclose(fpin);
    fclose(fpout);
}

void save(){
    savearray();
    saveinit();
}

void loadarray(){
    int b_width = WIDTH/CELLSIZE;
    int b_height = HEIGHT/CELLSIZE;

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,WIDTH,HEIGHT,0,-1,1);
    glMatrixMode(GL_MODELVIEW);

    current = createBoard(b_width,b_height);
    FILE *fp;
    fp = fopen("savearray.txt", "r");
    if(fp==NULL){
        printf("Open file error!");
        exit(1);
    }
    for(int i=0; i<WIDTH*HEIGHT/CELLSIZE/CELLSIZE; i++){
        fscanf(fp, "%d", &(current->box)[i]);
    }
    fclose(fp);
    next = createBoard(b_width,b_height);
}