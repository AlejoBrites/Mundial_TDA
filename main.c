#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seleccion.h"
#include "jugadores.h"
#include "mundial.h"

int main()
{

    printf ("======== Bienvenido al mundial Qatar 2022 ========\n\n");

    Mundial m1=leerdatos();

    mostraranfitrion(m1);

    char nomuno[20];
    //printf("\n--------------------------------------\n");
    //printf("ingrese el Jugador que quiere eliminar: ");
    //gets(nom1);

    eliminarjugadormundial(m1,nomuno);

    mostraranfitrion(m1);

    printf("\n\n-------- Ordenamos los jugadores por numero de dorsal --------");
    ordenarporjugadormundial(m1);

    mostraranfitrion(m1);

    char nomdos[20];
    //printf("\n--------------------------------------\n");
    //printf("ingrese el Jugador que quiere buscar: ");
    //gets(nom2);

    printf("\n\n-------- BUSQUEDA DE JUGADOR--------");
    buscarjugadorpornombremundial(m1,nomdos);


    return 0;
}
