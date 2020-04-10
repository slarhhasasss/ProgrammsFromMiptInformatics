/*
 * Переведите число, записанное в шестнадцатиричной системе счисления, в двоичную.

Входные данные: неотрицательное шестнадцатиричное число, содержащее не более 1000000 цифр (0123456789ABCDEF).

Единственная строка выходных данных должна содержать последовательность 0 и 1, образующих двоичную запись числа, полученного на входе. Лидирующих нулей быть не должно.
 *
 */



#include <stdio.h>
#include <stdlib.h>


void convert(char c) {
    int num1, num2, num3, num4;
    int curC;
    switch (c) {
        case '0':
            curC = 0;
            break;
        case '1':
            curC = 1;
            break;
        case '2':
            curC = 2;
            break;
        case '3':
            curC = 3;
            break;
        case '4':
            curC = 4;
            break;
        case '5':
            curC = 5;
            break;
        case '6':
            curC = 6;
            break;
        case '7':
            curC = 7;
            break;
        case '8':
            curC = 8;
            break;
        case '9':
            curC = 9;
            break;
        case 'a':
            curC = 10;
            break;
        case 'A':
            curC = 10;
            break;
        case 'b':
            curC = 11;
            break;
        case 'B':
            curC = 11;
            break;
        case 'c':
            curC = 12;
            break;
        case 'C':
            curC = 12;
            break;
        case 'D':
            curC = 13;
            break;
        case 'd':
            curC = 13;
            break;
        case 'e':
            curC = 14;
            break;
        case 'E':
            curC = 14;
            break;
        case 'f':
            curC = 15;
            break;
        case 'F':
            curC = 15;
            break;
        default:
            curC = 0;
            break;
    }
    int curNumber = curC;
    num4 = curNumber % 2;
    curNumber /= 2;
    num3 = curNumber % 2;
    curNumber /= 2;
    num2 = curNumber % 2;
    curNumber /= 2;
    num1 = curNumber % 2;

    printf("%i%i%i%i", num1, num2, num3, num4);

}


int main() {
    int num1, num2, num3, num4;
    int curC = strtol();



    int curNumber = curC;
    num4 = curNumber % 2;
    curNumber /= 2;
    num3 = curNumber % 2;
    curNumber /= 2;
    num2 = curNumber % 2;
    curNumber /= 2;
    num1 = curNumber % 2;


    if (num1 == 1) {
        printf("%i%i%i%i", num1, num2, num3, num4);
    } else if (num2 == 1) {
        printf("%i%i%i", num2, num3, num4);
    } else if (num3 == 1) {
        printf("%i%i", num3, num4);
    } else if (num4 == 1) {
        printf("%i", num4);
    } else {
        printf("%i", 0);
    }


    while (curC != '\n') {
        convert(curC);
        curC = atoi(getchar());
    }

    return 0;
}