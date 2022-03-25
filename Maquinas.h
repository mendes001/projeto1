/**
* Author: Mendes
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc: Declaracao de operacoes e lista de operacoes
* ???
*/

#pragma warning( disable : 4996 )
#include<stdbool.h>


#pragma region structs

typedef struct Maquina {
	int cod;
	int tempo;
}Maquina;

typedef struct ListaMaq {
	struct Maquina Maq;
	struct ListaMaq* next;
}ListaMaq;

#pragma endregion
extern ListaMaq* maqhead;
#pragma region funcoes 

ListaMaq* criaMaq(int cod, int tempo);

#pragma endregion
