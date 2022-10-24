#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED

struct JugadoresE;

typedef struct JugadoresE * JugadoresP;


void mostrarjugadores(JugadoresP j);


JugadoresP cargarjugadores();

JugadoresP cargarjugadoresvacio();

int getdorsal(JugadoresP j);
char * getnombre(JugadoresP j);

void setdorsal(JugadoresP j,int d);
void setnombre(JugadoresP j,char n[20]);

void destruirjugadores(JugadoresP j);
#endif // JUGADORES_H_INCLUDED
