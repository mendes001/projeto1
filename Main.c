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
	ListaMaq* maqhead = NULL;

	ListaMaq* m1 = criaMaq(1, 5);
	ListaMaq* m2 = criaMaq(2, 3);
	ListaMaq* m3 = criaMaq(3, 6);
	ListaMaq* m4 = criaMaq(4, 5);
	ListaMaq* m5 = criaMaq(5, 10);

	ListaOp* o1 = criarOp(1);
	ListaOp* o2 = criarOp(2);
	ListaOp* o3 = criarOp(3);






	
	
	ophead = InsereOpInicio(ophead, o1);
	ophead = InsereOpInicio(ophead, o2);



	/*ophead = inserirOpLista(ophead, o2);
	ophead = inserirOpLista(ophead, o3);*/




	/*o1->listaM = InsereMaqLista(o1, m2);
	o1->listaM = InsereMaqLista(o1, m1);
	o1->listaM = InsereMaqLista(o1, m3);*/

	ophead = adicionarMaqOp(ophead, 1, m3);
	ophead = adicionarMaqOp(ophead, 1, m4);
	ophead = adicionarMaqOp(ophead, 2, m1);
	ophead = adicionarMaqOp(ophead, 2, m2);

	
	mostrarMaqOp(ophead);

	/*int x = mediaTempo(ophead);*/
	/*printf("%d", x);*/
	
	//mediaTempoeMaq(headlista);
	//int x = miniTempo(ophead);
	//mostraMaquinasOp(ophead);

	

}