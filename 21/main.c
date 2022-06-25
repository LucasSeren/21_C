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

//Declaracao de Variaveis

//Configuracoies de Debug
int cartaAberta = 0; //Se 1 mostra a segunda carta do Dealer

//Tanto o dealer como os jogadores
typedef struct pessoa {
	char nome[50];
	int saldo;
	int aposta;
	int mao[10];
	int tamao; //Tamanho da mao
	int curPont; //Pontaos Atuais
}p;

//Guarda o Baraho com suas cartas
typedef struct baralho {
	int numCartas;
	int cart[52];

}b;

//Instanciando entidades
b Baralho = {51, {}};
p j1 = {"Jogador1", 1000, 0, {}, 0};
p dealer = {"Dealer", 1000, 0, {},0};

//Função utilitarias
int perguntaBinaria(){
    char resposta = 'n';
    int erro = 0;
    do{
        erro = 0;
        scanf(" %c", &resposta);
        if(resposta == 's' || resposta == 'S') return 1;
        if(resposta == 'n' || resposta == 'N') return 0;
        erro = 1;
        printf("\nVoce digitou um caractere invalido\nPor favor digite N ou S.\n");
    }while(erro);
    return 0;
}


//devolver um arranjo que corresponde a ordem em que as cartas estao embaralhadas
int embaralhar(int cartas[]){
	int mesa[52];
	int t,i;
	//inicializa um vetor com um baralho nao embaralhado
	for( i=0;i<52;i++){
		mesa[i] = (i/13+3)*100 + i%13 + 1;
	}

	//Embaralha o baralho e o guarda na variavel de destino
	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand() % 52;
		} while (mesa[t] == 0);
		cartas[i] = mesa[t];
		mesa[t] = 0;
	}

return 0;
}

//Converte o valor da carta para a sua pontuação 
//	!O modulo de 100 do returno é o valor da carta
//	!A divizao do returno por 100 é o nipe da carta
int ponto_carta(int a){
	if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
	else if(a%100==1){
		//pergunta ao jogador se ele quer 1 ou 11
	}else return a;

}

//Mostra todas as cartas que a pessoa tem na mao
int mostraMao(p pessoa){
	printf("\nMao do(a) %s: ", pessoa.nome);	
	for (int j = 0; j < pessoa.tamao; j++){
		printf("%d, ", pessoa.mao[j]);
	}
	return 0;
}

//Da cartas para pessoa, 
//atualiza o numero de cartas do baralho, 
//e atualiza a pontuacao da pessoa
p giveCard(p pessoa){

	pessoa.mao[pessoa.tamao] = Baralho.cart[Baralho.numCartas];
	
	pessoa.curPont += ponto_carta(pessoa.mao[pessoa.tamao])%100;
	
	pessoa.tamao++;
	Baralho.numCartas--;
	
	return pessoa;
}

//Determimina se a pessoa perdeu ganhou ou fez um natural
int comparacao(p pessoa, int comp){

	int poss = 0;
	if(pessoa.curPont < comp) poss = 2;
	else if(pessoa.curPont > comp) poss = 1;
	else poss = 0;

	return poss;
}

//Pergunta se o jogador quer uma carta
//ate que a resposta seja nao ou a pontuacao seja maior que 21
p picCart(p pessoa){

	printf("\nQuer mais uma carta? S/N:");
	while(perguntaBinaria() && pessoa.curPont <= 21){
		pessoa = giveCard(pessoa);
		mostraMao(pessoa);
		printf("\nQuer mais uma carta? S/N:");
	}
	
	return pessoa;
}

//O numero na tabela é multiplicado pela aposta para ser devolvido ao jogador
//			   D  J
float pontAble[3][3] = {{1  , 0, 0 },
						{1.5, 0, 2 },
						{1.5, 0, -1}};


p rodada(p pessoa1, p deal){

	//para deixar o resto do codigo menor
	int possJ = comparacao(pessoa1, 21);
	int possD = comparacao(deal, 21);

	//Se o jogo ainda nao estiver resolvido 
	if (pontAble[possD][possJ] == -1){
		//Pergunta se o jogador quer uma carta
		pessoa1 = picCart(pessoa1);
	}

	possJ = comparacao(pessoa1, 21);
	possD = comparacao(deal, 21);

	if (pontAble[possD][possJ] == -1){
		if(pessoa1.curPont >= deal.curPont) {
			//Jogador ganha
			possD = 1;
			possJ = 2;
		}else if(pessoa1.curPont <= deal.curPont) {
			//Jogador perde
			possD = 2;
			possJ = 1;
		}else if(pessoa1.curPont == deal.curPont) {
			//Inpate entre o jogador e o dealer
			possD = 0;
			possJ = 0;
		}
	};

	//Atualiza o saldo do jogador
	pessoa1.saldo += pessoa1.aposta*pontAble[possD][possJ];
	return pessoa1;
}

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