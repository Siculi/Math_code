#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	// Area sob a curva f(x) = ax� + bx + c
	
	setlocale(LC_ALL, "Portuguese");
	
	int opc;
	float i, x_i, x_f, delta, quant, ret, area, a, b, c;
	
	opc = 0;
	i = x_i = x_f = delta = quant = ret = area = a = b = c = 0.0;
	
	printf("Ar�a sob a fun��o f(x)=ax�+bx+c.\n");
	
	printf("\nEscolha: ");
	printf("\n1) �rea absoluta.");
	printf("\n2) �reas positivas - �rea negativa.");
	printf("\nOp��o: ");
	scanf("%i", &opc);
	
	switch(opc)
		{
			case 1:printf("\nSelecionada: �rea absoluta");break;
			case 2:printf("Selecionada: �reas positivas - �rea negativa");break;
			default:printf("Op��o Invalida. Selecionada: �rea absoluta automaticamente.");opc = 1;	
		}
	
	printf("\n\na: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	printf("c: ");
	scanf("%f", &c);

	printf("\nQuantos ret�ngulos abaixo da fun��o f(x) = %.2fx� +%.2fx + %.2f: ", a, b, c);
	scanf("%f", &quant);
	
	printf("\nIntervalo da fun��o.");
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
	
	printf("\nAr�a sob a curva �: %f", area);
	
	return 0;
}
