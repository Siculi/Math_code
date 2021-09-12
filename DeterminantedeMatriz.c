#include<stdio.h>
#include<stdlib.h>

int main(){
	
	/*
		Este algoritmo faz uso do Teorema de Jacobi para gerar um triângulo de zeros inferiores. 
		E então multiplicar a diagonal principal para obter o Determinante da Matriz.
		
			Nota: 
				O código apresenta alguns problemas de arredondamento. 
				Uma possivel solução seria cada termo indivudual da matriz receber duas variáveis (Numerodor e Denominador)
				e sendo sobre estes aplicado propriedades de fraçãos para poder transmitir ambas até a ultima etapa possivel 
				rodando ainda no final  algum algortimo para simplificar a fração em termos irredutiveis. 
				Mostrando no final um valor do tipo Float (como aproximação) e também a fração irredetivel (como valor exato).     
	*/
	
	int tam, l, c, coor_l, coor_c, i,j;
	float fat_det, aux, troca_coor, det;
	coor_l = coor_c = 0;
	troca_coor = aux =  0.0; 
	det = fat_det = 1.0;
		
	printf("Digite o tamanho da matriz: ");
	scanf("%i", &tam);
	
	float matriz[tam][tam];
	
	for(l=0;l<tam;l++)
	{
		for(c=0;c<tam;c++)
		{
			printf("Valor de [%i][%i]: ", l+1, c+1);
			scanf("%f", &matriz[l][c]); 					
		}
		printf("\n");
	}
	
	for(l=0;l<tam;l++){for(c=0;c<tam;c++){printf("|%3.2f |", matriz[l][c]);}printf("\n");}
	
	for(c=0;c<tam;c++)
	{
		for(l=0;l<tam;l++)
		{
		 	if(matriz[l][c] != 0)
			{
				aux = matriz[l][c];
				coor_l = l;
				coor_c = c;
				break;
			}
		}
		if(aux != 0){break;}						
	}	
		
	if(coor_l != 0)
	{
		for(i=0;i<tam;i++)
		{
			troca_coor = matriz[0][i];
			matriz[0][i] = matriz[coor_l][i];
			matriz[coor_l][i] = troca_coor;
		}
		fat_det = fat_det * (-1);
	}
		
	if(coor_c != 0)
	{
		for(i=0;i<tam;i++)
		{
			troca_coor = matriz[i][0];
			matriz[i][0] = matriz[i][coor_c];
			matriz[i][coor_c] = troca_coor; 
		}
		fat_det = fat_det * (-1);
	}
		
	i = 0;
		
	for(j=1;j<tam;j++) 
	{		
		for(l=j;l<tam;l++)
		{
			if(matriz[l][i] != 0)
			{
				aux = -(matriz[l][i]/matriz[j-1][i]); 
			
				for(c=i;c<tam;c++)
				{
					if(c == i)
					{
						matriz[l][c] = 0;
					}else
						{
							matriz[l][c] =  matriz[j-1][c]*aux + matriz[l][c];
						}
				}
			}								
		}
		i++;		
	}
		
	for(l=0;l<tam;l++)
	{
		for(c=0;c<tam;c++)
		{
			if(l == c)
			{
				det = det * matriz[l][c];	
			}
		}
	}
	
	printf("\n\nDeterminante = %f", det);
	printf("\nNota: Apresenta erros de arredondamento.");
		
	return 0;
}
