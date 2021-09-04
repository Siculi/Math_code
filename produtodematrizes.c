#include<stdio.h>

int main()
{
	//Produto de Matrizes
	
	int i, j, r, l_1, c_1, l_2, c_2, resul_celula;
	
	resul_celula = 0;
	
	printf("\t\tProduto de Matrizes");
	
	printf("\n\nPrimeira Matriz");
	
	printf("\n\nQuantidade de linhas da primeira matriz: ");
	scanf("%i", &l_1);
	printf("Quantidade de colunas da primeira matriz: ");
	scanf("%i", &c_1);
	
	printf("\nSegunda Matriz");
	
	printf("\n\nQuantidade de linhas da segunda matriz: ");
	scanf("%i", &l_2);
	printf("Quantidade de colunas da segunda matriz: ");
	scanf("%i", &c_2);
	
	printf("\n\n");
	
	if(c_1==l_2)
	{
		int matriz_1[l_1][c_1], matriz_2[l_2][c_2], matriz_prod[l_1][c_2];
		
		printf("Matriz 1\n\n");
		
		for(i=0;i<l_1;i++)
		{
			for(j=0;j<c_1;j++)
			{
				printf("[%i%i]: ", i+1,j+1);
				scanf("%i", &matriz_1[i][j]);
			}
		}
		
		printf("\nMatriz 2\n\n");
		
		for(i=0;i<l_2;i++)
		{
			for(j=0;j<c_2;j++)
			{
				printf("[%i%i]: ", i+1,j+1);
				scanf("%i", &matriz_2[i][j]);
			}
		}
		
	for(i=0;i<l_1;i++)
	{
		for(j=0;j<c_2;j++)
		{
			for(r=0;r<c_1;r++)
			{
				resul_celula = resul_celula + matriz_1[i][r] * matriz_2[r][j];
			}
			
			matriz_prod[i][j] = resul_celula;
			resul_celula = 0;
		}		
	}	
	
	printf("\n\n");
	
	for(i=0;i<l_1;i++)
	{
		for(j=0;j<c_2;j++)
		{
			printf(" %i ", matriz_prod[i][j]);				
		}
		
		printf("\n");
	}
			
	}else
		{
			printf("\n\nNao eh possivel fazer o Produto das Matrizes.");
		}
	
	return 0;
}
