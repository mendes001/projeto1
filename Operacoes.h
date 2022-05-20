/**
* Author: Tiago
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc:Operações
* ???
*/

#pragma once

#ifndef 2

#endif // !2


#include<stdbool.h>
#include"Maquinas.h"

#pragma region structs

/**
*/
typedef struct ListaOp {
	int id;
	int num;
	struct ListaMaq* listaM;
	struct ListaOp* next;
}ListaOp;

typedef struct ListaOpFile {
	int id;
	int num;
}ListaOpFile;

#pragma endregion

extern ListaOp* ophead;

#pragma region funcoes


ListaOp* criarOp(int id, int num);
ListaOp* insereOpInicio(ListaOp* h, ListaOp* novo);//feita
ListaOp* removerOp(ListaOp* h, int id); //feita
ListaOp* adicionarMaqOp(ListaOp* h,int id, ListaMaq* m);//feita
ListaOp* removerMaqOp(ListaOp* h, int id, int cod);//feita
ListaOp* procurarOp(ListaOp* h, int id);//feita
bool existeOp(ListaOp* h, int id); //feita
int miniTempoOp(ListaOp* h);//feita
void miniTempoeMaq(ListaOp* h);//feita
int maxTempoOp(ListaOp* h);//feita
void maxTempoeMaq(ListaOp* h);//feita
float mediaTempoOp(ListaOp* h);//feita
void mediaTempoeMaq(ListaOp* h);//+/- feita, mostra o valor arredondado
void mostrarMaqOp(ListaOp* h);//feita
bool gravarOp(char* nomeFicheiro,char* nomeFicheiro2, ListaOp* h);//????
ListaOp* lerOperacoes(char* nomeFicheiro,char* nomeFicheiro2);//????



#pragma endregion