//Villarreal Razo Carlos Gabriel 3CM5
#include<stdio.h>
#include<stdlib.h>

int moclaFrac(int capacidad, int numItems, int *utilizado, int *W, int *V);

int main()
{
    int capacidad, numItems, WActual, *utilizado;
    int i, *W, *V;
    
    printf("\t\t-----MOCHILA FRACCIONARIA-----\n");
    printf("Introduce capacidad de la mochila:\n");
    scanf("%d", &capacidad);
    printf("Introduce numero de items:\n");
    scanf("%d", &numItems);
    printf("\nIntroduce W y V de los %d items:\n", numItems);

    V=(int *)calloc(numItems,sizeof(int));
    W=(int *)calloc(numItems,sizeof(int));
    utilizado=(int *)calloc(numItems,sizeof(int));

    for (i=0;i<numItems;i++)
    {
        printf("\n\tValor %d: ", i+1);
        scanf("%d", &V[i]);
        printf("\tPeso %d: ", i+1);
        scanf("%d", &W[i]);
       
    }
    
    printf("\n\t\t-----SOLUCION-----");
    
    moclaFrac(capacidad, numItems, utilizado, W, V);
    return 0;
}

int moclaFrac(int capacidad, int numItems, int *utilizado, int *W, int *V){
    int i=0, item, WActual;
    float Ganancia;

    //se asigna la capacidad a la variable controladora del ciclo
    WActual = capacidad;
    while (WActual > 0)
    {
        item = -1;
        for (i=0;i<numItems;i++)
            if ((utilizado[i] == 0) && ((item == -1) || ((float) V[i] / W[i] > (float) V[item] / W[item])))
                item = i;

        utilizado[item] = 1;
        WActual -= W[item];
        Ganancia += (float)V[item];
        
        if (WActual >= 0){
            printf("\n Objeto %d (%d, %dKg) añadido al 100 %% en la mochila. \n", item + 1, V[item], W[item]);
            printf("\n Capacidad disponible: %d.",WActual);
        }
        else
        {
            int PorcentItem = (int) ((1 + (float) WActual / (float)W[item]) * 100);
            printf("\n Objeto %d (%d, %dKg) añadido con su %d %% en la mochila.\n",item + 1, V[item], W[item], PorcentItem);
            Ganancia -= (float)V[item];
            Ganancia += (1 + (float)WActual / (float)W[item]) * (float)V[item];
        }
    }
    printf("\nGanancia total de: %.2f\n", Ganancia);
    
}

