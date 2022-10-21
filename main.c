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

    eliminarjugadormundial(m1);

    mostraranfitrion(m1);

    return 0;
}
