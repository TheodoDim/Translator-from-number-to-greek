#include <stdio.h>
#include <stdlib.h>

int ar[9]={0};
int pin[9]={0};//789 159 751
int  num;       //789.159.751
char A[20][20]={"ena",
                "dio",
                "tria",
                "tesera",
                "pente",
                "eksi",
                "epta",
                "okto",
                "ennia"};
char V[20][20]={"deka",
                "enteka",
                "dodeka",
                "dekatria",
                "dekatessera",
                "dekapente",
                "dekaeksi",
                "dekaepta",
                "dekaokto",
                "dekaennia",
                };
char C[10][10]={"eikosi",
               "trianta",
               "saranta",
               "peninta",
               "eksinta",
               "ebdominta",
               "ogdonta",
               "eneninta"};
char D[10][15]={"ekaton",
               "diakosia",
               "triakosia",
               "tetrakosia",
               "pentakosia",
               "eksakosia",
               "eptakosia",
               "oktakosia",
               "enniakosia"};
char F[10][15]={"ekaton",
               "diakosies",
               "triakosies",
               "tetrakosies",
               "pentakosies",
               "eksakosies",
               "eptakosies",
               "oktakosies",
               "enniakosies"};
char E[10][15]={"ekaton",
               "diakosia",
               "triakosia",
               "tetrakosia",
               "pentakosia",
               "eksakosia",
               "eptakosia",
               "oktakosia",
               "enniakosia"};

int dig(int n){
    int i = 0,size=0;
    int j, y,keepn;
    keepn=n;
    while (n != 0)
    {
        y = n % 10;
        ar[i] = y;
        i++;
        size++;
        n=n/10;
    }
    return size;
}

void reverse(int ar[], int x)
{
    for (int i =0; i < x; i++)
    {
        pin[x-1-i]= ar[i];
    }

    for (int i=0; i<x; i++)
    {
        ar[i]=pin[i];
    }
}

int main()
{
    int i,x,z,n,psif,size,digit,pos;
    char a;
    int ekato[3]={0},xilia[3]={0},miria[3]={0};
    printf("Dose ena arithmo");
    scanf("%d",&num);
    if(num==0) printf("mhden\n");
    if(num<0){
        printf("meion\n");
        num=-num*1;
    }
    x=dig(num);
    n=num;
    reverse(ar,x);
    int b=0;
    int c=dig(num);
    for(i=c-1; i>=0; i--){
        ekato[2-b]=pin[i];
        b++;
    }
    b=0;
    for(i=c-4; i>=0; i--){
        xilia[2-b]=pin[i];
        b++;
    }
    b=0;
    for(i=c-7; i>=0; i--){
        miria[2-b]=pin[i];
        b++;
    }
    //printf(" \n ");
    //----------million ----------------
    if(miria[0]+miria[1]+miria[2]!=0){
    if(miria[0]!=0){
        puts(D[miria[0]-1]);
    }
    //-------------1dig----------
    if(miria[1]!=0){
        if(miria[1]>=2){//ok
            puts(C[miria[1]-2]);
        }
        else if(miria[1]==1 && miria[2]==2){
            printf("dodeka\n");//ok
        }
        else if(miria[1]==1 && miria[2]==1){
            printf("enteka\n");//ok
        }
        else if(miria[1]==1 && miria[2]!=1 && miria[2]!=2){
            //printf("deka\n");
            puts(V[miria[2]]);
        }
    }
    //----------2dig-------------
    if(miria[2]!=0 && miria[1]!=1){
            puts(A[miria[2]-1]);
    }
    printf("ekatomyria\n");
    }
    //----------xilia---------------------------------------------
     //----------million ----------------
    if(xilia[0]+xilia[1]+xilia[2]!=0){
    if(xilia[0]!=0){
        puts(F[xilia[0]-1]);
    }
    //-------------1dig----------
    if(xilia[1]!=0){
        if(xilia[1]>=2){//ok
            puts(C[xilia[1]-2]);
        }
        else if(xilia[1]==2){
            printf("eikosi\n");
        }

       else if(xilia[1]==1 && xilia[2]==2){
            printf("dodeka\n");
        }
       else if(xilia[1]==1 && xilia[2]==1){
            printf("enteka\n");
        }
        else if(xilia[1]==1 && xilia[2]!=1 && xilia[2]!=2){
            puts(V[xilia[2]]);
        }
    }
    //----------2dig-------------
    if(xilia[2]!=0 && xilia[1]!=1){
       puts(A[xilia[2]-1]);
    }
    printf("xiliades\n");
    }
    //----------------------------------------------
    if(ekato[0]+ekato[1]+ekato[2]!=0){
    if(ekato[0]!=0){
        puts(D[ekato[0]-1]);
    }
    //-------------1dig----------
    if(ekato[1]!=0){
        if(ekato[1]>=2){
            puts(C[ekato[1]-2]);
        }
        else if(ekato[1]==2){
            printf("eikosi\n");
        }
        else if(ekato[1]==1 && ekato[2]==2){
            printf("dodeka\n");
        }
        else if(ekato[1]==1 && ekato[2]==1){
            printf("enteka\n");//ok
        }
        else if(ekato[1]==1 && ekato[2]!=1 && ekato[2]!=2){
            puts(V[ekato[2]]);
        }
    }
    //----------2dig-------------
    if(ekato[2]!=0 && ekato[1]!=1){
       puts(A[ekato[2]-1]);

    }
    }
    return 0;
}
