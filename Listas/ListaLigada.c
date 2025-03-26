/*
	Name: ListaLigada.c 
	Author: Giovana Silva 
	Date: 19/03/25 11:37
	Description: Implementação de Lista Ligada (Encadeada).
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

typedef struct No //Um nó é cada registro para guardar as informações
{
	char *nome; //sequencia de caracteres exige *.
	int idade;
	float altura;
	struct No *proximo; //Armazena endereço do proximo nó dessa estrutura	
};

typedef struct //Segunda forma de declarar estrutura
{
	No *inicio, *fim; //Endereços do primeiro e último nós da lista, respectivamente.	
	int tamanho;
	
}Lista;

//Função para inserir um Nó (elemento) no início da Lista.
void inserirInicioLista(Lista *lista, char *n, int ida, float alt)
{
	No *novo = (No*)malloc(sizeof(No)); //memory allocation ---> função malloc do tamanho de um Nó para reservar espaço na memória em bytes.
	novo->nome = n;
	novo->idade = ida;
	novo->altura = alt;
	
	if(lista->inicio == NULL) //A lista está vazia?
	{
		novo->proximo = NULL; //Insere o primeiro elemento da lista, que por sua vez aponta para null
		lista->inicio = novo;
		lista->fim = novo;
	}
	else //A lista não está vazia?
	{
		novo->proximo = lista->inicio; //insere novo nó sempre no inicio da lista.
		lista->inicio = novo;	
	}
	lista->tamanho++; //recebe mais um elemento, seja if, seja else.
	puts("Elemento inserido com sucesso!");	
}//fim da função inserirInicioLista

main()
{
	Lista pessoas;
	char *nome = "Giovana";
	int idade = 19;	
	float altura = 1.63;
	inserirInicioLista(&pessoas, nome, idade, altura);
	
	
}//fim do programa





