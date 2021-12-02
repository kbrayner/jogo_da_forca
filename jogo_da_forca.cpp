#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

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
struct PalavraSecreta
{
	char palavra[30];
	char dica[255];
	int categoria;
};

/**
 * Declarações das funções em ordem alfabética
 */

/*  */
//
void cadastrar_palavra(void);

/* Função que desenha a forca de acordo com o número total de tentativas restantes */
// A função recebe um inteiro que representa o número de tentativas restantes e
// imprime o desenho da forca de acordo com as tentativas.
void desenha_forca(int num_tentativas);

/*  */
//
void desenha_menu(void);

/*  */
//
void jogar(void);

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
char *ler_nome_categoria(Categoria categoria);

/* Função que solicita opção de menu */
// Função solicita uma das opções válidas do menu ao usuário e caso seja informado uma opção inválida
// solicita novamente uma opção válida.
int ler_opcao_menu(void);

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

int main(void)
{
	setlocale(LC_ALL, "Portuguese");

	int opcao;
	bool voltar;
	do
	{
		opcao = ler_opcao_menu();

		switch (opcao)
		{
		case JOGAR:
			jogar();
			break;
		case MOSTRAR_RANK:
			mostrar_rank();
			break;
		case CADASTRAR_PALAVRA:
			cadastrar_palavra();
			break;
		case MOSTRAR_CREDITOS:
			mostrar_creditos();
			break;
		case SAIR:
			return 0;
		}
		voltar = voltar_ao_menu();
	} while (voltar);
	return 0;
}

void cadastrar_palavra()
{
	limpar_tela();
	printf("TODO IMPLEMENTAR FUNÇÃO QUE CADASTRA PALAVRA");
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

void jogar(void)
{
	limpar_tela();
	printf("TODO Implementar a lógica do jogo");
	int categoria;

	switch (categoria)
	{
	case ANIMAL:
		break;
	case COMIDA:
		break;
	case FRUTA:
		break;
	case PROFISSAO:
		break;
	case INFORMATICA:
		break;
	default:
		break;
	}
}

int ler_categoria(void)
{
	int opcao;
	do
	{
		limpar_tela();
		printf("\nQual das categorias você deseja jogar?  \n");
		printf("\n          %d - Animais                   \n", ANIMAL);
		printf("\n          %d - Comidas                   \n", COMIDA);
		printf("\n          %d - Frutas                    \n", FRUTA);
		printf("\n          %d - Profissões                \n", PROFISSAO);
		printf("\n          %d - Informática               \n", INFORMATICA);
		scanf("%d", &opcao);
		fflush(stdin);
	} while (opcao < 1 || opcao > 5);

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
		printf("Você digitou mais de uma letra, por favor digite APENAS uma letra: ");
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

char *ler_nome_categoria(Categoria categoria)
{
	switch (categoria)
	{
	case ANIMAL:
		return "Categoria Animal";
	case COMIDA:
		return "Categoria Comida";
	case FRUTA:
		return "Categoria Fruta";
	case PROFISSAO:
		return "Categoria Profissão";
	case INFORMATICA:
		return "Categoria Informática";
	default:
		return "Categoria não existente";
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
	printf(" TODO MOSTRAR CREDITOS ");
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
		printf("\n\nVocê deseja voltar ao menu principal ('s'/'n')? ");
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

/*char *get_string(int length) {
    char *word = malloc(length + 1);
    
    return word;
}*/

/*
último código atualizado por Antonio. Transformar o código em funções conforme a estrutura acima
*/
void codido_antonio(void)
{
	// Vetores com as palavras possíveis. A declaração do tamanho deve ser manual, pois C não permite que a constante seja declarada como dimensão do array.
	char animal[20][12] = {"AVESTRUZ", "BORBOLETA", "CARANGUEJO",
												 "ORANGOTANGO", "CROCODILO", "DROMEDARIO", "ROUXINOL", "CENTOPEIA",
												 "GAFANHOTO", "PINTASSILGO", "HIPOPOTAMO", "LEOPARDO", "GUAXINIM",
												 "JAGUATIRICA", "OSTRA", "MICO", "CHIMPANZE", "CARNEIRO", "GOLFINHO",
												 "MINHOCA"};
	char comida[20][12] = {"EMPADA", "FARINHA", "FEIJOADA", "COXINHA",
												 "BRIGADEIRO", "CHURRASCO", "LASANHA", "MACARRONADA", "TORTA",
												 "TORRADA", "PIZZA", "PANQUECA", "PIPOCA", "PAMONHA", "OVO",
												 "ACARAJE", "CROISSANT", "HAMBURGUER", "BISCOITO", "BOLO"};
	char fruta[20][12] = {"ABACATE", "BANANA", "CARAMBOLA", "DAMASCO", "FIGO",
												"GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA",
												"MARACUJA", "PESSEGO", "PITOMBA", "ROMA", "TANGERINA", "TOMATE",
												"TAMARINDO", "UVA", "UMBU"};
	char profissao[20][12] = {"ADVOGADO", "BOMBEIRO", "CARPINTEIRO",
														"DESENHISTA", "ENGENHEIRO", "ESCRITOR", "FERREIRO", "GUARDA",
														"HISTORIADOR", "JORNALISTA", "LEILOEIRO", "MARINHEIRO", "OURIVES",
														"PROGRAMADOR", "PADEIRO", "RELOJOEIRO", "SILVICULTOR", "TRADUTOR",
														"VETERINARIO", "ZOOLOGO"};
	char informatica[20][12] = {"LINUX", "WINDOWS", "C", "PROCESSADOR",
															"TECLADO", "MOUSE", "PROGRAMA", "ALGORITMO", "HACKER", "TOUCHPAD",
															"ASCII", "JAVA", "JAVASCRIPT", "PROGRAMADOR", "PYTHON", "INTERNET",
															"ROTEADOR", "SERVIDOR", "GOOGLE", "APPLE"};

	const int NUM_ITENS = 20; // Numero de itens em cada array de palavras aleatórias

	int i;									 //variavel de controle geral
	int letra_encontrada;		 // para verificar se o usuário acertou ou errou
	char secret_word[20];		 // variavel para salvar a palavra secreta
	char palavra_forca[20];	 //variável para verificar o acerto
	char dica[20];					 //dica
	char letra;							 //onde o palpite é salvo
	int num_tentativas = 6;	 //contador de tentativas restantes
	char letrasUsadas[27];	 // p/ salvar as letras usadas
	int numLetrasUsadas = 0; // p/ contar letras usadas
	int usada;							 // p/ controle geral de letras usadas
	int r = 1;							 // p/ saber o numero da rodada
	int opcao_escolhida;		 // variável para o menu
	int tema;								 // recebe o tema

	do
	{
		opcao_escolhida = ler_opcao_menu();

		switch (opcao_escolhida)
		{
		case JOGAR:
			/* code */
			break;
		case MOSTRAR_RANK:
			/* code */
			break;
		case CADASTRAR_PALAVRA:
			/* code */
			break;
		case MOSTRAR_CREDITOS:
			/* code */
			break;
		case SAIR:
			/* code */
			break;
		default:
			break;
		}

		if (opcao_escolhida == 1)
		{
			for (i = 0; i < strlen(secret_word); i++)
			{
				secret_word[i] = '*';
			}
			printf("ROUND %d:\n", r);
			printf("Informe a palavra secreta:\n");
			scanf("%s", &secret_word);
			fflush(stdin);
			printf("Digite uma dica:\n");
			scanf("%s", &dica);
			fflush(stdin);
			printf("A palavra secreta é: %s", secret_word);
			printf("A palavra possui %d caracteres", strlen(secret_word) - 1);

			//coloca toda a palavra secreta em maiusculo, para facilitar o tratamento no jogo
			for (i = 0; i < strlen(secret_word); i++)
			{
				secret_word[i] = toupper(secret_word[i]);
			}
			//limpa a tela para o player 2 não ver a palavra secreta
			for (i = 0; i < 30; i++)
			{
				printf("\n");
			}
			//copia a palavra secreta para a palavra que precisa ser acertada
			strcpy(palavra_forca, secret_word);
		}
		if (opcao_escolhida == 2)
		{
			do
			{
				printf("\n\t\tEscolha o tema que você deseja jogar:\n\n");
				printf("1-Animais\t 2-Comida\t 3-Frutas\t 4-Profissão\t 5-Informática\n");
				scanf("%d", &tema);
			} while (tema < 1 || tema > 5);

			srand(time(NULL));

			switch (tema)
			{
			case 1:
				//definir a dica
				strcpy(dica, "Animal");
				//escolher uma palavra aleatória
				strcpy(secret_word, animal[rand() % NUM_ITENS]);
				break;
			case 2:
				strcpy(dica, "Comida");
				strcpy(secret_word, comida[rand() % NUM_ITENS]);
				break;
			case 3:
				strcpy(dica, "Fruta");
				strcpy(secret_word, fruta[rand() % NUM_ITENS]);
				break;
			case 4:
				strcpy(dica, "Profissão");
				strcpy(secret_word, profissao[rand() % NUM_ITENS]);
				break;
			case 5:
				strcpy(dica, "Informática");
				strcpy(secret_word, informatica[rand() % NUM_ITENS]);
				break;
			default:
				break;
			}
			strcpy(palavra_forca, secret_word);
		}
		if (opcao_escolhida == 3)
			break;

		//transforma a palavra a ser advinhada em espaços vazios para ser advinhada
		for (i = 0; i < strlen(palavra_forca); i++)
		{
			palavra_forca[i] = '*';
		}
		// for para controle das letras usadas que aparecem em cima da forca (necessário caso o jogador queira jogar mais de uma vez)
		for (i = 0; i < strlen(letrasUsadas); i++)
		{
			letrasUsadas[i] = '*';
		}
		numLetrasUsadas = 0; // zera a variavel de controle
		num_tentativas = 6;	 // reinicia número de tentativas

		while (strcmp(secret_word, palavra_forca) != 0 && num_tentativas != 0)
		{

			letra_encontrada = 0;
			usada = 0;

			//imprime as letras usadas
			printf("\n\nDica: %s Letras usadas: ", dica);
			for (i = 0; i < numLetrasUsadas; i++)
			{
				printf("%c ", letrasUsadas[i]);
			}

			// imprimir a forca
			desenha_forca(num_tentativas);
			// imprimir os underline para cada letra da palavra secreta
			printf("\nAdivinhe a palavra:");
			for (i = 0; i < strlen(secret_word); i++)
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
			fflush(stdin);
			scanf("%c", &letra);

			letra = toupper(letra); // trata a letra para maiúscula para comparar com a palavra a ser adivinhada

			//Checa se a letra já foi usada
			for (i = 0; i < 26; i++)
			{
				if (letrasUsadas[i] == letra)
				{
					usada = 1;
				}
			}
			// se letra correta atualiza palavra na tela
			// verifica se a letra é correta
			if (usada == 0)
			{
				letrasUsadas[numLetrasUsadas] = letra;
				numLetrasUsadas++;

				for (i = 0; i < strlen(palavra_forca); i++)
				{
					if (letra == secret_word[i])
					{
						palavra_forca[i] = letra;
						letra_encontrada = 1;
					}
				}
				// se nao encontrou a letra, diminui uma tentativa
				if (letra_encontrada == 0)
				{
					num_tentativas--;
				}
			}
		}

		if (num_tentativas == 0)
		{
			desenha_forca(num_tentativas);
			printf("\n\nVocê perdeu, Fim de jogo! \n A palavra secreta era %s\n\n", secret_word); //printf final derrota
		}
		else
		{
			printf("\n\nParabens, você venceu! \nA palavra secreta era %s\n\n", secret_word); //printf final vitória
		}
		r++;
	} while (1);
}