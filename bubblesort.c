#include <stdio.h>
#include <stdlib.h>

// Fun��o para trocar dois elementos em um array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o que implementa o Bubble Sort
void bubbleSort(int arr[], int size) {
	int i, j;
    for (i = 0; i < size - 1; i++) {
    	
        for (j = 0; j < size - i - 1; j++) {
            // Compara elementos adjacentes e os troca se estiverem fora de ordem
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int lista[100], i;

    // Preencher a lista com n�meros aleat�rios entre 1 e 100
    for (i = 0; i < 100; i++) {
        lista[i] = rand() % 1000 + 1;
    }

    printf("Lista antes da ordena��o:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", lista[i]);
    }

    // Chamar a fun��o bubbleSort para ordenar a lista
    bubbleSort(lista, 100);

    printf("\nLista ap�s a ordena��o:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", lista[i]);
    }

    return 0;
}

