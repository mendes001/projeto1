/**
* Author: Tiago
* Email: a23490@alunos.ipca.pt
* Date: 10-05-2022
* Desc: Jobs
* ???
*/
#include "Operacoes.h"
#include <cstddef>
#pragma region struct

#ifndef HASH	
#define HASH
#define N 9

//typedef struct ListaJobs {
//
//	int nr;
//	struct ListaOp* listaO;
//
//}ListaJobs;

//Hash table
static struct ListaOp* jobs[N];

#pragma endregion

#pragma region funcoes

/*
Fun��o que inicia a hash table de jobs.
*/
void iniciaJobs(ListaOp* jobs[N]);
/*
Fun��o de Hash baseada num inteiro
*/
int hash(int x);
/*
Fun��o que insere uma opera��o no �nicio de um job;
*/
ListaOp* insereOpJob(ListaOp* opera, ListaOp* jobs[]);
/*
Fun��o que remove uma opera��o de um determinado job apartir do id da mesma.
*/
ListaOp* removerOpJob(int id, int num);
/*
Fun��o que adiciona uma m�quina a uma determinada opera��o de um determinado job.
*/
ListaOp* adicionarMaqOpJob(ListaMaq* maq, int num, int id);
/*
Fun��o que remove uma m�quina de uma determinada opera��o de um determinado job.
*/
ListaOp* removerMaqOpJob(int num, int id, int cod);
#pragma endregion
#endif



