/*
	Name: Funcoes1.cpp
	Author: Giovana Isis Silva
	Date: 19/02/25 11:06
	Description: Programa para demonstrar o uso das fun��es.
*/

#include <stdio.h> //Standard Input Output

//Sess�o de prototipa��o
int somar(int, int);
float dividir(int, int);
void linha();

main()
{
	int a, b, soma, xis;
	//printf("Endereco da variavel A: %p\n", &a); //%p de ponteiro
	//printf("Endereco da variavel B: %p\n", &b);
	//printf("Endereco da variavel soma: %p\n", &soma);
	//printf("Endereco da variavel xis: %p\n", &xis);

	a = b = soma = xis = 0;
	
	linha();
	printf("Digite o valor de A: ");
	scanf("%d", &a);
	linha();
	printf("Digite o valor de B: ");
	scanf("%d", &b);
	linha();
	//soma = somar(a,b); //invoke da fun��o somar
	printf("A soma eh: %d\n", somar(a,b));
	printf("A divisao eh: %.2f\n", dividir(a,b));
	linha();
	
}//Fim do programa

//Fun��es
int somar(int a, int b)
{
	return a + b;
	
}

float dividir(int a, int b)
{
	return (float)a/b; //Casting
}

void linha()
{
	puts("------------------------------------");
}





