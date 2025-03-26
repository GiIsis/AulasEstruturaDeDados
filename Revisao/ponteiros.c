/*
	Name: Ponteiros.c 
	Author: Giovana Silva
	Date: 19/03/25 11:07
	Description: Programa para explorar os recursos de ponteiros
*/


#include <stdio.h>
main()
{
	int a, b, c;
	char c1, c2, c3;
	
	a = 5;
	b = 8;
	c = 10;
	
	c1 = 'A';
	c2 = 'B';
	c3 = 'C';
	
	printf("Valor de A: %d", a);
	printf("\nValor de B: %d", b);
	printf("\nValor de C: %d", c);
	
	puts("\n\nValor dos Ponteiros em hexadecimal: ");
	printf("\nEndereco da variavel A: %p", &a);
	printf("\nEndereco da variavel B: %p", &b);
	printf("\nEndereco da variavel C: %p", &c);
	
	puts("\n\nValor dos Ponteiros em Decimal: ");
	printf("\nEndereco da variavel A: %d", &a);
	printf("\nEndereco da variavel B: %d", &b);
	printf("\nEndereco da variavel C: %d", &c);
	
	puts("\n\nVariaveis do tipo Char: ");
	printf("\nValor de C1: %c", c1);
	printf("\nValor de C2: %c", c2);
	printf("\nValor de C3: %c", c3);
	
	puts("\n\nValor dos Ponteiros em hexadecimal: ");
	printf("\nEndereco da variavel C1: %p", &c1);
	printf("\nEndereco da variavel C2: %p", &c2);
	printf("\nEndereco da variavel C3: %p", &c3);
	
	puts("\n\nValor dos Ponteiros em Decimal: ");
	printf("\nEndereco da variavel C1: %d", &c1);
	printf("\nEndereco da variavel C2: %d", &c2);
	printf("\nEndereco da variavel C3: %d", &c3);
	
}//fim do programa

