/**
* Author: Mendes
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
	ListaMaq* newMaq = (ListaMaq*)malloc(sizeof(ListaOp));
	newMaq->Maq.cod = cod;
	newMaq->Maq.tempo = tempo;
	newMaq->next = NULL;

	return newMaq;
}

#pragma endregion

#pragma region funcoes/operacoes

ListaOp* criaOp(ListaMaq* h, int id) {

	ListaOp* newOp = (ListaOp*)malloc(sizeof(ListaOp));
	ListaMaq* newMaq = (ListaMaq*)malloc(sizeof(ListaOp));
	newOp->listaM = h;
	newOp->ope.id = id;
	newOp->next = NULL;
	

	return newOp;
}

bool existeOp(ListaOp* h, int id) {
	if (h == NULL) return false;
	ListaOp* aux = h;
	while (aux != NULL) {
		if (aux->ope.id == id) return true;
		aux = aux->next;
	}
	return false;
}

ListaOp* InsereOpInicio(ListaOp* h, ListaOp* novo) {

	if (novo == NULL) return h;	//Verificar se apontadores são válidos

	//Verificar se o novo jogo já existe!!!
	if (existeOp(h, novo->ope.id)) return h;	//se existir não insere!

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

ListaOp* InserirPorId(ListaOp* h, ListaOp* novo) {

	if (existeOp(h, novo->ope.id)) return h;

	if (h == NULL)
	{
		h = novo;
	}
	else
	{
		ListaOp* aux = h;
		ListaOp* auxAnt = NULL;
		while (aux && aux->ope.id < novo->ope.id) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (auxAnt == NULL) {
			novo->next = h;
			h = novo;
		}
		else
		{
			auxAnt->next = novo;
			novo->next = aux;
		}
	}
	return h;
}
ListaOp* removerOp(ListaOp* h, int id) {

	if (h == NULL) return NULL;

	if (h->ope.id == id) {
		ListaOp* aux = h;
		h = h->next;
		free(aux);
	}
	else
	{
		ListaOp* aux = h;
		ListaOp* auxAnt = aux;
		while (aux->ope.id != id) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux != NULL) {
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return h;
}

ListaOp* adicionarMaqOp(ListaOp* h, int id, ListaMaq* m) {
	
	ListaOp* aux = ProcurarOp(h,id);

	while (aux->listaM != NULL) {
		aux->listaM = aux->listaM->next;
	}
	aux->listaM = m;
	return h;
}

ListaOp* ProcurarOp(ListaOp* h, int id) {
	if (h == NULL) return NULL;
	else {
		ListaOp* aux = h;
		while (aux != NULL) {
			if (aux->ope.id == id) {
				return (aux);
			}
			aux = aux->next;
		}
		return NULL;
	}
}
	
void mostraMaquinasOp(ListaOp* h) {
	ListaOp* aux = h;
	while (aux != NULL) {
		printf("Operacao %d:(maquina,tempo)\n ", aux->ope.id);
		while (aux->listaM != NULL) {
			printf("(%d,%d)\n", aux->listaM->Maq.cod, aux->listaM->Maq.tempo);
			aux->listaM = aux->listaM->next;
		}
		aux = aux->next;
	
	}

}

int miniTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	int tempo = 0;
	int minimo = 2;

	ListaOp* aux = h;
	ListaMaq* auxm = h->listaM;
	while (aux != NULL) { 
		while (auxm->next != NULL) {
		if (auxm->Maq.tempo < auxm->next->Maq.tempo) {
				tempo = auxm->Maq.tempo;
				auxm = auxm->next;
			}
			else {
				tempo = auxm->next->Maq.tempo;
				auxm = auxm->next;
			}
			
			
		minimo += tempo;
		}
		
		aux = aux->next;
		
    }
	return minimo;

}

void miniTempoeMaq(ListaOp* h) {
	int x = miniTempo(h);
	printf("o tempo minimo para completer o job é: %d\n", x);
	printf("Operacoes: ");
    mostraMaquinasOp(h);
}

int maxTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	int tempo = 0;
	int maximo = 0;

	ListaOp* aux = h;
	ListaMaq* auxm = h->listaM;
	while (aux != NULL) {
		while (auxm->next != NULL) {
			if (auxm->Maq.tempo > auxm->next->Maq.tempo) {
				tempo = auxm->Maq.tempo;
				auxm = auxm->next;
			}
			else {
				tempo = auxm->next->Maq.tempo;
				auxm = auxm->next;
			}


			maximo += tempo;
		}

		aux = aux->next;

	}
	return maximo;

}


void maxTempoeMaq(ListaOp* h) {
	int x = maxTempo(h);
	printf("o tempo minimo para completer o job é: %d\n", x);
	printf("Operacoes: ");
	mostraMaquinasOp(h);
}



int mediaTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	int tempo = 0;
	int media = 0;
	int count = 0;
	int count2 = 0;

	ListaOp* aux = h;
	while (aux != NULL) {
		while (aux->listaM != NULL) {
			tempo = aux->listaM->Maq.tempo;
			count++;
		}
		tempo = tempo / count;
		count2++;
	}
	tempo = tempo / count2;
	return tempo;

}

void mediaTempoeMaq(ListaOp* h) {
	int x = mediaTempo(h);
	printf("o tempo minimo para completer o job é: %d\n", x);
	printf("Operacoes: ");
	mostraMaquinasOp(h);
}

#pragma endregion