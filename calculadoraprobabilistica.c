#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	//Calculadora de raiz quadrada com valores randomicos.
	
	float num, i, v_aleat_1, num_aleat, resul, memoria, q_maisproximo, pare, ajuste, k;
	i = 0.0;
	ajuste = k = 1.0;
	
	int cont, cont_retorno; cont = cont_retorno = 0;
			
	printf("Digite o numero: ");
	scanf("%f", &num);
	
	do{
		q_maisproximo = i * i;
		i = i+1;
		pare = i * i;
		if(pare == num){q_maisproximo = num;}
	}while(pare<num);
	
	if(pare != num){i = i-1;}
	
	resul = i;
	
	srand(time(NULL));
		
	if(pare == num)
	{
		printf("\n%.2f ^ (1/2) = %.2f", num, i);
	}else
		{
			do
			{
				v_aleat_1 = rand()%1000000 + 1; 
									
				num_aleat = 1/(v_aleat_1*ajuste); 
	
				i = i + num_aleat; 
				
				resul = i * i; 
		
				if(resul > num)
					{
						i = i - num_aleat; 
						resul = i * i;
						cont_retorno = cont_retorno + 1; 
						if(ajuste >= 500){k = -1;} 
						if(ajuste <= 1){k = 1;} 
						ajuste = ajuste + k; 
					}
				
				cont = cont + 1; 
											
			}while(resul/num<=0.999999);
						
			printf("\nTotal de retornos: %i", cont_retorno);
			printf("\nTotal de tentantivas: %i", cont);
			printf("\n\n%f ^ (1/2) = %f", num, i);
						
		}
	
	return 0;
}
