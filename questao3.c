//Questão 3
#include <stdio.h>
#define TAM 12

//Prototipação
void carregaVetor(int[]);
void escreveVetor(int[]);
int somaVetorIndicePar(int[]);

//Implementação
int main(void) {
  int vet[TAM];
  //invoca o procedimento para carregar o vetor
  carregaVetor(vet);
  //invoca o procedimento para escrever o vetor
  escreveVetor(vet);
  //invoca o procedimento que faz a soma do vetor
  printf("\n\nA soma dos indices pares do vetor eh: %i\n", somaVetorIndicePar(vet));

  return 0;
}

void carregaVetor(int vet[]){
  //procedimento para carregar o vetor
  for(int i = 0; i < TAM; i++){
    printf("Digite o valor para vet[%i]: ", i);
    scanf("%i", &vet[i]);
  }
}

void escreveVetor(int vet[]){
  int i;
  //procedimento para escrever o vetor
  printf("\n\nValores do vetor:\n");
  for(i = 0; i < TAM; i++){
    printf("[%i] ", vet[i]);
  }
}

int somaVetorIndicePar(int vet[]){
  //procedimento para somar os elementos de indice par
  int soma = 0;
  for(int i = 0; i < TAM; i++){
    if (i % 2 == 0){
      soma = soma + vet[i];
    }
  }
  return soma;
}


