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
Função que inicia a hash table de jobs.
*/
void iniciaJobs(ListaOp* jobs[N]);
/*
Função de Hash baseada num inteiro
*/
int hash(int x);
/*
Função que insere uma operação no ínicio de um job;
*/
ListaOp* insereOpJob(ListaOp* opera, ListaOp* jobs[]);
/*
Função que remove uma operação de um determinado job apartir do id da mesma.
*/
ListaOp* removerOpJob(int id, int num);
/*
Função que adiciona uma máquina a uma determinada operação de um determinado job.
*/
ListaOp* adicionarMaqOpJob(ListaMaq* maq, int num, int id);
/*
Função que remove uma máquina de uma determinada operação de um determinado job.
*/
ListaOp* removerMaqOpJob(int num, int id, int cod);
#pragma endregion
#endif



