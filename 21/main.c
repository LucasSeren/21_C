#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int baralho(int cartas[]){
int mesa[52];
int t,i;
for( i=0;i<52;i++){
    mesa[i] = (i/13+3)*100 + i%13 + 1;
}
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

int converter_naipe(int a){
if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
	else return a;

}
int jogar(void){

return 0;
}
int main(void)
{

	return 0;
}
