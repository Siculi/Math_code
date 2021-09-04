#include<stdio.h>

int main()
{
	//Gerador de Transposta de Matriz
	
	int i, j, l_1, c_1;
	
	printf("\t\tTransposta de Matriz");
		
	printf("\n\nQuantidade de linhas da matriz: ");
	scanf("%i", &l_1);
	printf("Quantidade de colunas da matriz: ");
	scanf("%i", &c_1);
	
	int matriz_orig[l_1][c_1], matriz_tranp[c_1][l_1];
		
	printf("\nMatriz\n\n");
		
	for(i=0;i<l_1;i++)
	{
		for(j=0;j<c_1;j++)
		{
			printf("[%i%i]: ", i+1,j+1);
			scanf("%i", &matriz_orig[i][j]);
		}
	}
			
	printf("\n\n");
	
	for(i=0;i<l_1;i++)
	{
		for(j=0;j<c_1;j++)
		{
			matriz_tranp[j][i] = matriz_orig[i][j];	// realiza a transposição					
		}				
	}
			
	for(i=0;i<l_1;i++)
	{
		for(j=0;j<c_1;j++)
		{
			printf("[%i]", matriz_orig[i][j]);		
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(i=0;i<c_1;i++)
	{
		for(j=0;j<l_1;j++)
		{
			printf("[%i]", matriz_tranp[i][j]);		
		}
		printf("\n");
	}
	
	return 0;
}
