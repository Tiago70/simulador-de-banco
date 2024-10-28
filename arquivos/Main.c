#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Funcionarios.h"
#include "cliente.h"
#include <ctype.h>

void titulo(char texto[30]) // escreve o titulo de uma forma facil e adaptÃ¡vel
{	
	int i;
	printf("\t");
	for (i = 0; i < (strlen(texto) / 2 + 16); i++)
		printf("\\\\");
	printf("\n\n\t\t\t%s\n\n", texto);
	printf("\t");
	for (i = 0; i < strlen(texto) / 2 + 16; i++)
		printf("\\\\");
	printf("\n\n");
}

void menu_funcionario(FILE *arquivo_cliente, FILE *arquivo_funcionario)
{
	char menu_f;
	do
	{
		system("cls");
		titulo("MENU FUNCIONARIO");
		printf("\t\t1 - Abetura de conta \n\t\t2 - Encerramento de conta \n\t\t3 - Consultar dados \n\t\t4 - Alterar dados");
		printf("\n\t\t5 - Cadastro de Funcionarios \n\t\t6 - Sair");
		printf("\n\n\t\tEscolha uma opcao: ");

		menu_f = getch();
		switch (menu_f)
		{
		case '1':
			abrir_conta(arquivo_cliente);
			break;
		case '2':
			excluir_conta(ADM, arquivo_cliente);
			break;
		case '3':
			consultar_dados(arquivo_cliente, arquivo_funcionario);
			break;
		case '4':
			alterar_dados(ADM, arquivo_cliente, arquivo_funcionario);
			break;
		case '5':
			cadastrar_funcionario(ADM, arquivo_funcionario);
			break;
		case '6':
			break;
		default:
			printf("\n\nOpcaoo invalida!");
			break;
		}
	} while (menu_f != '6');
}

void menu_cliente(FILE *arquivo_cliente)
{
	char menu_c;
	do
	{
		system("cls");
		titulo("MENU CLIENTE");
		printf("\t\t1 - Consultar saldo \n\t\t2 - Deposito \n\t\t3 - Saque \n\t\t4 - Sair");
		printf("\n\nEscolha uma opcao: ");

		menu_c = getch();
		switch (menu_c)
		{
		case '1':
			saldo_cliente(arquivo_cliente);
			break;
		case '2':
			deposito_cliente(arquivo_cliente);
			break;
		case '3':
			saque_cliente(arquivo_cliente);
			break;
		case '4':
			break;
		default:
			printf("\n\nOpcaoo invalida. Tente novamente!");
			sleep(1);
			break;
		}
	} while (menu_c != '4');
}

int autenticar(char senha_padrao[10]) // verifica as senhas digitadas
{
	char entrada, senha[12];
	int contador1 = 0, contador2 = 0;
	while (1)
	{
		entrada = getch();
		if (isprint(entrada) && contador1 < 12)
		{
			printf("%c", entrada);
			senha[contador1] = entrada;
			contador1++;
		}
		else if (entrada == '\b' && contador1 > 0)
		{
			printf("\b \b");
			contador1--;
			if (contador2 != 0)
				contador2--;
		}
		else if (entrada == '\r')
			break;
		else if (contador1 != 0)
		{
			if (contador2 == 0)
			{
				printf("  Tamanho maximo atingido!");
				sleep(2);
				int i;
				for (i = 0; i <= 25; i++)
					printf("\b \b");
				contador2++;
			}
		}
	}
	senha[contador1] = '\0';
	if (!strcmp(senha_padrao, senha))
	{
		printf("\n\n\tBem Vindo!");
		sleep(1);
		return 1;
	}
	else
	{
		printf("\n\n\tSenha incorreta");
		sleep(2);
		return 0;
	}
}

int main()
{

	//	abre os arquivos e define a linguagem
	setlocale(LC_ALL, "Portuguese");

	FILE *arquivo_cliente, *arquivo_funcionario;
	arquivo_cliente = fopen("dados cliente.txt", "r+");
	arquivo_funcionario = fopen("dados funcionario.txt", "r+");

	if (arquivo_cliente == NULL)
	{
		arquivo_cliente = fopen("dados cliente.txt", "w+");
	}
	if (arquivo_funcionario == NULL)
	{
		arquivo_funcionario = fopen("dados funcionario.txt", "w+");
	}
	if (arquivo_cliente == NULL || arquivo_funcionario == NULL)
	{
		printf("Nao foi possivel abrir os arquivos");
		return 1;
	}

	char menu; // Menu principal
	int i;
	do
	{
		system("cls");
		titulo("BEM VINDO ESCOLHA UM OPCAO PARA ENTRAR");
		printf("\t\t1 - Funcionario \n\t\t2 - Cliente \n\t\t3 - Sair \n\n\t\tEscolha uma opcao: ");

		menu = getch();
		switch (menu)
		{

		case '1':
			system("cls"); 
			titulo("FUNCIONARIO"); 
			printf("\tColoque sua senha: ");
			if (autenticar(funcionario)) // verifica a senha do funcionÃ¡rio
			{	
				menu_funcionario(arquivo_cliente, arquivo_funcionario); // vai para o menu do funcionÃ¡rio
			}
			break;
		case '2':
			system("cls"); 
			titulo("CLIENTE");
			printf("\tColoque sua senha: ");
			if (autenticar(cliente)) // verifica a senha do cliente
			{
				menu_cliente(arquivo_cliente); // vai para o menu do cliente
			}
			break;
		case '3':
			printf("\n\n\tVolte sempre :)"); // finaliza o programa
			break;
		default:
			printf("\n\n\tOpcaoo invalida!\n\t");
			system("pause");
			break;
		}
	} while (menu != '3');

	return 0;
}
