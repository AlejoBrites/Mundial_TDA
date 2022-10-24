#ifndef SELECCION_H_INCLUDED
#define SELECCION_H_INCLUDED


struct EquipoEstruc;

typedef struct EquipoEstruc * Equipo;

void mostrarequipo(Equipo e);

Equipo cargarequipo();

Equipo cargarequipovacio();

int gettitulos(Equipo e);
char *getseleccion(Equipo e);

void eliminarjugador(Equipo e,char n[20]);

void ordenarporjugador(Equipo e);

int buscarjugadorpornombre(Equipo e,char n[20]);

void mostrarencontrado(Equipo e,char n[20]);

void escribirjugadores(Equipo e);

void destruirequipo(Equipo e);
#endif // SELECCION_H_INCLUDED
