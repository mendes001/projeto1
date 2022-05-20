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
Fun��o que cria um espa�o de mem�ria para uma m�quina.
*/
ListaMaq* criaMaq(int cod, int tempo);
/*
Fun��o que serve para mostra as m�quinas de uma determinada lista de m�quinas.
*/
void mostrarMaquinas(ListaMaq* m);
/*
Fun��o que insere uma m�quina no inicio de uma lista de m�quinas.
*/
ListaMaq* insereMaqLista(ListaMaq* m, ListaMaq* newM);
/*
Fun��o que verifica a exist�ncia de uma determinada m�quina.
*/
bool existeMaq(ListaMaq* m, int cod);
int miniTempoListaMaq(ListaMaq* m);
int maxTempoListaMaq(ListaMaq* m);
float mediaTempoListaMaq(ListaMaq* m);



#pragma endregion
