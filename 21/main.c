#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int embaralhar(int cartas[]){
	int mesa[52];
	int t,i;
	//inicializa um vetor com um baralho nao embaralhado
	for( i=0;i<52;i++){
		mesa[i] = (i/13+3)*100 + i%13 + 1;
	}

	//Embaralha o baralho e o guarda na variavel de destino
	srand(time(NULL));
	for (i = 0; i < 52; i++){
		do{
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
	else return a;

}
int jogar(void){

	return 0;
}
int main(void){


	//testes aleatorios
	int baralho[52];
	embaralhar(baralho);



	printf("Ola mundo\n");
	printf("Cartas do baralho: ");
	for (int i = 0;i < 52; i++){
		printf("%d, ", ponto_carta(baralho[i]%100));
	}
	
	return 0;
}
