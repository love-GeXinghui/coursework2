
#include "GameOfLife.h"


#define JsonStrSize 10000
#define Presubmission 1







int IsAutoGradinng = 0;
int mustShow=0;
int stage= 1;
char* JsonStr;
board* current;



void tell (char* s)
{
    if (Presubmission && stage == 1)
        printf ("%s", s);
}
// test createboard()
int t_createBoard () // 8 marks
{
    int r;
    int m=0;
    char s[100];
    board* a;
    int fail = 0;

    tell ("\n*** Checking function createboard ***\n");
    tell ("#Checking it can handle invalid parameters, boardwidth<=0:\n");
    r = createBoard (-200,200);
    if (r == NULL)
    {
        m++; // 1
        tell ("Passed\n");
    }
    else tell("Failed\n");
    tell ("#Checking it can handle invalid parameters, boardheight<=0:\n");
    r = createBoard (200,-400);
    if (r == NULL)
    {
        m++; // 1
        tell ("Passed\n");
    }
    else tell("Failed\n");
    tell ("#Checking it can handle invalid parameters, boardwidth<=0 and boardheight<=0:\n");
    r = createBoard (-300,-400);
    if (r == NULL)
    {
        m++; // 1
        tell ("Passed\n");
    }
    else tell("Failed\n");
    tell ("#Checking it can handle invalid parameters, 0<boardwidth<1 and 0<boardheight<1:\n");
    r = createBoard (0.01,0.01);
    if (r == NULL)
    {
        m++; // 1
        tell ("Passed\n");
    }
    else tell("Failed\n");
    tell ("#Checking it does accept valid parameters:\n");
    r = createBoard (300,300);
    if (r != NULL)
    {
        m++; // 1
        tell ("Passed\n");
    }
    else tell("Failed\n");
    tell ("#Checking board is initialised correctly:\n");
    a = createBoard(400,400);
    if (a)
    {
        m+=3;
        tell ("Passed\n");
    }
    else tell("Failed\n");


    printf ("%i/8 for function createboard", m);




    return m;
}



int t_save_load_init(){
    int r=0;
    int m=0;
    char s[100];
    int fail = 0;
    tell ("\n*** Checking function loadinit and saveinit ***\n");
    FILE *fp;
    fp = fopen("init.txt", "w");
    if(fp==NULL){
        printf("Open file error!");
        exit(1);
    }
    fprintf(fp, "WORD_WIDTH 800\n");
    fprintf(fp, "WORD_HEIGHT 800\n");
    fprintf(fp, "CELLSIZE 10\n");
    fprintf(fp, "DELTATIME 0.1\n");
    fprintf(fp, "INITCELLNUM 1000\n");
    fclose(fp);
    saveinit();
    loadinit("saveinit.txt");
    if(WIDTH==800)m++;
    if(HEIGHT==800)m++;
    if(CELLSIZE==10)m++;
    if(DTIME==0.1)m++;
    if(INITNUM==1000)m++;

    if(m==5) tell("Passed\n");
    else tell("Failed\n");

    sprintf (s,"%i/5 for function loadinit and saveinit", m);

    if (Presubmission)
        printf ("%s\n", s);
    else
        AddTestString (m, 5, s, 0);
    return m;
}

int main ()
{

    int tot = 0;


    tell ("\t$$$ Checking your functions, behold $$$\n");
    tell ("\t=========================================\n");
    tell ("Started ...\n");


    tot += t_createBoard ();

    tot += t_save_load_init();





    printf ("\n---------------------------------------------------\n");
    printf ("\t\tTotal mark = %i/13\n", tot);
    printf ("---------------------------------------------------\n\n");

    tell ("Finished\n");


    return 0;
}

