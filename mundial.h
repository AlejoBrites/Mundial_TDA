#ifndef MUNDIAL_H_INCLUDED
#define MUNDIAL_H_INCLUDED

struct MundialEstruc;

typedef struct MundialEstruc * Mundial;

Mundial leerdatos();
Mundial transformardatos(char t[50]);

//Mundial cargarmundial();
void mostraranfitrion(Mundial m);

void eliminarjugadormundial(Mundial m,char n[20]);

void ordenarporjugadormundial(Mundial m);

void buscarjugadorpornombremundial(Mundial m,char n[20]);

#endif // MUNDIAL_H_INCLUDED
