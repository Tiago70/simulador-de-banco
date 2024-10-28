static char ADM[10] = "112233", funcionario[10] = "12345", cliente[10] = "54321"; // define as senhas internas para o acesso ao programa

struct conta
{
	char agencia[6], numero_da_conta[10], nome[45], cpf[16];
	char data_nascimento[12], telefone[15], endereco[27], cep[20];
	char cidade[27], estado[27], senha_cliente[27], data_vencimento[12];
	float saldo; // saldo da conta
	int tipo;	 // tipo da conta
};

void receber_texto(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]);

void receber_texto_numero(int tamanho_min, int tamanho_max, char nomeDo_dado[10], char dado[50]);

void receber_numeros(int tamanho, char numeros[20]);

void receber_telefone(char numero[13]);

void receber_cpf(char cpf[14]);

void receber_cep(char cep[9]);

void receber_data(char data[10]);

void abrir_conta( FILE *arquivo_cliente );

void excluir_conta_senha( char ADM[], FILE *arquivo_cliente );

void consultar_dados( FILE *arquivo_cliente, FILE *arquivo_funcionario);

void alterar_dados( char ADM[], FILE *arquivo_cliente,  FILE *arquivo_funcionario);

void cadastro_funcionario( FILE *arquivo_funcionari0, char ADM[] );
