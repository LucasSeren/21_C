#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
	char name[50];
	int saldo;
	int aposta;
	int mao[10];
	int tamao;
	int curPont;
}p;


typedef struct baralho {
	int numCartas;
	int cart[52];

}b;

b Baralho = {51, {}};

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

//Da cartas para alguem e atualiza o numero de cartas do baralho
p distributor(p pessoa){

	pessoa.mao[pessoa.tamao] = Baralho.cart[Baralho.numCartas];
	
	pessoa.tamao++;
	Baralho.numCartas--;
	
	return pessoa;
}

int main(){


	//Instanciando entidades
	p j1 = {"Luan", 1000, 0, {}, 0};
	p dealer = {"Louige", 1000, 0, {}, 0};


	embaralhar(Baralho.cart);

	//pedindo o valor da aposta do jogador 1
	printf("Quanto vc quer apostar:");
	scanf("%d", &j1.aposta);

	while (j1.aposta > j1.saldo)
	{
		printf("Voce nao tem esse valor\nTente um valor menor: ");
		scanf("%d", &j1.aposta);
	};
	j1.saldo -= j1.aposta;

	//Distribuicao
	for (int i = 0; i < 2; i++)
	{
		system("cls");
		j1 = distributor(j1);

		dealer = distributor(dealer);
		
	}
	
	printf("Mao do jogador 1: ");	
	for (int j = 0; j < j1.tamao; j++){
		printf("%d, ", j1.mao[j]);
	}
		printf("\n");

	printf("Mao do dealer: %d, %s", dealer.mao[0], "down");
	
	//verificar naturais

	
	


	return 0;
}