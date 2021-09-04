#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	// Area sob a curva f(x) = x²
	
	setlocale(LC_ALL, "Portuguese");
	
	float i, x_i, x_f, delta, quant, ret, area;
	
	i = x_i = x_f = delta = quant = ret = area = 0.0;
	
	printf("Programa para encontrar aréa para x>=0 da função f(x) = x²\n\n");
	printf("Quantos retângulos quer abaixo da função f(x) = x²: ");
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
	
	printf("Aréa sob a curva é: %f", area);
	
	return 0;
}
