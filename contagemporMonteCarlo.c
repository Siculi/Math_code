#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	/*
		Simulação de uma contagem de peixes em um lago através do Método de Monte Carlo.
		
		Um exemplo clássico do uso do método de Monte Carlo é a estimativa da população de peixes em um lago. 
		Nesse método é feita uma primeira etapa de identificação: são pescados diversos peixes que são marcados por meio de um anel.
		Nessa etapa é importante saber exatamente o número de peixes que foram identificados dessa forma.
		
		Na segunda etapa são pescados novamente uma certa quantidade de peixes aleatoriamente, 
		anotando respectivamente aqueles que estavam identificados com o anel e aqueles que não estavam identificados.
		É esperado que a proporção entre peixes pescados com a identificação e o número total de peixes pescados siga 
		a mesma proporção entre o número total de peixes com a identificação e o número total de peixes, como mostra a relação:
		
		N_{Pm}/N_{P} approx. igual a:  N_{Tm}/N_{T}
		
		Sendo N_{Pm} o número de peixes pescados que estavam marcados, N_{P} o número total de peixes pescados, 
		N_{Tm} o número total de peixes marcados e N_{T} o número total de peixes.
		
		Por meio desta relação é possível obter o número total de peixes no lago N_{Pm}, já que N_{P}, N_{Pm} e N_{Tm} são dados do experimento.
		
		No algoritmo baixo pedesse que o usario entre com um valor para a quantidade total de Peixes na lagoa
		e então o algortimo tentará atraves de valores aleatorios e usando estatística aproximar o valor de entrada.
		
		Nota. Por algum motivo que não identifiquei o codigo só funciona para valores abaixo dos 32 mil.
			  Acredito que seja por algum estouro de memória.	  
	*/
	
	int i, tam_amostra, quantidade, marcador, tam_repescagem, contator_marcados; 
	float aproximacao_do_valor_entrada;
	
	contator_marcados = 0;
	
	printf("!!! Use valores abaixo dos 32 mil peixes !!!\n\n");
	printf("  Quantidade de total de peixes na lagoa N_{P}: ");
	scanf("%i", &quantidade);
	
	int elementos[quantidade];
	char elementos_marcados[quantidade];
	
	printf("\n   N_{Pm}        N_{Tm}\n ---------  =  --------- , Aonde N_{Pm}, N_{Tm} e N_{T} sao valores aleatorios gerados pelo computador.\n   N_{P}         N_{T}");
	
	for(i=0;i<quantidade;i++){
		elementos_marcados[i] = '0';
	}
	
	srand(time(NULL));
	
	tam_amostra = rand()%quantidade + 1; 
    
    printf("\n\n  N_{Pm} - Tamanho da Primeira Amostra:...................................... %i", tam_amostra);
        
    for(i=0;i<tam_amostra;i++){
    	
    	marcador = rand()%quantidade;
    			
		if(elementos_marcados[marcador] != 'M'){
    		elementos_marcados[marcador] = 'M';
		}else{
			i--;
		}	
	}
	
	tam_repescagem = rand()%quantidade + 1;
	
	printf("\n  N_{T}  - Tamanho da Amostra da Repescagem:................................. %i", tam_repescagem);
	
	for(i=0;i<tam_repescagem;i++){
	 	
		marcador = rand()%quantidade;
	 	 	
	 	if(elementos_marcados[marcador] == 'C'){
			i--;
		}else{
			if(elementos_marcados[marcador] == 'M'){
    			contator_marcados++;
			}
			elementos_marcados[marcador] = 'C';	
		}	 		 	
	}
	
	printf("\n  N_{Tm} - Quantidade de peixes ja marcados encontrados durante a repescagem: %i", contator_marcados);
    
    aproximacao_do_valor_entrada = ((float)tam_repescagem*(float)tam_amostra)/(float)contator_marcados;
    
    printf("\n\n--> Aprox. do valor de entrada N_{P}: %f", aproximacao_do_valor_entrada);
    
    getch();
    return 0;
}
