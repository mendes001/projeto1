/**
* Author: Tiago
* Email: a23490@alunos.ipca.pt
* Date: 10-05-2022
* Desc: Jobs
* ???
*/

#include <stdio.h>
#include <stdlib.h>
#include "Jobs.h"

#pragma region functions

void iniciaJobs(ListaOp* jobs[N]) {

	int i;
	for (i = 0; i < N; i++) {
		jobs[i] = NULL;
	}
}
int hash(int x) {

	int y = x - 1;
	return y;
}
ListaOp* insereOpJob(ListaOp* opera) {

	int pos = hash(opera->num);
	insereOpInicio(jobs[pos], opera);
	return jobs;
}
ListaOp* removerOpJob(int id, int num) {
	
	int pos;
	pos = hash(num);
	removerOp(jobs[pos], id);
	return jobs;
}
ListaOp* adicionarMaqOpJob(ListaMaq* maq, int num, int id) {
	
	int pos = hash(num);
	jobs[pos] = adicionarMaqOp(jobs[pos], id, maq);
	return jobs;
}
ListaOp* removerMaqOpJob(int num, int id, int cod) {
	
	int pos = hash(num);
	jobs[pos] = removerMaqOp(jobs[pos], id, cod);
	return jobs;
}
bool existeOpJob(int num, int id) {
	
	int pos = hash(num);
	if(existeOp(jobs[pos], id)) return true;
	return false;
}
ListaOp* procurarOpJob(int num, int id) {
	
	int pos = hash(num);
	procurarOp(jobs[pos], id);
	return jobs;
}



#pragma endregion