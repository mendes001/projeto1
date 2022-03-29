/**
* Author: Tiago
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc:funcoes
* ???
*/
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include"Operacoes.h"

#pragma region funcoes/maquinas

ListaMaq* criaMaq(int cod, int tempo) {
	ListaMaq* maq = (ListaMaq*)calloc(1,sizeof( ListaMaq));
	maq->cod = cod;
	maq->tempo = tempo;
	maq->next = NULL;

	return maq;
}

bool existeMaq(ListaMaq* m, int cod) {

	if (m == NULL) return false;
	ListaMaq* aux = m;
	while (aux) {
		if (aux->cod == cod) return true;
		aux = aux->next;
	}
	return false;
}

ListaMaq* InsereMaqLista(ListaMaq* m, ListaMaq* newM) {
	if (newM == NULL) return m;	//Verificar se apontadores são válidos

	//Verificar se o novo jogo já existe!!!
	if (existeMaq(m, newM->cod)) return m;	//se existir não insere!

	if (m == NULL)		//Lista está vazia
	{
		m = newM;
	}
	else
	{
		newM->next = m;	//aponta para onde "h" está a apontar
		m = newM;
	}
	return m;
}

void mostrarMaquinas(ListaMaq* m) {
	ListaMaq* aux = m;
	if (aux == NULL) " ";
	else {
		while (aux) {
			printf("(%d,%d)", aux->cod, aux->tempo);
			aux = aux->next;
		}
	}
}
#pragma endregion

#pragma region funcoes/operacoes

ListaOp* criarOp(int id) {
	ListaOp* aux = (ListaOp*)calloc(1,sizeof(ListaOp));
	if (aux != NULL) {
		aux->id = id;
		aux->listaM = NULL;
		aux->next = NULL;
		return aux;
	}
}

bool existeOp(ListaOp* h, int id) {
	if (h == NULL) return false;
	ListaOp* aux = h;
	while (aux) {
		if (aux->id == id) return true;
		aux = aux->next;
	}
	return false;
}

ListaOp* InsereOpInicio(ListaOp* h, ListaOp* novo) {

	if (novo == NULL) return h;	//Verificar se apontadores são válidos

	//Verificar se o novo jogo já existe!!!
	if (existeOp(h, novo->id)) return h;	//se existir não insere!

	if (h == NULL)		//Lista está vazia
	{
		h = novo;
	}
	else
	{
		novo->next = h;	//aponta para onde "h" está a apontar
		h = novo;
	}
	return h;
}

ListaOp* removerOp(ListaOp* h, int id) {

	if (h == NULL) return NULL;

	if (h->id == id) {
		ListaOp* aux = h;
		h = h->next;
		free(aux);
	}
	else
	{
		ListaOp* aux = h;
		ListaOp* auxAnt = aux;
		while (aux->id != id) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux) {
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return h;
}

ListaOp* adicionarMaqOp(ListaOp* h, int id, ListaMaq* m) {
	if (h == NULL) return NULL;
	if (m == NULL) return h;
	ListaOp* aux = ProcurarOp(h,id);

	if (aux != NULL) {
		aux->listaM = InsereMaqLista(aux->listaM, m);
		
	}
	return h;
	
}

ListaOp* ProcurarOp(ListaOp* h, int id) {
	ListaOp* auxop = h;
		while (auxop) {
			if (auxop->id == id) return auxop;
			else {
				auxop = auxop->next;
			}
		}
		return NULL;
	}

int miniTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	ListaOp* aux = h;
	int minimo = 0;


	while (aux) {
		int tempo = aux->listaM->tempo;

		ListaMaq* auxm = aux->listaM;
		while (auxm) {

			if (auxm->tempo < tempo)tempo = auxm->tempo;
			auxm = auxm->next;


		}
		minimo += tempo;
		aux = aux->next;

	}
	return minimo;
}

void miniTempoeMaq(ListaOp* h) {
	mostrarMaqOp(h);
	int x = miniTempo(h);
	printf("\nO tempo minimo para completer o job e: %d\n", x);
} 

int maxTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	ListaOp* aux = h;
	int maximo = 0;


	while (aux) {
		int tempo = aux->listaM->tempo;
		
		ListaMaq* auxm = aux->listaM;
		while (auxm) {
			
			 if (auxm->tempo > tempo)tempo = auxm->tempo; 
			 auxm = auxm->next;
				
			
		}
		maximo += tempo;
		aux = aux->next;

	}
	return maximo;
}

void maxTempoeMaq(ListaOp* h) {
	mostrarMaqOp(h);
	int x = maxTempo(h);
	printf("\nO tempo maximo para completar o job e: %d\n", x);
	
}

int mediaTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	ListaOp* aux = h;
	int media = 0;
	


	while (aux) {
		int count = 0;
		int tempo = 0;
		ListaMaq* auxm = aux->listaM;
		while (auxm) {

			tempo += auxm->tempo;
			count++;

			auxm = auxm->next;

		}
		
		media += tempo/count;
		aux = aux->next;

	}
	return media;
}

void mediaTempoeMaq(ListaOp* h) {
	mostrarMaqOp(h);
	int x = mediaTempo(h);
	printf("\nO tempo medio para completer o job e: %d\n", x);


}

void mostrarMaqOp(ListaOp* h) {
	ListaOp* aux = h;
	if (aux == NULL) printf("Lista vazia.");
	while (aux != NULL) {
		printf("\nOperacao %d:(maquina,tempo)\n ", aux->id);
		mostrarMaquinas(aux->listaM);
		aux = aux->next;
	}
}

bool gravarOp(char* nomeFicheiro, ListaOp* h) {
	FILE* fp;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava n registos no ficheiro
	ListaOp* aux = h;
	ListaOpFile auxOp;	//para gravar em ficheiro!
	while (aux) {		//while(aux!=NULL)
		//Colocar no registo de ficheiro a inf que está no registo de memória
		auxOp.id = aux->id;
		auxOp.listaMaq = aux->listaM;
		fwrite(&auxOp, sizeof(ListaOpFile), 1, fp);
		aux = aux->next;
	}
	fclose(fp);
	return true;
}
ListaOp* lerOperacoes(char* nomeFicheiro) {
	FILE* fp;
	ListaOp* h = NULL;
	ListaOp* aux;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;

	ListaOpFile auxOp;
	while (fread(&auxOp, sizeof(ListaOpFile), 1, fp)) {
		aux = criarOp(auxOp.id);
		h = InsereOpInicio(h, aux);
	}
	fclose(fp);
	return h;
}

#pragma endregion