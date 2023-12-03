#include <stdio.h>
#include <stdlib.h>

// Fun��o para trocar dois elementos em um array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o que implementa o CombSort
void combSort(int arr[], int size) {
    int gap = size;  // Inicializa o gap com o tamanho do array
    int swapped = 1; // Flag para verificar se houve trocas

    while (gap != 1 || swapped == 1) {
        // Atualiza o gap usando a f�rmula de redu��o
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        // Inicializa a flag de trocas para esta itera��o
        swapped = 0;

        // Percorre o array com o gap atual
        for (int i = 0; i < size - gap; i++) {
            // Compara elementos a uma dist�ncia de gap
            if (arr[i] > arr[i + gap]) {
                // Troca os elementos se estiverem fora de ordem
                swap(&arr[i], &arr[i + gap]);
                swapped = 1; // Sinaliza que houve uma troca
            }
        }
    }
}

int main() {
    int lista[100];

    // Preencher a lista com n�meros aleat�rios entre 1 e 100
    for (int i = 0; i < 100; i++) {
        lista[i] = rand() % 100 + 1;
    }

    printf("Lista antes da ordena��o:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", lista[i]);
    }

    // Chamar a fun��o combSort para ordenar a lista
    combSort(lista, 100);

    printf("\nLista ap�s a ordena��o:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", lista[i]);
    }

    return 0;
}

