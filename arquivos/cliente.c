#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "cliente.h"
#include "funcionarios.h"

void saldo_cliente(FILE *arquivo_cliente){
	char cpf[13],senha[15];
	int encontrado = 0;
    struct conta conta_temp;
    
    system("cls");
	titulo("CONSULTAR SALDO");
    printf("\tDigite o CPF do cliente: ");
    receber_cpf(cpf);
    
    fseek(arquivo_cliente, 0, SEEK_SET);
    while (fread(&conta_temp, sizeof(struct conta), 1, arquivo_cliente)) {

        if (!strcmp(cpf, conta_temp.cpf)) {
		    printf("\n\n\tDigite a senha do cliente para realizar a consulta: ");
		    receber_texto_numero(0, 12, "Senha", senha);
	
		    if (!strcmp(conta_temp.senha_cliente, senha)) {
		    	system("cls");
		    	titulo("CONSULTAR SALDO");
				
				encontrado = 1;
		        printf("\tNome: %s \n\tCPF: %s \n\tSaldo: %.2f\n\n", conta_temp.nome, conta_temp.cpf, conta_temp.saldo);
				system("pause");
			}
			else {
		    	printf("\n\n\tSenha incorreta!\n");
		    	sleep(1);
				return;
		    }
			break;
        }
    }
	if(!encontrado){
		printf("\n\n\tCliente nao encontrado\n\n");
		system("pause");
	}
}

void deposito_cliente(FILE *arquivo_cliente) {
	
    char cpf[13],senha[15];
	int encontrado = 0;
	double adicionar_saldo;
    struct conta conta_temp;
    
    system("cls");
	titulo("ADICONAR SALDO");
    printf("\tDigite o CPF do cliente: ");
    receber_cpf(cpf);
    
    fseek(arquivo_cliente, 0, SEEK_SET);
    while (fread(&conta_temp, sizeof(struct conta), 1, arquivo_cliente)) {

        if (!strcmp(cpf, conta_temp.cpf)) {
		    printf("\n\n\tDigite a senha do cliente para realizar a auteracao: ");
		    receber_texto_numero(0, 12, "Senha", senha);
	
		    if (!strcmp(conta_temp.senha_cliente, senha)) {
		    	system("cls");
		    	titulo("ADICIONAR SALDO");
				printf("Coloque o saldo a ser adicionado: ");
				scanf("%lf", &adicionar_saldo);

				if(adicionar_saldo <= 0 ){
					printf("\n\n\tEntrada invalida, coloque um saldo maior que zero\n");
					system("pause");
					return;
				}
				encontrado = 1;
				conta_temp.saldo += adicionar_saldo;
				fseek(arquivo_cliente, -sizeof(struct conta), SEEK_CUR);
				fwrite(&conta_temp, sizeof(struct conta), 1, arquivo_cliente);
				printf("\n\tCliente atualizado:");
		        printf("\n\tNome: %s \n\tCPF: %s \n\tNovo saldo: %.2f\n\n", conta_temp.nome, conta_temp.cpf, conta_temp.saldo);
				system("pause");
			}
			else {
		    	printf("\n\n\tSenha incorreta!\n");
		    	sleep(1);
				return;
		    }
			break;
        }
    }
	if(!encontrado){
		printf("\n\n\tCliente nao encontrado\n\n");
		system("pause");
	}
}
	
void saque_cliente(FILE *arquivo_cliente) {
		
	char cpf[13],senha[15];
	int encontrado = 0;
	double sacar_saldo;
    struct conta conta_temp;
    
    system("cls");
	titulo("SAQUE");
    printf("\tDigite o CPF do cliente: ");
    receber_cpf(cpf);
    
    fseek(arquivo_cliente, 0, SEEK_SET);
    while (fread(&conta_temp, sizeof(struct conta), 1, arquivo_cliente)) {

        if (!strcmp(cpf, conta_temp.cpf)) {
		    printf("\n\n\tDigite a senha do cliente para realizar O saque: ");
		    receber_texto_numero(0, 12, "Senha", senha);
	
		    if (!strcmp(conta_temp.senha_cliente, senha)) {
		    	system("cls");
		    	titulo("SAQUE");
				printf("Coloque o saldo a ser sacado: ");
				scanf("%lf", &sacar_saldo);

				if(sacar_saldo > conta_temp.saldo ){
					printf("\n\n\tErro: o valor do saque e maior que o saldo disponível\n");
					system("pause");
					return;
				}
				if(sacar_saldo < 0){
					sacar_saldo *= -1;
					return;
				}
				encontrado = 1;
				conta_temp.saldo -= sacar_saldo;
				fseek(arquivo_cliente, -sizeof(struct conta), SEEK_CUR);
				fwrite(&conta_temp, sizeof(struct conta), 1, arquivo_cliente);
				printf("\n\tCliente atualizado:");
		        printf("\n\tNome: %s \n\tCPF: %s \n\tNovo saldo: %.2f\n\n", conta_temp.nome, conta_temp.cpf, conta_temp.saldo);
				system("pause");
			}
			else {
		    	printf("\n\n\tSenha incorreta!\n");
		    	sleep(1);
				return;
		    }
			break;
        }
    }
	if(!encontrado){
		printf("\n\n\tCliente nao encontrado\n\n");
		system("pause");
	}
}