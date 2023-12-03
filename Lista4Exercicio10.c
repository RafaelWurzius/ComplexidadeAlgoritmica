#include<stdio.h>

#define TAM 5

void receberValores(int[TAM][TAM]);
void imprimirValores(int[TAM][TAM], int, int, int, int, int);
int somaDigonalPrincipal(int[TAM][TAM]);
int somaDigonalSecundaria(int[TAM][TAM]);
int somaLinha4(int[TAM][TAM]);
int somaColuna2(int[TAM][TAM]);
int somaTotal(int[TAM][TAM]);

void receberValores(int num[TAM][TAM]){
	int i, j;
	printf("\nDigite 25 valores: ");
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			scanf("%i", &num[i][j]);
		}
	}
}

void imprimirValores(int num[TAM][TAM], int diagonalP, int diagonalS, int somaL, int somaC, int somaTotal){
	int i, j;
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			printf("%i \t", num[i][j]);
		}
		printf("\n");
	}
	printf("\nA soma da linha 4 é %i \n", somaL);
	printf("A soma da coluna 2 é %i \n", somaC);
	printf("A soma da diagonal principal é %i \n", diagonalP);
	printf("A soma da diagonal secundária é %i \n", diagonalS);
	printf("A soma de todos os elementos da matriz é %i \n", somaTotal);
}

int somaDigonalPrincipal(int num[TAM][TAM]){
	int diagonalP = 0, i, j;
	
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			if(j == i){
				diagonalP += num[i][j];
			}
		}	
	}
	
	return diagonalP;
}

int somaDigonalSecundaria(int num[TAM][TAM]){
	int i, c, diagonalS = 0;
	
	c = TAM - 1;
	for(i = 0; i < TAM; i++){
		diagonalS += num[i][c];
		c--;	
	}
	
	return diagonalS;
}

int somaLinha4(int num[TAM][TAM]){
	int i, linha4 = 0;
	for(i = 0; i < TAM; i++){
		linha4 += num[3][i];
	}
	return linha4;
}

int somaColuna2(int num[TAM][TAM]){
	int i, coluna2 = 0;
	for(i = 0; i < TAM; i++){
		coluna2 += num[i][1];
	}
	return coluna2;
}

int somaTotal(int num[TAM][TAM]){
	int i, j, somaTotal = 0;
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			somaTotal += num[i][j];
		}
	}
	return somaTotal;
}

int main(){
	int num[TAM][TAM], somaL, somaC, diagonalP, diagonalS, somaT;
	receberValores(num);
	
	somaL = somaLinha4(num);
	somaC = somaColuna2(num);
	diagonalP = somaDigonalPrincipal(num);
	diagonalS = somaDigonalSecundaria(num);
	somaT = somaTotal(num);
	imprimirValores(num, diagonalP, diagonalS, somaL, somaC, somaT);
}
