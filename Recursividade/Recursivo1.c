/*
  Name: Recursivo1.c
  Author: Giovana Isis Silva
  Date: 26/02/25 09:49
  Description: Programa para demonstrar a utilização do conceito de Recursividade
*/

#include <stdio.h> //STanDard Input Output

//Sessão de prototipação
void imprimir(int);
int lerNum();

int main()
{
    puts("Iniciando a chamada recursiva");
    //imprimir(0);
    lerNum();
    puts("FIM - Voce digitou 99 para finalizar a recursao.");


    //Só executa após o fim da função recursiva
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


//Sessão de funções:
void imprimir(int x)
{
    if(x == 10) //condição de saída
    {
        return; /*retorna para quem chamou após atingir a condição. Ou seja, se x for
                  igual a 10, para de imprimir e vai para a próxima linha da função.*/
    }

    printf("%d ", x);

    imprimir(x+1); //invoca a chamada à função de maneira recursiva, pode usar ++x

    printf("\nFim da %dª chamada: ", x); //Aguarda o return e só é executada após o fim da chamada recursiva, quando é desempilhada;
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
    puts("Você digitou 99 para finalizar a recursão.");


}
