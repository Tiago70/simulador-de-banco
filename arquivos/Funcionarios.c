#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funcionarios.h"

struct conta_f
{
	char codigo_f[6], cargo_f[25], nome_f[25], cpf_f[16], data_nascimento_f[12], telefone_f[15];
	char endereco_f[27], cep_f[16], cidade_f[25], estado_f[25], senha_f[27];
};


void receber_texto(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]) // colocar um limitador na função
{
	char entrada, nome[25];
	int contador1 = 0, contador2 = 0, contador3 = 0;
	while (1)
	{
		entrada = getch();
		if ((isalpha(entrada) || entrada == ' ') && contador1 < tamanho_max) // verifica se o digito digitado é uma letra
		{
			if (entrada == ' ' && !contador3) // evita do usuario digitar muitos espaços
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3++;
			}
			else if (entrada != ' ') // guarda o valor se tudo estiver de acordo
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3 = 0;
			}
		}
		else if ((contador1 == tamanho_max && !contador2) && isalpha(entrada))
		{
			printf("  Tamanho maximo atingido!");
			sleep(2);
			int i;
			for (i = 0; i <= 25; i++)
				printf("\b \b");
			contador2++;
		}
		if (entrada == '\b' && contador1 > 0) // apaga o digito quando o backspace é precionado
		{
			if (nome[contador1 - 1] == ' ')
			{
				contador3 = 0;
			}
			printf("\b \b");
			contador2 = 0;
			contador1--;
		}
		else if (entrada == '\r' && contador1 >= tamanho_min) // finaliza a entrada de dados
			break;
		else if (entrada == '\r' && contador1 < tamanho_min) // exibe uma mensagem quando o nome é muito curto
		{
			if (!contador2)
			{
				char tamanho[2];
				printf(" %s muito curto, minimo de %d caracteres", nomeDo_dado, tamanho_min);
				sprintf(tamanho, "%d", tamanho_min);
				sleep(2);
				int i;
				for (i = 0; i <= 35 + strlen(tamanho) + strlen(nomeDo_dado); i++)
					printf("\b \b");
				contador2 = 1;
			}
		}
	}
	nome[contador1] = '\0';
	strcpy(dado, nome);
}

void receber_texto_numero(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]) // colocar um limitador na função
{
	char entrada, nome[25];
	int contador1 = 0, contador2 = 0, contador3 = 0;
	while (1)
	{
		entrada = getch();
		if ((entrada == ' ' || isalnum(entrada)) && contador1 < tamanho_max) // verifica se o digito digitado é uma letra
		{
			if (entrada == ' ' && !contador3) // evita do usuario digitar muitos espaços
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3++;
			}
			else if (entrada != ' ') // guarda o valor se tudo estiver de acordo
			{
				printf("%c", entrada);
				nome[contador1] = entrada;
				contador1++;
				contador3 = 0;
			}
		}
		else if ((contador1 == tamanho_max && !contador2) && isalnum(entrada))
		{
			printf("  Tamanho maximo atingido!");
			sleep(2);
			int i;
			for (i = 0; i <= 25; i++)
				printf("\b \b");
			contador2++;
		}
		if (entrada == '\b' && contador1 > 0) // apaga o digito quando o backspace é precionado
		{
			if (nome[contador1 - 1] == ' ')
			{
				contador3 = 0;
			}
			printf("\b \b");
			contador2 = 0;
			contador1--;
		}
		else if (entrada == '\r' && contador1 >= tamanho_min) // finaliza a entrada de dados
			break;
		else if (entrada == '\r' && contador1 < tamanho_min) // exibe uma mensagem quando o nome é muito curto
		{
			if (!contador2)
			{
				char tamanho[2];
				printf(" %s muito curto, minimo de %d caracteres", nomeDo_dado, tamanho_min);
				sprintf(tamanho, "%d", tamanho_min);
				sleep(2);
				int i;
				for (i = 0; i <= 35 + strlen(tamanho) + strlen(nomeDo_dado); i++)
					printf("\b \b");
				contador2 = 1;
			}
		}
	}
	nome[contador1] = '\0';
	strcpy(dado, nome);
}

void receber_numeros(int tamanho, char numeros[20])
{
	char entrada;
	int contador1 = 0;

	while (contador1 < tamanho)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			numeros[contador1] = entrada;
			printf("%c", entrada);
			contador1++;
		}
		else if (entrada == '\b' && contador1 > 0)
		{
			printf("\b \b");
			contador1--;
		}
	}
	numeros[contador1] = '\0';
}

void receber_telefone(char numero[13])
{
	char entrada;
	int contador = 0;

	while (contador < 13)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			numero[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 3)
			{
				printf("\b %c", entrada);
				numero[contador - 1] = ' ';
				numero[contador] = entrada;
				contador++;
			}
			if (contador == 9)
			{
				printf("\b-%c", entrada);
				numero[contador - 1] = '-';
				numero[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 4 || contador == 9)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	numero[13] = '\0';
}

void receber_cpf(char cpf[14])
{
	char entrada;
	int contador = 0;

	while (contador < 14)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			cpf[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 4 || contador == 8)
			{
				printf("\b.%c", entrada);
				cpf[contador - 1] = '.';
				cpf[contador] = entrada;
				contador++;
			}
			if (contador == 12)
			{
				printf("\b-%c", entrada);
				cpf[contador - 1] = '-';
				cpf[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 5 || contador == 9 || contador == 13)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	cpf[14] = '\0';
}

void receber_cep(char cep[9])
{
	char entrada;
	int contador = 0;

	while (contador < 9)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			cep[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 6)
			{
				printf("\b-%c", entrada);
				cep[contador - 1] = '-';
				cep[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 7)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	cep[9] = '\0';
}

void receber_data(char data[10])
{
	char entrada;
	int contador = 0;

	while (contador < 10)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			data[contador] = entrada;
			printf("%c", entrada);
			contador++;
			if (contador == 3 || contador == 6)
			{
				printf("\b/%c", entrada);
				data[contador - 1] = '/';
				data[contador] = entrada;
				contador++;
			}
		}
		else if (entrada == '\b' && contador > 0)
		{
			if (contador == 4 || contador == 7)
			{
				printf("\b \b");
				contador--;
			}
			printf("\b \b");
			contador--;
		}
	}
	data[10] = '\0';
}

void recebe_dados(FILE *arquivo_cliente, int tipo_conta)
{
	system("cls");
	titulo("COLOQUE SEUS DADOS");
	struct conta conta_temp;
	size_t tamanho;
	//	pede as informações da conta poupança
	printf("\t1 - AGENCIA (4 digitos): ");
	receber_numeros(4, conta_temp.agencia);

	printf("\n\n\t2 - NUMERO DA CONTA (8 digitos): ");
	receber_numeros(8, conta_temp.numero_da_conta);

	printf("\n\n\t3 - NOME: ");
	receber_texto(3, 40, "Nome", conta_temp.nome);

	printf("\n\n\t4 - CPF: ");
	receber_cpf(conta_temp.cpf);

	printf("\n\n\t5 - DATA DE NASCIMENTO: ");
	receber_data(conta_temp.data_nascimento);

	printf("\n\n\t6 - TELEFONE DE CONTATO: ");
	receber_telefone(conta_temp.telefone);

	printf("\n\n\t7 - ENDERECO: ");
	receber_texto_numero(8, 25, "Endereco", conta_temp.endereco);

	printf("\n\n\t8 - CEP: ");
	receber_cep(conta_temp.cep);

	printf("\n\n\t9 - CIDADE: ");
	receber_texto(3, 25, "Cidade", conta_temp.cidade);

	printf("\n\n\t10 - ESTADO: ");
	receber_texto(2, 25, "Estado", conta_temp.estado);

	if (tipo_conta == 2)
	{
		printf("\n\n\t11 - SALDO DA CONTA: ");
		scanf("%f", &conta_temp.saldo);

		printf("\n\t12 - DATA DE VENCIMENTO: ");
		receber_data(conta_temp.data_vencimento);
		conta_temp.tipo = 2;
	}
	else
	{
		conta_temp.tipo = 1;
		conta_temp.saldo = 0.0;
		conta_temp.saldo = 0;
	}
	printf("\n\n\t14 - SENHA DO CLIENTE: ");
	receber_texto_numero(8, 12, "Senha", conta_temp.senha_cliente);

	fseek(arquivo_cliente, 0, SEEK_END);
	if (fwrite(&conta_temp, sizeof(conta_temp), 1, arquivo_cliente))
	{
		printf("\n\n\tConta cadastrada com sucesso!\n");
	}
	else
	{
		printf("Erro ao cadastrar o usuario!");
		fclose(arquivo_cliente);
		exit(1);
	}
	rewind(arquivo_cliente);
	system("pause");
}

void abrir_conta(FILE *arquivo_cliente)
{
	char menu_f;
	do
	{
		system("cls");
		titulo("ESCOLHA O TIPO DA CONTA");
		printf("\t1 - Conta poupanca - CP \n\t2 - Conta corrente - CC \n\t3 - voltar");
		printf("\n\n\tEscolha uma opcao: ");

		menu_f = getch();
		switch (menu_f)
		{
		case '1':
			recebe_dados(arquivo_cliente, 1);
			break;
		case '2':
			recebe_dados(arquivo_cliente, 2);
			break;
		case '3':
			break;
		}
	} while (menu_f != '3');
}

void excluir_conta(char ADM[], FILE *arquivo_cliente)
{
	system("cls");
	printf("\tDigite a senha de administrador: ");
	if (!autenticar(ADM))
		return;
	system("cls");
	titulo("ENCERRAR CONTA");
	const char nome_antigo[] = "dados cliente.txt";
	const char nome_novo[] = "dados cliente temporario.txt";

	FILE *arquivo_cliente_temp = fopen(nome_novo, "w+");
	if (arquivo_cliente_temp == NULL)
	{
		printf("Ocorrreu um erro ao abrir os arquivos");
		exit(5);
	}
	struct conta conta_analisada;
	char codigo_cliente[10];
	int encontrado = 0;

	printf("\tDigite o numero da conta para encerramento (8 digitos): ");
	receber_numeros(8, codigo_cliente);

	fseek(arquivo_cliente, 0, SEEK_SET);
	while (fread(&conta_analisada, sizeof(conta_analisada), 1, arquivo_cliente))
	{
		if (strcmp(codigo_cliente, conta_analisada.numero_da_conta))
		{
			fseek(arquivo_cliente_temp, 0, SEEK_END);
			fwrite(&conta_analisada, sizeof(conta_analisada), 1, arquivo_cliente_temp);
		}
		else
			encontrado = 1;
	}
	if (encontrado)
	{
		fclose(arquivo_cliente_temp);
		fclose(arquivo_cliente);
		remove(nome_antigo);
		rename(nome_novo, nome_antigo);

		arquivo_cliente = fopen("dados cliente.txt", "r+");
		printf("\n\n\tConta encerrada com sucesso!\n");
	}
	else
	{
		fclose(arquivo_cliente_temp);
		remove(nome_novo);
		printf("\n\n\tNao foram encontrados clientes com esse numero\n");
	}
	system("pause");
}

void consultar_dados(FILE *arquivo_cliente, FILE *arquivo_funcionario)
{
	char menu_f;
	struct conta conta_cliente;
	struct conta_f conta_funcionario;

	do
	{
		system("cls");
		titulo("CONSULTE SUAS CONTAS CADASTRADAS");
		printf("\t1 - Consultar dados da conta \n\t2 - Consultar funcionario \n\t3 - Consultar cliente \n\t4 - Sair");
		printf("\n\n\tEscolha uma das opcoes: ");

		menu_f = getch();
		switch (menu_f)
		{
		case '1':
			system("cls");
			titulo("DADOS DAS CONTAS");
			fseek(arquivo_cliente, 0, SEEK_SET);
			if (fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente) < 1)
				printf("\tNao ha clientes cadatrados!\n\n");
			else
			{
				fseek(arquivo_cliente, 0, SEEK_SET);
				while (fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente))
				{
					if (conta_cliente.tipo == 1)
					{
						printf("\tTipo da conta: Conta poupanca \n\tNome do cliente: %s \n\tCPF do cliente: %s \n\tSaldo da conta: %.2f\n\tNumero da conta: %s \n\n", conta_cliente.nome, conta_cliente.cpf, conta_cliente.saldo, conta_cliente.numero_da_conta);
					}
					else
					{
						printf("\tTipo da conta: Conta corrente  \n\tNome do cliente: %s \n\tCPF do cliente: %s \n\tSaldo da conta: %.2f \n\tNumero da conta: %s  \n\tData de vencimento: %s\n\n", conta_cliente.nome, conta_cliente.cpf, conta_cliente.saldo, conta_cliente.numero_da_conta, conta_cliente.data_vencimento);
					}
				}
			}
			system("pause");
			break;

		case '2':
			system("cls");
			titulo("DADOS DOS FUNCIONARIOS");
			fseek(arquivo_funcionario, 0, SEEK_SET);
			if (fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario) < 1)
				printf("\tNao ha funcionarios cadatrados!\n\n");
			else
			{
				fseek(arquivo_funcionario, 0, SEEK_SET);
				while (fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario))
				{
					printf("\tCODIGO: %s \n\tCARGO: %s \n\tNOME: %s \n\tCPF: %s \n\tDATA DE NASCIMENTO: %s \n\tTELEFONE:  %s\n\t", conta_funcionario.codigo_f, conta_funcionario.cargo_f, conta_funcionario.nome_f, conta_funcionario.cpf_f, conta_funcionario.data_nascimento_f, conta_funcionario.telefone_f);
					printf("ENDERECO: %s \n\tCEP: %s \n\tCIDADE: %s \n\tESTADO: %s\n\n", conta_funcionario.endereco_f, conta_funcionario.cep_f, conta_funcionario.cidade_f, conta_funcionario.estado_f);
				}
			}
			system("pause");
			break;

		case '3':
			system("cls");
			titulo("DADOS DOS CLIENTES CADASTRADOS");
			fseek(arquivo_cliente, 0, SEEK_SET);
			if (fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente) < 1)
				printf("\tNao ha clientes cadatrados!\n\n");
			else
			{
				fseek(arquivo_cliente, 0, SEEK_SET);
				while (fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente))
				{
					printf("\tNOME DO CLIENTE: %s \n\tCPF DO CLIENTE: %s \n\tDATA DE NASCIMENTO: %s \n\tTELEFONE: %s \n\tENDERECO: %s \n", conta_cliente.nome, conta_cliente.cpf, conta_cliente.data_nascimento, conta_cliente.telefone, conta_cliente.endereco);
					printf("\tCEP: %s \n\tCIDADE: %s \n\tESTADO: %s \n\n", conta_cliente.cep, conta_cliente.cidade, conta_cliente.estado);
				}
			}
			system("pause");
			break;

		case '4':
			break;
		}
	} while (menu_f != '4');
}

int escolher_conta(FILE *arquivo, int tipo, int *contadorDe_contas)
{
	struct conta conta_cliente;
	struct conta_f conta_funcionario;
	int contador = -1, contador2;
	char escolha[4], tamanho_max[4], entrada;

	fseek(arquivo, 0, SEEK_SET);
	if (tipo)
	{
		while (fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo))
		{
			contador++;
			printf("\tNome %d: %s\n\n", contador + 1, conta_cliente.nome);
		}
		printf("\n\tEscolha o cliente que deseja modificar (coloque o numero das opcoes): ");
	}
	else
	{
		while (fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo))
		{
			contador++;
			printf("\tNome %d: %s\n\n", contador + 1, conta_funcionario.nome_f);
		}
		printf("\n\tEscolha o funcionario que deseja modificar (coloque o numero das opcoes): ");
	}
	sprintf(tamanho_max, "%d", contador + 1);
	*contadorDe_contas = contador;
	contador = 0;
	while (1)
	{
		if (tamanho_max[contador] != '\0')
			contador++;
		else
			break;
	}
	contador2 = contador;
	contador = 0;
	while (contador < contador2)
	{
		entrada = getch();
		if (isdigit(entrada))
		{
			escolha[contador] = entrada;
			printf("%c", entrada);
			contador++;
		}
		else if (entrada == '\b' && contador > 0)
		{
			printf("\b \b");
			contador--;
		}
		else if (entrada == '\r' && contador > 0)
			break;
	}
	contador = atoi(escolha);
	return contador;
}

void escreverNo_arquivo(FILE *arquivo, int tipo, struct conta *conta_cliente, struct conta_f *conta_funcionario)
{	
	if (tipo)
	{
		if (fwrite(conta_cliente, sizeof(*conta_cliente), 1, arquivo))
			printf("\n\tAlterado com sucesso!");
		
		else
			printf("\n\tOcorreu um erro ao realizar a alteracao");
	}
	else
	{
		if (fwrite(conta_funcionario, sizeof(*conta_funcionario), 1, arquivo)){ //revisar isso aqui
			printf("\tCODIGO: %s \n\tCARGO: %s \n\tNOME: %s \n\tCPF: %s \n\tDATA DE NASCIMENTO: %s \n\tTELEFONE:  %s\n\t", conta_funcionario->codigo_f, conta_funcionario->cargo_f, conta_funcionario->nome_f, conta_funcionario->cpf_f, conta_funcionario->data_nascimento_f, conta_funcionario->telefone_f);
			printf("ENDERECO: %s \n\tCEP: %s \n\tCIDADE: %s \n\tESTADO: %s\n\n", conta_funcionario->endereco_f, conta_funcionario->cep_f, conta_funcionario->cidade_f, conta_funcionario->estado_f);
			system("pause");
			printf("\n\tAlterado com sucesso");

		}
		else
			printf("\n\tOcorreu um erro ao realizar a alteracao");
	}
	sleep(2);
}

void alterar_dados(char ADM[], FILE *arquivo_cliente, FILE *arquivo_funcionario)
{
	system("cls");
	struct conta conta_cliente;
	struct conta_f conta_funcionario;
	char menu_f;
	int contador, escolha;

	do
	{
		system("cls");
		titulo("ESCOLHA A CONTA QUE DESEJA ALTERAR");
		printf("\t1 - Alterar dados da conta (cliente) \n\t2 - Alterar dados de funcionarios \n\t3 - Alterar dados de clientes \n\t4 - Voltar");
		printf("\n\n\tEscolha a opcao desejada: ");

		menu_f = getch();
		switch (menu_f)
		{
		case '1':
			system("cls");
			fseek(arquivo_cliente, 0, SEEK_SET);
			titulo("CONTAS DISPONIVEIS");
			escolha = escolher_conta(arquivo_cliente, 1, &contador);

			if (escolha > contador + 1 || escolha < 1)
			{
				printf("\n\n\tOpcao invalida");
				sleep(1);
			}
			else
			{
				system("cls");
				escolha--;
				fseek(arquivo_cliente, 0, SEEK_SET);
				fseek(arquivo_cliente, sizeof(conta_cliente) * escolha, SEEK_SET);
				fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente);
				fseek(arquivo_cliente, -sizeof(conta_cliente), SEEK_CUR);

				titulo("ESCOLHA O QUE DESEJA ALTERAR");
				printf("\n\n\t1 - TIPO DE CONTA \n\t2 - saldo DISPONiVEL \n\t3 - DATA DE VENCIMENTO");
				printf("\n\tColoque o numero referente a escolha: ");

				menu_f = getch();
				switch (menu_f)
				{
				case '1':
					system("cls");
					titulo("ALTERAR TIPO DA CONTA");
					if (conta_cliente.tipo == 1)
					{
						printf("\tAlterado para conta corrente");
						conta_cliente.tipo = 2;
					}
					else
					{
						printf("Alterado para conta poupanca");
						conta_cliente.tipo = 1;
					}
					sleep(2);
					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				case '2':
					system("cls");
					titulo("ALTERAR SALDO");
					printf("\tColoque o novo saldo: ");
					fflush(stdin);
					scanf("%f", &conta_cliente.saldo);

					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				case '3':
					system("cls");
					titulo("ALTERAR DATA DE VENCIMENTO");
					printf("Coloque a nova data de vencimento: ");
					receber_data(conta_cliente.data_vencimento);

					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				default:
					printf("\nOpcao invalida\n");
					break;
				}
			}
			break;
		case '2':
			system("cls");
			contador = -1;
			fseek(arquivo_funcionario, 0, SEEK_SET);
			titulo("CONTAS DISPONIVEIS");
			escolha = escolher_conta(arquivo_funcionario, 0, &contador);

			if (escolha > contador + 1 || escolha < 1)
			{
				printf("\n\n\tOpcao invalida");
				sleep(2);
			}
			else
			{
				system("cls");
				escolha--;
				fseek(arquivo_funcionario, 0, SEEK_SET);
				fseek(arquivo_funcionario, sizeof(conta_funcionario) * escolha, SEEK_SET);
				fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario);
				fseek(arquivo_funcionario, -sizeof(conta_funcionario), SEEK_CUR);

				titulo("ESCOLHA O DADO QUE DESEJA ALTERAR");
				printf("\t1 - CODIGO DO FUNCIONARIO \n\t2 - CARGO \n\t3 - TELEFONE \n\t4 - ENDERECO \n\t5 - CEP \n\t6 - BAIRRO \n\t7 - CIDADE \n\t8 - ESTADO\n\n");
				printf("Coloque o numero correspondente: ");
				menu_f = getch();
				system("cls");
				switch (menu_f)
				{
				case '1':
					printf("\tColoque o novo codigo do funcionario: ");
					receber_numeros(4, conta_funcionario.codigo_f);

					escreverNo_arquivo(arquivo_funcionario, 0, &conta_cliente, &conta_funcionario);
					break;

				case '2':
					printf("\tColoque o novo cargo do funcionario: ");
					receber_texto(2, 23, "Cargo", conta_funcionario.cargo_f);

					escreverNo_arquivo(arquivo_funcionario, 0, &conta_cliente, &conta_funcionario);
					break;

				case '3':
					printf("\tColoque o novo telefone do funcionario: ");
					receber_telefone(conta_funcionario.telefone_f);

					escreverNo_arquivo(arquivo_funcionario, 0, &conta_cliente, &conta_funcionario);
					break;

				case '4':
					printf("\tColoque o novo endereco do funcionario: ");
					receber_texto_numero(8, 25, "Endereco", conta_funcionario.endereco_f);

					escreverNo_arquivo(arquivo_funcionario, 0, &conta_cliente, &conta_funcionario);
					break;

				case '5':
					printf("\tColoque o novo CEP do funcionario: ");
					receber_cep(conta_funcionario.cep_f);

					escreverNo_arquivo(arquivo_funcionario, 0, &conta_cliente, &conta_funcionario);
					break;

				case '6':
					printf("Coloque a nova cidade do funcionario: ");
					receber_texto(2, 25, "Cidade", conta_funcionario.cidade_f);

					escreverNo_arquivo(arquivo_funcionario, 0, &conta_cliente, &conta_funcionario);
					break;

				case '7':
					printf("\tColoque o novo estado do funcionario: ");
					receber_texto(2, 25, "Estado", conta_funcionario.estado_f);

					escreverNo_arquivo(arquivo_funcionario, 0, &conta_cliente, &conta_funcionario);
					break;

				default:
					printf("\nOpcao invalida\n");
					break;
				}
			}
			break;
		case '3':
			system("cls");
			titulo("CONTAS DISPONIVEIS");
			escolha = escolher_conta(arquivo_cliente, 1, &contador);

			if (escolha > contador + 1 || escolha < 1)
			{
				printf("Opcao invalida");
				sleep(1);
			}
			else
			{
				system("cls");
				escolha--;
				fseek(arquivo_cliente, 0, SEEK_SET);
				fseek(arquivo_cliente, sizeof(conta_cliente) * escolha, SEEK_SET);
				fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente);
				fseek(arquivo_cliente, -sizeof(conta_cliente), SEEK_CUR);

				titulo("ESCOLHA O QUE DESEJA ALTERAR");
				printf("\n\n\t1 - TELEFONE \n\t2 - ENDERECO \n\t3 - CEP \n\t4 - CIDADE \n\t5 - ESTADO\n");
				printf("\n\tColoque o numero referente a escolha: ");

				menu_f = getch();
				system("cls");
				switch (menu_f)
				{
				case '1':
					printf("Coloque o novo numero de telefone: ");
					receber_telefone(conta_cliente.telefone);

					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				case '2':
					printf("Coloque o novo endereco: ");
					receber_texto_numero(8, 25, "Endereco", conta_cliente.endereco);

					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				case '3':
					printf("Coloque o novo CEP: ");
					receber_cep(conta_cliente.cep);

					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				case '4':
					printf("\nColoque a nova cidade: ");
					receber_texto(3, 25, "Cidade", conta_cliente.cidade);

					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				case '5':
					printf("Coloque o novo estado: ");
					receber_texto(2, 25, "Estado", conta_cliente.estado);

					escreverNo_arquivo(arquivo_cliente, 1, &conta_cliente, &conta_funcionario);
					break;

				default:
					printf("\nOpcao invalida\n");
					break;
				}
			}
			break;
		case '4':
			break;
		}
	} while (menu_f != '4');
}

void cadastrar_funcionario(char ADM[], FILE *arquivo_funcionario)
{
	system("cls");
	printf("\tDigite a senha de administrador: ");
	if (!autenticar(ADM))
		return;
	system("cls");
	struct conta_f conta_temp_f;

	titulo("CADASTRAR FUNCIONARIO");
	printf("\t1 - CODIGO (4 digitos): ");
	receber_numeros(4, conta_temp_f.codigo_f);

	printf("\n\n\t2 - CARGO: ");
	receber_texto(2, 23, "Cargo", conta_temp_f.cargo_f);

	printf("\n\n\t5 - NOME: ");
	receber_texto(3, 18, "Nome", conta_temp_f.nome_f);

	printf("\n\n\t6 - CPF: ");
	receber_cpf(conta_temp_f.cpf_f);

	printf("\n\n\t7 - DATA DE NASCIMENTO: ");
	receber_data(conta_temp_f.data_nascimento_f);

	printf("\n\n\t8 - TELEFONE DE CONTATO: ");
	receber_telefone(conta_temp_f.telefone_f);

	printf("\n\n\t9 - ENDERECO DO FUNCIONARIO: ");
	receber_texto_numero(8, 25, "Endereco", conta_temp_f.endereco_f);

	printf("\n\n\t10 - CEP: ");
	receber_cep(conta_temp_f.cep_f);

	printf("\n\n\t14 - CIDADE:  ");
	receber_texto(2, 25, "Cidade", conta_temp_f.cidade_f);

	printf("\n\n\t15 - ESTADO:  ");
	receber_texto(2, 25, "Estado", conta_temp_f.estado_f);

	printf("\n\n\t16 - SENHA DO FUNCIONARIO: ");
	receber_texto_numero(8, 25, "Password", conta_temp_f.senha_f);

	fseek(arquivo_funcionario, 0, SEEK_END);
	if (fwrite(&conta_temp_f, sizeof(conta_temp_f), 1, arquivo_funcionario))
		printf("\n\n\tConta cadastrada com sucesso!\n");
	else
	{
		printf("\n\n\tErro ao cadastrar o Funcionario!\n");
		fclose(arquivo_funcionario);
		exit(1);
	}
	rewind(arquivo_funcionario);
	system("pause");
}