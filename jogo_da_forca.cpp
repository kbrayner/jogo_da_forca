#include <stdio.h>
#include <string.h>
#include <locale.h>

void forca(int num_tentativas){
	
	switch (num_tentativas) {
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
	 
int main(void) {
	setlocale (LC_ALL, "Portuguese");
	
	int num_tentativas = 6;
	int i;
	int letra_encontrada;
	char secret_word[100];
	char palavra_forca[100];
	char letra;
	
	printf("JOGADOR 1:\n");
	printf("Informe a palavra secreta:\n");
	fgets(secret_word, 100, stdin);
	printf("A palavra secreta é: %s", secret_word);
	printf("A palavra possui %d caracteres", strlen(secret_word)-1);
	for(i = 0; i < 30; i++){
		printf("\n");
	}
	strcpy(palavra_forca, secret_word);
	palavra_forca[strlen(palavra_forca)-1]='\0';
	
	for(i = 0; i < strlen(palavra_forca); i++){
		palavra_forca[i] = '_';
	}
	
	while(1){
		
		letra_encontrada = 0;
		
		// imprimir a forca
		forca(num_tentativas);
		// imprimir os underline para cada letra da palavra secreta
		printf("\nAdivinhe a palavra:");
		for(i = 0; i < strlen(palavra_forca); i++){
			printf("%c", palavra_forca[i]);
		}
		// recebe a letra
		printf("\nLetra: ");
		scanf("%c", &letra);
		// se letra correta atualiza palavra na tela
		// verifica se a letra é correta
		for(i = 0; i < strlen(palavra_forca); i++){
			if(letra == secret_word[i]){
				palavra_forca[i] = letra;
				letra_encontrada = 1;
			}
		}
		// se nao encontrou a letra, diminiu uma tentativa
		if(letra_encontrada == 0){
			num_tentativas--;
		}
		// verifica se o jogo acabou
		if(num_tentativas == 0){
			forca(num_tentativas);
			break;
		}
	}
	
	return 0;
}
