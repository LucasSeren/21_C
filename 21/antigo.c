
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float Dinheiro[4];//cada elemento do  vetor sera a pontuação de um jogador
int Mao[5][10], Baralho[52];// a primeira dimencao e para dizer o jogador e a segunda, para cada carta

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
int ponto_carta(int a){
	if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
	else if(a%100==1){
		//pergunta ao jogador se ele quer 1 ou 11
	}else return a;

}

int jogo(void){
	float aposta[4];
	int curCard = 0, tmao = 4, curMao[5] = {0, 0, 0, 0, 0};


	embaralhar(Baralho);

	for(int jogador = 0; jogador < 4; jogador++){
		
		/*
		printf("\nJogador %d tem: R$%.2f", jogador, Dinheiro[0]);
		printf("\nquanto gostaria de apostar?: ");
		scanf("%.2f", &aposta[jogador]);
		*/

		printf("\nMao do jogador %d: ", jogador+1);
		for(; curMao[jogador] < 2; curMao[jogador]++, curCard++){
			Mao[jogador][curMao[jogador]] = Baralho[curCard];

			printf("%d, ", Mao[jogador][curMao[jogador]]);
		}
	}

	for(; curMao[4] < 2; curMao[4]++, curCard++){
			Mao[5][curMao[4]] = Baralho[curCard];
	}
	
	printf("\nO dealer recebeu: %d e uma carta virada", Mao[5][0]);


	return 0;
}
int main(void)
{
	jogo();
	
	return 0;
}
