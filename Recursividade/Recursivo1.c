/*
  Name: Recursivo1.c
  Author: Giovana Isis Silva
  Date: 26/02/25 09:49
  Description: Programa para demonstrar a utiliza��o do conceito de Recursividade
*/

#include <stdio.h> //STanDard Input Output

//Sess�o de prototipa��o
void imprimir(int);
int lerNum();

int main()
{
    puts("Iniciando a chamada recursiva");
    //imprimir(0);
    lerNum();
    puts("FIM - Voce digitou 99 para finalizar a recursao.");


    //S� executa ap�s o fim da fun��o recursiva
    float alt = 0.0;
    printf("\nDigite sua altura: ");
    scanf("%f", &alt);

    if(alt <= 1.70)
    {
        puts("Individuo Baixo.");
    }
    else
    {
        puts("Individuo Alto");
    }

} //Fim do programa


//Sess�o de fun��es:
void imprimir(int x)
{
    if(x == 10) //condi��o de sa�da
    {
        return; /*retorna para quem chamou ap�s atingir a condi��o. Ou seja, se x for
                  igual a 10, para de imprimir e vai para a pr�xima linha da fun��o.*/
    }

    printf("%d ", x);

    imprimir(x+1); //invoca a chamada � fun��o de maneira recursiva, pode usar ++x

    printf("\nFim da %d� chamada: ", x); //Aguarda o return e s� � executada ap�s o fim da chamada recursiva, quando � desempilhada;
}

int lerNum()
{
    int num = 0;
    printf("\n\nDigite um numero: ");
    scanf("%d", &num);

    if(num == 99)
    {
        return num; //retorna 99 para o main
    }

    printf("\nNumero digitado: %d", num);
    lerNum();
    puts("Voc� digitou 99 para finalizar a recurs�o.");


}
