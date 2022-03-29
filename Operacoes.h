/**
* Author: Tiago
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc:Operações
* ???
*/

#include<stdbool.h>
#include"Maquinas.h"

#pragma region structs


typedef struct ListaOp {
	
	int id;
	struct ListaMaq* listaM;
	
	struct ListaOp* next;
}ListaOp;

typedef struct ListaOpFile {
	int id;
	struct ListaMaq* listaMaq;
	
}ListaOpFile;

#pragma endregion

extern ListaOp* ophead;

#pragma region funcoes


ListaOp* criarOp(int id);
ListaOp* InsereOpInicio(ListaOp* h, ListaOp* novo);//feita
ListaOp* removerOp(ListaOp* h, int id); //feita
ListaOp* adicionarMaqOp(ListaOp* h,int id, ListaMaq* m);//feita
ListaOp* ProcurarOp(ListaOp* h, int id);//feita
bool existeOp(ListaOp* h, int id); //feita
int miniTempo(ListaOp* h);//feita
void miniTempoeMaq(ListaOp* h);//feita
int maxTempo(ListaOp* h);//feita
void maxTempoeMaq(ListaOp* h);//feita
int mediaTempo(ListaOp* h);//feita
void mediaTempoeMaq(ListaOp* h);//+/- feita, mostra o valor arredondado
void mostrarMaqOp(ListaOp* h);//feita
bool gravarOp(char* nomeFicheiro, ListaOp* h);//????
ListaOp* lerOperacoes(char* nomeFicheiro);//????



#pragma endregion