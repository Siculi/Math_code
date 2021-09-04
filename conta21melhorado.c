#include<stdio.h>
#include<time.h>

int main()
{
	//Contador de cartas combinadas que somam 21. De 1 combinação de cartas até 32.
	
	float tempo; time_t t_ini, t_fim;
	int vetor[52];
	int c_v = 0;
	int cp, co, cc, ce;
	int p[13],o[13],c[13],e[13];
	int i, num, cont_p = 0, soma = 0, contadorde_21 = 0;
			
	for(cp=0;cp<13;cp++){if(cp<=9){p[cp] = cp+1;}else{p[cp] = 10;}vetor[c_v]=p[cp];c_v++;}	
	for(co=0;co<13;co++){if(co<=9){o[co] = co+1;}else{o[co] = 10;}vetor[c_v]=p[co];c_v++;}
	for(cc=0;cc<13;cc++){if(cc<=9){c[cc] = cc+1;}else{c[cc] = 10;}vetor[c_v]=p[cc];c_v++;}
	for(ce=0;ce<13;ce++){if(ce<=9){e[ce] = ce+1;}else{e[ce] = 10;}vetor[c_v]=p[ce];c_v++;}
	
	t_ini = time(NULL);
				
	for(i=0;i<4294967296;i++)
	{	
		num = i;
		while(num>0)
		{
			if(num % 2 == 0)
			{
				cont_p++;
			}else
				{
					soma = soma + vetor[cont_p];					
					cont_p++;
					if(soma > 21) break;																			
				}
			num = num/2;					
		}
		if(soma == 21){contadorde_21++;}
		cont_p = 0;
		soma = 0;				
	}	
	
	t_fim = time(NULL);
	
	tempo = difftime(t_fim, t_ini);
	
	printf("\nTotal de Somas 21: %d\n", contadorde_21);
	printf("Tempo total: %.2f\n", tempo);	
					
	return 0;
}
