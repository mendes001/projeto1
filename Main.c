/**
* Author: Mendes
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc:Declaraçao de máquinas e lista de máquinas
* ???
*/

#include <stdio.h>
#include<stdbool.h>
#include"Operacoes.h"

void main() {
	
	ListaOp* ophead = NULL;
	ListaMaq* maqhead = NULL;

	ListaMaq* m1 = criaMaq(1, 2);
	ListaMaq* m2 = criaMaq(2, 2);
	ListaMaq* m3 = criaMaq(3, 6);
	ListaMaq* m4 = criaMaq(4, 5);

	ListaOp* o1 = criaOp(m1, 1);
	ListaOp* o2 = criaOp(m2, 4);
	ListaOp* o3 = criaOp(m3, 3);
	ListaOp* op4 = criaOp(m4, 2);

	
	ophead = InsereOpInicio(ophead, o1);
	ophead = InsereOpInicio(ophead, o2);
	ophead = InsereOpInicio(ophead, o3);

	ophead = InserirPorId(ophead, op4);
	
	int x = maxTempo(ophead);
	printf("%d", x);
	//mediaTempoeMaq(headlista);
	//int x = miniTempo(ophead);
	//mostraMaquinasOp(ophead);

	

}