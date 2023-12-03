#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int **matriz;
	int altura;
	int largura;
}ObjetoMatriz;

// Prototipa��o
void definirTamanhoMatrizes(ObjetoMatriz*, ObjetoMatriz*, ObjetoMatriz*);
int** alocarMemoriaPrimaria(ObjetoMatriz*);
int** alocarMemoriaNucleo(ObjetoMatriz*);
int** alocarMemoriaResultado(ObjetoMatriz*);

void preencherMatrizesAleatorio(ObjetoMatriz*, ObjetoMatriz*);
void preencherMatrizesPorArquivo(ObjetoMatriz*, ObjetoMatriz*);
void processarMatrizes(ObjetoMatriz*, ObjetoMatriz*, ObjetoMatriz*);
void mostrarMatrizes(ObjetoMatriz*, ObjetoMatriz*, ObjetoMatriz*);

void desalocarMemoria(ObjetoMatriz*, ObjetoMatriz*, ObjetoMatriz*);
int escolherOpcao(int);
void gravarTXT(ObjetoMatriz*, int);

int main(){
	ObjetoMatriz matrizPrimaria, matrizNucleo, MatrizResultado;
	ObjetoMatriz *primaria = &matrizPrimaria, *nucleo = &matrizNucleo, *resultado = &MatrizResultado;
	int opcao;
	
	// Define se as matrizes ser�o populadas por n�meros aleat�rios ou por n�meros tirados de aquivos .txt
	opcao = escolherOpcao(opcao);
	
	// Define a altura e a largura das matrizes
	definirTamanhoMatrizes(primaria, nucleo, resultado);
	
	// Aloca��o dinamica de mem�ria	
	primaria->matriz = alocarMemoriaPrimaria(primaria);
	nucleo->matriz = alocarMemoriaNucleo(nucleo);
	resultado->matriz = alocarMemoriaResultado(resultado);
		
	if(opcao == 1){
		// Popular as matriz com n�meros aleat�rios
		preencherMatrizesAleatorio(primaria, nucleo);
	
	}else if(opcao == 2){
		// Popular as matriz com n�meros retirados de documento .txt
		preencherMatrizesPorArquivo(primaria, nucleo);
	}
	
	// Realizar os c�lculos
	processarMatrizes(primaria, nucleo, resultado);
	
	// Mostrar as matrizes
	mostrarMatrizes(primaria, nucleo, resultado);
	
	// Grava a matriz Resultado em um documento .txt
	gravarTXT(resultado, opcao);
	
	//Desalocar mem�ria que as matrizes ocupavam
	desalocarMemoria(primaria, nucleo, resultado);

	return 0;
}

void definirTamanhoMatrizes(ObjetoMatriz *primaria, ObjetoMatriz *nucleo, ObjetoMatriz *resultado){
	printf("Digite a largura da matriz primaria: ");
	scanf("%i", &primaria->largura);
	
	printf("Digite a altura da matriz primaria: ");
	scanf("%i", &primaria->altura);
	
	printf("Digite a largura da matriz n�cleo: ");
	scanf("%i", &nucleo->largura);
	
	printf("Digite a altura da matriz n�cleo: ");
	scanf("%i", &nucleo->altura);
	printf("\n");
	
	resultado->largura = (primaria->largura - nucleo->largura) + 1;
	resultado->altura = (primaria->altura - nucleo->altura) + 1;	
}

int** alocarMemoriaPrimaria(ObjetoMatriz *primaria){
	int i;
	primaria->matriz = (int**)malloc(sizeof(int*)* primaria->altura);
	
	for(i = 0; i < primaria->altura; i++){
		primaria->matriz[i] = (int*)malloc(sizeof(int)*primaria->largura);
	}
	return primaria->matriz;
}

int** alocarMemoriaNucleo(ObjetoMatriz *nucleo){
	int i;
	
	nucleo->matriz = (int**)malloc(sizeof(int*)* nucleo->altura);
	for(i = 0; i < nucleo->altura; i++){
		nucleo->matriz[i] = (int*)malloc(sizeof(int)*nucleo->largura);
	}
	return nucleo->matriz;	
}

int** alocarMemoriaResultado(ObjetoMatriz *resultado){
	int i;
	
	resultado->matriz = (int**)malloc(sizeof(int*)* resultado->altura);
	for(i = 0; i < resultado->altura; i++){
		resultado->matriz[i] = (int*)malloc(sizeof(int)*resultado->largura);
	}
	return resultado->matriz;	
}	

void preencherMatrizesAleatorio(ObjetoMatriz *primaria, ObjetoMatriz *nucleo){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < primaria->altura; i++){
		for(j = 0; j < primaria->largura; j++){
			primaria->matriz[i][j] = rand() % 100;
		}	
	}
	
	for(i = 0; i < nucleo->altura; i++){
		for(j = 0; j < nucleo->largura; j++){
			nucleo->matriz[i][j] = rand() % 100;
		}	
	}
}

void preencherMatrizesPorArquivo(ObjetoMatriz *primaria, ObjetoMatriz *nucleo){
	FILE *file1;
	file1 = fopen("MatrizPrimaria.txt", "r");
	int i, j;

	for(i = 0; i < primaria->altura; i++){
        for(j = 0; j < primaria->largura; j++){
            fscanf(file1,"%d ", &primaria->matriz[i][j]);
    	}
    }
	fclose(file1);
	
	FILE *file2;
	file2 = fopen("MatrizNucleo.txt", "r");

	for(i = 0; i < nucleo->altura; i++){
        for(j = 0; j < nucleo->largura; j++){
            fscanf(file2,"%d ", &nucleo->matriz[i][j]);
    	}
    }	
	fclose(file2);
}

void processarMatrizes(ObjetoMatriz *primaria, ObjetoMatriz *nucleo, ObjetoMatriz *resultado){
	int i, j, k , l, movimentoX = -1, movimentoY = 0, result = 0;
	
	for(i = 0; i < resultado->altura; i++){
		for(j = 0; j < resultado->largura; j++){

			movimentoX++;
			
			for(k = 0; k < nucleo->altura; k++){
				for(l = 0; l < nucleo->largura; l++){
					result += (nucleo->matriz[k][l] * primaria->matriz[k+movimentoY][l+movimentoX]);
				}
			}
			resultado->matriz[i][j] = result;
			result = 0;
		}
		movimentoX = -1;
		movimentoY++;
	}
}

void mostrarMatrizes(ObjetoMatriz *primaria, ObjetoMatriz *nucleo, ObjetoMatriz *resultado){
	int i, j;
	//Mostrar matriz Primaria
	printf("MATRIZ PRIM�RIA:\n");
	for(i = 0; i < primaria->altura; i++){
		for(j = 0; j < primaria->largura; j++){
			printf("%i \t", primaria->matriz[i][j]);
		}
		printf("\n");	
	}
	printf("\n");
	
	//Mostrar matriz Nucleo
	printf("MATRIZ N�CLEO:\n");
	for(i = 0; i < nucleo->altura; i++){
		for(j = 0; j < nucleo->largura; j++){
			printf("%i \t", nucleo->matriz[i][j]);
		}
		printf("\n");	
	}
	printf("\n");
	
	//Mostrar matriz resultado
	printf("MATRIZ RESULTANTE:\n");
	for(i = 0; i < resultado->altura; i++){
		for(j = 0; j < resultado->largura; j++){
			printf("%i \t", resultado->matriz[i][j]);	
		}
		printf("\n");	
	}
}

void desalocarMemoria(ObjetoMatriz *primaria, ObjetoMatriz *nucleo, ObjetoMatriz *resultado){
	int i, j;
	for(i = 0; i < primaria->altura; i++){
		for(j = 0; j < primaria->largura; j++){
			free(primaria->matriz[i][j]);
		}
	}
	
	for(i = 0; i < nucleo->altura; i++){
		for(j = 0; j < nucleo->largura; j++){
			free(nucleo->matriz[i][j]);
		}
	}
	
	for(i = 0; i < resultado->altura ; i++){
		for(j = 0; j < resultado->largura; j++){
			free(resultado->matriz[i][j]);
		}
	}
	free(primaria->matriz);
	free(nucleo->matriz);
	free(resultado->matriz);
}

int escolherOpcao(int opcao){
	printf("PROCESSAMENTO DE ARRAY \nUma matriz n�cleo ser� sobreposta em uma matriz Primaria somando-se o produto entre os respectivos \nvalores sobrepostos, gerando um valor que ser� reproduzido para uma terceira matriz-> Esse processo \nser� repetido at� que a matriz n�cleo percorra toda a Primaria.\n\n");
	printf("Digite:\n1 para que as matrizes sejam preenchidas aleatoriamente.\n2 para que sejam preenchidas com base em um arquivo .txt:\n");
	scanf("%i", &opcao);
	return opcao;
}

void gravarTXT(ObjetoMatriz *resultado, int opcao){
	if(opcao == 2){
		int i, j;
		FILE *file3;
		file3 = fopen("MatrizResultado.txt", "w");
		
		for(i = 0; i < resultado->altura; i++){
			for(j = 0; j < resultado->largura; j++){
				fprintf(file3, "%i \t", resultado->matriz[i][j]);
			}
			fprintf(file3, "\n");
		}
		fclose(file3);
		printf("\nO documento 'MatrizResultado.txt' foi salvo no diret�rio e contem os valores da matriz resultante.");
	}
}
