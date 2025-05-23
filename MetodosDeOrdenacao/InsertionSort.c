/*
	Name: InsertionSort.c
	Author: Giovana Isis
	Date: 14/05/25 11:38
	Description: Implementação do algoritmo do método de ordenação Insertion Sort
*/


# include <stdio.h>


//Sessão de Prototipação
void insertionSort(int *, int); //asterisco pois será passado o vetor como primeiro parametro


main()
{
	int i, comp, troca;
	int vet[] = {35, 72, 17, 3, 28, 93, 54, 12, 21, 45}; //Vetor randomico
	//int vet[] = {93, 72, 54, 45, 35, 28, 21, 17, 12, 3}; //pior caso -> nº trocas = nº comparações
	//int vet[] = {3, 12, 17, 21, 28, 35, 45, 54, 72, 93}; //melhor caso -> 0 trocas
	
	int tam = sizeof(vet)/sizeof(int);
	
	puts("Vetor desordenado (Original): ");
	for(i = 0; i < tam; i++) //imprime o vetor original
		printf("%d|", vet[i]);

	insertionSort(vet, tam); //invoke da função para ordenação
	
	puts("\nVetor ordenado com o Insertion Sort: ");
	for(i = 0; i < tam; i++) //imprime o vetor ordenado
		printf("%d|", vet[i]);
	
}//Fim do main

void insertionSort(int vet[], int tam)
{
	int i, j, k, chave;
	for(i = 1; i < tam; i++)
	{
		chave = vet[i];
		j = i - 1;
		
		while(j >= 0 && vet[j] > chave)
		{
			vet[j+1] = vet[j];
			j = j - 1;
			
		}//fim do while
		
		vet[j+1] = chave;
		
	}//fim dor for
}
