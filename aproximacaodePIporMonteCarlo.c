#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	/*
		Aproximação do avlor de Pi pelo metodo de Monte Carlo.		
	*/
		
	float x, y, hip, aprox_de_PI;
	int pontos_totais, pontos_no_circulo, i, precisao, rodadas;
	
	rodadas = 100000000; // Ajuste aqui a quantidade de lançamentos.
	precisao = 1001; // Ajuste aqui a precisão das coordenadas X e Y. É preciso aumenta em multiplos de 10 mais 1.
	
	srand(time(NULL));
	
	for(i=0;i<rodadas;i++){
		x = (float)(rand() % precisao)/(precisao - 1);
		y = (float)(rand() % precisao)/(precisao - 1);
		
		//printf("( %f , %f )\n", x,y);
		
		hip = x*x + y*y;
		
		if(hip <= 1){
			pontos_no_circulo++;
		}
		
		pontos_totais++;
	}
    
    aprox_de_PI = 4*((float)pontos_no_circulo/(float)pontos_totais);
    
    //printf("\n%i/%i\n",pontos_no_circulo,pontos_totais);
    printf("PI eh aprox. = %f", aprox_de_PI);
    
    getch();
    return 0;
}
