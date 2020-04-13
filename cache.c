/*
Оптимизации с использованием кэша
The matrix has you....

Time limit: 2 секунды

        Memory limit: 1 гигабайт

        Рассмотрим две квадратные матрицы А и В размера n. A[i][j]=НОД(i+1, j+1), B[i][j]=НОД(n-i+1, n-j+1),
        где НОД(x,y) - наибольший общий делитель чисел x и y. Выведите количество элементов произведения матриц АВ,
        которые делятся на заданное число d.

Вход: целые числа n, d

        Ограничения: 0 ≤ n ≤ 1024.

Ограничения: 1 ≤ d ≤ 100.
*/

#include <stdio.h>

int nod(int a, int b) {
    while(a - b != 0) {
        if(a >= b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int ARR[1024][1024];
int BRR[1024][1024];


int main() {
    int n;        //размер матрицы
    int d;        //Делитель
    int SUMSUM = 0;

    scanf("%i", &n);
    scanf("%i", &d);

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ARR[i][j] = nod(i + 1, j + 1);
            BRR[i][j] = nod(n - i + 1, n - j + 1);
            if(i != j) {
                ARR[j][i] = ARR[i][j];
                BRR[j][i] = BRR[i][j];
            }


            //printf("%i ", ARR[i][j]);
        }
        //printf("\n");
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum = 0;
            for(int t = 0; t < n; t++) {
                sum += ARR[i][t] * BRR[j][t];
            }
            if(sum % d == 0) {
                SUMSUM += 1;
            }
        }
    }
    printf("%i", SUMSUM);

    return 0;

}