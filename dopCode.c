/*
C: Дополнительный код
Дано целое число А. Выведите запись числа A в двоичном 8-разрядном дополнительном коде.

Ограничения: -128 ≤ A ≤ 127.
*/


#include <stdio.h>


int main() {
    int num;
    scanf("%i", &num);
    int arr[8];
    for(int i = 0; i < 8; i++) {
        arr[i] = 0;
    }

    if(num == -128) {
        printf("%s", "10000000");
        return 0;
    }
    else if(num < 0) {
        arr[0] = 1;
        num = num * (-1);
        int p = 0;
        while(num != 0) {
            arr[7 - p] = num % 2;
            num /= 2;
            p++;
        }

        for(int j = 1; j < 8; j++) {
            if(arr[j] == 0) {
                arr[j] = 1;
            }
            else {
                arr[j] = 0;
            }
        }

        int curAdd = 1;
        int k = 0;
        while(curAdd != 0) {
            int tmp = arr[7 - k];
            arr[7 - k] = (arr[7 - k] + curAdd) % 2;
            curAdd = (tmp + curAdd) / 2;
            k++;
        }
    }
    else {
        arr[0] = 0;
        int p = 0;
        while(num != 0) {
            arr[7 - p] = num % 2;
            num /= 2;
            p++;
        }

    }



    for(int i = 0; i < 8; i++) {
        printf("%i", arr[i]);
    }

}