#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos em um array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que implementa o CombSort
void combSort(int arr[], int size) {
    int gap = size;  // Inicializa o gap com o tamanho do array
    int swapped = 1; // Flag para verificar se houve trocas

    while (gap != 1 || swapped == 1) {
        // Atualiza o gap usando a fórmula de redução
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        // Inicializa a flag de trocas para esta iteração
        swapped = 0;

        // Percorre o array com o gap atual
        for (int i = 0; i < size - gap; i++) {
            // Compara elementos a uma distância de gap
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

    // Preencher a lista com números aleatórios entre 1 e 100
    for (int i = 0; i < 100; i++) {
        lista[i] = rand() % 100 + 1;
    }

    printf("Lista antes da ordenação:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", lista[i]);
    }

    // Chamar a função combSort para ordenar a lista
    combSort(lista, 100);

    printf("\nLista após a ordenação:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", lista[i]);
    }

    return 0;
}

