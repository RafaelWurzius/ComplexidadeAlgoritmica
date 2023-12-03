#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 10

typedef struct{
	
	int inicioX, inicioY, finalX, finalY;

}Roi;

Roi localizaPalavra(char* matriz, char* palavra){
	Roi roi;
	
	roi.inicioX = 0;
	roi.inicioY = 0;
	roi.finalX = 0;
	roi.finalY = 0;
	
	int i, j, cont=0;
	int xi, yi, xf, yf;
	
	//para cada letra que for igual à primeira letra da palavra
    for(i = 0; i < (N*N); i++){
    	if(palavra[0] == matriz[i]){
    		//printf("A ta na posicao %i \n", i);
    		
			//para cada letra da palavra-----------------------------Direita
		    for(j = 1; j < strlen(palavra); j++){
//    			    printf("Passou aqui palavra j: %c e matriz i: %c\n", palavra[j], matriz[i]+J);
				if(palavra[j] == matriz[i+j]){

					//printf("Posicao 61: %i \n", i);
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i+j) % N;
						roi.finalY = trunc((i+j)/N);
						
//						printf("Xi: %i\n", roi.inicioX);
//						printf("Yi: %i\n", roi.inicioY);
//						printf("Xf: %i\n", roi.finalX);
//						printf("Yf: %i\n", roi.finalY);
						break;
					}

				}else {
					//printf("Saiu\n", i);
					cont = 1;
					break;
				}
			}	
		
			//para cada letra da palavra-----------------------------Esquerda
		    for(j = 1; j < strlen(palavra); j++){
				if(palavra[j] == matriz[i-j]){
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i-j) % N;
						roi.finalY = trunc((i-j)/N);
						
						break;
					}

				}else {
					cont = 1;
					break;
				}
			}
		
			//para cada letra da palavra-----------------------------Cima
			for(j = 1; j < strlen(palavra); j++){
				if(palavra[j] == matriz[i-(j*N)]){
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i-(j*N)) % N;
						roi.finalY = trunc((i-(j*N))/N);
						
						break;
					} 

				}else {
					cont = 1;
					break;
				}
			}
			
			//para cada letra da palavra-----------------------------Baixo
			for(j = 1; j < strlen(palavra); j++){
				if(palavra[j] == matriz[i+(j*N)]){
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i+(j*N)) % N;
						roi.finalY = trunc((i+(j*N))/N);

						break;
					}

				}else {
					cont = 1;
					break;
				}
			}
		
			//para cada letra da palavra-----------------------------Direita-baixo
			for(j = 1; j < strlen(palavra); j++){
				if(palavra[j] == matriz[i+(j*(N+1))]){
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i+(j*(N+1))) % N;
						roi.finalY = trunc((i+(j*(N+1)))/N);
						
						break;
					}

				}else {
					cont = 1;
					break;
				}
			}
		
			//para cada letra da palavra-----------------------------Direita-cima
			for(j = 1; j < strlen(palavra); j++){
				if(palavra[j] == matriz[i-(j*(N-1))]){
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i-(j*(N-1))) % N;
						roi.finalY = trunc((i-(j*(N-1)))/N);
			
						break;
					}

				}else {
					cont = 1;
					break;
				}
			}
			
			//para cada letra da palavra-----------------------------Esquerda-cima
			for(j = 1; j < strlen(palavra); j++){
				if(palavra[j] == matriz[i-(j*(N+1))]){
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i-(j*(N+1))) % N;
						roi.finalY = trunc((i-(j*(N+1)))/N);
						
						break;
					}

				}else {
					cont = 1;
					break;
				}
			}
		
			//para cada letra da palavra-----------------------------Direita-baixo
			for(j = 1; j < strlen(palavra); j++){
				if(palavra[j] == matriz[i+(j*(N-1))]){
					cont++;
					
					if(cont == strlen(palavra)){
						printf("Achou a palavra!\n");
						roi.inicioX = i % N;
						roi.inicioY = trunc(i/N);
						roi.finalX = (i+(j*(N-1))) % N;
						roi.finalY = trunc((i+(j*(N-1)))/N);
						break;
					}

				}else {
					cont = 1;
					break;
				}
			}
		}   	
	}
	return roi;
	
}

void imprimirMatriz(char* matriz){
	int i;
	for (i = 0; i < (N*N); i++) {
    	if(i % N == 0){
    		printf("\n");
		}
            printf("%c ", matriz[i]);
    }
}
int main() {
	int i, j;
    char* matriz = (char*)malloc((N*N) * sizeof(char*));
    char* palavra = "SAPO";

	matriz = "SAPAACAVAAAAPADAVUUJTAPAAPASONASJAVMVARAJPOATRRASRAOJALORAAAOPAOMOUPSLPAPPMVAUAAOATALSVAPAAOTTRAASOP";
    
    
	Roi roi = localizaPalavra(matriz, palavra);
	

	//imprimindo posições inicail e final
	printf("Xi: %i\n", roi.inicioX);
	printf("Yi: %i\n", roi.inicioY);
	printf("Xf: %i\n", roi.finalX);
	printf("Yf: %i\n", roi.finalY);
    
    // Imprimindo a matriz
	imprimirMatriz(matriz);
    
	// Liberando a memória alocada
    for (i = 0; i < (N*N); i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
    
    //TODO LIST:
    //Modularização
    //Dar lógica pro sruct
    //Menu no console
    //

}

