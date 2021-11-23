/**
 * Importação de bibliotecas
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


const int VALOR_DICA = 20;
const int VALOR_PALAVRA = 50;
const int VALOR_TENTATIVAS = 10;

/**
 * Declarações das funções em ordem alfabética
 */

/* Função que desenha a forca de acordo com o número total de tentativas restantes */
// A função recebe um inteiro que representa o número de tentativas restantes e
// imprime o desenho da forca de acordo com as tentativas.
void desenha_forca(int num_tentativas);
/* Função que permite que usuário digite apenas um caractere no console para entrada de dados */
// Função solicita um caractere ao usuário e caso seja informado mais de um caractere, solicita
// que o usuário digite novamente. Retorna o caractere.
char ler_letra(void);
/* Função que solicita opção de menu */
// Função solicita uma das opções válidas do menu ao usuário e caso seja informado uma opção inválida
// solicita novamente uma opção válida.
int menu(void);

/**
 * Função principal do jogo
 */
int main()
{
	setlocale(LC_ALL, "Portuguese");
	menu();

	

	// variaveis
	char palavra_secreta[30], dica[128], palavra_forca[30];
	char letra;
	int i, num_tentativas = 0;

	//info jogador 1
	printf("|---JOGADOR 1---|\n");
	printf("Digite a palavra secreta: "); // palava secreta = palavra_secreta!
	fgets(palavra_secreta, 30, stdin);
	//dica
	printf("Dica: ");
	fgets(dica, 128, stdin);
	//info palavra_secreta
	printf("\nA palavra secreta é: %s", palavra_secreta);									 // informaçoes da palavra secreta
	printf("Quantidade de caracteres: %d\n", strlen(palavra_secreta) - 1); // -1 pq o "enter" tbm é somado!!
	printf("A dica é: %s\n", dica);
	//fim jogardor 1
	printf("*****Pressione qualquer tecla para prosseguir*****");
	getch();

	//limpando a tela do console
	system("cls");

	//vez do jogador 2 ---
	//tirando o ultimo caractere "\0" & escondendo a palavra secreta usando o strcpy() pra copiar o "palavra_secreta" em "palavra_forca"
	palavra_secreta[strlen(palavra_secreta) - 1] = '\0';

	strcpy(palavra_forca, palavra_secreta);

	//imprimindo o '_' na msm quantidade de letras da palavra_secreta/palavra_forca
	for (i = 0; i < strlen(palavra_forca); i++)
	{
		palavra_forca[i] = '_';
	}

	printf("|---JOGADOR 2---|");
	while (1)
	{
		// imprimir a forca
		desenha_forca(num_tentativas);

		//interface do jogador 2
		//"for" para verificar de a caractere digitada é igual a alguma caractere da 'palavra_forca'
		printf("\nAdivinhe a palavra:");
		for (i = 0; i < strlen(palavra_forca); i++)
		{
			printf(" %c ", palavra_forca[i]);
		}
		printf("\nDica: %s", dica);
		printf("Contagem de erros: %d (Max.: 6)\n", num_tentativas);

		//recebendo a letra
		letra = ler_letra();

		//verifica se a letra é correta e atualizar na tela
		int teste_erro = 1;
		for (i = 0; i < strlen(palavra_forca); i++)
		{
			if (letra == palavra_secreta[i])
			{
				palavra_forca[i] = letra;
				teste_erro = 0;
			}
		}
		//testando se a letra existe na variavel e caso não tenha a letra, aumenta o numero de erros
		if (teste_erro == 1)
		{
			(num_tentativas++);
		}
		//imprimindo vitoria
		if (strcmp(palavra_forca, palavra_secreta) == 0)
		{ //strcmp foi visto na aula de 09 Walace : "strcmp() = 0, if the s1 and s2 are equal"
			printf("\nAdivinhe a palavra:");
			for (i = 0; i < strlen(palavra_forca); i++)
			{
				printf(" %c ", palavra_forca[i]);
			}
			printf("\n******* Você venceu! *******");
			printf("\n********* You won! *********");
			printf("\n******* Tu as gagné! *******");
			printf("\n******** Hai vinto! *********");
			printf("\n******** ¡Ganaste! **********");
			break;
		}
		//imprimindo derrota
		if (num_tentativas == 6)
		{
			desenha_forca(num_tentativas);
			break;
		}
	}
	return 0;
}

void desenha_forca(int num_tentativas)
{
	switch (num_tentativas)
	{
	case 0:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 1:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 2:
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
	case 4:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|           ");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 5:
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|         / ");
		printf("\n|");
		printf("\n|");
		printf("\n-");
		break;
	case 6:
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

int menu(void)
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
	printf("**    ================                                                             **\n");
	printf("**    ||             |                                                             **\n");
	printf("**    ||         _======_                      ______________________              **\n");
	printf("**    ||        || o  o ||                    |         MENU         |             **\n");
	printf("**    ||        ||   _  ||                    | 1 - Jogar            |             **\n");
	printf("**    ||        ||-====-||                    | 2 - Exibir Ranking   |             **\n");
	printf("**    ||        |    |   |                    | 3 - Mostrar Creditos |             **\n");
	printf("**    ||          //|||\\\\                     |______________________|             **\n");
	printf("**    ||         // ||| \\\\                                                         **\n");
	printf("**    ||            |||                                                            **\n");
	printf("**    ||            |||                                                            **\n");
	printf("**    ||           // \\\\                                                           **\n");
	printf("**    ||          //   \\\\                                                          **\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("**                                                                                 **\n");
	printf("*************************************************************************************\n");
	printf("*************************************************************************************\n");
}
