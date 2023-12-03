#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

typedef struct{
	int minimo;
	int maximo;
	int abertura;
	int fechamento;
}Candle;

int* alocarMemoriaCandle(Candle*);
int* alocarMemoriaMedia(float*);
int* alocarMemoriaDiasMedia(int*);
void carregarCandles(Candle*);
void calcularMedias(Candle*, float*);
int encontrarMenorAbertura(Candle*);
int encontrarMaiorFechamento(Candle*);
int encontrarMediaMaiorQueAberturaAnterior(Candle*, float*, int*);
void mostrarAtivos(Candle*, float*, int, int, int*, int);

int main(){
	Candle *candles;
	int maior, menor, *diasMedia, cont;
	float *media;
	
	candles = alocarMemoriaCandle(candles);
	media = alocarMemoriaMedia(media);
	diasMedia = alocarMemoriaMedia(diasMedia);
		
	carregarCandles(candles);
    
    calcularMedias(candles, media);
    
    menor = encontrarMenorAbertura(candles);
    maior = encontrarMaiorFechamento(candles);
    
    cont = encontrarMediaMaiorQueAberturaAnterior(candles, media, diasMedia);
    
    mostrarAtivos(candles, media, menor, maior, diasMedia, cont);
    
    
}

int* alocarMemoriaCandle(Candle *candles){
	return (Candle*)malloc(sizeof(Candle) * N);
}

int* alocarMemoriaMedia(float *media){
	return (float*)malloc(sizeof(float) * N);
}

int* alocarMemoriaDiasMedia(int *diasMedia){
	return (int*)malloc(sizeof(int) * N);
}

void carregarCandles(Candle *candles){
	int i;
	srand(time(NULL));
	for(i = 0; i < N; i++){
        candles[i].maximo = rand() % 100;
        candles[i].fechamento = rand() % 100;
        candles[i].minimo = rand() % 100;
        candles[i].abertura = rand() % 100;
    }
}

void calcularMedias(Candle *candles, float *media){
	int i;
	for(i = 0; i < N; i++){
        media[i] = ((float)candles[i].minimo + (float)candles[i].maximo)/2;
    }
}

int encontrarMenorAbertura(Candle *candles){
	int i, menor = INT_MAX, diaMenor;
	for(i = 0; i < N; i++){
    	if(candles[i].abertura < menor){
    		menor = candles[i].abertura;
    		diaMenor = i;
		}
    }
    return diaMenor;
}

int encontrarMaiorFechamento(Candle *candles){
	int i, maior = 0, diaMaior;
	for(i = 0; i < N; i++){
    	if(candles[i].fechamento > maior){
    		maior = candles[i].fechamento;
    		diaMaior = i;
		}
    }
    return diaMaior;
}

int encontrarMediaMaiorQueAberturaAnterior(Candle *candles, float *media, int *diasMedia){
	int i, cont = 0;
	int tamanhoVetor = N;
	tamanhoVetor -= 1;
	
	for(i = 0; i < tamanhoVetor; i++){
    	if(media[i+1] > candles[i].abertura){
    		diasMedia[cont] = i+2;
    		cont++;
		}
    }
    return cont;
}

void mostrarAtivos(Candle *candles, float *media, int menor, int maior, int *diasMedia, int cont){
	int i;
	for(i = 0; i < N; i++){
    	printf("Candle dia %i:\n", i+1);
    	
    	printf("Abertura: %i\n", candles[i].abertura);
    	printf("Fechamento: %i\n", candles[i].fechamento);
    	printf("Maximo: %i\n", candles[i].maximo);
    	printf("Minimo: %i\n\n", candles[i].minimo);
	}
	    
    for(i = 0; i < N; i++){
    	printf("Média do dia %i: %.2f \n", i+1, media[i]);
    }
    
    printf("Dia de menor preço de abertura: %i\n", menor+1);
    printf("Dia de maior preço de fechamento: %i\n", maior+1);
    
    printf("Dias em que a média dos preços mínimos e máximo do ativo ficou maior do que o preço de abertura do dia anterior: \n");
    for(i = 0; i < cont; i++){
    	printf("%i ", diasMedia[i]);	
    }
}

