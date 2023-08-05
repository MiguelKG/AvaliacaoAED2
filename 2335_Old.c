#include <stdio.h>
#include <stdlib.h>

int fillCups(int* amount, int amountSize);

int main()
{
    int amount[] = {0, 2, 2};
    int r = fillCups ( amount, sizeof(amount) / sizeof(int) );
    printf("Resultado: %d\n", r);
}

int fillCups(int* amount, int amountSize){
    int maior1 = 0, maior2 = 1;
    int passos = 0;

    while (amount[0] != 0 || amount[1] != 0 || amount[2] != 0) {
        for (int i = 0; i < amountSize; i++) {
            if (amount[i] == amount[maior1] && i != maior1) {
                maior2 = i;
            } else
            if (amount[i] > amount[maior1]) {
                maior2 = maior1;
                maior1 = i;
            } else
            if (amount[i] > amount[maior2] && amount[i] < amount[maior1]) {
                maior2 = i;
            }
        }

        if (amount[maior1] > 0 && amount[maior2] > 0) {
            amount[maior1]--;
            amount[maior2]--;
        } else {
            amount[maior1]--;
        }
        passos++;
    }

    return passos;
}
