/*
 * Powered by Kolesnikov D. V. from 10.04.2020
 *
 * Уникальная и необычно дешёвая для своего времени ЭВМ
 * "Сетунь" работала в уравновешенной троичной системе счисления.
 * В уравновешенной троичной системе счисления используется основание
 * 3 и три цифры: 0, 1 и -1. Цифру -1 будем обозначать знаком $.
 * Достоинство уравновешенной троичной системы счисления:
 * простота хранения отрицательных чисел и удобство нахождения числа, противоположному данному.
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    char * c1 = malloc(2001 * sizeof(char));
    char * c2 = malloc(2001 * sizeof(char));

    scanf("%s", c1);
    scanf("%s", c2);

    int num1[2001], num2[2001];

    int ans[2001];

    for(int i = 0; i < strlen(c1); i++) {
        if(c1[i] == '0') {
            num1[i] = 0;
        }
        else if(c1[i] == '$'){
            num1[i] = -1;
        }
        else {
            num1[i] = 1;
        }
    }

    for(int i = 0; i < strlen(c2); i++) {
        if(c2[i] == '0') {
            num2[i] = 0;
        }
        else if(c2[i] == '$'){
            num2[i] = -1;
        }
        else {
            num2[i] = 1;
        }
    }



    int curPtr1 = strlen(c1) - 1, curPtr2 = strlen(c2) - 1;
    int curPoint = 0;
    int curAdd = 0;
    while(curPtr1 >= 0 && 0 <= curPtr2) {
        if(num1[curPtr1] + num2[curPtr2] + curAdd == 3) {
            ans[curPoint] = 0;
            curAdd = 1;
        }
        else if(num1[curPtr1] + num2[curPtr2] + curAdd == 2) {
            ans[curPoint] = -1;
            curAdd = 1;
        }
        else if(num1[curPtr1] + num2[curPtr2] + curAdd == 1) {
            ans[curPoint] = 1;
            curAdd = 0;
        }
        else if(num1[curPtr1] + num2[curPtr2] + curAdd == 0) {
            ans[curPoint] = 0;
            curAdd = 0;
        }
        else if(num1[curPtr1] + num2[curPtr2] + curAdd == -1) {
            ans[curPoint] = -1;
            curAdd = 0;
        }
        else if(num1[curPtr1] + num2[curPtr2] + curAdd == -2) {
            ans[curPoint] = 1;
            curAdd = -1;
        }
        else if(num1[curPtr1] + num2[curPtr2] + curAdd == -3) {
            ans[curPoint] = 0;
            curAdd = -1;
        }






        /*ans[curPoint] = (num1[curPtr1] + num2[curPtr2] + curAdd) % 2;
        curAdd = (num1[curPtr1] + num2[curPtr2] + curAdd) / 2;*/

        curPoint++;
        curPtr2--;
        curPtr1--;
    }

    if(curPtr1 < 0 && curPtr2 < 0 && curAdd == 0) {
        curPoint--;
    }

    if(curPtr1 >= 0) {
        while(curPtr1 >= 0) {
            /*ans[curPoint] = (num1[curPtr1] + curAdd) % 2;
            curAdd = (num1[curPtr1] + curAdd) / 2;*/
            if(num1[curPtr1] + curAdd == -2) {
                ans[curPoint] = 1;
                curAdd = -1;
            }
            else if (num1[curPtr1] + curAdd == -1) {
                ans[curPoint] = -1;
                curAdd = 0;
            }
            else if (num1[curPtr1] + curAdd == 0) {
                ans[curPoint] = 0;
                curAdd = 0;
            }
            else if (num1[curPtr1] + curAdd == 1) {
                ans[curPoint] = 1;
                curAdd = 0;
            }
            else if (num1[curPtr1] + curAdd == 2) {
                ans[curPoint] = -1;
                curAdd = 1;
            }

            curPtr1--;
            curPoint++;
        }
        curPoint--;
        if(curAdd != 0) {
            curPoint++;
            ans[curPoint] = curAdd;
        }
    }

    if(curPtr2 >= 0) {
        while(curPtr2 >= 0) {
            /*ans[curPoint] = (num2[curPtr2] + curAdd) % 2;
            curAdd = (num2[curPtr2] + curAdd) / 2;*/
            if(num2[curPtr2] + curAdd == -2) {
                ans[curPoint] = 1;
                curAdd = -1;
            }
            else if (num2[curPtr2] + curAdd == -1) {
                ans[curPoint] = -1;
                curAdd = 0;
            }
            else if (num2[curPtr2] + curAdd == 0) {
                ans[curPoint] = 0;
                curAdd = 0;
            }
            else if (num2[curPtr2] + curAdd == 1) {
                ans[curPoint] = 1;
                curAdd = 0;
            }
            else if (num2[curPtr2] + curAdd == 2) {
                ans[curPoint] = -1;
                curAdd = 1;
            }

            curPtr2--;
            curPoint++;
        }
        curPoint--;
        if(curAdd != 0) {
            curPoint++;
            ans[curPoint] = curAdd;
        }
    }

    if(curPtr2 < 0 && curPtr1 < 0 && curAdd == 1) {
        ans[curPoint] = curAdd;
    }

    if(curPtr2 < 0 && curPtr1 < 0 && curAdd == -1) {
        ans[curPoint] = curAdd;
    }


    int was1 = 0;
    for(int i = 0; i <= curPoint; i++) {
        if(ans[curPoint - i] == 1 || ans[curPoint - i] == -1) {
            was1 = 1;
        }
        if(was1 == 1) {
            if(ans[curPoint - i] == 1) {
                printf("%c", '1');
            }
            else if (ans[curPoint - i] == 0) {
                printf("%c", '0');
            }
            else {
                printf("%c", '$');
            }
        }
    }

    free(c1);
    free(c2);

    if(was1 == 0) {
        printf("%i", 0);
    }

    return 0;
}