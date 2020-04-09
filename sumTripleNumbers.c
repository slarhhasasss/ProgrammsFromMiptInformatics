/*
 * На стандартном потоке ввода подается последовательно вещественное число x и целое число в 16-ричной записи y.
 * Единственным аргументов программы является целое число z в 27-ричной системе исчисления.
 * Необходимо вывести вычислить значение x+y+z и вывести его на стандартный поток вывода с точностью до 3-го знака после точки.
 *
 *
 *
 *
 */


#include <stdio.h>
#include <string.h>
#include <math.h>

float charToFloat(char *string);

int main(int args, char* argv[]) {

    float x;
    int y;
    scanf("%f", &x);
    scanf("%x", &y);
    printf("%.3f", x + y + charToFloat(argv[1]));

    return 0;
}

float charToFloat(char *str) {
    int number10 = 0;
    int curPosition = strlen(str);
    for(int i = 0; i < strlen(str); i++) {
        curPosition = curPosition - 1;
        switch (str[curPosition]) {
            case 'a':
                number10 += 10 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'A':
                number10 += 10 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'b':
                number10 += 11 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'B':
                number10 += 11 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'c':
                number10 += 12 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'C':
                number10 += 12 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'd':
                number10 += 13 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'D':
                number10 += 13 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'e':
                number10 += 14 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'E':
                number10 += 14 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'f':
                number10 += 15 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'F':
                number10 += 15 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'g':
                number10 += 16 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'G':
                number10 += 16 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'h':
                number10 += 17 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'H':
                number10 += 17 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'I':
                number10 += 18 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'i':
                number10 += 18 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'j':
                number10 += 19 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'J':
                number10 += 19 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'k':
                number10 += 20 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'K':
                number10 += 20 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'l':
                number10 += 21 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'L':
                number10 += 21 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'm':
                number10 += 22 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'M':
                number10 += 22 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'n':
                number10 += 23 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'N':
                number10 += 23 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'o':
                number10 += 24 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'O':
                number10 += 24 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'p':
                number10 += 25 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'P':
                number10 += 25 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'q':
                number10 += 26 * pow(27, strlen(str) - curPosition - 1);
                break;
            case 'Q':
                number10 += 26 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '0':
                number10 += 0 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '1':
                number10 += 1 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '2':
                number10 += 2 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '3':
                number10 += 3 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '4':
                number10 += 4 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '5':
                number10 += 5 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '6':
                number10 += 6 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '7':
                number10 += 7 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '8':
                number10 += 8 * pow(27, strlen(str) - curPosition - 1);
                break;
            case '9':
                number10 += 9 * pow(27, strlen(str) - curPosition - 1);
                break;
            default:
                break;
        }
    }
    return number10;
}
