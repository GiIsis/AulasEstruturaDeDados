/*
	Name: ListaLigada.c
	Author: Giovana Silva
	Date: 19/03/25 11:37
	Description: Implementação de Lista Ligada (Encadeada).
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct No //Um nó é cada registro para guardar as informações. Tamanho do nó é a soma de cada variável
{
	char *nome; //sequencia de caracteres exige *.
	int idade;
	float altura;
	struct No *proximo; //Armazena endereço do proximo nó dessa estrutura
} No;

typedef struct //Segunda forma de declarar estrutura
{
	No *inicio, *fim; //Endereços do primeiro, o do meio e último nós da lista, respectivamente.
	int tamanho;
} Lista;

//Função para inserir um Nó (elemento) no início da Lista.
void inserirInicioLista(Lista *lista, char *n, int ida, float alt)
{
	No *novo = (No*)malloc(sizeof(No)); //memory allocation ---> função malloc do tamanho de um Nó para reservar espaço na memória em bytes. Aloca na memória um espaço do tamanho do nó
	novo->nome = strdup(n); //aloca memória para armazenar o nome e copia seu conteúdo, evitando problemas de sobrescrita
	novo->idade = ida;
	novo->altura = alt;

	if(lista->inicio == NULL) //A lista está vazia? Sim, se não tiver nenhum nó na lista
	{
		novo->proximo = NULL; //Insere o primeiro elemento da lista, que por sua vez aponta para null. O primeiro nó é o primeiro e o último
		lista->inicio = novo;
		lista->fim = novo;
	}
	else //A lista não está vazia?
	{
		novo->proximo = lista->inicio; //insere novo nó sempre no inicio da lista.
		lista->inicio = novo;
	}
	lista->tamanho++; //a cada novo nó adiciona mais um em tamanho, seja if, seja else.
	puts("Elemento inserido no INICIO com sucesso!");
}//fim da função inserirInicioLista

//Função para inserir um Nó (elemento) no MEIO da Lista.
void inserirMeioLista(Lista *lista, char *n, int ida, float alt, char nReferencia[100])
{
	No *i = lista->inicio; //variavel i para percorrer todos os nós na lista

	if (i == NULL) // Se a lista está vazia
	{
		printf("\nA lista ainda nao tem nenhum elemento!\n");
	        return;
	}

    	while (i != NULL && strcmp(i->nome, nReferencia) != 0) //enquanto i não for um nó vazio e o nome da pessoa não for igual ao nome de referencia
    	{
       		i = i->proximo; //i passa para o seu próximo nó, até encontrar o nome de referencia
   	}

    	if (i == NULL) //Se i já chegou ao fim da lista e não encontrou o nome de referencia
    	{
     		printf("\nO nome de referencia '%s' nao existe na lista!\n",nReferencia);
     	   	return;
   	}

	No *novo = (No*)malloc(sizeof(No));
	novo->nome = strdup(n);
	novo->idade = ida;
	novo->altura = alt;

    	novo->proximo = i->proximo; //o nó após o nó inserido será o que estava após ao nome de referencia, ou seja, o novo nó entra entre os nós com o nome de referencia e o seguinte a ele
    	i->proximo = novo; // o nó após o nome de referencia será o novo nó inserido

    	if (i == lista->fim) //se o último nó for o nome de referencia
    	{
        	lista->fim = novo; //o fim agora será o novo nó inserido
    	}

    	lista->tamanho++;
    	printf("\nElemento inserido APOS o nome de referencia '%s' com sucesso!\n",nReferencia);
}//fim do inserirMeioLista

//Função para inserir um Nó (elemento) no fim da Lista.
void inserirFimLista(Lista *lista, char *n, int ida, float alt)
{
	No *novo = (No*)malloc(sizeof(No));
	novo->nome = strdup(n); //aloca memória para armazenar o nome e copia seu conteúdo, evitando problemas de sobrescrita
	novo->idade = ida;
	novo->altura = alt;
	novo->proximo = NULL; //não existe mais nenhum elemento, pois é o nó final que está sendo inserido

	if(lista->inicio == NULL) //se a lista estiver vazia fim e inicio receberão o mesmo nó
	{
		lista->inicio = novo; //inicio recebe novo
		lista->fim = novo;//fim recebe novo
	}
	else //se a lista NÃO estiver vazia
	{
		lista->fim->proximo = novo; //o campo próximo do nó fim da lista recebe novo, e agora ele é o nó fim.
		lista->fim = novo;
	}
	lista->tamanho++;
	puts("Elemento inserido no FIM com sucesso!\n");

}//fim do inserirFimLista

//Função para exibir todo o conteúdo da lista
void exibirLista(Lista *lista)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	/*Salvar os atriutos de cores*/
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	No *inicio = lista->inicio; //posiciona no primeiro nó da lista.
	printf("\nTamanho da Lista: %d elementos\n\n", lista->tamanho);
	puts("\nConteudo da Lista: ");

	while(inicio != NULL) //enquanto inicio diferente de null
	{
		printf("| Nome: %s | Idade: %d | Altura: %.2f |", inicio->nome, inicio->idade, inicio->altura);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		printf(" -> ");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		inicio = inicio->proximo; //inicio recebe próximo até que o próximo seja null (ultimo elemento)
	}
	printf("NULL\n");
}

//Função para retirar um nó (elemento) da lista
void retirarNoLista(Lista *lista, char *nomeRemover)
{
	No *inicio = lista->inicio; //Ponteiro para o primeiro nó da lista.
	No *noARemover = NULL; //Cria um nó e diz que ele é nulo, será o nó removido

	if (inicio == NULL) // Se a lista estiver vazia
	{
	        printf("A lista está vazia!\n");
	        return;
	}

	if(lista->inicio->nome != NULL && strcmp(lista->inicio->nome, nomeRemover) == 0) //se o primeiro nó existir e for o que se quer remover, remove o prmeiro elemento da lista
	{
		noARemover = lista->inicio;
		lista->inicio = noARemover->proximo;
		if(lista->inicio == NULL)
        	{
           		lista->fim = NULL;
		}
	}
	else //Remover nós do meio da lista ou do fim dela.
	{
		while(inicio != NULL && inicio->proximo != NULL && strcmp(inicio->proximo->nome, nomeRemover) != 0) //enquanto não for o que se quer remover, pula para o próximo
	        {
	            inicio = inicio->proximo; //vai para o próximo até encontrar o que quer remover
	        }
	        if(inicio != NULL && inicio->proximo != NULL)
	        {
	            noARemover = inicio->proximo;
	            inicio->proximo = noARemover->proximo;
	            if(inicio->proximo == NULL) //Se o último elemn=ento for removido
	            {
	                lista->fim = inicio;
	            }
	        }
	}

	if(noARemover != NULL) //Testa se noARemover é NULL
	{
		free(noARemover); //função free libera o espaço de memória reservado para o nó.
	        lista->tamanho--; //um elemento a menos
	        printf("Elemento removido da Lista com sucesso!\n");
	}
	else
	{
		printf("O elemento escolhido não existe na Lista!\n");
	}
}//fim do retirarNoLista

main()
{
	//declaração da lista e das variáveis do Nó.
	Lista pessoas;
	pessoas.inicio = NULL;
	pessoas.fim = NULL;
	pessoas.tamanho = 0;

	char nome[100];
	int idade;
	float altura;

	int opc = 0; //variável que irá armazenar a opção do menu.

	while(1) //enquanto verdadeiro
	{
	    system("cls"); //invoca função cls (clear screen) do Windows

		puts("1 - Inserir INICIO\n2 - Inserir FIM\n3 - Inserir APOS NOME DE REFERENCIA\n4 - Exibir Lista\n5 - Remover elemento\n6 - Sair...");
		printf("\nEscolha sua opcao: ");
		scanf("%d", &opc);
		fflush(stdin); //Limpa buffer

		switch(opc)
		{
			case 1:
				puts("\nINICIO da Lista");
				puts("===============");
				printf("Nome: "); scanf("%s", nome);
				printf("Idade: "); scanf("%d", &idade);
				printf("Altura: "); scanf("%f", &altura);
				inserirInicioLista(&pessoas, nome, idade, altura);
				break;
			case 2:
				puts("\nFIM da Lista");
				puts("===============");
				printf("Nome: "); scanf("%s", nome);
				printf("Idade: "); scanf("%d", &idade);
				printf("Altura: "); scanf("%f", &altura);
				inserirFimLista(&pessoas, nome, idade, altura);
				break;
		        case 3:
		                char nReferencia[100];
		
		                puts("\nAPOS nome da Lista");
		                puts("====================");
		                printf("Inserir apos o nome: "); scanf("%s", nReferencia);
		
		                printf("Inserir nome: "); scanf("%s", nome);
				printf("Inserir Idade: "); scanf("%d", &idade);
				printf("Inserir Altura: "); scanf("%f", &altura);
				inserirMeioLista(&pessoas, nome, idade, altura, nReferencia);
				break;
			case 4:
				exibirLista(&pessoas);
				break;
			case 5:
				printf("\nDigite o nome da pessoa que deseja remover da lista: ");
				scanf("%s", nome);
				retirarNoLista(&pessoas, nome);
				break;
			case 6: 
				exit(0); //exit fecha o programa, break sai do loop
			default:
                		puts("Opcao invalida, tente novamente!");
		} //fim do switch

	puts("\nPressione qualquer tecla para continuar...");
	fflush(stdin);
	getchar();  //pega o caractere da tecla pressionada
		
	}//fim do loop infinito
	
}//fim do programa
