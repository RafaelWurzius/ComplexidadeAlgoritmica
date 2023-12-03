#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sElemento{
	struct sElemento *next;
	struct sElemento *prev;
	char nome[30];
	
}Elemento;

typedef struct sLista{
	Elemento* tail;
	Elemento* head;
	struct sLista *next;
	struct sLista *prev;
	int chave;
	int size;
}Lista;

typedef struct sListaHash{
	Lista* tail;
	Lista* head;
	int size;
}ListaHash;

//PROTOTIPAÇÃO
Lista* criarLista(int);
Elemento* criaElemento(char[30]);
int insereElementosNaLista(Lista*, Elemento*, char[30]);
int removeElementoDaLista(Lista*, Elemento*);
void percorreListaH_T(Lista*);
void percorreListaT_H(Lista*);
int removeElementoPorNome(ListaHash*, char[30]);
int inserirListaNaListaHash(ListaHash*, Lista*, Lista*);
void percorreListaHash(ListaHash*);
int is_i_menorIgual_j(Elemento*, Elemento*);
void trocaValores(Elemento*, Elemento*);
int isForward(Elemento*, Elemento*);
void setPivoMeio(Elemento*, Elemento*, char[30]);
void executarRecursao(Lista*, Elemento*, Elemento*, Elemento*, Elemento*);
void QuickSort(Lista*, Elemento*, Elemento*);
ListaHash* criarListaHash();
int hash(char[30], int );
Lista* encontrarListaPorChave(ListaHash*, int);
void informarQuantidade(ListaHash*);
void predeterminarQtdChaves(ListaHash*, int);
void popularTabelaHash(ListaHash*, char[30]);
void quickSortALL(ListaHash*);
void mostrarListaDaChave(ListaHash*, int);
int chaveDoNome(ListaHash*, char[30]);
void informainsercao();
void informaRemocao();

Lista* criarLista(int chave){
	Lista* lista;
	lista = (Lista*)malloc(sizeof(Lista));
	
	if(lista == NULL){
		return NULL;
	}else{
		lista->head = NULL;
		lista->tail = NULL;
		lista->next = NULL;
		lista->prev = NULL;
		lista->chave = chave;
		lista->size = 0;	
	}
	return lista;
}

//Inserindo a lista na listaHash, apontando o next e o prev das listas e mudando o size da listaHash
int inserirListaNaListaHash(ListaHash* listaHash, Lista* pivo, Lista* lista){
	if ((pivo == NULL) && (listaHash->size != 0)){
		informainsercao();
    	return -1;
    }
    if (listaHash->size == 0){
    	listaHash->head = lista;
    	listaHash->tail = lista;
    }else{
	  	lista->next = pivo->next;
	  	lista->prev = pivo;
	  	if(pivo->next == NULL){
	  	  	listaHash->tail = lista;
	  	}else{
		  	pivo->next->prev = lista;
		}
	  	pivo->next = lista;
	}
    listaHash->size++;
}

Elemento* criaElemento(char nome[30]){
	Elemento* nodo;
	nodo = (Elemento*)malloc(sizeof(Elemento));
	if(nodo == NULL){
		return NULL;
	}else{
		nodo->next = NULL;
		nodo->prev = NULL;
		strcpy(nodo->nome, nome);
	}
	return nodo;
}

int insereElementosNaLista(Lista* lista, Elemento* pivo, char nome[30]){
	Elemento* novo = criaElemento(nome);
	
	if ((pivo == NULL) && (lista->size != 0)){
		informainsercao();
    	return -1;
    }
    if (lista->size == 0){
    	lista->head  = novo;
    	lista->tail = novo;
    }else{
	  	novo->next = pivo->next;
	  	novo->prev = pivo;
	  	if(pivo->next == NULL){
	  	  	lista->tail = novo;
	  	}else{
		  	pivo->next->prev = novo;
		}
	  	pivo->next = novo;
	}
    lista->size++;
}

int removeElementoDaLista(Lista* lista, Elemento* pivo){
	if ((pivo != NULL) && (lista->size != 0)){
		if (pivo == lista->head){
			lista->head = pivo->next;

			if(lista->head == NULL){
				lista->tail = NULL;
			}else{
				pivo->next->prev = NULL;
		 	}
		}else{
			pivo->prev->next = pivo->next;
			if(pivo->next == NULL){
				lista->tail = pivo->prev;
			}else{
				pivo->next->prev = pivo->prev;
			}
		}
		free(pivo);
		lista->size--;
    }else{
    	informaRemocao();
	}
	
}

int removeElementoPorNome(ListaHash* lh, char nome[30]){
	
	int chave = chaveDoNome(lh,nome);
	Lista* lista = lh->head;
	
	while(lista->chave != chave){
		lista = lista->next;
	}
	Elemento* aux;
	aux = lista->head;
	
	while(strcmp(aux->nome, nome)){
		aux = aux->next;
	}
	removeElementoDaLista(lista, aux);
}

//QUICKSORT
//Verifica se o j está na mesma posição ou à frente de i	
int is_i_menorIgual_j(Elemento* i, Elemento* j){
	int i_menorIgual_j = 1;

	if(i == j->next){
		i_menorIgual_j = 0;
		
 	}
	return i_menorIgual_j;
}

//troca os valores
void trocaValores(Elemento* i, Elemento* j){
	char auxTroca[30];
	strcpy(auxTroca, i->nome);

	strcpy(i->nome, j->nome);
	strcpy(j->nome, auxTroca);
	
}

//verifica se o segundo elemento está a frente do primeiro na lista
int isForward(Elemento* x1, Elemento* x2){
	Elemento* aux1;
	
	if(x1 == NULL){
		aux1 = x1;
	}else{
		aux1 = x1->next;
	}
	int menor = 0;
	while(aux1 != NULL){
		if(aux1 == x2){
			menor = 1;
			break;
		}else{
			menor = 0;
		}
		aux1 = aux1->next;
	}
	return menor;
}

//percorre a lista até o pivo apontar pro elemento do meio da lista ou meio+1
void setPivoMeio(Elemento* ini, Elemento* fim, char nomePivo[30]){
	Elemento* pivo = ini;
	Elemento* aux = ini;
	int cont = 0;
	
	while(aux != fim){
		cont++;
		aux = aux->next;
	}

	if(cont % 2 != 0 && cont != 1){
	}else{
		cont++;
	}
	
	int meio = (cont / 2);
	int k;
	for(k = 0; k < meio; k++){
		pivo = pivo->next;
	}
	strcpy(nomePivo, pivo->nome);
}

//Chama novamente o quicksort
void executarRecursao(Lista* l, Elemento* i, Elemento* j, Elemento* ini, Elemento* fim){
	//Percorre a lista a partir de ini para tentar achar o j(se achar true(1), senão false(0))
	if(isForward(ini, j)){
		QuickSort(l, ini, j);
	}
	//Percorre a lista a partir de i para tentar achar o fim(se achar true(1), senão false(0))
	if(isForward(i, fim)){
		QuickSort(l, i, fim);
	}
}

void QuickSort(Lista* l, Elemento* ini, Elemento* fim){
	Elemento *i = ini, *j = fim;
	int menor = 0, i_menorIgual_j = 1, iniMenorJ = 1;
	char nomePivo[30];
	
	setPivoMeio(ini, fim, nomePivo);

	//enquanto i e j não apontarem por mesmo elemento
	while(i_menorIgual_j){
		//enquanto pivo > i	
		while(strcmp(nomePivo, i->nome) == 1){
			i = i->next;
			i_menorIgual_j = is_i_menorIgual_j(i,j);
		}
		//enquanto j > pivo
		while(strcmp(j->nome, nomePivo) == 1){
			j = j->prev;
			i_menorIgual_j = is_i_menorIgual_j(i,j);
		}
		//se i <= j
		if(i_menorIgual_j){
			trocaValores(i, j);

			i = i->next;
			i_menorIgual_j = is_i_menorIgual_j(i,j);
		
			j = j->prev;
			if(i == j->next){
				i_menorIgual_j = 0;
			}
		}
	}
	executarRecursao(l, i, j, ini, fim);
}
		
ListaHash* criarListaHash(){
	ListaHash* listaHash;
	listaHash = (ListaHash*)malloc(sizeof(ListaHash));
	
	if(listaHash == NULL){
		return NULL;
	}else{
		listaHash->head = NULL;
		listaHash->tail = NULL;
		listaHash->size = 0;
	}
	return listaHash;
}

//resto da soma dos numeros ASCII de cada caractere
int hash(char nome[30], int m){
	int chave;
	int soma = 0;
	int i;
	for(i = 0; i < strlen(nome); i++){
		soma += nome[i];		
	}
	chave = soma % m;

	return chave;
	
}

Lista* encontrarListaPorChave(ListaHash* lh, int chave){
	
	Lista* lAux = lh->head;
	
	while(lAux->chave != chave){	
		lAux = lAux->next;
	}
	return lAux;
}


//cria todas as lista(vazias) da tabela Hash
void predeterminarQtdChaves(ListaHash* lh, int chaves){
	int i;
	for(i = 0; i < chaves; i++){
		inserirListaNaListaHash(lh,lh->tail,criarLista(i));
	}
}

//Popular tabela hash com nomes vindo de um arquivo
void popularTabelaHash(ListaHash* lh, char nomeArquivo[30]){
	
	FILE *nomes;
	char nome[30];
	nomes = fopen(nomeArquivo, "r");
	
	Lista* l;
	int chave;
	while (!feof(nomes)){
        fgets(nome, 30, nomes);
		
		chave = hash(nome, lh->size);
		l = encontrarListaPorChave(lh,chave);
		insereElementosNaLista(l,l->tail,nome);
    }
    removeElementoDaLista(l, l->tail);
}
//strtok

//aplica o quicksort em todas as listas
void quickSortALL(ListaHash* lh){
	Lista* aux = lh->head;
	
	while(aux != NULL){
		QuickSort(aux, aux->head, aux->tail);
		aux = aux->next;
	}
}

int chaveDoNome(ListaHash* lh, char nome[30]){	
	return hash(nome,53);
	
}

//INTERFACE
//printa lista de determinada chave
void mostrarListaDaChave(ListaHash* lh, int chave){
	Lista* l = encontrarListaPorChave(lh,chave);

	printf("Chave %i:\n", chave);
	percorreListaH_T(l);
}

//Printa a quantidade de nomes por chave
void informarQuantidade(ListaHash* lh){
	Lista* lAux;
	lAux = lh->head;
	printf("Numero de nomes por chave:\n");
	while(lAux != NULL){
		printf("%i\n",lAux->size);	

		lAux = lAux->next;
	}
}

void percorreListaT_H(Lista* lista){
	Elemento* aux;
	aux = lista->tail;
	
	while(aux != NULL){
		printf("%s\t", aux->nome);	
		aux = aux->prev;
	}
	printf("\n");
}

void percorreListaH_T(Lista* lista){
	Elemento* aux;
	aux = lista->head;
	
	while(aux != NULL){
		printf("%s", aux->nome);		
		aux = aux->next;
	}
	printf("\n");
}

//Percorre todas as listas
void percorreListaHash(ListaHash* lh){
	Elemento* eAux;	
	Lista* lAux;
	lAux = lh->head;
	
	while(lAux != NULL){
		printf("Chave: %i\n",lAux->chave);
		
		eAux = lAux->head;
		while(eAux!= NULL){
			printf("\t%s", eAux->nome);	
			eAux = eAux->next;	
		}


		lAux = lAux->next;
	}
	printf("\n");
}

void informainsercao(){
	printf("Não pode ser inserido em NULL!\n");	
}

void informaRemocao(){
	printf("O elemento a ser excluido não pode ser NULL, e a lista precisa estar populada!\n");
}

int main(){
	ListaHash* lh = criarListaHash();
	
	char nomeArquivo[30];
	
	if(lh == NULL){
		printf("\nNão foi possível alocar memória!\n");
		return -1;
	}
	
	
	predeterminarQtdChaves(lh,53);
	
	popularTabelaHash(lh,"nomes.txt");
	
	quickSortALL(lh);

//	mostrarListaDaChave(lh,30);	
//	printf("Chave: %i\n", chaveDoNome(lh,"MANASSES\n"));
//	removeElementoPorNome(lh,"MANASSES\n");
//	mostrarListaDaChave(lh,30);
	
	
	percorreListaHash(lh);
	informarQuantidade(lh);
	
}
