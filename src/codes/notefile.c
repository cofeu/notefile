#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/noteraw.h"
#include <termios.h>  
#include <unistd.h>   
#include <sys/ioctl.h>
#include <signal.h>


#define CTRL_KEY(k) ((k) & 0x1F)
struct termios orig_termios;

void handle_sigint(int sig) {
    (void)sig;
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    ekraniSil();
    printf("UYARI: Sigint yaparak programdan ciktiniz haberiniz olsun\n");
    printf("\n");
    exit(0);
}

int dosyaKaydi(char **test, size_t *idx, size_t *kapasite, char *dosya) {
            if(*idx > 0 && (*test)[*idx - 1] != '\n') {
                if(*idx + 1 >= *kapasite) {
                    *kapasite = (*kapasite == 0) ? 1024 : *kapasite * 2;
                    char *testP = realloc(*test, *kapasite);
                if(testP == NULL) {
                    printf("HATA: Bellek Yetersiz\n");
                    return 0;
                }
            else {
                *test = testP;
                
                
        }
        

        }
        (*test)[*idx] = '\n';
        (*idx)++;
        }
        FILE *yazDosya = fopen(dosya, "w");
        if(yazDosya == NULL) {
            printf("HATA: Dosya acilamadi!\n");
            return 0;
        }
        fwrite(*test, 1, *idx, yazDosya);
        fclose(yazDosya);
        return 1;
}
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

    tcgetattr(STDIN_FILENO, &ayar1);
    orig_termios = ayar1;

    
    ayar2.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &ayar2);

    tcsetattr(STDIN_FILENO, TCSANOW, &ayar2);
    signal(SIGINT, handle_sigint);
   
    
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
    char *test = NULL;
    size_t idx = 0;
    size_t kapasite = 0;
    size_t cursor = 0;
    char tusuYakala;

    fflush(stdout);
    
    FILE *okumaFp = fopen(argv[1], "r");
     if (okumaFp != NULL) {
        int ch;

        while((ch = fgetc(okumaFp)) != EOF) {

            if(idx + 1 >= kapasite) {
                kapasite = (kapasite == 0) ? 1024 : kapasite * 2;
                char *yeni = realloc(test, kapasite);

                if (yeni == NULL) {
                printf("HATA: Bellek yetersiz!\n");
                free(test);
                fclose(okumaFp);
                return 1;
        }
        test = yeni;
    }
    test[idx] = ch;
    idx++;

    putchar(ch);

    
}
}
    
    while(1) {
        tusuYakala = getchar();
        if (tusuYakala == CTRL_KEY('o')) {
        dosyaKaydi(&test, &idx, &kapasite, argv[1]);
        printf("\033[1;1H");
        fflush(stdout);
    }
    else if (tusuYakala == CTRL_KEY('x')) {
        ekraniSil();
        printf("Programdan cikildi.\n");
        fflush(stdout);
        break; 
    }
    else if (tusuYakala == 127 || tusuYakala == 8) {
    if (idx > 0) {
        idx--;
        while (idx > 0 && ((unsigned char)test[idx] & 0xC0) == 0x80) {
            idx--;
        }
        printf("\b \b");
        fflush(stdout);
    }
    }
    else if (tusuYakala == '\n' || tusuYakala == '\r') {

    if (idx + 1 >= kapasite) {
        kapasite = (kapasite == 0) ? 1024 : kapasite * 2;

        char *yeni = realloc(test, kapasite);

        if (yeni == NULL) {
            printf("HATA: Bellek yetersiz!\n");
            break;
        }

        test = yeni;
    }

    test[idx] = '\n';
    idx++;

    printf("\r\n");
    fflush(stdout);
}

    else {
    if(idx + 1 >= kapasite) {
        kapasite = (kapasite == 0) ? 1024 : kapasite * 2;

        char *yeni = realloc(test, kapasite);

        if (yeni == NULL) {
            printf("HATA: Bellek yetersiz!\n");
            break;
        }

        test = yeni;
    }

    putchar(tusuYakala);
    fflush(stdout);

    test[idx] = tusuYakala;
    idx++;
}
    
    }
    

    
    tcsetattr(STDIN_FILENO, TCSANOW, &ayar1);

    free(test);

    return 0;
    // notefile end
}