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
//ListaMaq* criarNodoListaMaq(Maquina* m) {
//	if (m == NULL) return NULL;
//	else {
//		ListaMaq* maquina = (ListaMaq*)calloc(1,sizeof(ListaMaq));
//		maquina->Maq.cod = m->cod;
//		maquina->Maq.tempo = m->tempo;
//		maquina->next = NULL;
//		return maquina;
//	}
//}
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
			printf("(%d,%d)\n", aux->cod, aux->tempo);
			aux = aux->next;
		}
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

ListaOp* inserirOpLista(ListaOp* h, ListaOp* nova) {
	if (nova == NULL) return h;
	if (existeOp(h, nova->id)) return h;
	if (h = NULL) {
		h = nova;
	}
	else {
		nova->next = h;
		h = nova;
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
	ListaOp* aux = h;

	if (existeOp(aux, novo->id)) return aux;

	if (aux == NULL)
	{
		aux = novo;
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
	return aux;
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
	ListaOp* aux = h;
	int tempo = aux->listaM->tempo;
	int minimo = 0;
	

	while (aux) {
		while (aux->listaM != NULL) {
			if (aux->listaM->tempo < aux->listaM->next) {
				tempo = aux->listaM->tempo;
				aux->listaM = aux->listaM->next;
			}
			else {
				
				aux->listaM = aux->listaM->next;
			}



		}
		minimo += tempo;
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
	ListaOp* aux = h;
	
	int tempo = aux->listaM->tempo;
	int maximo = 0;
	

	while (aux) {
		while (aux->listaM != NULL) {
				if (aux->listaM->tempo > aux->listaM->next) {
					tempo = aux->listaM->tempo;
					aux->listaM = aux->listaM->next;
				}
				else {

					aux->listaM = aux->listaM->next;
				}
		}
		maximo += tempo;
		aux = aux->next;

	}
	return maximo;

}


void maxTempoeMaq(ListaOp* h) {
	int x = maxTempo(h);
	printf("o tempo maximo para completer o job e: %d\n", x);
	mostrarMaqOp(h);
}



int mediaTempo(ListaOp* h) {
	if (h == NULL) return NULL;
	int tempo = 0;
	int media = 0;
	int count = 0;
	int count2 = 0;

	ListaOp* aux = h;
	while (aux) {
		while (aux->listaM != NULL) {
			if (aux->listaM->tempo == NULL) {

				aux = aux->listaM->next;
			}
			else {
				tempo += aux->listaM->tempo;
				count++;
			}
		}
		aux = aux->next;
		count2++;
	}
	tempo = tempo / count;
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
	if (aux == NULL) printf("Lista vazia.");
	while (aux != NULL) {
		printf("Operacao %d:(maquina,tempo)\n ", aux->id);
		mostrarMaquinas(aux->listaM);
		aux = aux->next;
	}
}

#pragma endregion