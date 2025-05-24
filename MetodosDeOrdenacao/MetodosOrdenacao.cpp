/*
	Name: MetodosOrdenacao.cpp
	Author: Giovana Isis
	Date: 23/05/25 21:03
	Description: Programa para demonstrar a implementação dos principais algoritmos de ordenação
    abordados na disciplina de Estrutura de Dados, permitindo a seleção do método por meio de um menu interativo.
*/

//Importando Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Sessão de prototipação
void gerarVetorAleatorio(int *, int);
void imprimirVetor(int *, int);
void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int); //asterisco pois será passado o vetor como primeiro parametro
void mergeSort(int *, int, int); //Prototipação da Função que quebra
void merge(int *, int, int, int); //Prototipação da função que mescla
void heapfy(int *, int, int); //heapfy( int vet[], tam, i)
void heapSort(int *, int); //heapSort(int vet[], tam


//Variáveis Globais
int copia = 0;

main()
{
    int op, *vetor, tamVet;

    do {
        printf("\n====== METODOS DE ORDENACAO ======\n");
        printf("========== 1 - Bubble Sort =========\n");
        printf("======== 2 - Selection Sort ========\n");
        printf("======== 3 - Insertion Sort ========\n");
        printf("========== 4 - Merge Sort ==========\n");
        printf("=========== 5 - Heap Sort ==========\n");
        printf("============= 0 - Sair =============\n");

        printf("\nEscolha uma opcao para ordenar um vetor (0 para sair): ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                printf("Quantas posicoes voce deseja que o vetor tenha?\n");
                scanf("%d", &tamVet);

                vetor = (int *)malloc(tamVet * sizeof(int));
                if (vetor == NULL) {
                    printf("Erro!Erro!Erro!Erro!\n");
                    break;
                }

                gerarVetorAleatorio(vetor, tamVet);

                printf("\nVetor desordenado:\n\n");
                imprimirVetor(vetor, tamVet);

                switch (op) {
                    case 1:
                        bubbleSort(vetor, tamVet);
                        printf("Vetor ordenado com Bubble Sort:\n");
                        break;
                    case 2:
                        selectionSort(vetor, tamVet);
                        printf("Vetor ordenado com Selection Sort:\n");
                        break;
                    case 3:
                        insertionSort(vetor, tamVet);
                        printf("Vetor ordenado com Insertion Sort:\n");
                        break;
                    case 4:
                        mergeSort(vetor, 0, tamVet - 1);
                        printf("Vetor ordenado com Merge Sort:\n");
                        break;
                    case 5:
                        heapSort(vetor, tamVet);
                        printf("Vetor ordenado com Heap Sort:\n");
                        break;
                }

                imprimirVetor(vetor, tamVet);
                free(vetor);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (op != 0);

} //Fim do main


//Sessão das Funções

//Função que gera um vetor com valores aleatórios entre 0 e 99
void gerarVetorAleatorio(int *vetor, int tam)
{
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 100;
    }
}//Fim da função gerarVetorAleatorio


//Função que imprime os elementos do vetor separados por '|'
void imprimirVetor(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++) {
        printf("%d|", vetor[i]);
    }
    printf("\n");
}//Fim da função imprimirVetor

//Função que implementa o algoritmo Bubble Sort para ordenar o vetor
void bubbleSort(int vetor[], int tam)
{
    int comp = 0, troca = 0, aux;

    while (tam > 0)
    {
        for (int i = 0; i < tam - 1; i++)
        {
            comp++;
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = aux;
                troca++;
            }
        }
        tam--;
    }

    printf("\n\n======> Comparacoes: %d\n", comp);
    printf("\n======> Trocas: %d\n\n", troca);
}//Fim da função bubbleSort

//Função que implementa o algoritmo Selection Sort para ordenar o vetor
void selectionSort(int vetor[], int tam)
{
    int i = 0, j, menor, aux, comp = 0, troca = 0;

    while (i < tam - 1)
    {
        menor = i;
        j = i + 1;

        do {
            comp++;
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
            j++;
        } while (j < tam);

        if (i != menor)
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            troca++;
        }

        i++;
    }

    printf("\n\n======> Comparacoes: %d\n", comp);
    printf("\n======> Trocas: %d\n\n", troca);
}//Fim da função selectionSort

//Função que implementa o algoritmo Insertion Sort para ordenar o vetor
void insertionSort(int vet[], int tam)
{
    int i, j, chave;
    for (i = 1; i < tam; i++)
    {
        chave = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > chave)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }

        vet[j + 1] = chave;
    }
}//Fim da função insertionSort

//Função recursiva que quebra até chegar em uma única unidade
void mergeSort(int vetor[], int inicio, int fim)
{

	if(inicio < fim)
	{
		int meio = ( fim + inicio )/2;
		mergeSort(vetor, inicio, meio); //lado esquerdo
		mergeSort(vetor, meio + 1, fim); //lado direito
		merge(vetor, inicio, meio, fim);
	}
} //Fim da função mergeSort

//Função que junta as partes unitárias (merge), mesclando os elementos
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


	//Caso ainda haja elementos na PRIMEIRA METADE, copiará todo o restante para o vetor auxiliar
	while(esq <= meio)
	{
		copia++;
		vetAux[aux] = V[esq];
		aux++;
		esq++;
	}

	//Caso ainda haja elementos na SEGUNDA METADE, copiará todo o restante para o vetor auxiliar
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

}//Fim da função merge

//Função recursiva que sempre testa se o nó pai é maior que seus filhos, no caso do MAX Heap
void heapfy(int vet[], int tam, int i)
{
	int maior = i;
	int esq = (2 * i) + 1; //nó filho da esquerda
	int dir = (2 * i) + 2; //nó filho da direita

	if(esq < tam && vet[esq] > vet[maior]) //se a arvore existe (< tam) E se o filho for maior que o pai
		maior = esq;

	if(dir < tam && vet[dir] > vet[maior])
		maior = dir;

	if(maior != i) //se não é um elemento únic, como quando o índice é 0 (i=0)
	{
		int aux = vet[i];
		vet[i] = vet[maior];
		vet[maior] = aux;

		heapfy(vet,tam,maior);
	}
}//Fim da função recursiva heapfy

//Função do Heap Sort que organiza o vetor usando heapfy e troca elementos
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
}//Fim da função heapSort
