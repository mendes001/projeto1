/**
* Author: Tiago
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

	ListaMaq* m1 = criaMaq(1, 5);
	ListaMaq* m2 = criaMaq(2, 4);
	ListaMaq* m3 = criaMaq(4, 7);
	ListaMaq* m4 = criaMaq(3, 6);
	ListaMaq* m5 = criaMaq(5, 4);
	ListaMaq* m6 = criaMaq(6, 9);
	ListaMaq* m7 = criaMaq(7, 5);
	ListaMaq* m8 = criaMaq(8, 12);

	ListaOp* o1 = criarOp(1);
	ListaOp* o2 = criarOp(2);
	ListaOp* o3 = criarOp(3);

	ophead = InsereOpInicio(ophead, o1);
	ophead = InsereOpInicio(ophead, o2);
	ophead = InsereOpInicio(ophead, o3);

	ophead = adicionarMaqOp(ophead, 1, m3);
	ophead = adicionarMaqOp(ophead, 1, m4);
	ophead = adicionarMaqOp(ophead, 2, m8);
	ophead = adicionarMaqOp(ophead, 2, m1);
	ophead = adicionarMaqOp(ophead, 2, m2);
	ophead = adicionarMaqOp(ophead, 3, m7); 
	ophead = adicionarMaqOp(ophead, 3, m6);
	ophead = adicionarMaqOp(ophead, 3, m5);

	ophead = removerOp(ophead, 3);
	
	maxTempoeMaq(ophead);
	printf("\n-------------------\n");
	miniTempoeMaq(ophead);
	printf("\n-------------------\n");
	mediaTempoeMaq(ophead);
	


	

}