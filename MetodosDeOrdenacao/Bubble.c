/*
	Name: Bubble.c
	Author: Giovana Isis
	Date: 16/04/25 11:15
	Description: Programa para demonstrar um método de ordenação Bubble Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int tam, i, aux, comp, troca;
	//int vetor[] = {35, 72, 17, 3, 28, 93, 54, 12, 21, 45}; //Vetor randomico
	//int vetor[] = {93, 72, 54, 45, 35, 28, 21, 17, 12, 3}; //pior caso -> nº trocas = nº comparações
	//int vetor[] = {3, 12, 17, 21, 28, 35, 45, 54, 72, 93};   //melhor caso -> 0 trocas
	int vetor[10];
	comp = troca = 0;
	
	tam = sizeof(vetor)/sizeof(int);
	srand(time(NULL));
	for(i = 0; i < tam; i++)
		vetor[i] = rand()%100;
		
	
	
	puts("Vetor desordenado (Original): ");
	for(i = 0; i < tam; i++) //imprime o vetor original
		printf("%d|", vetor[i]);
		
	//Lógica do Bubble Sort
	while(tam > 0)
	{
		for(i = 0; i < tam-1; i++)
		{
			comp++;
			if(vetor[i] > vetor[i+1])
			{
				aux = vetor[i+1];
				vetor[i+1] = vetor[i];	
				vetor[i] = aux;
				troca++;
			}
		}
		tam--;
	}//Fim do while
	
	tam = sizeof(vetor)/sizeof(int);
	puts("\n\nVetor ordenado com o Bubble Sort: ");
	for(i = 0; i < tam; i++) 
		printf("%d|", vetor[i]);
		
	printf("\n\n======> Comparacoes: %d", comp); 
	printf("\n======> Trocas: %d", troca);
	
}//fim do programa
