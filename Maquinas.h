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

#pragma endregion

#pragma region funcoes 

ListaMaq* criaMaq(int cod, int tempo);
void mostrarMaquinas(ListaMaq* m);
ListaMaq* InsereMaqLista(ListaMaq* m, ListaMaq* newM);
bool existeMaq(ListaMaq* m, int cod);



#pragma endregion
