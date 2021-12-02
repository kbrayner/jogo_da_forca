#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

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
	
	//Vetores com as palavras possíveis. A declaração do tamanho deve ser manual, pois C não permite que a constante seja declarada como dimensão do array.
	char animal[20][12] = { "AVESTRUZ", "BORBOLETA", "CARANGUEJO",
			"ORANGOTANGO", "CROCODILO", "DROMEDARIO", "ROUXINOL", "CENTOPEIA",
			"GAFANHOTO", "PINTASSILGO", "HIPOPOTAMO", "LEOPARDO", "GUAXINIM",
			"JAGUATIRICA", "OSTRA", "MICO", "CHIMPANZE", "CARNEIRO", "GOLFINHO",
			"MINHOCA" };
	char comida[20][12] = { "EMPADA", "FARINHA", "FEIJOADA", "COXINHA",
			"BRIGADEIRO", "CHURRASCO", "LASANHA", "MACARRONADA", "TORTA",
			"TORRADA", "PIZZA", "PANQUECA", "PIPOCA", "PAMONHA", "OVO",
			"ACARAJE", "CROISSANT", "HAMBURGUER", "BISCOITO", "BOLO" };
	char fruta[20][12] = { "ABACATE", "BANANA", "CARAMBOLA", "DAMASCO", "FIGO",
			"GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA",
			"MARACUJA", "PESSEGO", "PITOMBA", "ROMA", "TANGERINA", "TOMATE",
			"TAMARINDO", "UVA", "UMBU" };
	char profissao[20][12] = { "ADVOGADO", "BOMBEIRO", "CARPINTEIRO",
			"DESENHISTA", "ENGENHEIRO", "ESCRITOR", "FERREIRO", "GUARDA",
			"HISTORIADOR", "JORNALISTA", "LEILOEIRO", "MARINHEIRO", "OURIVES",
			"PROGRAMADOR", "PADEIRO", "RELOJOEIRO", "SILVICULTOR", "TRADUTOR",
			"VETERINARIO", "ZOOLOGO" };
	char informatica[20][12] = { "LINUX", "WINDOWS", "C", "PROCESSADOR",
			"TECLADO", "MOUSE", "PROGRAMA", "ALGORITMO", "HACKER", "TOUCHPAD",
			"ASCII", "JAVA", "JAVASCRIPT", "PROGRAMADOR", "PYTHON", "INTERNET",
			"ROTEADOR", "SERVIDOR", "GOOGLE", "APPLE" };
			
	int NUM_ITENS = 20;// Numero de itens em cada array de palavras aleatórias
	
	int i;//variavel de controle geral
	int letra_encontrada;// para verificar se o usuario acertou ou errou
	char secret_word[20];// variavel para salvar a palavra secreta
	char palavra_forca[20];//variável para verificar o acerto
	char dica[20];//dica
	char letra;//onde o palpite é salvo
	int erros;//contador de erros
	char letrasUsadas[27];// p/ salvar as letras usadas
	int numLetrasUsadas = 0;// p/ contar letras usadas
	int usada;// p/ controle geral de letas usadas
	int r = 1; // p/ saber o numero da rodada
	int opc = 0; // variável para o menu
	int tema; // recebe o tema
	
	do{
		opc = 0;
		printf("\n____________");
		printf("\n|          |");
		printf("\n|          O");
		printf("\n|         -|-");
		printf("\n|         / \\");
		printf("\n|");
		printf("\n|      JOGO DA FORCA");
		printf("\n-");
		printf("TECLE PARA COMEÇAR:\n");
		printf(" 1-JOGAR PLAYER VS PLAYER (Palavras personalizadas)\n 2-JOGAR CONTRA O COMPUTADOR\n 3-SAIR\n");
		
		while(opc < 1 || opc > 3){
			fflush(stdin);
			scanf("%d", &opc);
		}
		
		if(opc == 1){
			for(i = 0; i < strlen(secret_word); i++){
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
		}
		if(opc == 2){
			do{
				printf("\n\t\tEscolha o tema que você deseja jogar:\n\n");
				printf("1-Animais\t 2-Comida\t 3-Frutas\t 4-Profissão\t 5-Informática\n");
				scanf("%d", &tema);
			}while(tema < 1 || tema > 5);
			
			srand(time(NULL));
			
			switch(tema){
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
		if(opc == 3)
		break;
			
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
			printf("\n\nVocê perdeu, Fim de jogo! \n A palavra secreta era %s\n\n", secret_word);//printf final derrota
		}
		else{
			printf("\n\nParabens, você venceu! \nA palavra secreta era %s\n\n", secret_word);//printf final vitória
		}
		r++;
	}while(1);

	return 0;
}
