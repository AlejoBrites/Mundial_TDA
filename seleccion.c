#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 11
#include "seleccion.h"
#include "jugadores.h"
#include "mundial.h"

struct EquipoEstruc{

     char nomdelpais[20];
     int titulos;
     JugadoresP plantel[TAMA];

};

Equipo cargarequipovacio(){

     Equipo e= malloc(sizeof(struct EquipoEstruc));

     strcpy(e->nomdelpais," VACIO ");
     e->titulos=-1;

return e;
};

Equipo cargarequipo(){

     Equipo e= malloc(sizeof(struct EquipoEstruc));

     printf("\n-   Ingrese el nombre de una seleccion: ");
     fflush(stdin);
     gets(e->nomdelpais);
     printf("-   Ingrese los titulos ganados por esa seleccion: ");
     scanf("%d",&(e->titulos));

     int tamaux;
     printf("\n-   Cuantos jugadores desea ingresar: ");
     scanf("%d",&tamaux);

     for(int i=0;i<TAMA;i++){

        if(i<tamaux){
            e->plantel[i]=cargarjugadores();
        }else{
            e->plantel[i]=cargarjugadoresvacio();
        }
     }

     return e;
};

void mostrarequipo(Equipo e){

    printf("\n\n======= SELECCION =======\n");
    printf("\n   Seleccion: %s",e->nomdelpais);
    printf("\n   Titulos ganados: %d\n",e->titulos);

    printf("======= JUGADORES =======\n");

    for(int i=0;i<TAMA;i++){

       if(getdorsal(e->plantel[i])!=-1){

           mostrarjugadores(e->plantel[i]);
        }
     }

};

int gettitulos(Equipo e){

return e->titulos;
};

void eliminarjugador(Equipo e,char n[20]){

    /*char nombreaux[20];
    printf("\n -Ingrese el jugador que quiere eliminar: ");
    fflush(stdin);
    gets(nombreaux);
*/
    for(int i=0;i<TAMA;i++){

         if(strcmp(getnombre(e->plantel[i]),n)==0){

              setdorsal(e->plantel[i],- 1);
              setnombre(e->plantel[i],"VACIO");
              i=TAMA;

         }

    }

};


