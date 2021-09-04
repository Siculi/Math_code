#include<stdio.h>
#include<stdlib.h>

int main(){
	
	// Raiz quadrada por Taylor. 
	// Nota: falha para algum números. Exemplos, para valores na cercania de 8.
	
	float num, q_maisproximo, pare, i, dif, resp, fat, qn, fatorial, k, exp, difn;
		
	num = q_maisproximo = pare = dif = resp = qn = 0.0;
	exp = 0.5;
	fatorial = fat = difn = 1.0;
	i = 1.0;	
				
	printf("Digite o numero: ");
	scanf("%f", &num);
	
	do{
		q_maisproximo = i * i;
		i = i+1;
		pare = i * i;
		if(pare == num){q_maisproximo = num;}
	}while(pare<num);	
	
	if(pare != num){i = i-1;}

	fat = fat*exp;
	exp = exp - 1;
		
	if(pare == num)
	{
		printf("\n%.2f ^ (1/2) = %.2f", num, i);
	}else
		{
			qn = q_maisproximo;
			resp = i;
			dif = num - q_maisproximo;
			difn = num - q_maisproximo;
			
			for(k=1;k<=35;k++)
			{
				if(k==1)
				{
					qn=1;
				}else
					{
						if(k==2){qn=q_maisproximo;}
						if(k>2){qn = qn*q_maisproximo;}
					}
									
				resp = resp + fat*(difn)/(fatorial*qn*i);				
				//printf("\n%.0f) Termo: %f",k,fat*(difn)/(fatorial*qn*i));
				//printf("\n    Soma:  %f\n\n", resp);
				difn = difn*dif;				
				fatorial = fatorial * (k+1); 
				fat = fat*exp;
				exp = exp - 1;								
			}
			
			printf("\n%f ^ (1/2) = %f", num, resp);
						
		}
		
	return 0;
}
