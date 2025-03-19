/******************************************************************************

    Nome: loginSenha.c
    Autor: Giovana Isis Ferreira da Silva
    data: 12/03/2025    09:50
    Descrição: Programa para realizar recursividade INDIRETA para simular login
                                       em um sistema

*******************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Sessão de prototipação
void verLogin();
void verSenha();


char nome[20] = "Giovana";  //variáveis globais
int senha = 74393;
int contador = 0;

int main()
{
		puts("Realizar login no sistema \n");
		puts("========================= \n");
		verLogin();

}//fim do programa

void verLogin()
{
    fflush(stdin);
    char user[10] = " ";

    printf("login: ");
    gets(user);

    if(strcmp(user,nome) == 0){ // < 0 - a primeiro string possui um valor inferior à string2
        verSenha();             // = 0 - o conteúdo de ambas as sequências é igual
    }else{                      // > 0 - a primeiro string possui um valor maior que a string2
        verLogin();
    }
}                                                     *


void verSenha(){
    int pwd = 0;

    printf("Senha: ");
    scanf("%d", &pwd);

    if(pwd == senha){
        puts("Login efetuado com sucesso. Seja bem vindo(a)!!!");
    }else if(contador < 2){ //Tentativas máximas.
        puts("Senha incorreta! Tente novamente.");
        contador ++;
        verSenha();
     }else{
        verLogin();
    }
}
