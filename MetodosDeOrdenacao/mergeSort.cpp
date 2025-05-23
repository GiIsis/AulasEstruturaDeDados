/*
	Name: MergeSort.cpp 
	Author: Giovana Isis
	Date: 14/05/25 12:07
	Description: Implementa��o do algoritmo do m�todo de ordena��o Merge Sort
*/


# include <stdio.h>


//Sess�o de Prototipa��o
void mergeSort(int *, int, int); //Prototipa��o da Fun��o que quebra 
void merge(int *, int, int, int); //Prototipa��o da fun��o que mescla

//Vari�veis globais
int copia = 0;


main()
{
	int inicio, fim, i, j;
	inicio = 0;
	
	int vet[] = {35, 72, 17, 3, 28, 93, 54, 12, 21, 45}; //Vetor randomico
	//int vet[] = {93, 72, 54, 45, 35, 28, 21, 17, 12, 3}; //pior caso -> n� trocas = n� compara��es
	//int vet[] = {3, 12, 17, 21, 28, 35, 45, 54, 72, 93}; //melhor caso -> 0 trocas
	
	int tam = sizeof(vet)/sizeof(int);
	fim = tam - 1;
	
	puts("Vetor desordenado (Original): ");
	for(i = 0; i < tam; i++) //imprime o vetor original
		printf("%d|", vet[i]);

	mergeSort(vet, inicio, fim); //invoke da fun��o para ordena��o
	
	puts("\nVetor ordenado com o Merge Sort: ");
	for(i = 0; i < tam; i++) //imprime o vetor ordenado
		printf("%d|", vet[i]);
	
}//Fim do main

//Fun��o recursiva que quebra at� chegar em uma �nica unidade
void mergeSort(int vetor[], int inicio, int fim) 
{
	
	if(inicio < fim)
	{
		int meio = ( fim + inicio )/2;
		mergeSort(vetor, inicio, meio); //lado esquerdo
		mergeSort(vetor, meio + 1, fim); //lado direito
		merge(vetor, inicio, meio, fim);
	}
}
//Fun��o que junta as partes unit�rias (merge), mesclando os elementos
void merge(int V[], int inicio, int meio, int fim)
{
	int esq, dir; //indices para os vetores do lado direito e esquerdo
	int aux, tam;	
	
	esq = inicio;
	dir = meio + 1;
	aux = 0;
	tam = (fim - inicio) + 1;
	int vetAux[tam];
	
	while(esq <= meio && dir <= fim)
	{
		if(V[esq] < V[dir])
		{
			copia++;
			vetAux[aux] = V[esq];
			esq++;
		}
		else
		{
			copia++;
			vetAux[aux] = V[dir];
			dir++;
		}
		
		aux++;
	}
	
	
	//Caso ainda haja elementos na PRIMEIRA METADE, copiar� todo o restante para o vetor auxiliar
	while(esq <= meio)
	{
		copia++;
		vetAux[aux] = V[esq];
		aux++;
		esq++;
	}
	
	//Caso ainda haja elementos na SEGUNDA METADE, copiar� todo o restante para o vetor auxiliar
	while(dir <= fim)
	{
		copia++;
		vetAux[aux] = V[dir];
		aux++;
		dir++;
	}
	
	//Move os elementos de volta para o vetor original
	for(aux = inicio; aux <= fim; aux++)
	{
		copia++;
		V[aux] = vetAux[aux - inicio];
	}
	
	//free(vetAux);
}
