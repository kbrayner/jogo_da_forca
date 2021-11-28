#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void forca(int erros){
	
	switch (erros) {
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
	 
int main(void) {
	setlocale (LC_ALL, "Portuguese");
	
	int i;//variavel de controle geral
	int letra_encontrada;// para verificar se o usuario acertou ou errou
	char secret_word[100];// variavel para salvar a palavra secreta
	char palavra_forca[100];//variável para verificar o acerto
	char dica[100];//dica
	char letra;//onde o palpite é salvo
	int erros;//contador de erros
	char letrasUsadas[26];// p/ salvar as letras usadas
	int numLetrasUsadas = 0;// p/ contar letras usadas
	int usada;// p/ controle geral de letas usadas
	char jn;
	
	do{
		for(i = 0; i < strlen(secret_word); i++){
			secret_word[i] = '*';
		}
		printf("JOGADOR 1:\n");
		printf("Informe a palavra secreta:\n");
		scanf("%s", &secret_word);
		fflush(stdin);
		printf("Digite uma dica:\n");
		scanf("%s", &dica);
		fflush(stdin);
		printf("A palavra secreta é: %s", secret_word);
		printf("A palavra possui %d caracteres", strlen(secret_word)-1);
		
		//coloca toda a palavra secreta em maiusculo, para facilitar o tratamento no jogo
		for(i = 0; i < strlen(secret_word); i++){
			secret_word[i] = toupper(secret_word[i]);
		}
		//limpa a tela para o player 2 não ver a palavra secreta	
		for(i = 0; i < 30; i++){
			printf("\n");
		}
		//copia a palavra secreta para a palavra que precisa ser acertada
		strcpy(palavra_forca, secret_word);
		
		//transforma a palavra a ser advinhada em espaços vazios para ser advinhada
		for(i = 0; i < strlen(palavra_forca); i++){
			palavra_forca[i] = '*';
		}
		// for para controle das letras usadas que aparecem em cima da forca (necessário caso o jogador queira jogar mais de uma vez)
		for(i = 0; i < strlen(letrasUsadas); i++){
			letrasUsadas[i] = '*';
		}
		numLetrasUsadas = 0;// zera a variavel de controle para a segunda tentativa
		erros = 0;//zera os erros para a segunda tentativa
		
		while(strcmp(secret_word, palavra_forca) != 0 && erros != 6){
			
			letra_encontrada = 0;
			usada = 0;
			
			//imprime as letras usadas
			printf("\n\nDica: %s Letras usadas: ", dica);
			for(i = 0; i < numLetrasUsadas; i++){
				printf("%c ", letrasUsadas[i]);
			}
			
			// imprimir a forca
			forca(erros);
			// imprimir os underline para cada letra da palavra secreta
			printf("\nAdivinhe a palavra:");
			for(i = 0; i < strlen(secret_word); i++){
				if(palavra_forca[i] == '*'){
					printf("_ ");
				}
				else{
					printf("%c", palavra_forca[i]);
				}
			}
			
			// recebe a letra
			printf("\nLetra: ");
			fflush(stdin);
			scanf("%c", &letra);
			
			letra = toupper(letra);// trata a letra para maiuscula para comparar com a palavra a ser advinhada
			
		//Checa se a letra já foi usada
			for(i = 0; i < 26; i++){
				if(letrasUsadas[i] == letra){
				usada = 1;
				}
			}
			// se letra correta atualiza palavra na tela
			// verifica se a letra é correta
			if(usada == 0){
				letrasUsadas[numLetrasUsadas] = letra;
				numLetrasUsadas++;
				
				for(i = 0; i < strlen(palavra_forca); i++){
					if(letra == secret_word[i]){
						palavra_forca[i] = letra;
						letra_encontrada = 1;
					}
				}	
			// se nao encontrou a letra, diminiu uma tentativa
				if(letra_encontrada == 0){
					erros++;
				}
			}
		}
	
		if(erros == 6){
			forca(erros);
			printf("\n\nVocê perdeu, Fim de jogo! \n A palavra secreta era %s", secret_word);//printf final derrota
		}
		else{
			printf("\n\nParabens, você venceu! \nA palavra secreta era %s", secret_word);//printf final vitória
		}
		printf("\n\nDeseja jogar novamente?(reponda com s ou n)\n");// menu para perguntar se o jogador deseja jogar novamente
		fflush(stdin);
		jn = getchar();
		jn = tolower(jn);
		while(jn != 's' && jn != 'n'){//para controle de erros do usuario
			printf("Resposta inválida!");
			printf("\nDeseja jogar novamente?(reponda com s ou n)\n");
			fflush(stdin);
			jn = getchar();
			jn = tolower(jn);
		}
	}while(jn == 's');
	
	return 0;
}
