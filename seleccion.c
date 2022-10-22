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

    for(int i=0;i<TAMA;i++){

         if(strcmp(getnombre(e->plantel[i]),n)==0){

              setdorsal(e->plantel[i],- 1);
              setnombre(e->plantel[i],"VACIO");

         }

    }

};

void ordenarporjugador(Equipo e){

    JugadoresP aux;

    for(int i=0;i<TAMA;i++){

      for(int j=i+1;j<TAMA;j++){

            if(getdorsal(e->plantel[i])>getdorsal(e->plantel[j])){

                   aux=e->plantel[i];
                   e->plantel[i]=e->plantel[j];
                   e->plantel[j]=aux;

            }
      }
    }
};

Equipo buscarjugadorpornombre(Equipo e,char n[20]){

    int ret=-1;

    for(int i=0;i<TAMA;i++){

           if(strcmp(getnombre(e->plantel[i]),n)==0){

                 ret=i;
                 i=TAMA;
           }
    }

    return ret;
};


void mostrarencontrado(Equipo e,char n[20]){

    int i=buscarjugadorpornombre(e,n);

    if(i!=-1){

       printf("\n********** JUGADOR - %s - ENCONTRADO **********\n",n);
       printf("\n Jugador---> %s \n",getnombre(e->plantel[i]));
       printf(" Dorsal del jugador---> %d \n",getdorsal(e->plantel[i]));
       printf(" Seleccion del jugador---> %s \n",e->nomdelpais);
       printf("*************************************************\n");
       i=TAMA;

    }else{

       printf("\n******** JUGADOR NO ENCONTRADO ********\n");

    }

};
