/*
	Name: heapSort.cpp
	Author: Giovana Isis
	Date: 21/05/25 11:41
	Description: Implementa��o do algoritmo para o m�todo de ordena��o Heap Sort
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Sess�o de Prototipa��o
void heapfy(int *, int, int); //heapfy( int vet[], tam, i)
void heapSort(int *, int); //heapSort(int vet[], tam

main()
{
	int i;
	//int vet[] = {-35, 72, 17, -3, 28, 93, 54, 12, 21, 45}; //Vetor randomico
	//int vet[] = {93, 72, 54, 45, 35, 28, 21, 17, 12, 3}; //pior caso -> n� trocas = n� compara��es
	//int vet[] = {3, 12, 17, 21, 28, 35, 45, 54, 72, 93}; //melhor caso -> 0 trocas
	
	int vet[100];
	int tam = sizeof(vet)/sizeof(int);

	srand(time(NULL));
	for(i = 0; i < tam; i++)
		vet[i] = rand()%100;
	

	
	puts("Vetor desordenado (Original): ");
	for(i = 0; i < tam; i++) //imprime o vetor original
		printf("%d|", vet[i]);

	heapSort(vet, tam); //invoke da fun��o para iniciar a ordena��o
	
	puts("\nVetor ordenado com o Heap Sort: ");
	for(i = 0; i < tam; i++) //imprime o vetor ordenado
		printf("%d|", vet[i]);
	
}//Fim do main


//Fun��o recursiva que sempre testa se o n� pai � maior que seus filhos, no caso do MAX Heap
void heapfy(int vet[], int tam, int i)
{
	int maior = i;
	int esq = (2 * i) + 1; //n� filho da esquerda	
	int dir = (2 * i) + 2; //n� filho da direita
	
	if(esq < tam && vet[esq] > vet[maior]) //se a arvore existe (< tam) E se o filho for maior que o pai
		maior = esq;
	
	if(dir < tam && vet[dir] > vet[maior])
		maior = dir;
		
	if(maior != i) //se n�o � um elemento �nic, como quando o �ndice � 0 (i=0)
	{
		int aux = vet[i];
		vet[i] = vet[maior];
		vet[maior] = aux;
		
		heapfy(vet,tam,maior);
	}
}//Fim da fun��o recursiva heapfy

//Fun��o do Heap Sort
void heapSort(int vet[], int tam)
{
	for(int i = tam/2-1; i >= 0; i--)
		heapfy(vet, tam, i);
		
	//Aqui faz o swap
	for(int i = tam-1; i > 0; i--)
	{
		int aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		
		heapfy(vet, i, 0);
	}	
}


