/*******************************************************************************
    Nome: caixaEconomico.c
    Autor: Giovana Isis Ferreira da Silva
    Data: 18/03/2025 - 21:51
    Descrição: Programa para realizar recursividade INDIRETA para
               funcionalidades de um caixa eletrônico.
*******************************************************************************/

#include <stdio.h>

// Sessão de prototipação
int verNumeroConta(int);
int verSenha(int);
void depositar();
void verSaldo();
void realizarSaque();
void linha();

int numeroConta = 54321;
int senha = 123;
int opcao = 0;
float saldo = 3000;
int tentativa = 0;


int main() {
    puts("Caixa Eletrônico\n");
    linha();

    do {
        puts("O que deseja fazer hoje?\n");
        puts("1 - Ver saldo disponível");
        puts("2 - Realizar saque");
        puts("3 - Depositar");
        puts("0 - Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            case 2:
            case 3:
                linha();
                verNumeroConta(opcao);
                break;
            case 0:
                linha();
                puts("Saindo do programa!");
                linha();
                break;
            default:
                puts("Opção inválida! Tente novamente.");
                linha();
        }
    } while (opcao != 0);

    return 0;
}

// Função para verificar número da conta
int verNumeroConta(int opcao) {
    if (tentativa >= 3) {
        puts("Acesso bloqueado! Entre em contato com a central de atendimento.");
        return 0;
    }

    int numConta;
    printf("Digite o número da conta: ");
    scanf("%d", &numConta);

    if (numConta == numeroConta) {
        tentativa = 0;
        return verSenha(opcao);
    } else {
        puts("Número de conta inválido.");
        tentativa++;
        return verNumeroConta(opcao);
    }
}

// Função para verificar senha
int verSenha(int opcao) {
    if (tentativa >= 3) {
        puts("Acesso bloqueado! Entre em contato com a central de atendimento.");
        return 0;
    }

    int pwd;
    printf("Digite a senha da conta: ");
    scanf("%d", &pwd);

    if (pwd == senha) {
        tentativa = 0; // Reseta a contagem de tentativas ao acertar a senha

        // Chama a função correspondente à opção selecionada
        switch (opcao) {
            case 1:
                verSaldo();
                break;
            case 2:
                realizarSaque();
                break;
            case 3:
                depositar();
                break;
        }
        return 1;
    } else {
        puts("Senha inválida.");
        tentativa++;
        return verSenha(opcao);
    }
}

// Função para exibir o saldo
void verSaldo() {
    printf("Saldo atual: R$%.2f\n", saldo);
}

// Função para realizar saque
void realizarSaque() {
    float valor;
    printf("Valor para sacar: R$");
    scanf("%f", &valor);

    if (valor <= 0) {
        puts("Valor inválido! Digite um valor maior que zero.");
        realizarSaque();
    } else if (valor > saldo) {
        puts("Saldo insuficiente!");
        realizarSaque();
    } else {
        saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso!\n", valor);
    }
}

// Função para depositar dinheiro
void depositar() {
    float valor;
    printf("Valor para depositar: R$");
    scanf("%f", &valor);

    if (valor <= 0) {
        puts("Valor inválido! Digite um valor maior que zero.");
        depositar();
    } else {
        saldo += valor;
        printf("Depósito de R$%.2f realizado com sucesso!\n", valor);
    }
}

// Função para exibir uma linha
void linha() {
    puts("\n-------------------------------------\n");
}
