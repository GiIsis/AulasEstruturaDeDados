/*
  Name: PosNeg.c
  Author: Giovana Isis Silva
  Date: 26/02/25 12:03
  Description: Programa para ler um número inteiro positivo e exibir
               uma contagem regressiva até o seu equivalente negativo.
*/

# include <stdio.h>
//Sessão de prototipação
void regressiva(int, int);

int main()
{
    int num = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d",&num);
    regressiva(num, num);

}//fim do Programa

void regressiva(int num, int limite)
{
    printf("%d, ", num);
    if ( num == -limite)
    {
        return;
    }
    regressiva(num-1, limite);
}

