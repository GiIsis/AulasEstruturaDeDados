/*
	Name: Selection.c
	Author: Giovana Isis
	Date: 07/05/25 11:43
	Description: Implementação do algoritmo do método de ordenação Selection Sort
*/


# include <stdio.h>

main()
{
	int i, j, menor, aux, chave;
	int comp, troca;
	int vet[] = {35, 72, 17, 3, 28, 93, 54, 12, 21, 45}; //Vetor randomico
	//int vet[] = {93, 72, 54, 45, 35, 28, 21, 17, 12, 3}; //pior caso -> nº trocas = nº comparações
	//int vet[] = {3, 12, 17, 21, 28, 35, 45, 54, 72, 93}; //melhor caso -> 0 trocas
	
	int tam = sizeof(vet)/sizeof(int);
	
	puts("Vetor desordenado (Original): ");
	for(i = 0; i < tam; i++) //imprime o vetor original
		printf("%d|", vet[i]);
		
	i = 0;
	while(i < tam-1)
	{
		menor = i; //na primeira execução, menor recebe o endereço do primeiro elemento (indice 0)
		j = i + 1; //começa da segunda posição, posição após a chave
		
		do{
			comp++;
			if(vet[j] < vet[menor])
			{
				menor = j;
			}
		j++;
		}while(j < tam);
		
		if(i != menor)
		{
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux;
			troca++;
		}
		
	i++;
		
	}//fim do while
	
	puts("\n\nVetor ordenado pelo Selection Sort: ");
	for(i = 0; i < tam; i++) 
		printf("%d|", vet[i]);
		
	printf("\n\n======> Comparacoes: %d", comp); 
	printf("\n======> Trocas: %d", troca);
	
	
}//Fim do Programa

