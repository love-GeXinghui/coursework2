//
// Created by coral on 2021/5/1.
//

#ifndef COURSEWORK2_GOL_H
#define COURSEWORK2_GOL_H
int selectGame(); //
int selectStep(); //
void init();
void input();
void display();
void savearray();
void saveinit();
void save();
int loadinit(FILE *file);
void loadarray();
board* createBoard(int w, int h);
int checkNeighbors(board *b, int x, int y);
void generation(board* current, board* next);
int game();



typedef struct board{
    char *box;
    int width;
    int height;
} board;

board* next = NULL;
board* current = NULL;
int STEP;
int WIDTH;
int HEIGHT;
int CELLSIZE;
int INITNUM;
int lastTime = 0;
int newTime = 0;
double DTIME;
double deltaTime = 0.0;
#endif //COURSEWORK2_GOL_H
