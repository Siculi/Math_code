#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	// Area sob a curva f(x) = x�
	
	setlocale(LC_ALL, "Portuguese");
	
	float i, x_i, x_f, delta, quant, ret, area;
	
	i = x_i = x_f = delta = quant = ret = area = 0.0;
	
	printf("Programa para encontrar ar�a para x>=0 da fun��o f(x) = x�\n\n");
	printf("Quantos ret�ngulos quer abaixo da fun��o f(x) = x�: ");
	scanf("%f", &quant);
	
	printf("x inicial: ");
	scanf("%f", &x_i);
	printf("x final: ");
	scanf("%f", &x_f);
	
	delta = (x_f - x_i)/quant;
	
	for(i=1;i<=quant;i++)
		{
			ret = (x_i*x_i)*delta;
			x_i = x_i + delta;
			area = area + ret;
		}	
	
	printf("Ar�a sob a curva �: %f", area);
	
	return 0;
}
