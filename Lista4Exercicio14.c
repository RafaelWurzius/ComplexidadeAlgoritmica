#include<stdio.h>
#include <string.h>

#define LIN 10
#define COL 10

void receberRespostas(char[LIN][COL]);
void receberGabarito(char[LIN], int[LIN]);
void definirResultado(char[LIN][COL], char[LIN], int[LIN]);
void imprimirResultado(int[LIN]);

void receberRespostas(char resp[LIN][COL]){
	int i, j;
	for(i = 0; i < LIN; i++){
		for(j = 0; j < COL; j++){
			printf("Digite a resposta da questão %i do aluno %i: \n", j+1, i+1);
			do{
				scanf("%c", &resp[i][j]);
			} while(resp[i][j] == '\n');
			
		}
	}
	
	printf("\n");

}

void receberGabarito(char gabarito[LIN], int resultado[LIN]){
	int i, j;
	
	for(i = 0; i < LIN; i++){
		printf("Digite o gabarito da questão %i: \n", i+1);
		
		do{
			scanf("%c", &gabarito[i]);
		} while(gabarito[i] == '\n');
		

		resultado[i] = 0;
	}	
}

void definirResultados(char resp[LIN][COL], char gabarito[LIN], int resultado[LIN]){
	int i, j;
	for(i = 0; i < LIN; i++){
		for(j = 0; j < COL; j++){
			if(resp[i][j] == gabarito[j]){
				resultado[i]++;
			}
		}
	}
}

void impimirResultado(int resultado[LIN]){
	int i;
	for(i = 0; i < LIN; i++){
		printf("A nota do aluno %i foi %i \n", i+1, resultado[i]);
	}
}

int main(){
	int resultado[LIN];
	char gabarito[LIN], resp[LIN][COL];
	
	receberRespostas(resp);
	receberGabarito(gabarito, resultado);
	definirResultados(resp, gabarito, resultado);
	impimirResultado(resultado);
}


