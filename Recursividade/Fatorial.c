/*
  Name: Fatorial.c
  Author: Giovana Isis Silva
  Date: 26/02/25 11:30
  Description: Programa para exibir o Fatorial de um número
               por meio de chamadas recursivas em função.
               Exemplo: 5! = 5 x 4 x 3 x 2 x 1 = 120
*/


#include <stdio.h>
int Fatorial(int);


int main()
{
    int num, result;
    num = result = 0;

    printf("Digite um numero inteiro para calcular seu fatorial: ");
    scanf("%d", &num);
    result = Fatorial(num);
    printf("\nO fatorial de %d = %d", num, result);

}//fim do programa


//Sessão de Funções:
int Fatorial(int x)
{
    if (x == 1)
    {
        return 1;
    }

    return x * Fatorial(x-1);
}
