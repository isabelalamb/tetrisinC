/*
TETRIS
Desenvolvido por: Isabela Lamb
isabelaclamb@gmail.com

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

char m[25][20],muv,nome[20];
int i,j,k,l,p,d,r=1,b,v=200,o,pont=0,pos=0,aux,kbhit();

void pecas();
void desce();
void cont();
int teste();
void rot();
void com();
int testel();
int tester();

void pecas(){
    srand(time(NULL));
    p=rand()%7;//sorteando a peça

    switch(p){
        case 0://N
            m[2][9]='x';
            m[2][8]='x';
            m[1][9]='x';
            m[1][10]='x';
            strcpy(nome,"N");
            break;
        case 1://N VIRADO
            m[2][9]='x';
            m[2][10]='x';
            m[1][8]='x';
            m[1][9]='x';
            strcpy(nome,"N VIRADO");
            break;
        case 2://Q
            m[2][9]='x';
            m[2][8]='x';
            m[1][8]='x';
            m[1][9]='x';
            strcpy(nome,"QUADRADO");
            break;
        case 3://I
            m[2][9]='x';
            m[2][8]='x';
            m[2][10]='x';
            m[2][11]='x';
            strcpy(nome,"I");
            break;
        case 4://T
            m[2][9]='x';
            m[2][10]='x';
            m[2][8]='x';
            m[1][9]='x';
            strcpy(nome,"T");
            break;
        case 5://L
            m[2][9]='x';
            m[1][9]='x';
            m[2][10]='x';
            m[2][11]='x';
            strcpy(nome,"L VIRADO");
            break;
        case 6://LV
            m[2][9]='x';
            m[1][9]='x';
            m[2][8]='x';
            m[2][7]='x';
            strcpy(nome,"L");
            break;
    }
}

void desce(){/*IDEIA::IDENTIFICAR A PEÇA E DESCER DE ACORDO COM O PIVO SE HOUVER ESPAÇO EM BAIXO*/
    for(i=0;i<25;i++){
        for(j=0;j<20;j++){
            for(b=0;b<20;b++){
                if(m[4][b]=='X'){
                    system("cls");
                    printf("  XXXXX           XX          XX       XX         XXXXXX\n");
                    printf(" X               X  X        X  X     X  X       X\n");
                    printf("X               X    X       X    X  X   X      XXXXX\n");
                    printf("X     XXX       XXXXXX       X     XX    X      X\n");
                    printf(" X      X       X    X       X     XX    X      X\n");
                    printf("  XXXXXX        X    X       X           X       XXXXXXX\n\n");

                    printf("  XXXXX         X       X       XXXXXX       XXXXXX\n");
                    printf(" X     X        X       X      X             X     X\n");
                    printf("X       X        X     X      XXXXX          XXXXXX\n");
                    printf("X       X         X   X       X              X     X\n");
                    printf(" X     X           X X        X              X      X\n");
                    printf("  XXXXX            XXX         XXXXXXX       X       X\n");

                    printf("\n\nPONTUAÇÃO: %d\n",pont);
                    system("pause");
                    pont=0;
                    main();
                }
            }
            if(m[i][j]=='x'){
                system("cls");
                printf("       TETRIS       \n");
                printf("|##################|\n");
                for(k=4;k<25;k++){
                    for(l=0;l<20;l++){
                        printf("%c",m[k][l]);
                    }
                    printf("\n");
                }
                cont();
                printf("\nA - MOVE A PEÇA PARA A ESQUERDA\nD - MOVE A PEÇA PARA A DIREITA\nS - A PEÇA DESCE MAIS RÁPIDO\nQUALQUER OUTRA TECLA - GIRA A PEÇA");
                printf("\n\nPONTUAÇÃO: %d",pont);
                printf("\nPEÇA ATUAL: %s\n\n",nome);
                Sleep(v);
                com();
                switch(p){
                    case 0://n
                        if(teste()){
                            if(r==1){
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                m[i+1][j-1]=' ';
                                m[i+1][j+1]='x';
                                m[i+2][j-1]='x';
                                m[i+2][j]='x';
                                desce();
                            }
                            if(r==2){
                                m[i+2][j]='x';
                                m[i+3][j+1]='x';
                                m[i][j]=' ';
                                m[i+1][j+1]=' ';
                                desce();
                            }
                        }
                        else{
                            for(k=4;k<25;k++){
                                for(l=0;l<20;l++){
                                    if(m[k][l]=='x')
                                        m[k][l]='X';
                                }
                            }
                        }
                        break;
                    case 1://nv
                        if(teste()){
                            if(r==1){
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                m[i+1][j+2]=' ';
                                m[i+1][j]='x';
                                m[i+2][j+1]='x';
                                m[i+2][j+2]='x';
                                desce();
                            }
                            if(r==2){
                                m[i][j]=' ';
                                m[i+1][j-1]=' ';
                                m[i+2][j]='x';
                                m[i+3][j-1]='x';
                                desce();
                            }

                        }
                        else{
                            for(k=4;k<25;k++){
                                for(l=0;l<20;l++){
                                    if(m[k][l]=='x')
                                        m[k][l]='X';
                                }
                            }
                        }
                        break;
                    case 2://q
                        if(teste()){
                            m[i+2][j]='x';
                            m[i+2][j+1]='x';
                            m[i+1][j]='x';
                            m[i+1][j+1]='x';
                            m[i][j]=' ';
                            m[i][j+1]=' ';
                            desce();
                        }
                        else{
                            for(k=4;k<25;k++){
                                for(l=0;l<20;l++){
                                    if(m[k][l]=='x')
                                        m[k][l]='X';
                                }
                            }
                        }
                        break;
                    case 3://I
                        if(teste()){
                            if(r==1){
                                m[i+1][j]='x';
                                m[i+1][j+1]='x';
                                m[i+1][j+2]='x';
                                m[i+1][j+3]='x';
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                m[i][j+2]=' ';
                                m[i][j+3]=' ';
                                desce();
                            }
                            if(r==2){
                                m[i][j]=' ';
                                m[i+4][j]='x';
                                desce();
                            }
                        }
                        else{
                            for(k=4;k<25;k++){
                                for(l=0;l<20;l++){
                                    if(m[k][l]=='x')
                                        m[k][l]='X';
                                }
                            }
                        }
                        break;
                    case 4://t
                        if(teste()){
                            if(r==1){
                                m[i+2][j-1]='x';
                                m[i+2][j]='x';
                                m[i+2][j+1]='x';
                                m[i][j]=' ';
                                m[i+1][j-1]=' ';
                                m[i+1][j+1]=' ';
                                desce();
                            }
                            if(r==2){
                                m[i+3][j]='x';
                                m[i+2][j+1]='x';
                                m[i][j]=' ';
                                m[i+1][j+1]=' ';
                                desce();
                            }
                            if(r==3){
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                m[i][j+2]=' ';
                                m[i+1][j]='x';
                                m[i+1][j+2]='x';
                                m[i+2][j+1]='x';
                                desce();
                            }
                            if(r==4){
                                m[i][j]=' ';
                                m[i+1][j-1]=' ';
                                m[i+2][j-1]='x';
                                m[i+3][j]='x';
                                desce();
                            }
                        }
                        else{
                            for(k=4;k<25;k++){
                                for(l=0;l<20;l++){
                                    if(m[k][l]=='x')
                                        m[k][l]='X';
                                }
                            }
                        }
                        break;
                    case 5://l
                        if(teste()){
                            if(r==1){
                                m[i+2][j]='x';
                                m[i+2][j+1]='x';
                                m[i+2][j+2]='x';
                                m[i][j]=' ';
                                m[i+1][j+1]=' ';
                                m[i+1][j+2]=' ';
                                desce();
                            }
                            if(r==2){
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                m[i+3][j]='x';
                                m[i+1][j+1]='x';
                                desce();
                            }
                            if(r==3){
                                m[i+1][j]='x';
                                m[i+1][j+1]='x';
                                m[i+2][j+2]='x';
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                m[i][j+2]=' ';
                                desce();
                            }
                            if(r==4){
                                m[i+3][j]='x';
                                m[i+3][j-1]='x';
                                m[i][j]=' ';
                                m[i+2][j-1]=' ';
                                desce();
                            }
                        }
                        else{
                            for(k=4;k<25;k++){
                                for(l=0;l<20;l++){
                                    if(m[k][l]=='x')
                                        m[k][l]='X';
                                }
                            }
                        }
                        break;
                    case 6://lv
                        if(teste()){
                            if(r==1){
                                m[i+2][j]='x';
                                m[i+2][j-1]='x';
                                m[i+2][j-2]='x';
                                m[i][j]=' ';
                                m[i+1][j-1]=' ';
                                m[i+1][j-2]=' ';
                                desce();
                            }
                            if(r==2){
                                m[i+3][j]='x';
                                m[i+3][j+1]='x';
                                m[i][j]=' ';
                                m[i+2][j+1]=' ';
                                desce();
                            }
                            if(r==3){
                                m[i+2][j]='x';
                                m[i+1][j+1]='x';
                                m[i+1][j+2]='x';
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                m[i][j+2]=' ';
                                desce();
                            }
                            if(r==4){
                                m[i+1][j]='x';
                                m[i+3][j+1]='x';
                                m[i][j]=' ';
                                m[i][j+1]=' ';
                                desce();
                            }
                        }
                        else{
                            for(k=4;k<25;k++){
                                for(l=0;l<20;l++){
                                    if(m[k][l]=='x')
                                        m[k][l]='X';
                                }
                            }
                        }
                        break;
                }
            }
        }
    }
}

void lado(){
    if(muv=='a'){
        switch(p){
            case 0://n
                if(testel()){
                    if(r==1){
                        m[i][j-1]='x';
                        m[i+1][j-2]='x';
                        m[i][j+1]=' ';
                        m[i+1][j]=' ';
                        desce();
                    }
                    if(r==2){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i+2][j]='x';
                        m[i][j]=' ';
                        m[i+1][j+1]=' ';
                        m[i+2][j+1]=' ';
                        desce();
                    }
                }
                else
                    desce();
                break;
            case 1://nv
                if(testel()){
                    if(r==1){
                        m[i][j-1]='x';
                        m[i+1][j]='x';
                        m[i][j+1]=' ';
                        m[i+1][j+2]=' ';
                        desce();
                    }
                    if(r==2){
                        m[i][j-1]='x';
                        m[i+1][j-2]='x';
                        m[i+2][j-2]='x';
                        m[i][j]=' ';
                        m[i+1][j]=' ';
                        m[i+2][j-1]=' ';
                        desce();
                    }
                }
                else
                    desce();
                break;
            case 2://q
                if(testel()){
                    m[i][j-1]='x';
                    m[i+1][j-1]='x';
                    m[i][j+1]=' ';
                    m[i+1][j+1]=' ';
                    desce();
                }
                else
                    desce();
                break;
            case 3://i
                if(testel()){
                    if(r==1){
                        m[i][j-1]='x';
                        m[i][j+3]=' ';
                        desce();
                    }
                    if(r==2){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i+2][j-1]='x';
                        m[i+3][j-1]='x';
                        m[i][j]=' ';
                        m[i+1][j]=' ';
                        m[i+2][j]=' ';
                        m[i+3][j]=' ';
                        desce();
                    }
                }
                else
                    desce();
                break;
            case 4://t
                if(testel()){
                    if(r==1){
                        m[i][j-1]='x';
                        m[i+1][j-2]='x';
                        m[i][j]=' ';
                        m[i+1][j+1]=' ';
                        desce();
                    }
                    if(r==2){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i+2][j-1]='x';
                        m[i][j]=' ';
                        m[i+1][j+1]=' ';
                        m[i+2][j]=' ';
                        desce();
                    }
                    if(r==3){
                        m[i][j-1]='x';
                        m[i+1][j]='x';
                        m[i][j+2]=' ';
                        m[i+1][j+1]=' ';
                        desce();
                    }
                    if(r==4){
                        m[i][j-1]='x';
                        m[i+1][j-2]='x';
                        m[i+2][j-1]='x';
                        m[i][j]=' ';
                        m[i+1][j]=' ';
                        m[i+2][j]=' ';
                        desce();
                    }
                }
                else
                    desce();
                break;
            case 5://l
                if(testel()){
                    if(r==1){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i][j]=' ';
                        m[i+1][j+2]=' ';
                        desce();
                    }
                    if(r==2){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i+2][j-1]='x';
                        m[i][j+1]=' ';
                        m[i+1][j]=' ';
                        m[i+2][j]=' ';
                        desce();
                    }
                    if(r==3){
                        m[i][j-1]='x';
                        m[i+1][j+1]='x';
                        m[i][j+2]=' ';
                        m[i+1][j+2]=' ';
                        desce();
                    }
                    if(r==4){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i+2][j-2]='x';
                        m[i][j]=' ';
                        m[i+1][j]=' ';
                        m[i+2][j]=' ';
                        desce();
                    }
                }
                else
                    desce();
                break;
            case 6:
                if(testel()){
                    if(r==1){
                        m[i][j-1]='x';
                        m[i+1][j-3]='x';
                        m[i][j]=' ';
                        m[i+1][j]=' ';
                        desce();
                    }
                    if(r==2){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i+2][j-1]='x';
                        m[i][j]=' ';
                        m[i+1][j]=' ';
                        m[i+2][j+1]=' ';
                        desce();
                    }
                    if(r==3){
                        m[i][j-1]='x';
                        m[i+1][j-1]='x';
                        m[i+1][j]=' ';
                        m[i][j+2]=' ';
                        desce();
                    }
                    if(r==4){
                        m[i][j-1]='x';
                        m[i+1][j]='x';
                        m[i+2][j]='x';
                        m[i][j+1]=' ';
                        m[i+1][j+1]=' ';
                        m[i+2][j+1]=' ';
                        desce();
                    }
                }
                else
                    desce();
                break;
        }

    }
    if(muv=='d'){
            switch(p){
                case 0:
                    if(testel()){
                        if(r==1){
                            m[i][j+2]='x';
                            m[i+1][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j-1]=' ';
                            desce();
                        }
                        if(r==2){
                            m[i][j+1]='x';
                            m[i+1][j+2]='x';
                            m[i+2][j+2]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            m[i+2][j+1]=' ';
                            desce();
                        }
                    }
                    else
                        desce();
                    break;
                case 1:
                    if(testel()){
                        if(r==1){
                            m[i][j+2]='x';
                            m[i+1][j+3]='x';
                            m[i][j]=' ';
                            m[i+1][j+1]=' ';
                            desce();
                        }
                        if(r==2){
                            m[i][j+1]='x';
                            m[i+1][j+1]='x';
                            m[i+2][j]='x';
                            m[i][j]=' ';
                            m[i+1][j-1]=' ';
                            m[i+2][j-1]=' ';
                            desce();
                        }
                    }
                    else
                        desce();
                    break;
                case 2:
                    if(testel()){
                        m[i][j+2]='x';
                        m[i+1][j+2]='x';
                        m[i][j]=' ';
                        m[i+1][j]=' ';
                        desce();
                    }
                    else
                        desce();
                    break;
                case 3:
                    if(testel()){
                        if(r==1){
                            m[i][j+4]='x';
                            m[i][j]=' ';
                            desce();
                        }
                        if(r==2){
                            m[i][j+1]='x';
                            m[i+1][j+1]='x';
                            m[i+2][j+1]='x';
                            m[i+3][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            m[i+2][j]=' ';
                            m[i+3][j]=' ';
                            desce();
                        }
                    }
                    else
                        desce();
                    break;
                case 4:
                    if(testel()){
                        if(r==1){
                            m[i][j+1]='x';
                            m[i+1][j+2]='x';
                            m[i][j]=' ';
                            m[i+1][j-1]=' ';
                            desce();
                        }
                        if(r==2){
                            m[i][j+1]='x';
                            m[i+1][j+2]='x';
                            m[i+2][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            m[i+2][j]=' ';
                            desce();
                        }
                        if(r==3){
                            m[i][j+3]='x';
                            m[i+1][j+2]='x';
                            m[i][j]=' ';
                            m[i+1][j+1]=' ';
                            desce();
                        }
                        if(r==4){
                            m[i][j+1]='x';
                            m[i+1][j+1]='x';
                            m[i+2][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j-1]=' ';
                            m[i+2][j]=' ';
                            desce();
                        }
                    }
                    else
                        desce();
                    break;
                case 5:
                    if(testel()){
                        if(r==1){
                            m[i][j+1]='x';
                            m[i+1][j+3]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            desce();
                        }
                        if(r==2){
                            m[i][j+2]='x';
                            m[i+1][j+1]='x';
                            m[i+2][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            m[i+2][j]=' ';
                            desce();
                        }
                        if(r==3){
                            m[i][j+3]='x';
                            m[i+1][j+3]='x';
                            m[i+1][j+2]=' ';
                            m[i][j]=' ';
                            desce();
                        }
                        if(r==4){
                            m[i][j+1]='x';
                            m[i+1][j+1]='x';
                            m[i+2][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            m[i+2][j-1]=' ' ;
                            desce();
                        }
                    }
                    else
                        desce();
                    break;
                case 6:
                    if(testel()){
                        if(r==1){
                            m[i][j+1]='x';
                            m[i+1][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j-2]=' ';
                            desce();
                        }
                        if(r==2){
                            m[i][j+1]='x';
                            m[i+1][j+1]='x';
                            m[i+2][j+2]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            m[i+2][j]=' ';
                            desce();
                        }
                        if(r==3){
                            m[i][j+3]='x';
                            m[i+1][j+1]='x';
                            m[i][j]=' ';
                            m[i+1][j]=' ';
                            desce();
                        }
                        if(r==4){
                            m[i][j+2]='x';
                            m[i+1][j+2]='x';
                            m[i+2][j+2]='x';
                            m[i][j]=' ';
                            m[i+1][j+1]=' ';
                            m[i+2][j+1]=' ';
                            desce();
                        }
                    }
                    else
                        desce();
                    break;
            }
    }
}

void rot(){
    if(tester()){
        switch(p){
            case 0://n
                if(r==1){
                    m[i-1][j]='x';
                    m[i+1][j+1]='x';
                    m[i+1][j]=' ';
                    m[i+1][j-1]=' ';
                    r=2;
                    desce();
                }
                if(r==2){
                    m[i][j+1]='x';
                    m[i+1][j-1]='x';
                    m[i+1][j+1]=' ';
                    m[i+2][j+1]=' ';
                    r=1;
                    desce();
                }

                break;
            case 1://nv
               if(r==1){
                        m[i-1][j+2]='x';
                        m[i][j+2]='x';
                        m[i+1][j+2]=' ';
                        m[i][j]=' ';
                        r=2;
                        desce();
                }
                if(r==2){
                    m[i+1][j-1]=' ';
                    m[i+2][j-1]=' ';
                    m[i][j-1]='x';
                    m[i+1][j+1]='x';
                    r=1;
                    desce();
                }
                break;
            case 3://
                if(r==1){
                    m[i-1][j]='x';
                    m[i+1][j]='x';
                    m[i+2][j]='x';
                    m[i][j+1]=' ';
                    m[i][j+2]=' ';
                    m[i][j+3]=' ';
                    r=2;
                    desce();
                }
                if(r==2){
                    m[i][j+1]='x';
                    m[i][j+2]='x';
                    m[i][j+3]='x';
                    m[i+1][j]=' ';
                    m[i+2][j]=' ';
                    m[i+3][j]=' ';
                    r=1;
                    desce();
                }
                break;
            case 4://t
              if(r==1){
                    m[i+1][j-1]=' ';
                    m[i+2][j]='x';
                    r=2;
                    desce();
              }
              if(r==2){
                m[i][j]=' ';
                m[i+1][j-1]='x';
                r=3;
                desce();
              }
              if(r==3){
                m[i][j+2]=' ';
                m[i-1][j+1]='x';
                r=4;
                desce();
              }
              if(r==4){
                m[i+1][j+1]='x';
                m[i+2][j]=' ';
                r=1;
                desce();
              }
                break;
            case 5://l
               if(r==1){
                    m[i+1][j+2]=' ';
                    m[i+1][j+1]=' ';
                    m[i][j+1]='x';
                    m[i+2][j]='x';
                    r=2;
                    desce();
               }
               if(r==2){
                    m[i][j+2]='x';
                    m[i+1][j+2]='x';
                    m[i+1][j]=' ';
                    m[i+2][j]=' ';
                    r=3;
                    desce();
               }
               if(r==3){
                    m[i-1][j+2]='x';
                    m[i+1][j+1]='x';
                    m[i][j]=' ';
                    m[i][j+1]=' ';
                    r=4;
                    desce();
               }
               if(r==4){
                    m[i+1][j+1]='x';
                    m[i+1][j+1]='x';
                    m[i+2][j-1]=' ';
                    m[i+2][j]=' ';
                    r=1;
                    desce();
               }
                break;
            case 6://lv
              if(r==1){
                    m[i+1][j-2]=' ';
                    m[i][j]=' ';
                    m[i][j-1]='x';
                    m[i-1][j-1]='x';
                    r=2;
                    desce();
              }
              if(r==2){
                m[i][j+1]='x';
                m[i][j+2]='x';
                m[i+2][j]=' ';
                m[i+2][j+1]=' ';
                r=3;
                desce();
              }
              if(r==3){
                m[i][j-1]='x';
                m[i+2][j]='x';
                m[i][j+1]=' ';
                m[i][j+2]=' ';
                r=4;
                desce();
              }
              if(r==4){
                m[i+1][j]='x';
                m[i+1][j-1]='x';
                m[i][j]=' ';
                m[i+2][j+1]=' ';
                r=1;
                desce();
              }
                break;
        }
    }
}

void cont(){
    for(b=23;b>3;b--){
        for(d=0;d<20;d++){
            if(m[b][d]=='X')
                 pos++;
      }
     if(pos==18){
        pont+=24;
        for(aux=b;aux>4;aux--){
            for(k=0;k<20;k++){
                m[aux][k]=m[aux-1][k];
            }
        }
    }
    pos=0;
    }
}
int testel(){
    if(muv=='a'){
        switch(p){
            case 0://n
                if(r==1){
                    if(m[i][j-1]==' '&&m[i+1][j-2]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j-1]==' '&&m[i+1][j-1]==' '&&m[i+2][j]==' ')
                        return 1;
                    else
                        return 0;
                }
            case 1:
                if(r==1){
                    if(m[i][j-1]==' ' && m[i+1][j]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j-1]==' '&&m[i+1][j-2]==' '&&m[i+2][j-2]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 2://q
                if(m[i][j-1]==' ' && m[i+1][j-1]==' ')
                    return 1;
                else
                    return 0;
                break;
            case 3://i
                if(r==1){
                    if(m[i][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j-1]==' '&&m[i+1][j-1]==' '&&m[i+2][j-1]==' '&&m[i+3][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 4://t
                if(r==1){
                    if(m[i][j-1]==' '&&m[i+1][j-2]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j-1]==' '&&m[i+1][j-1]==' '&&m[i+2][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==3){
                    if(m[i][j-1]==' ' && m[i+1][j]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==4){
                    if(m[i][j-1]==' '&&m[i+1][j-2]==' '&&m[i+2][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 5://l
                if(r==1){
                    if(m[i][j-1]==' '&&m[i+1][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j-1]==' '&&m[i+1][j-1]==' '&&m[i+2][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==3){
                    if(m[i][j-1]==' '&&m[i+1][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==4){
                    if(m[i][j-1]==' '&& m[i+1][j-1]==' '&&m[i+2][j-2]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 6://lv
                 if(r==1){
                    if(m[i][j-1]==' '&&m[i+1][j-3]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j-1]==' '&&m[i+1][j-1]==' '&&m[i+2][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==3){
                    if(m[i][j-1]==' '&&m[i+1][j-1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==4){
                    if(m[i][j-1]==' '&& m[i+1][j]==' '&& m[i+2][j]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
        }
    }
    if(muv=='d'){
        switch(p){
            case 0:
                if(r==1){
                    if(m[i][j+2]==' '&&m[i+1][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j+1]==' '&&m[i+1][j+2]==' '&& m[i+2][j+2]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 1:
                if(r==1){
                    if(m[i][j+2]==' '&&m[i+1][j+3]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j+1]==' '&&m[i+1][j+1]==' '&&m[i+2][j]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 2:
                if(m[i][j+2]==' '&&m[i+1][j+2]==' ')
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if(r==1){
                    if(m[i][j+4]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j+1]==' '&&m[i+1][j+1]==' '&&m[i+2][j+1]==' '&&m[i+3][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 4:
                if(r==1){
                    if(m[i][j+1]==' '&& m[i+1][j+2]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j+1]==' '&&m[i+1][j+2]==' '&&m[i+2][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==3){
                    if(m[i][j+3]==' ' && m[i+1][j+2]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==4){
                    if(m[i][j+1]==' '&& m[i+1][j+1]==' '&&m[i+2][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 5:
                if(r==1){
                    if(m[i][j+1]==' '&&m[i+1][j+3]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j+2]==' '&&m[i+1][j+1]==' '&&m[i+2][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==3){
                    if(m[i][j+3]==' '&& m[i+1][j+3]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==4){
                    if(m[i][j+1]==' '&&m[i+1][j+1]==' '&&m[i+2][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
            case 6:
                if(r==1){
                    if(m[i][j+1]==' '&&m[i+1][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==2){
                    if(m[i][j+1]==' '&&m[i+1][j+1]==' '&&m[i+2][j+2]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==3){
                    if(m[i][j+3]==' '&&m[i+1][j+1]==' ')
                        return 1;
                    else
                        return 0;
                }
                if(r==4){
                    if(m[i][j+2]==' '&&m[i+1][j+2]==' '&&m[i+2][j+2]==' ')
                        return 1;
                    else
                        return 0;
                }
                break;
        }
    }
    return 0;
}

int tester(){
    switch(p){
        case 0:
            if(r==1){
                if(m[i-1][j]==' ' && m[i+1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i][j+1]==' '&&m[i+1][j-1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 1:
            if(r==1){
                if(m[i-1][j+2]==' '&&m[i][j+2]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i][j-1]==' '&& m[i+1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 3:
            if(r==1){
                if(m[i-1][j]==' '&&m[i+1][j]==' '&&m[i+2][j]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i][j+1]==' '&&m[i][j+2]==' '&&m[i][j+3]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 4:
            if(r==1){
                if(m[i+2][j]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i+1][j-1]==' ')
                    return 1;
                else
                    return 0;

            }
            if(r==3){
                if(m[i-1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==4){
                if(m[i+1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 5:
            if(r==1){
                if(m[i][j+1]==' '&&m[i+2][j]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i][j+2]==' '&&m[i+1][j+2]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==3){
                if(m[i-1][j+2]==' '&&m[i+1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==4){
                if(m[i+1][j+1]==' '&&m[i+1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 6:
            if(r==1){
                if(m[i][j-1]==' '&&m[i-1][j-1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i][j+1]==' '&&m[i][j+2]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==3){
                if(m[i][j-1]==' '&&m[i+2][j]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==4){
                if(m[i+1][j]==' '&&m[i+1][j-1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
    }
    return 0;
}

void com(){
    while(_kbhit()){
        muv=_getch();
        if(muv=='s')
            v=0;
        if(muv=='a')
            lado();
        if(muv=='d')
            lado();
        if(muv!='a'&&muv!='s'&&muv!='d')
            rot();
    }
}

int teste(){
    switch(p){
        case 0://n
            if(r==1){
                if(m[i+1][j+1]==' ' && m[i+2][j-1]==' ' && m[i+2][j]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i+2][j]==' '&& m[i+3][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 1://nv
            if(r==1){
                if(m[i+1][j]==' '&& m[i+2][j+1]==' ' && m[i+2][j+2]==' ')
                    return 1;
                if((m[i+1][j]=='#' || m[i+1][j]=='X')|| (m[i+2][j+1]=='#' || m[i+2][j+1]=='X')  || (m[i+2][j+2]!='X' || m[i+2][j+2]!='#'))
                    return 0;
            }
            if(r==2){
                if(m[i+2][j]==' ' && m[i+3][j-1]==' ')
                    return 1;
                if((m[i+2][j]=='X' ||m[i+2][j]=='#') || (m[i+3][j-1]=='X' ||m[i+3][j-1]=='#'))
                    return 0;
            }
            break;
        case 2://q
            if(m[i+2][j]==' '&& m[i+2][j+1]==' ')
                return 1;
            if(m[i+2][j]=='X'|| m[i+2][j+1]=='#'||m[i+2][j]=='#'|| m[i+2][j+1]=='X')
                return 0;
            break;
        case 3://I
            if(r==1){
                if(m[i+1][j]==' ' && m[i+1][j+1]==' ' && m[i+1][j+2]==' ' && m[i+1][j+3]==' ')
                    return 1;
                    if((m[i+1][j]=='X' || m[i+1][j]=='#') || (m[i+1][j+1]=='#'||m[i+1][j+1]=='X') || (m[i+1][j+2]=='X'||m[i+1][j+2]=='#') || (m[i+1][j+3]=='X' || m[i+1][j+3]=='#'))
                        return 0;
            }
            if(r==2){
                if(m[i+4][j]==' ')
                    return 1;
                if(m[i+4][j]=='X' || m[i+4][j]=='#')
                    return 0;
            }
            break;
        case 4://t
            if(r==1){
                if(m[i+2][j-1]==' '&& m[i+2][j]==' '&&m[i+2][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i+3][j]==' ' && m[i+2][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==3){
                if(m[i+1][j]==' ' && m[i+1][j+2]==' '&& m[i+2][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==4){
                if(m[i+2][j-1]==' ' && m[i+3][j]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 5://l
            if(r==1){
                if(m[i+2][j]==' ' && m[i+2][j+1]==' ' && m[i+2][j+2]==' ')
                    return 1;
                if(m[i+2][j]=='X' || m[i+2][j+1]=='X' || m[i+2][j+2]=='X'||m[i+2][j]=='#' || m[i+2][j+1]=='#' || m[i+2][j+2])
                   return 0;
            }
            if(r==2){
                if(m[i+3][j]==' ' && m[i+1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==3){
                if(m[i+1][j]==' '&& m[i+1][j+1]==' ' && m[i+2][j+2]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==4){
                if(m[i+3][j]==' '&& m[i+3][j-1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
        case 6://lv
            if(r==1){
                if(m[i+2][j]==' ' && m[i+2][j-1]==' ' && m[i+2][j-2]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==2){
                if(m[i+3][j]==' '&&m[i+3][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==3){
                if(m[i+2][j]==' '&&m[i+1][j+1]==' '&&m[i+1][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            if(r==4){
                if(m[i+1][j]==' '&&m[i+3][j+1]==' ')
                    return 1;
                else
                    return 0;
            }
            break;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    for(i=0;i<25;i++){//limpando a matriz
        for(j=0;j<20;j++){
            m[i][j]=' ';
            m[i][0]='|';
            m[24][j]='#';
            m[i][19]='|';
        }
    }
    while(1){
        pont+=4;
        v=200;
        r=1;
        if(pont>150)
            v=160;
        if(pont>250)
            v=140;
        if(pont>350)
            v=120;
        if(pont>450)
            v=100;
        if(pont>550)
            v=80;
        if(pont>650)
            v=60;
        if(pont>750)
            v=40;
        if(pont>850)
            v=20;
        pecas();
        desce();
    }
    return 0;
}
