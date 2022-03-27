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

	Maquina* m1 = criaMaq(1, 2);
	Maquina* m2 = criaMaq(2, 2);
	Maquina* m3 = criaMaq(3, 6);
	Maquina* m4 = criaMaq(4, 5);
	Maquina* m5 = criaMaq(5, 10);

	





	
	ophead = inserirOpLista(ophead, 1);
	ophead = inserirOpLista(ophead, 2);
	ophead = inserirOpLista(ophead, 3);
	ophead = inserirOpLista(ophead, 4);

	ophead = adicionarMaqOp(ophead, 2, m1);
	ophead = adicionarMaqOp(ophead, 2, m2);
	ophead = adicionarMaqOp(ophead, 2, m3);
	ophead = adicionarMaqOp(ophead, 2, m4);

	
	mostrarMaqOp(ophead);


	
	
	int x = maxTempo(ophead);
	printf("%d", x);
	//mediaTempoeMaq(headlista);
	//int x = miniTempo(ophead);
	//mostraMaquinasOp(ophead);

	

}