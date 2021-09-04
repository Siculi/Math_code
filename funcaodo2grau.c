#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	// Area sob a curva f(x) = ax² + bx + c
	
	setlocale(LC_ALL, "Portuguese");
	
	int opc;
	float i, x_i, x_f, delta, quant, ret, area, a, b, c;
	
	opc = 0;
	i = x_i = x_f = delta = quant = ret = area = a = b = c = 0.0;
	
	printf("Aréa sob a função f(x)=ax²+bx+c.\n");
	
	printf("\nEscolha: ");
	printf("\n1) área absoluta.");
	printf("\n2) áreas positivas - área negativa.");
	printf("\nOpção: ");
	scanf("%i", &opc);
	
	switch(opc)
		{
			case 1:printf("\nSelecionada: área absoluta");break;
			case 2:printf("Selecionada: áreas positivas - área negativa");break;
			default:printf("Opção Invalida. Selecionada: área absoluta automaticamente.");opc = 1;	
		}
	
	printf("\n\na: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	printf("c: ");
	scanf("%f", &c);

	printf("\nQuantos retângulos abaixo da função f(x) = %.2fx² +%.2fx + %.2f: ", a, b, c);
	scanf("%f", &quant);
	
	printf("\nIntervalo da função.");
	printf("\n\nlim inferior: ");
	scanf("%f", &x_i);
	printf("lim superior: ");
	scanf("%f", &x_f);
	
	delta = (x_f - x_i)/quant;
	if(delta<0){delta = delta*(-1);}
	
	for(i=1;i<=quant;i++)
		{
			ret = (a*(x_i*x_i) + b*(x_i) + c) *delta;
			if(opc==1){if(ret<0){ret = ret*(-1);}}
			x_i = x_i + delta;
			area = area + ret;
		}	
	
	printf("\nAréa sob a curva é: %f", area);
	
	return 0;
}
