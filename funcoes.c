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

Maquina* criaMaq(int cod, int tempo) {
	Maquina* maq = (Maquina*)malloc(sizeof(Maquina));
	 maq->cod = cod;
	maq->tempo = tempo;
	return maq;

	return maq;
}
ListaMaq* criarNodoListaMaq(Maquina* m) {
	ListaMaq* Maq = (ListaMaq*)malloc(sizeof(ListaMaq));
	Maq->Maq.cod = m->cod;
	Maq->Maq.tempo = m->tempo;
	Maq->next = NULL;
	return Maq;
}
ListaMaq* InsereMaqListaM(ListaMaq* m, Maquina* newM) {
	if (newM == NULL) return m;
	ListaMaq* novo = criarNodoListaMaq(m);
	if (m == NULL) m = novo;
	else {
		novo->next = m;
		m = novo;
	}
	return m;
}

void mostrarMaquinas(ListaMaq* m) {
	ListaMaq* aux = m;
	while (aux) {
		printf("(%d,%d)\n", m->Maq.cod, m->Maq.tempo);
	}
}
#pragma endregion

#pragma region funcoes/operacoes

//ListaOp* criaOp(ListaMaq* h, int id) {
//
//	ListaOp* newOp = (ListaOp*)malloc(sizeof(ListaOp));
//	ListaMaq* newMaq = (ListaMaq*)malloc(sizeof(ListaOp));
//	newOp->listaM = h;
//	newOp->ope.id = id;
//	newOp->next = NULL;
//	
//
//	return newOp;
//}
ListaOp* criarOp(int id) {
	ListaOp* aux = (ListaOp*)calloc(1,sizeof(ListaOp));
	if (aux != NULL) {
		aux->id = id;
		aux->listaM = NULL;
		aux->next = NULL;
		return aux;
	}
}

ListaOp* inserirOpLista(ListaOp* h, int id) {
	if (id == NULL) return h;
	ListaOp* new = criarOp(id);
	if (h == NULL) h = new;
	else {
		new->next = h;
		h = new;
	}
	return h;
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

ListaOp* InserirPorId(ListaOp* h, ListaOp* novo) {

	if (existeOp(h, novo->id)) return h;

	if (h == NULL)
	{
		h = novo;
	}
	else
	{
		ListaOp* aux = h;
		ListaOp* auxAnt = NULL;
		while (aux && aux->id < novo->id) {
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

ListaOp* adicionarMaqOp(ListaOp* h, int id, Maquina* m) {
	if (h == NULL) return NULL;
	if (m == NULL) return h;
	ListaOp* aux = ProcurarOp(h,id);

	if (aux) {
		aux->listaM = InsereMaqListaM(aux->listaM, m);
	}
	return h;
}

ListaOp* ProcurarOp(ListaOp* h, int id) {
	ListaOp* aux = h;
		while (aux) {
			if (aux->id == id)return (aux);
			aux = aux->next;
		}
		return NULL;
	}

//	
//void mostraMaquinasOp(ListaOp* h) {
//	ListaOp* aux = h;
//	while (aux) {
//		printf("Operacao %d:(maquina,tempo)\n ", aux->ope.id);
//		while (aux->listaM) {
//			printf("(%d,%d)\n", aux->listaM->Maq.cod, aux->listaM->Maq.tempo);
//			aux->listaM = aux->listaM->next;
//		}
//		aux = aux->next;
//	
//	}
//
//}

int miniTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	int tempo = 0;
	int minimo = 2;

	ListaOp* aux = h;
	ListaMaq* auxm = h->listaM;
	while (aux) { 
		while (auxm) {
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
	mostrarMaquinas(h->listaM);
}

int maxTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	int tempo = 0;
	int maximo = 0;
	ListaOp* aux = h;

	while (aux) {
		while (aux->listaM) {
			if (aux->listaM->Maq.tempo > aux->listaM->next->Maq.tempo) {
				tempo = aux->listaM->Maq.tempo;
				aux->listaM = aux->listaM->next;
			}
			else {
				tempo = aux->next->listaM->next;
				aux->listaM = aux->listaM->next;
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
	mostrarMaqOp(h);
}



int mediaTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	int tempo = 0;
	int media = 0;
	int count = 0;
	int count2 = 0;

	ListaOp* aux = h;
	while (aux != NULL) {
		while (aux->listaM) {
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
	mostrarMaqOp(h);
}

void mostrarMaqOp(ListaOp* h) {
	ListaOp* aux = h;
	while (aux) {
		printf("Operacao %d:(maquina,tempo) ", h->id);
		mostrarMaquinas(aux->listaM);
		aux = aux->next;
	}
}

#pragma endregion