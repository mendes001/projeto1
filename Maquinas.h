/**
* Author: Tiago
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc: Maquinas
* ???
*/

#pragma warning( disable : 4996 )
#include<stdbool.h>


#pragma region structs

//typedef struct Maquina {
//	int cod;
//	int tempo;
//}Maquina;

typedef struct ListaMaq {
	int cod;
	int tempo;
	struct ListaMaq* next;
}ListaMaq;

typedef struct ListaMaqFile {
	int cod;
	int tempo;
	int id;
}ListaMaqFile;

#pragma endregion


#pragma region funcoes 
/*
Função que cria um espaço de memória para uma máquina.
*/
ListaMaq* criaMaq(int cod, int tempo);
/*
Função que serve para mostra as máquinas de uma determinada lista de máquinas.
*/
void mostrarMaquinas(ListaMaq* m);
/*
Função que insere uma máquina no inicio de uma lista de máquinas.
*/
ListaMaq* insereMaqLista(ListaMaq* m, ListaMaq* newM);
/*
Função que verifica a existência de uma determinada máquina.
*/
bool existeMaq(ListaMaq* m, int cod);
int miniTempoListaMaq(ListaMaq* m);
int maxTempoListaMaq(ListaMaq* m);
float mediaTempoListaMaq(ListaMaq* m);



#pragma endregion
