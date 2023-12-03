Questão 13
#include <stdio.h>
#define LIN 5
#define COL 5

//Prototipação
void carregaMatriz(int[][COL]);
void escreveMatriz(int[][COL], float);
float calculaValoresPares(int[][COL]);

//Implementação
int main(void) {
  int mat[LIN][COL];
  float media;
  carregaMatriz(mat);
  media = calculaValoresPares(mat);
  escreveMatriz(mat, media);
}

void carregaMatriz(int ma[][COL]){
  int i,j;
  for (i = 0; i < LIN; i++){
    for (j = 0; j < COL; j++){
      printf("Digite o valor para a matriz[%i][%i]: ", i, j);
      scanf("%i", &ma[i][j]);
    }
  }
}

void escreveMatriz(int ma[][COL], float media){
  int i,j;
  printf("\n\nOs valores da matriz sao:\n");
  for (i = 0; i < LIN; i++){
    for (j = 0; j < COL; j++){
      printf("\t%i", ma[i][j]);
    }
    printf("\n");
  }

  printf("\nA media dos valores pares da matriz eh: %.3f\n", media);
}

float calculaValoresPares(int ma[][COL]){
  int i,j, contPar;
  float media;
  media = 0;
  contPar = 0;
  for (i = 0; i < LIN; i++){
    for (j = 0; j < COL; j++){
      if (ma[i][j] % 2 == 0) {
        media = media + ma[i][j];
        contPar++;
      }
    }
  }

  return (media / contPar);
