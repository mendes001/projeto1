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

/**
*/
bool existeMaq(ListaMaq* m, int cod) {

	if (m == NULL) return false;
	ListaMaq* aux = m;
	while (aux) {
		if (aux->cod == cod) return true;
		aux = aux->next;
	}
	return false;
}

ListaMaq* insereMaqLista(ListaMaq* m, ListaMaq* newM) {
	if (newM == NULL) return m;	
	
	if (existeMaq(m, newM->cod)) return m;	

	if (m == NULL)		
	{
		m = newM;
	}
	else
	{
		newM->next = m;	
		m = newM;
	}
	return m;
}

int miniTempoListaMaq(ListaMaq* m) {
	if (m == NULL) return 0;

	ListaMaq* aux = m;
	int tempo = aux->tempo;

	while (aux) {
		if (aux->tempo < tempo) tempo = aux->tempo;
		aux = aux->next;
	}
	return tempo;
}

int maxTempoListaMaq(ListaMaq* m) {
	if (m == NULL) return 0;

	ListaMaq* aux = m;
	int tempo = aux->tempo;

	while (aux) {
		if (aux->tempo > tempo) tempo = aux->tempo;
		aux = aux->next;
	}
	return tempo;
}

float mediaTempoListaMaq(ListaMaq* m) {
	if (m == NULL) return 0;

	ListaMaq* aux = m;
	float media = 0;
	float tempo = 0;
	int count = 0;

	while (aux) {
		tempo += aux->tempo;
		aux = aux->next;
		count++;
	}
	media = tempo / count;
	return media;
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

//a função criarOp recebe um inteiro e cria um espaço de memória para uma operação.
ListaOp* criarOp(int id, int num) {
	ListaOp* aux = (ListaOp*)calloc(1,sizeof(ListaOp));
	if (aux != NULL) {
		aux->id = id;
		aux->num = num;
		aux->listaM = NULL;
		aux->next = NULL;
		return aux;
	}
	return NULL;
}

//a função existeOp recebe um inteiro e uma lista de operações e verifica se uma certa operação existe.
bool existeOp(ListaOp* h, int id) {
	if (h == NULL) return false;
	ListaOp* aux = h;
	while (aux) {
		if (aux->id == id) return true;
		aux = aux->next;
	}
	return false;
}

ListaOp* insereOpInicio(ListaOp* h, ListaOp* novo) {

	if (novo == NULL) return h;	
	
	if (existeOp(h, novo->id)) return h;	

	if (h == NULL)		
	{
		h = novo;
	}
	else
	{
		novo->next = h;	
		h = novo;
	}
	return h;
}

//a função removerMaqOp recebe a lista de operações e remove uma máquina específica de uma operação específica.
ListaOp* removerMaqOp(ListaOp* h, int id, int cod) {
	if (h == NULL) return NULL;
	ListaOp* aux = procurarOp(h, id);
	if (aux == NULL) return NULL;
	else {
		if (aux->listaM->cod == cod) {
			ListaMaq* auxm = aux->listaM;
			aux = aux->next;
			free(auxm);
		}
		else
		{
			ListaMaq* auxm = aux->listaM;
			ListaMaq* auxmAnt = auxm;
			while (auxm->cod != cod) {
				auxmAnt = auxm;
				auxm = auxm->next;
			}
			if (aux) {
				auxmAnt->next = auxm->next;
				free(auxm);
			}
		}
		
	}
	return h;

}

ListaOp* removerOp(ListaOp* h, int id) {

	if (h == NULL) return NULL;

	if (h->id == id) {
		ListaOp* aux = h;
		h = h->next;
		//remover as maquinas
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

ListaOp* procurarOp(ListaOp* h, int id) {
	ListaOp* auxop = h;
		while (auxop) {
			if (auxop->id == id) return auxop;
			else {
				auxop = auxop->next;
			}
		}
		return NULL;
	}

int miniTempoOp(ListaOp* h) {
	if (h == NULL) return 0;
	ListaOp* aux = h;
	int minimo = 0;


	while (aux) {
		//int tempo = aux->listaM->tempo;

		//ListaMaq* auxm = aux->listaM;
		//while (auxm) {


		//	/*if (auxm->tempo < tempo)tempo = auxm->tempo;
		//	auxm = auxm->next;*/

		//}
		int tempo = miniTempoListaMaq(aux->listaM);

		minimo += tempo;
		aux = aux->next;

	}
	return minimo;
}

void miniTempoeMaq(ListaOp* h) {
	mostrarMaqOp(h);
	int x = miniTempoOp(h);
	if (x == 0) printf("Lista vazia!!!");
	printf("\nO tempo minimo para completar o job e: %d\n", x);
} 

int maxTempoOp(ListaOp* h) {
	if (h == NULL) return 0;
	ListaOp* aux = h;
	int maximo = 0;


	while (aux) {
		/*int tempo = aux->listaM->tempo;
		
		ListaMaq* auxm = aux->listaM;
		while (auxm) {
			
			 if (auxm->tempo > tempo)tempo = auxm->tempo; 
			 auxm = auxm->next;
				
			
		}*/
		int tempo = maxTempoListaMaq(aux->listaM);
		maximo += tempo;
		aux = aux->next;

	}
	return maximo;
}

void maxTempoeMaq(ListaOp* h) {
	mostrarMaqOp(h);
	int x = maxTempoOp(h);
	if (x == 0) printf("Lista vazia!!!");
	printf("\nO tempo maximo para completar o job e: %d\n", x);
	
}

float mediaTempoOp(ListaOp* h) {
	if (h == NULL) return 0;
	ListaOp* aux = h;
	float media = 0;
	


	while (aux) {
		/*int count = 0;
		int tempo = 0;
		ListaMaq* auxm = aux->listaM;
		while (auxm) {

			tempo += auxm->tempo;
			count++;

			auxm = auxm->next;

		}*/
		float tempo = mediaTempoListaMaq(aux->listaM);
		
		media += tempo;
		aux = aux->next;

	}
	return media;
}

void mediaTempoeMaq(ListaOp* h) {
	mostrarMaqOp(h);
	float x = mediaTempoOp(h);
	if (x == 0) printf("Lista vazia!!!");
	printf("\nO tempo medio para completar o job e: %f\n", x);


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

bool gravarOp(char* nomeFicheiro, char* nomeFicheiro2, ListaOp* h) {
	FILE* fp;
	FILE* fm;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	if ((fm = fopen(nomeFicheiro2, "wb")) == NULL) return false;
	
	ListaOp* aux = h;
	ListaOpFile auxOp;	
	ListaMaqFile auxMaq;
	while (aux){	//while(aux!=NULL)
		fwrite(&auxOp, sizeof(ListaOpFile), 1, fp);
		auxOp.id = aux->id;
		auxOp.num = aux->num;
		ListaMaq* auxm = aux->listaM;
		while (auxm) {
			fwrite(&auxMaq, sizeof(ListaMaqFile), 1, fm);
			auxMaq.cod = auxm->cod;
			auxMaq.tempo = auxm->tempo;
			auxMaq.id = aux->id;	
			auxm = auxm->next;
		}
		fclose(fm);
		aux = aux->next;

	}
	fclose(fp);
	
	return true;
}

ListaOp* lerOperacoes(char* nomeFicheiro, char* nomeFicheiro2) {
	FILE* fp;
	FILE* fm;
	ListaOp* h = NULL;
	ListaOp* aux;
	

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	if ((fm = fopen(nomeFicheiro2, "rb")) == NULL) return NULL;

	ListaOpFile auxOp;
	while (fread(&auxOp, sizeof(ListaOpFile), 1, fp)) {
		aux = criarOp(auxOp.id,auxOp.num);
		ListaMaqFile auxMaq;
		while (fread(&auxMaq, sizeof(ListaOpFile), 1, fm)) {
			if (auxMaq.id == aux->id) {
				ListaMaq* auxm = criaMaq(auxMaq.cod,auxMaq.tempo);
				aux->listaM = InsereMaqLista(aux->listaM, auxm);
			}
		}

		/*while (fread(&auxMaq, sizeof(ListaMaqFile), 1, fp)) {
			auxm = criaMaq(auxMaq.cod,auxMaq.tempo);
			aux->listaM = InsereMaqLista(aux, auxm);
		}*/
		
		h = InsereOpInicio(h, aux);
		
	}
	fclose(fm);
	fclose(fp);
	return h;
}

#pragma endregion