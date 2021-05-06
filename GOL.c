#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <time.h>
#include "GameOfLife.h"









void init() {
    int b_width = WIDTH/CELLSIZE;
    int b_height = HEIGHT/CELLSIZE;
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,WIDTH,HEIGHT,0,-1,1);
    glMatrixMode(GL_MODELVIEW);

    current = createBoard(b_width,b_height);
    srand((unsigned )time(NULL));

    for(int i=0; i<INITNUM; i++){
        int j = rand() % (b_width*b_height);
        (current->box)[j] = 1;
    }



    next = createBoard(b_width,b_height);
}

void display() {
    int i,j;
    int Y,X;

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for(i=0; i < current->width; i++) {
        for(j=0; j < current->height; j++)
        {
            X = i*CELLSIZE;
            Y = j*CELLSIZE;

            if((current->box)[i+j*current->width] == 1)
            {
                glBegin(GL_QUADS);
                glColor3f(1.0,1.0,1.0);
                glVertex2d(X,Y);
                glVertex2d(X+CELLSIZE,Y);
                glVertex2d(X+CELLSIZE,Y+CELLSIZE);
                glVertex2d(X,Y+CELLSIZE);
                glEnd();
            }
        }
    }
}

board* createBoard(int w, int h) {
    if (w <= 0 || h <= 0) {
        return NULL;
    }

    board *b = (board *)malloc(sizeof(board));
    if(!b) {
        return NULL;
    }

    b->box = (char*)calloc(w*h,sizeof(char));

    if(!(b->box))
    {
        free(b);
        return NULL;
    }

    b->width=w;
    b->height=h;

    return b;
}


int checkNeighbors(board *b, int x, int y) {
    int k,l;
    int count = 0;
    if(x >= b->width || y >= b->height || x < 0 || y < 0)
        return 0;

    for(k=-1; k <= 1; k++) {
        for(l=-1; l <= 1; l++) {
            if(x+k >= 0 && x+k < b->width && y+l >= 0 && y+l < b->height && !(k == 0 && l == 0)) {
                if((b->box)[(x+k)+(y+l)*b->width] == 1) {
                    count++;
                }
            }
        }
    }

    return count;
}

void generation(board* current, board* next) {
    int i,j;

    int count;
    memcpy(next->box, current->box, (current->width*current->height)*sizeof(char));
//    for(i=0; i < current->width*current->height; i++)
//        (next->box)[i] = (current->box)[i];


    for(i=0; i < next->width; i++) {
        for(j=0; j < next->height; j++)
        {
            count = checkNeighbors(next,i,j);
            if((next->box)[i+j*next->width] == 1 && count < 2)
                (current->box)[i+j*next->width] = 0;
            else if((next->box)[i+j*next->width] == 1 && count > 3)
                (current->box)[i+j*next->width] = 0;
            else if((next->box)[i+j*next->width] == 1 && count <= 3)
                (current->box)[i+j*next->width] = 1;
            else if((next->box)[i+j*next->width] == 0 && count == 3)
                (current->box)[i+j*next->width] = 1;
            // If cell is alive and neighbors equals 2 or 3 it stays alive
            // If cell is dead and neighbors is not equal to 3 it stays dead
        }
    }
}



int game(){



    SDL_Window *window;
    SDL_GLContext glcontext;
    SDL_Event e;



    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "\nUnable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }







    int option,option2;
    option2=selectGame();
    option=selectStep();






    window = SDL_CreateWindow(
            "Conway's Game of life",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WIDTH,
            HEIGHT,
            SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        fprintf(stderr, "\nCould not create widnow: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    glcontext = SDL_GL_CreateContext(window);

    if (option2==0){printf("44444444444444");init();}
    else if (option2==1){loadarray();}



    if(option==0){
        int i=0;
        while(i<STEP && e.type != SDL_QUIT){
            SDL_PollEvent(&e);
            newTime = SDL_GetTicks();
            deltaTime = (double) (newTime - lastTime) / 10000;
            if(deltaTime >= DTIME) {
                generation(current,next);
                lastTime = newTime;
                i++;
            }
            display();





            SDL_GL_SwapWindow(window);

            if(e.key.keysym.sym==SDLK_ESCAPE){
                save();
                e.type=SDL_QUIT;
            }
            if (e.type==SDL_KEYDOWN){
                if (e.key.keysym.sym==SDLK_SPACE){
                    while (1){
                        SDL_PollEvent(&e);
                        display();
                        if (e.type==SDL_QUIT){
                            return 0;
                        }
                        if (e.type==SDL_KEYDOWN){
                            if (e.key.keysym.sym==SDLK_ESCAPE){
                                save();
                                e.type=SDL_QUIT;
                                return 0;
                            }
                            if (e.key.keysym.sym==SDLK_SPACE){printf("\nshabichen\n"); break;}}
                    }
                    printf("\nzhaoyimin\n");
                }}
            printf("\nzhaoyimin250\n");
        }
        while(e.type != SDL_QUIT){
            SDL_PollEvent(&e);
            display();
            if(e.key.keysym.sym==SDLK_ESCAPE){
                save();
                e.type=SDL_QUIT;
            }
            if (e.type==SDL_KEYDOWN){
                if (e.key.keysym.sym==SDLK_SPACE){
                    while (1){
                        SDL_PollEvent(&e);
                        display();
                        if (e.type==SDL_QUIT){
                            return 0;
                        }
                        if (e.type==SDL_KEYDOWN){
                            if (e.key.keysym.sym==SDLK_ESCAPE){
                                save();
                                e.type=SDL_QUIT;
                                return 0;
                            }
                            if (e.key.keysym.sym==SDLK_SPACE){printf("\nshabichen\n");e.key.keysym.sym == SDLK_p; break;}}
                    }
                    printf("\nzhaoyimin\n");
                }}
            printf("\nzhaoyimin250\n");
        }
    }
    else if(option==1){
        while(e.type != SDL_QUIT){
            SDL_PollEvent(&e);
            newTime = SDL_GetTicks();
            deltaTime = (double) (newTime - lastTime) / 10000;
            if(deltaTime >= DTIME) {
                generation(current,next);
                lastTime = newTime;
            }
            display();
            SDL_GL_SwapWindow(window);
            if(e.key.keysym.sym==SDLK_ESCAPE){
                save();
                e.type=SDL_QUIT;
            }
            if (e.type==SDL_KEYDOWN){
                if (e.key.keysym.sym==SDLK_SPACE){
                    while (1){
                        SDL_PollEvent(&e);
                        display();
                        if (e.type==SDL_QUIT){
                            return 0;
                        }
                        if (e.type==SDL_KEYDOWN){
                            if (e.key.keysym.sym==SDLK_ESCAPE){
                                save();
                                e.type=SDL_QUIT;
                                return 0;
                            }
                            if (e.key.keysym.sym==SDLK_SPACE){printf("\nshabichen\n");e.key.keysym.sym == SDLK_p; break;}}
                    }
                    printf("\nzhaoyimin\n");
                }}
            printf("\nzhaoyimin250\n");
        }
    }


    SDL_GL_DeleteContext(glcontext);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;

}
int main(){

   game();

}

