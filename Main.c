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

	maqhead = InsereMaqListaM(maqhead, m1);
	maqhead = InsereMaqListaM(maqhead, m2); 
	maqhead = InsereMaqListaM(maqhead, m3);
	maqhead = InsereMaqListaM(maqhead, m4);
	maqhead = InsereMaqListaM(maqhead, m5);





	Operacao* o1 = criarOp(1);
	Operacao* o2 = criarOp(2);
	Operacao* o3 = criarOp(3);
	Operacao* op4 = criarOp(4);

	
	ophead = inserirOpLista(ophead, o1);
	ophead = inserirOpLista(ophead, o2);
	ophead = inserirOpLista(ophead, o3);
	ophead = inserirOpLista(ophead, op4);

	ophead = adicionarMaqOp(ophead, 1, maqhead);

	mostrarMaquinas(o1);


	mostrarMaqOp(ophead);
	
	int x = maxTempo(ophead);
	printf("%d", x);
	//mediaTempoeMaq(headlista);
	//int x = miniTempo(ophead);
	//mostraMaquinasOp(ophead);

	

}