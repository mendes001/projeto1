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

#pragma endregion

extern ListaOp* ophead;

#pragma region funcoes

//ListaOp* criaOp(ListaMaq* h, int id); //feita	
ListaOp* criarOp(int id);
//ListaOp* CriarNodoOp(ListaOp* op);
ListaOp* inserirOpLista(ListaOp* h, ListaOp* nova);
ListaOp* InsereOpInicio(ListaOp* h, ListaOp* novo);//feita
ListaOp* InserirPorId(ListaOp* h, ListaOp* novo);//feita
ListaOp* removerOp(ListaOp* h, int id); //feita
ListaOp* adicionarMaqOp(ListaOp* h,int id, ListaMaq* m);//????
ListaOp* ProcurarOp(ListaOp* h, int id);//feita
bool existeOp(ListaOp* h, int id); //???
bool gravarOp(char* nomeFicheiro, ListaOp* h);//????
ListaOp* lerFicherio(char* nomeFicheiro);//????
int miniTempo(ListaOp* h);
void miniTempoeMaq(ListaOp* h);
int maxTempo(ListaOp* h);
void maxTempoeMaq(ListaOp* h);
int mediaTempo(ListaOp* h);
void mediaTempoeMaq(ListaOp* h);
void mostrarMaqOp(ListaOp* h);


#pragma endregion