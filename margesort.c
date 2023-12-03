#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas sub-listas ordenadas
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar sub-listas temporárias
    int L[n1], R[n2];

    // Copiar dados para as sub-listas temporárias L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar as sub-listas de volta na lista original arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para realizar o Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontrar o ponto médio
        int m = l + (r - l) / 2;

        // Ordenar a primeira metade
        mergeSort(arr, l, m);

        // Ordenar a segunda metade
        mergeSort(arr, m + 1, r);

        // Mesclar as duas metades ordenadas
        merge(arr, l, m, r);
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

    // Chamar a função mergeSort para ordenar a lista
    mergeSort(lista, 0, 99);

    printf("\nLista após a ordenação:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", lista[i]);
    }

    return 0;
}

