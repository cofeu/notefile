#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/noteraw.h"
#include <termios.h>  
#include <unistd.h>   
#include <sys/ioctl.h>


#define CTRL_KEY(k) ((k) & 0x1F)

int main(int argc, char *argv[]) {
    struct termios ayar1, ayar2;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int max_satir = w.ws_row;
    int max_sutun = w.ws_col;
    if (argc < 2) {
        printf("Lütfen bir dosya ekleyin!\n");
        return 1;
    }
  
    tcgetattr(STDIN_FILENO, &ayar1);
    ayar2 = ayar1;

    
    ayar2.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &ayar2);
   
    
    char dosya[2048];
    getcwd(dosya, sizeof(dosya));

    strcat(dosya, "/");
    strcat(dosya, argv[1]);

    int metin_uzunlugu = strlen(dosya);

    int hedef_satir = max_satir;
    int hedef_sutun = max_sutun - metin_uzunlugu + 1;

    if (hedef_sutun < 1) hedef_sutun = 1;
    ekraniSil();

    printf("\033[%d;%dH%s", hedef_satir, hedef_sutun, dosya);
    fflush(stdout);
    
    printf("\033[1;1H");
    char test[2048];
    int idx = 0;
    char tusuYakala;

    fflush(stdout);
    
    FILE *okumaFp = fopen(argv[1], "r");
     if (okumaFp != NULL) {
        int ch;

        while((ch = fgetc(okumaFp)) != EOF) {
            if (idx < 2047) {
                putchar(ch);
                test[idx] = ch;
                idx++;
            }
        }
        fclose(okumaFp);
        fflush(stdout);
     }
    
    while(1) {
        tusuYakala = getchar();
        if (tusuYakala == CTRL_KEY('o')) {
        test[idx] = '\0';
       
        FILE *fp = fopen(argv[1], "w");
        if (fp != NULL) {
           fprintf(fp, "%s", test);
           fclose(fp);
        }
        printf("\033[1;1H");
        fflush(stdout);
    }
    else if (tusuYakala == CTRL_KEY('x')) {
        test[idx] = '\0';
        ekraniSil();
        printf("Programdan cikildi.\n");
        FILE *fp = fopen(argv[1], "w");
        if (fp != NULL) {
           fprintf(fp, "%s", test);
           fclose(fp);
        }
        fflush(stdout);
        break; 
    }
    else if (tusuYakala == 127 || tusuYakala == 8) {
            if (idx > 0) {
                idx--; 
                printf("\b \b"); 
                fflush(stdout);
            }
        }
    else if (tusuYakala == '\n' || tusuYakala == '\r') {
        if (idx < 2047) {
                test[idx] = '\n'; 
                idx++;
            }
        printf("\r\n");
        fflush(stdout);


    }
    else {
            putchar(tusuYakala);
            fflush(stdout);
            if (idx < 2047) { 
                test[idx] = tusuYakala; 
                idx++;
            }
        }
    
    }
    

    
    tcsetattr(STDIN_FILENO, TCSANOW, &ayar1);

    return 0;
}