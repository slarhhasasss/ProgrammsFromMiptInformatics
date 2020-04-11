/*
В одном байте закодирована следующая информация (от младших бит к старшим):

Ширина (бит)	Признак	Возможные значения	Условные сокращения
1	пол	1 - male, 0 - female	ma, fe
1	умный	1 - clever, 0 - dummy	cl, du
1	шляпа	1 - hat, 0 - without hat	ha, nh
1	брюки-юбка	1 - trousers, 0 - skirt	tr, sk
2	цвет волос	00 - blonde, 01 - red, 10 - brown, 11 - black	bn, rd, bw,bk
2	цвет глаз	00 - blue, 01 - green, 10 - gray, 11 - dark	bu, ge, gy, da
Например, 0x6B, в бинарном виде 0110 1011 (читаем от младших бит к старшим) - (1) - мужчина, (1) - умный,
(0) - без шляпы, (1) - в брюках, (10) - шатен (цвет волос - brown), (01) - зеленоглазый.
Можно написать аббревиатурами: ma cl nh tr bw ge

Следователь опросил нескольких свидетелей и аббревиатурой записал их
описание подозреваемого. Нужно закодировать описание подозреваемого одним числом. Внимание!
Так как свидетелей было несколько, одна и та же характеристика может быть перечислена несколько раз.
Характеристика не может изменяться от свидетеля к свидетелю, т.е. голубоглазый блондин не станет темноглазым брюнетом.
*/

#include <stdio.h>
#include <malloc.h>

int main() {
    int bits[8];
    for(int i = 0; i < 8; i++) {
        bits[i] = 0;
    }

    char * curStr =(char *) malloc(2 * sizeof(char *));
    int len = scanf("%s", curStr);


    while(len != -1) {
        if(curStr[0] == 'm' && curStr[1] == 'a') {
            bits[7] = 1;
        }
        else if (curStr[0] == 'f' && curStr[1] == 'e') {
            bits[7] = 0;
        }
        else if (curStr[0] == 'c' && curStr[1] == 'l') {
            bits[6] = 1;
        }
        else if (curStr[0] == 'd' && curStr[1] == 'u') {
            bits[6] = 0;
        }
        else if (curStr[0] == 'h' && curStr[1] == 'a') {
            bits[5] = 1;
        }
        else if (curStr[0] == 'n' && curStr[1] == 'h') {
            bits[5] = 0;
        }
        else if (curStr[0] == 't' && curStr[1] == 'r') {
            bits[4] = 1;
        }
        else if (curStr[0] == 's' && curStr[1] == 'k') {
            bits[4] = 0;
        }
        else if (curStr[0] == 'b' && curStr[1] == 'n') {
            bits[2] = 0;
            bits[3] = 0;
        }
        else if (curStr[0] == 'r' && curStr[1] == 'd') {
            bits[2] = 0;
            bits[3] = 1;
        }
        else if (curStr[0] == 'b' && curStr[1] == 'w') {
            bits[2] = 1;
            bits[3] = 0;
        }
        else if (curStr[0] == 'b' && curStr[1] == 'k') {
            bits[2] = 1;
            bits[3] = 1;
        }
        else if (curStr[0] == 'b' && curStr[1] == 'u') {
            bits[0] = 0;
            bits[1] = 0;
        }
        else if (curStr[0] == 'g' && curStr[1] == 'e') {
            bits[0] = 0;
            bits[1] = 1;
        }
        else if (curStr[0] == 'g' && curStr[1] == 'y') {
            bits[0] = 1;
            bits[1] = 0;
        }
        else if (curStr[0] == 'd' && curStr[1] == 'a') {
            bits[0] = 1;
            bits[1] = 1;
        }
        len = scanf("%s", curStr);
    }

    char ans[2];
    ans[0] = '0';
    ans[1] = '0';

    if(bits[0] == 0 && bits[1] == 0 && bits[2] == 0 && bits[3] == 0) {
        ans[0] = '0';
    }
    else if (bits[0] == 0 && bits[1] == 0 && bits[2] == 0 && bits[3] == 1) {
        ans[0] = '1';
    }
    else if (bits[0] == 0 && bits[1] == 0 && bits[2] == 1 && bits[3] == 0) {
        ans[0] = '2';
    }
    else if (bits[0] == 0 && bits[1] == 0 && bits[2] == 1 && bits[3] == 1) {
        ans[0] = '3';
    }
    else if (bits[0] == 0 && bits[1] == 1 && bits[2] == 0 && bits[3] == 0) {
        ans[0] = '4';
    }
    else if (bits[0] == 0 && bits[1] == 1 && bits[2] == 0 && bits[3] == 1) {
        ans[0] = '5';
    }
    else if (bits[0] == 0 && bits[1] == 1 && bits[2] == 1 && bits[3] == 0) {
        ans[0] = '6';
    }
    else if (bits[0] == 0 && bits[1] == 1 && bits[2] == 1 && bits[3] == 1) {
        ans[0] = '7';
    }
    else if (bits[0] == 1 && bits[1] == 0 && bits[2] == 0 && bits[3] == 0) {
        ans[0] = '8';
    }
    else if (bits[0] == 1 && bits[1] == 0 && bits[2] == 0 && bits[3] == 1) {
        ans[0] = '9';
    }
    else if (bits[0] == 1 && bits[1] == 0 && bits[2] == 1 && bits[3] == 0) {
        ans[0] = 'a';
    }
    else if (bits[0] == 1 && bits[1] == 0 && bits[2] == 1 && bits[3] == 1) {
        ans[0] = 'b';
    }
    else if (bits[0] == 1 && bits[1] == 1 && bits[2] == 0 && bits[3] == 0) {
        ans[0] = 'c';
    }
    else if (bits[0] == 1 && bits[1] == 1 && bits[2] == 0 && bits[3] == 1) {
        ans[0] = 'd';
    }
    else if (bits[0] == 1 && bits[1] == 1 && bits[2] == 1 && bits[3] == 0) {
        ans[0] = 'e';
    }
    else if (bits[0] == 1 && bits[1] == 1 && bits[2] == 1 && bits[3] == 1) {
        ans[0] = 'f';
    }


    //hjhjh
    if(bits[4] == 0 && bits[5] == 0 && bits[6] == 0 && bits[7] == 0) {
        ans[1] = '0';
    }
    else if (bits[4] == 0 && bits[5] == 0 && bits[6] == 0 && bits[7] == 1) {
        ans[1] = '1';
    }
    else if (bits[4] == 0 && bits[5] == 0 && bits[6] == 1 && bits[7] == 0) {
        ans[1] ='2';
    }
    else if (bits[4] == 0 && bits[5] == 0 && bits[6] == 1 && bits[7] == 1) {
        ans[1] = '3';
    }
    else if (bits[4] == 0 && bits[5] == 1 && bits[6] == 0 && bits[7] == 0) {
        ans[1] = '4';
    }
    else if (bits[4] == 0 && bits[5] == 1 && bits[6] == 0 && bits[7] == 1) {
        ans[1] = '5';
    }
    else if (bits[4] == 0 && bits[5] == 1 && bits[6] == 1 && bits[7] == 0) {
        ans[1] = '6';
    }
    else if (bits[4] == 0 && bits[5] == 1 && bits[6] == 1 && bits[7] == 1) {
        ans[1] = '7';
    }
    else if (bits[4] == 1 && bits[5] == 0 && bits[6] == 0 && bits[7] == 0) {
        ans[1] = '8';
    }
    else if (bits[4] == 1 && bits[5] == 0 && bits[6] == 0 && bits[7] == 1) {
        ans[1] = '9';
    }
    else if (bits[4] == 1 && bits[5] == 0 && bits[6] == 1 && bits[7] == 0) {
        ans[1] = 'a';
    }
    else if (bits[4] == 1 && bits[5] == 0 && bits[6] == 1 && bits[7] == 1) {
        ans[1] = 'b';
    }
    else if (bits[4] == 1 && bits[5] == 1 && bits[6] == 0 && bits[7] == 0) {
        ans[1] = 'c';
    }
    else if (bits[4] == 1 && bits[5] == 1 && bits[6] == 0 && bits[7] == 1) {
        ans[1] = 'd';
    }
    else if (bits[4] == 1 && bits[5] == 1 && bits[6] == 1 && bits[7] == 0) {
        ans[1] = 'e';
    }
    else if (bits[4] == 1 && bits[5] == 1 && bits[6] == 1 && bits[7] == 1) {
        ans[1] = 'f';
    }

    printf("%c", ans[0]);
    printf("%c", ans[1]);
    free(curStr);
}