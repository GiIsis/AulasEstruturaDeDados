/*
	Name: Filas.c
	Author: Giovana Isis Ferreira da Silva
	Date: 02/04/25 11:27
	Description: Programa para implementar o conceito de filas - FIFO
*/


//Sessão de Importação
# include <stdio.h>

//Sessão de Prototipação
void enqueue(int); //Inserir elementos na Fila (enfileirar)
int dequeue(); //Retirar um elemento da Fila (desinfileirar)
int isFull(); //Testa se a fila está cheia.
int isEmpty(); //Testa se a fila está vazia.
void showFIFO(); //exibir o conteúdo da fila

//Variáveis globais
int inicio, fim, total, tamanho, opcao, senha;
int senhas[7]; //vetor de 7 posições
//total = 0; NÃO SE INICIALIZA VARIAVEL FORA DO MAIN, MESMO QUE GLOBAL


main()
{
	inicio = 0;
	fim = 0;
	total = 0;
	opcao = 0;
	senha = 0;

	tamanho = sizeof(senhas)/sizeof(int); //retorna tamanho do vetor.
	printf("Tamanho do vetor: %d ", tamanho);
	//printf("\nTamanho do vetor em bytes: %d", sizeof(senhas)); tamanho do vetor em bytes

    do {
        printf("\n================== MENU ==================\n");
        printf("1. Inserir elementos na Fila (enfileirar)\n");
        printf("2. Retirar um elemento da Fila (desenfileirar)\n");
        printf("3. Exibir o conteudo da fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nOpcao Enfileirar selecionada.\n");
                printf("Digite uma senha para adicionar a fila: ");
                scanf("%d", &senha);
                enqueue(senha);
                break;
            case 2:
                printf("\nOpcao Desenfileirar selecionada. Um elemento saiu da fila\n");
                dequeue();
                break;
            case 3:
                printf("\nOpcao Exibir Conteudo selecionada.");
                showFIFO();
                printf("\n");
                break;
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while(opcao != 4);

}//Fim do main

//Inserir elementos na Fila (enfileirar)
void enqueue(int elem)
{
	if(isFull() == 1)
	{
		puts("\nA Fila esta cheia!");
	}
	else
	{
		senhas[fim] = elem; //o elemento sempre será inserido no fim da Fila
		fim++; //o fim agora é o próximo espaço
		total++; //quantidade de elementos recebe + 1
	}
}

//Retirar um elemento da Fila (desinfileirar)
int dequeue()
{
	if(isEmpty() == 1)
	{
		puts("\nA Fila esta vazia!");
	}
	else
	{
		int elemento;
		elemento = senhas[inicio]; //elemento armazena o elemento que foi retirado
		inicio++; //o elemento que estava no inicio foi retirado e agora o próximo é o inicio
		total--; //menos um elemento na fila
		return elemento; //retorna o elemento que foi retirado
	}
}


//Testa se a fila está cheia.
int isFull() //está cheia?
{
	if(total == tamanho)
	{
		return 1; //verdadeiro (está vazia)
	}
	else
	{
		return 0; //falso (ainda não está cheio)
	}
}

//Testa se a fila está vazia.
int isEmpty() //(está vazia?)
{
	if(total == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//exibir o conteúdo da fila
void showFIFO()
{
	int cont, i;
	puts("\n\nConteudo da Fila: \n");

	for(cont = 0, i = inicio; cont < total; cont++)
	{
		printf("%d|", senhas[i++]);
		if(i == tamanho)
		{
			i = 0;
		}
	}
}

