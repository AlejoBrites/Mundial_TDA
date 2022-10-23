#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seleccion.h"
#include "jugadores.h"
#include "mundial.h"
#define TAM 32


struct MundialEstruc{

    char paisorg[6];
    int cantestadios;
    Equipo paises[TAM];

};

///**************Carga por archivo************
Mundial leerdatos(){

   Mundial m=malloc(sizeof(struct MundialEstruc));

   FILE * archivo= fopen("qatar.txt","r");

   while(!feof(archivo)){

      char datos[50];

      fgets(datos,50,archivo);

      m=transformardatos(datos);

   }

   fclose(archivo);

   int tamaux;

   printf("- Ingrese la cantidad que selecciones que quiere ingresar: ");
   scanf("%d",&tamaux);

   for(int i = 0;i<TAM;i++){

      if (i<tamaux){
          m->paises[i]=cargarequipo();
      }else{
          m->paises[i]=cargarequipovacio();
      }
   }


   return m;
};
///******************************************

Mundial transformardatos(char t[50]){

    Mundial m=malloc(sizeof(struct MundialEstruc));


    int posdeldelimitador=-1;

    for(int i=0;i<50;i++){

        if(t[i]==';'){
            posdeldelimitador=i;
            i=50;
        }
    }

    char anfitrionaux[6]="";

    for (int i=0;i<posdeldelimitador;i++){

        anfitrionaux[i]=t[i];

    }

    char cantestadiosaux[3]="";

    for (int i=posdeldelimitador+1;i<posdeldelimitador+3;i++){

        cantestadiosaux[i-posdeldelimitador-1]=t[i];

    }

    strcpy(m->paisorg,anfitrionaux);
    m->cantestadios=atoi(cantestadiosaux);

return m;
};

///***************Carga por teclado******************************
/*
Mundial cargarmundial(){

     Mundial m=malloc(sizeof(struct MundialEstruc));

     m->cantestadios=16;
     strcpy(m->paisorg,"Qatar");

     for(int j = 0;j<TAM;j++){

       m->paises[j]=cargarequipo();

     }

     return m;
};
*/
///***************************************************************

void mostraranfitrion(Mundial m){

     printf("\n\n ----------- Mundial 2022 ----------- \n");
     printf("\nNombre del anfitrion: %s \n", m->paisorg);
     printf("Cantidad de estadios: %d \n", m->cantestadios);

     printf("\n --------------- SELECCIONES --------------- \n");
     for(int i=0;i<TAM;i++){

        if(gettitulos(m->paises[i])!=-1){
            mostrarequipo(m->paises[i]);
        }
     }

};

void eliminarjugadormundial(Mundial m,char n[20]){

    printf("\n--------------------------------------\n");
    printf("ingrese el Jugador que quiere eliminar: ");
    fflush(stdin);
    gets(n);

    for(int i=0;i<TAM;i++){

        if(gettitulos(m->paises[i])!=-1){

            eliminarjugador(m->paises[i],n);

        }
    }
};

void ordenarporjugadormundial(Mundial m){

    for(int i=0;i<TAM;i++){

        if(gettitulos(m->paises[i])!=-1){

            ordenarporjugador(m->paises[i]);

        }
    }
};

void buscarjugadorpornombremundial(Mundial m,char n[20]){

    printf("\n--------------------------------------\n");
    printf("ingrese el Jugador que quiere buscar: ");
    fflush(stdin);
    gets(n);

    int aux;

    for(int i=0;i<TAM;i++){

      aux=buscarjugadorpornombre(m->paises[i],n);

        if(gettitulos(m->paises[i])!=-1){

               if (aux!=-1){

                    mostrarencontrado(m->paises[i],n);
                    i=TAM;

               }

        }
    }

};

void escribirmundial(Mundial m){

    FILE * archivo=fopen("quiYjug.txt","a");
    fprintf(archivo,"Mundial 2022// Sede: %s // Cant de estadios: %d \n\n",m->paisorg,m->cantestadios);

    for(int i=0;i<TAM ;i++){

       if(gettitulos(m->paises[i])!=-1){
         fprintf(archivo,"   Seleccion %s // Titulos: %d \n",getseleccion(m->paises[i]),gettitulos(m->paises[i]));

         escribirjugadores(m->paises[i]);

       }
    }


};
