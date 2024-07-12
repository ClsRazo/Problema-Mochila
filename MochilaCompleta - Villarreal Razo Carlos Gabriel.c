//Villarreal Razo Carlos Gabriel - 3CM5 - 10 de enero de 2023
#include <stdio.h>
#include <stdlib.h>

int moclaEntera(int n, int C, int *W, int *V);
int max(int a, int b);

int main()
{
	int n, C, i=0, j=0;
	int matriz, *V, *W;

	printf("-----------------MOCHILA ENTERA-----------------\n\n");
	printf("Introduce la cantidad de elementos: ");
	scanf("%d",&n);
	printf("Introduce la capacidad de la mochila: ");
	scanf("%d",&C);

	V=(int *)calloc(n,sizeof(int));
	W=(int *)calloc(n,sizeof(int));

	for (i=0;i<n;i++){
        printf("\n\tValor %d: ", i+1);
        scanf("%d", &V[i]);
        printf("\tPeso %d: ", i+1);
        scanf("%d", &W[i]);
    }

    printf("\nGanancia: %d",moclaEntera(n,C,W,V));

	return 0;
}

int moclaEntera(int n, int C, int *W, int *V){
	int j=0, i=0;
	int **matriz;

	//Se crea la matriz de tamanio n
	matriz=(int **)malloc((n+1)*sizeof(int *));
	for(int i=0;i<n+1;i++){
		matriz[i]=(int *)malloc((C+1)*sizeof(int));
	}

	//Algoritmo
	for(j=0;j<n+1;j++){
		matriz[0][j]=0;
	}
	for(i=1;i<n+1;i++){
		for(j=0;j<C+1;j++){
			if(W[i-1]>j){
				matriz[i][j]=matriz[i-1][j];
			}else{
				matriz[i][j]=max(V[i-1]+matriz[i-1][j-W[i-1]],matriz[i-1][j]);
			}
		}
	}
	return matriz[n][C];
}

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
