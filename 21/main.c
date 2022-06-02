
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

<<<<<<< Updated upstream
int baralho(int cartas[]){
int mesa[52];
int t,i;
for( i=0;i<52;i++){
    mesa[i] = (i/13+3)*100 + i%13 + 1;
}
=======
int Dinheiro[4];//cada elemento do  vetor sera a pontuação de um jogador
int Mao[4][10];// a primeira dimencao e para dizer o jogador a segunda, para cada carta

int embaralhar(int cartas[]){
	int mesa[52];
	int t,i;
	//inicializa um vetor com um baralho nao embaralhado
	for( i=0;i<52;i++){
		mesa[i] = (i/13+3)*100 + i%13 + 1;
	}

	//Embaralha o baralho e o guarda na variavel de destino
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
int converter_naipe(int a){
if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
	else return a;
=======
//Converte o valor da carta para a sua pontuação
int ponto_carta(int a){
	if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
	else if(a%100==1){
		//pergunta ao jogador se ele quer 1 ou 11
	}else return a;
>>>>>>> Stashed changes

}

<<<<<<< Updated upstream
return 0;
=======
int joga(void){
	
	return 0;
>>>>>>> Stashed changes
}
int main(void)
{

	return 0;
}
