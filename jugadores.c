#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seleccion.h"
#include "jugadores.h"
#include "mundial.h"

struct JugadoresE{

     char nombre[20];
     int dorsal;

};;

JugadoresP cargarjugadores(){

     JugadoresP j=malloc(sizeof(struct JugadoresE));

     printf("\n       Ingrese el nombre de un jugador: ");
     fflush(stdin);
     gets(j->nombre);
     printf("       Ingrese el dorsal del jugador: ");
     scanf("%d",&(j->dorsal));

return j;
};

void mostrarjugadores(JugadoresP j){

     printf("\n       Nombre del jugadores: %s\n",j->nombre);
     printf("       Dorsal: %d",j->dorsal);

};

int getdorsal(JugadoresP j){

return j->dorsal;
};

char * getnombre(JugadoresP j){

return j->nombre;
};

JugadoresP cargarjugadoresvacio(){

     JugadoresP j=malloc(sizeof(struct JugadoresE));

     j->dorsal=-1;
     strcpy(j->nombre,"VACIO");

 return j;
};

void setdorsal(JugadoresP j,int d){

    j->dorsal=d;

};

void setnombre(JugadoresP j,char n[20]){

     strcpy(j->nombre,n);

};

void destruirjugadores(JugadoresP j){

     free(j);

};
