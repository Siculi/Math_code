#include<stdio.h>

int main()
{
	int num, cont;
	
	cont = 0;
	
	printf("Numero: ");
	scanf("%i", &num);
	
	do{
		if(num % 2 == 0)
		{
			num = num/2;
		}else
			{
				num = 3*num + 1;
			}
		cont = cont + 1;
		printf("%i\n", num);
		
	}while(num!=1);
	
	printf("\nTotal de numeros gerados: %i + 1", cont);
	
	return 0;
}
