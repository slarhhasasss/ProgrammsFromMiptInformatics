/*
 * Напишите программу, которая суммирует большие натуральные числа, заданные в двоичной системе счисления.
 *
 *Две строки, содержащие двоичные записи неотрицательных целых чисел a и b. Количество цифр в каждой записи не более 1000.
 */


#include <stdio.h>
#include <string.h>

int main() {
    char c1[2001];
    char c2[2001];

    scanf("%s", c1);
    scanf("%s", c2);

    int num1[2001], num2[2001];

    int ans[2001];

    for(int i = 0; i < strlen(c1); i++) {
        if(c1[i] == '0') {
            num1[i] = 0;
        }
        else {
            num1[i] = 1;
        }
    }

    for(int i = 0; i < strlen(c2); i++) {
        if(c2[i] == '0') {
            num2[i] = 0;
        }
        else {
            num2[i] = 1;
        }
    }



    int curPtr1 = strlen(c1) - 1, curPtr2 = strlen(c2) - 1;
    int curPoint = 0;
    int curAdd = 0;
    while(curPtr1 >= 0 && 0 <= curPtr2) {
        ans[curPoint] = (num1[curPtr1] + num2[curPtr2] + curAdd) % 2;
        curAdd = (num1[curPtr1] + num2[curPtr2] + curAdd) / 2;

        curPoint++;
        curPtr2--;
        curPtr1--;
    }

    if(curPtr1 >= 0) {
        while(curPtr1 >= 0) {
            ans[curPoint] = (num1[curPtr1] + curAdd) % 2;
            curAdd = (num1[curPtr1] + curAdd) / 2;

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
            ans[curPoint] = (num2[curPtr2] + curAdd) % 2;
            curAdd = (num2[curPtr2] + curAdd) / 2;

            curPtr2--;
            curPoint++;
        }
        curPoint--;
        if(curAdd != 0) {
            curPoint++;
            ans[curPoint] = curAdd;
        }
    }

    if(curPtr2 < 0 && curPtr1 < 0 && curAdd > 0) {
        ans[curPoint] = curAdd;
    }

    int was1 = 0;
    for(int i = 0; i <= curPoint; i++) {
        if(ans[curPoint - i] == 1) {
            was1 = 1;
        }
        if(was1 == 1) {
            printf("%i", ans[curPoint - i]);
        }
    }

    if(was1 == 0) {
        printf("%i", 0);
    }

    return 0;
}