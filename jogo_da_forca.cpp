#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

const int TAMANHO_MAX_PALAVRA = 30;
const int TAMANHO_MAX_DICA = 255;
const int VALOR_DICA = 20;
const int VALOR_PALAVRA = 50;
const int VALOR_TENTATIVAS = 10;

enum Opcao
{
	JOGAR = 1,
	MOSTRAR_RANK = 2,
	CADASTRAR_PALAVRA = 3,
	MOSTRAR_CREDITOS = 4,
	SAIR = 5
};

enum Categoria
{
	ANIMAL = 1,
	COMIDA = 2,
	FRUTA = 3,
	PROFISSAO = 4,
	INFORMATICA = 5
};

/*Criando a struct */
typedef struct
{
	char palavra[TAMANHO_MAX_PALAVRA];
	char dica[TAMANHO_MAX_DICA];
	int categoria;
} PalavraSecreta;

/**
 * Declarações das funções em ordem alfabética
 */

/* Função que */
// Função.
void cadastrar_palavra(char *nome_arquivo, PalavraSecreta **array_palavras, int *tamanho_array);

/* Função que desenha a forca de acordo com o número total de tentativas restantes */
// A função recebe um inteiro que representa o número de tentativas restantes e
// imprime o desenho da forca de acordo com as tentativas.
void desenha_forca(int num_tentativas);

/*  */
//
void desenha_menu(void);

/*  */
//
void jogar(PalavraSecreta *palavras, int total_palavras);

/*  */
//
int ler_categoria(void);

/* Função que permite que usuário digite apenas um caractere no console para entrada de dados */
// Função solicita um caractere ao usuário e caso seja informado mais de um caractere, solicita
// que o usuário digite novamente. Retorna o caractere.
char ler_letra(void);

/* Função que */
// Função.
void ler_nome(char *nome, int tamanho_maximo);

/* Função que */
// Função.
const char *ler_nome_categoria(int categoria);

/* Função que solicita opção de menu */
// Função solicita uma das opções válidas do menu ao usuário e caso seja informado uma opção inválida
// solicita novamente uma opção válida.
int ler_opcao_menu(void);

/* Função que */
// Função.
void ler_palavras(char *nome_arquivo, PalavraSecreta **array_palavras, int *tamanho_array);

/* Função que limpa a tela do terminal */
// Função imprime 30 novas linhas em branco no terminal.
void limpar_tela(void);

/*  */
//
void mostrar_creditos(void);

/*  */
//
void mostrar_rank(void);

bool voltar_ao_menu(void);

void salvar_palavra(PalavraSecreta palavra);

PalavraSecreta sortear_palavra_categoria(int categoria, PalavraSecreta *array_palavras, int tamanho_array);

int main(void)
{
	setlocale(LC_ALL, "Portuguese");

	PalavraSecreta *palavras;
	char *nome_arquivo = "palavras_secretas.csv";
	int total_palavras = 0;
	int opcao;
	bool voltar;

	// Carrega as palavras do arquivo de texto
	ler_palavras(nome_arquivo, &palavras, &total_palavras);

	do
	{
		opcao = ler_opcao_menu();

		switch (opcao)
		{
		case JOGAR:
			jogar(palavras, total_palavras);
			break;
		case MOSTRAR_RANK:
			mostrar_rank();
			break;
		case CADASTRAR_PALAVRA:
			cadastrar_palavra(nome_arquivo, &palavras, &total_palavras);
			break;
		case MOSTRAR_CREDITOS:
			mostrar_creditos();
			break;
		case SAIR:
			return 0;
		}
		voltar = voltar_ao_menu();
	} while (voltar);

	free(palavras);

	return 0;
}

void atualizar_arquivo_palavras(char *nome_arquivo, PalavraSecreta palavra)
{
	FILE *arquivo = fopen(nome_arquivo, "a");
	fprintf(arquivo, "%s;%s;%d\n", palavra.palavra, palavra.dica, palavra.categoria);
	fclose(arquivo);
}

void cadastrar_palavra(char *nome_arquivo, PalavraSecreta **array_palavras, int *tamanho_array)
{
	limpar_tela();

	// Atualiza o tamanho da lista de palavras
	*tamanho_array = *tamanho_array + 1;
	// Realoca o array para adicionar a nova palavra
	*array_palavras = (PalavraSecreta *)realloc(*array_palavras, (*tamanho_array) * sizeof(PalavraSecreta));

	PalavraSecreta *nova_palavra = &(*array_palavras)[*tamanho_array - 1];

	printf("============  CADASTRO DE PALAVRAS  ============\n");
	(*nova_palavra).categoria = ler_categoria();

	printf("\nQual palavra da %s voce deseja cadastrar?  ", ler_nome_categoria((*nova_palavra).categoria));
	//char * palavra_digitada;
	fgets((*nova_palavra).palavra, TAMANHO_MAX_PALAVRA - 1, stdin);
	fflush(stdin);
	strtok((*nova_palavra).palavra, "\n"); // Remove o '\n' do fim da string
	// Transforma a string para upper case
	for (int i = 0; (*nova_palavra).palavra[i] != '\0'; i++)
	{
		(*nova_palavra).palavra[i] = toupper((*nova_palavra).palavra[i]);
	}

	printf("\nAgora informe a dica para palavra '%s'?  ", (*nova_palavra));
	fgets((*nova_palavra).dica, TAMANHO_MAX_DICA - 1, stdin);
	strtok((*nova_palavra).dica, "\n"); // Remove o '\n' do fim da string
	fflush(stdin);

	atualizar_arquivo_palavras(nome_arquivo, *nova_palavra);
}

void desenha_forca(int num_tentativas)
{
	switch (num_tentativas)
	{
	case 6:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 5:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 4:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|          |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 3:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|");
		printf("\n|           ");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 2:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|           ");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 1:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|         / ");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 0:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|         / \\");
		printf("\n|");
		printf("\n|      Game Over!");
		printf("\n-");
		break;
	}
}

void desenha_menu()
{
	printf("*************************************************************************************\n");
	printf("*************************************************************************************\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("**    ||||||||||||    ||||||||||    ||||||||||       |||||||||||      ||||||       **\n");
	printf("**    ||             ||        ||   ||       ||     ||               ||    ||      **\n");
	printf("**    ||             ||        ||   ||        ||   ||               ||      ||     **\n");
	printf("**    |||||||        ||        ||   ||       ||    ||              ||        ||    **\n");
	printf("**    ||             ||        ||   |||||||||      ||              ||||||||||||    **\n");
	printf("**    ||             ||        ||   ||      ||     ||              ||        ||    **\n");
	printf("**    ||             ||        ||   ||       ||     ||             ||        ||    **\n");
	printf("**    ||              ||||||||||    ||        ||     |||||||||||   ||        ||    **\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("*************************************************************************************\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("**    ================                                                             **\n");
	printf("**    ||             |                                                             **\n");
	printf("**    ||         _======_                      _______________________             **\n");
	printf("**    ||        || o  o ||                    |         MENU          |            **\n");
	printf("**    ||        ||   _  ||                    | 1 - Jogar             |            **\n");
	printf("**    ||        ||-====-||                    | 2 - Exibir Ranking    |            **\n");
	printf("**    ||        |    |   |                    | 3 - Cadastrar Palavra |            **\n");
	printf("**    ||          //|||\\\\                     | 4 - Mostrar Creditos  |            **\n");
	printf("**    ||         // ||| \\\\                    | 5 - Sair              |            **\n");
	printf("**    ||            |||                       |_______________________|            **\n");
	printf("**    ||            |||                                                            **\n");
	printf("**    ||           // \\\\                                                           **\n");
	printf("**    ||          //   \\\\                                                          **\n");
	printf("**    ||                                                                           **\n");
	printf("**    ||                                                                           **\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("*************************************************************************************\n");
	printf("*************************************************************************************\n");
}

void jogar(PalavraSecreta *palavras, int total_palavras)
{
	limpar_tela();

	int categoria = ler_categoria();
	char letra;
	// Sorteia uma palavra aleatoriamente
	PalavraSecreta palavra_sorteada = sortear_palavra_categoria(categoria, palavras, total_palavras);
	int tamanho_palavra_sorteada = strlen(palavra_sorteada.palavra);
	// Aloca dinamicamente uma string com mesmo tamanho da string da palavra sorteada
	char *palavra_forca = (char *)malloc(tamanho_palavra_sorteada * sizeof(char));
	// Para salvar as letras usadas
	char letras_usadas[27];
	// Contador das letras utilizadas
	int qtd_letras_usadas = 0;
	int qtd_tentativas = 6;
	bool letra_usada = false;
	bool letra_encontrada = false;

	// Transforma a palavra a ser adivinhada em espaços vazios
	// Usa-se ate o tamanho da string -1, pois o ultimo caractere eh o '\0' de fim de string
	for (int i = 0; i < tamanho_palavra_sorteada; i++)
	{
		palavra_forca[i] = '*';
	}
	// for para controle das letras usadas que aparecem em cima da forca (necessário caso o jogador queira jogar mais de uma vez)
	for (int i = 0; i < 27; i++)
	{
		letras_usadas[i] = '*';
	}

	qtd_letras_usadas = 0; // zera a variavel de controle
	qtd_tentativas = 6;	 // reinicia número de tentativas

	while (strcmp(palavra_sorteada.palavra, palavra_forca) != 0 && qtd_tentativas > 0)
	{

		letra_encontrada = false;
		letra_usada = false;

		// Imprime as letras usadas
		printf("\n\nCategoria: %s.\nDica: %s.\nLetras usadas: ", ler_nome_categoria(palavra_sorteada.categoria), palavra_sorteada.dica);
		for (int i = 0; i < qtd_letras_usadas; i++)
		{
			printf("%c ", letras_usadas[i]);
		}

		// Imprimir a forca
		desenha_forca(qtd_tentativas);
		// Imprimir os underline para cada letra da palavra secreta
		printf("\nAdivinhe a palavra: ");
		// O -1 é para desconsiderar o '\0'
		for (int i = 0; i < tamanho_palavra_sorteada; i++)
		{
			if (palavra_forca[i] == '*')
			{
				printf("_ ");
			}
			else
			{
				printf("%c", palavra_forca[i]);
			}
		}

		// recebe a letra
		printf("\nLetra: ");
		scanf("%c", &letra);
		fflush(stdin);

		letra = toupper(letra); // trata a letra para maiúscula para comparar com a palavra a ser adivinhada

		//Checa se a letra já foi usada
		for (int i = 0; i < 26; i++)
		{
			if (letras_usadas[i] == letra)
			{
				letra_usada = true;
			}
		}
		// se letra correta atualiza palavra na tela
		// verifica se a letra é correta
		if (letra_usada == false)
		{
			letras_usadas[qtd_letras_usadas] = letra;
			qtd_letras_usadas++;

			for (int i = 0; i < tamanho_palavra_sorteada; i++)
			{
				if (letra == palavra_sorteada.palavra[i])
				{
					palavra_forca[i] = letra;
					letra_encontrada = true;
				}
			}
			// se nao encontrou a letra, diminui uma tentativa
			if (letra_encontrada == false)
			{
				qtd_tentativas--;
			}
		}
	}

	if (qtd_tentativas == 0)
	{
		desenha_forca(qtd_tentativas);
		printf("\n\nVocê perdeu, Fim de jogo! \n A palavra secreta era %s\n\n", palavra_sorteada.palavra); //printf final derrota
	}
	else
	{
		printf("\n\nParabens, você venceu! \nA palavra secreta era %s\n\n", palavra_sorteada.palavra); //printf final vitória
	}

	free(palavra_forca); // Sempre liberar variáveis alocadas dinamicamente
}

PalavraSecreta sortear_palavra_categoria(int categoria, PalavraSecreta *array_palavras, int tamanho_array)
{

	PalavraSecreta palavras_categoria[tamanho_array];
	int contador_categoria = 0;
	// Encontra as palavras da categoria passada como parametro
	for (int i = 0; i < tamanho_array; i++)
	{
		rand();
		if (array_palavras[i].categoria == categoria)
		{
			palavras_categoria[contador_categoria] = array_palavras[i];
			contador_categoria++;
		}
	}
	srand(time(NULL));
	return palavras_categoria[rand() % contador_categoria];
}

int ler_categoria(void)
{
	int opcao;
	printf("\nPor favor escolha uma das categorias:  \n");
	printf("\n          %d - Animais                   \n", ANIMAL);
	printf("\n          %d - Comidas                   \n", COMIDA);
	printf("\n          %d - Frutas                    \n", FRUTA);
	printf("\n          %d - Profissoes                \n", PROFISSAO);
	printf("\n          %d - Informatica               \n", INFORMATICA);
	scanf("%d", &opcao);
	fflush(stdin);
	while (opcao < 1 || opcao > 5)
	{
		printf("Opcao invalida, escolha uma das opcoes acima: ");
		scanf("%d", &opcao);
		fflush(stdin);
	}

	return opcao;
}

char ler_letra(void)
{
	// Cria string de tamanho 3 para ler até 2 caracteres do usuário no scanf, para verificar se o
	// usuário digitou mais de um caractere, pois o terceiro caractere será o '\0' (fim de string)
	char letra[3];

	printf("Digite uma letra: ");
	scanf("%2s", &letra);
	fflush(stdin);

	// Entra no loop para pedir para o usuário digitar apenas um caractere
	while (strlen(letra) > 1)
	{
		printf("Voce digitou mais de uma letra, por favor digite APENAS uma letra: ");
		scanf("%2s", &letra);
		fflush(stdin);
	}

	// Retorna o caractere
	return letra[0];
}

void ler_nome(char *nome, int tamanho_maximo)
{
	printf("Informe o seu nome: ");
	fgets(nome, tamanho_maximo - 1, stdin);
	fflush(stdin);
}

const char *ler_nome_categoria(int categoria)
{
	switch (categoria)
	{
	case ANIMAL:
		return "Animal";
	case COMIDA:
		return "Comida";
	case FRUTA:
		return "Fruta";
	case PROFISSAO:
		return "Profissao";
	case INFORMATICA:
		return "Informatica";
	default:
		return "não existente";
	}
}

int ler_opcao_menu(void)
{
	int opcao;
	do
	{
		limpar_tela();
		desenha_menu();
		printf("Digite uma das opções: ");
		scanf("%d", &opcao);
		fflush(stdin);
	} while (opcao < 1 || opcao > 5); // Enquanto não for uma opção válida (1 , 2, 3, 4 ou 5)
}

int get_numero_linhas_arquivo(char *nome_arquivo)
{
	int contador_linha = 0;
	FILE *arquivo = fopen(nome_arquivo, "r");
	while (!feof(arquivo))
	{
		char c = fgetc(arquivo);
		if (c == '\n')
		{
			contador_linha++;
		}
	}
	fclose(arquivo);

	return contador_linha;
}

void ler_palavras(char *nome_arquivo, PalavraSecreta **array_palavras, int *tamanho_array)
{
	FILE *arquivo;
	char linha[1024];
	int contador_linha = 0;
	int contador_coluna = 0;
	char *token;
	int max_colunas = 3;
	int total_linhas = get_numero_linhas_arquivo(nome_arquivo) - 1; // Desconsidera primeira linha (cabeçalho)

	if (total_linhas < 1)
	{
		*tamanho_array = 0;
		return;
	}

	*tamanho_array = total_linhas;
	*array_palavras = (PalavraSecreta *)malloc(total_linhas * sizeof(PalavraSecreta));

	arquivo = fopen(nome_arquivo, "r");
	// Ignora primeira linha, pois eh o cabeçalho
	fgets(linha, 1024, arquivo);

	while (fgets(linha, 1024, arquivo))
	{
		//palavra = (PalavraSecreta *)malloc(sizeof(PalavraSecreta));
		contador_coluna = 0;
		char *tmp = strdup(linha);
		/* Lê a primeira coluna */
		token = strtok(tmp, ";");

		/* Enquanto existir colunas (token) e o número de coluna for menor que o máximo */
		while (token && contador_coluna < max_colunas)
		{
			switch (contador_coluna)
			{
			case 0:
				strcpy((*array_palavras)[contador_linha].palavra, token);
				break;
			case 1:
				strcpy((*array_palavras)[contador_linha].dica, token);
				break;
			case 2:
				(*array_palavras)[contador_linha].categoria = atoi(token);
				break;
			}
			token = strtok(NULL, ";");
			contador_coluna++;
		}
		contador_linha++;
		free(tmp);
	}
	fclose(arquivo);
}

void limpar_tela(void)
{
	for (int i = 0; i < 30; i++)
	{
		printf("\n");
	}
}

void mostrar_creditos(void)
{
	limpar_tela();
	printf("*************************************************************************************\n");
	printf("*************************************************************************************\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("**    ||||||||||||    ||||||||||    ||||||||||       |||||||||||      ||||||       **\n");
	printf("**    ||             ||        ||   ||       ||     ||               ||    ||      **\n");
	printf("**    ||             ||        ||   ||        ||   ||               ||      ||     **\n");
	printf("**    |||||||        ||        ||   ||       ||    ||              ||        ||    **\n");
	printf("**    ||             ||        ||   |||||||||      ||              ||||||||||||    **\n");
	printf("**    ||             ||        ||   ||      ||     ||              ||        ||    **\n");
	printf("**    ||             ||        ||   ||       ||     ||             ||        ||    **\n");
	printf("**    ||              ||||||||||    ||        ||     |||||||||||   ||        ||    **\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("*************************************************************************************\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("**    ================                                                             **\n");
	printf("**    ||             |                 _______________________________________     **\n");
	printf("**    ||         _======_             |                                       |    **\n");
	printf("**    ||        || o  o ||            |            Desenvolvedores            |    **\n");
	printf("**    ||        ||   _  ||            |_______________________________________|    **\n");
	printf("**    ||        ||-====-||            |                                       |    **\n");
	printf("**    ||        |    |   |            |      Antonio Lopes de Souza Neto      |    **\n");
	printf("**    ||          //|||\\\\             |   Erick Henrique dos Santos Oliveira  |    **\n");
	printf("**    ||         // ||| \\\\            |          Gabriel Minga Pontes         |    **\n");
	printf("**    ||            |||               |   Katarina Melany Brayner Carvalho    |    **\n");
	printf("**    ||            |||               |_______________________________________|    **\n");
	printf("**    ||           // \\\\                                                           **\n");
	printf("**    ||          //   \\\\                                                          **\n");
	printf("**    ||                                                                           **\n");
	printf("**    ||                                                                           **\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("*************************************************************************************\n");
	printf("*************************************************************************************\n");
}

void mostrar_rank(void)
{
	limpar_tela();
	printf(" TODO MOSTRAR RANK ");
}

bool voltar_ao_menu(void)
{
	char voltar;
	do
	{
		printf("\n\nVoce deseja voltar ao menu principal ('s'/'n')? ");
		scanf("%c", &voltar);
		fflush(stdin);
		voltar = toupper(voltar);
	} while (voltar != 'S' && voltar != 'N');

	switch (voltar)
	{
	case 'S':
		return true;
	case 'N':
		return false;
	}
}

void salvar_palavra(PalavraSecreta *palavra)
{
	FILE *arquivo;
	arquivo = fopen("palavras_secretas.csv", "r");

	// Se o arquivo não existir cria o arquivo e adiciona os cabeçalhos
	if (!arquivo)
	{
		arquivo = fopen("palavras_secretas.csv", "w+");
		fprintf(arquivo, "Palavra;Dica;Categoria\n");
	}
	else
	{
		arquivo = fopen("palavras_secretas.csv", "a");
		fprintf(arquivo, "%s;%s;%d\n", palavra->palavra, palavra->dica, palavra->categoria);
	}
	fclose(arquivo);
}
