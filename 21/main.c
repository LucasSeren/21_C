/*
Coisas Pendentes
-Verificar o input sa aposta( ele tem que ser um numero positivo)
-Escolher dinamicamente se o As vai valer 1 ou 11
-Programar a ia do dealer
-Dizer se o jogador ganhou ou nao, antes de mostrar o saldo atualizado

Bugs Conhecidos
-Se eu digitar s, S, n ou N para o valor da aposta ele usa esse resultado
para responder a primeira pergunta de S/N que aparece
-O As vale 0 por emqunato
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes1.h"

//Declaracao de Variaveis

//Configuracoies de Debug
int cartaAberta = 0; //Se 1 mostra a segunda carta do Dealer
/*
//Tanto o dealer como os jogadores
typedef struct pessoa {
	char nome[50];
	int saldo;
	int aposta;
	int mao[0];
	int tamao; //Tamanho da mao
	int curPont; //Pontaos Atuais
}p;

//Guarda o Baraho com suas cartas
typedef struct baralho {
	int numCartas;
	int cart[52];

}b;
*/

//Instanciando entidades
p j1 = {"Jogador1", 1000, 0, {}, 0};
p dealer = {"Dealer", 1000, 0, {},0};

//O jogo
void jogo(){
	embaralhar(Baralho.cart);

	//pedindo o valor da aposta do jogador 1
	printf("\nSauldo do Jogador 1: %d\n", j1.saldo);
	printf("Quanto vc quer apostar:");
	scanf("%d", &j1.aposta);

	//Garantindo que o jogador nao aposte mais do que tem
	while (j1.aposta > j1.saldo)
	{
		printf("Voce nao tem esse valor\nTente um valor menor: ");
		scanf("%d", &j1.aposta);
	};
	j1.saldo -= j1.aposta; //Subtra o valor da aposta do saldo

	//Distribuicao
	for (int i = 0; i < 2; i++)
	{
		system("cls");

		dealer = giveCard(dealer);
		j1 = giveCard(j1);	
	}

	mostraMao(j1);

	//Mostra a mao do dealer
	if(cartaAberta){
		mostraMao(dealer);
	}else {
		printf("\nMao do dealer: %d, %s", dealer.mao[0], "down");
	}


	//Game loop
	j1 = rodada(j1, dealer);
	printf("\nSauldo do Jogador 1: %d\n", j1.saldo);

}

int main(){
	system("cls");

	//Pergunta se quer continuar e reinicia se sim mantendo o mesmo saldo
	do{
		dealer.tamao = 0;
		dealer.curPont = 0;
		j1.tamao = 0;
		j1.curPont = 0;
		jogo();
		printf("Quer jogar novamente? S/N: ");
	}while(perguntaBinaria());	
	
	printf("\nObrigado Por jogar");


	return 0;
}