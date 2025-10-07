//
// Created by User on 6/10/2025.
//

#ifndef PUNTOYFAMA_PERSISTENCIAUSUARIO_H
#define PUNTOYFAMA_PERSISTENCIAUSUARIO_H

#include <string>
#include <iostream>
#include "usuario.h"
#include <sstream>
#include <fstream>

using namespace std;

class persistenciaUsuario {
public:
    persistenciaUsuario(string archivo);
    usuario cargarUsuarios(string nombre);
    void guardarUsuario(usuario jugador);


private:
    vector<usuario> listaUsuarios;
    string nArchivo;
    vector<string> dividirString(string linea, char delimitador);
    usuario encontrarUsuario(vector<usuario> listaUsuarios, string nombre);
    int indiceUsuario(usuario user);
};


#endif //PUNTOYFAMA_PERSISTENCIAUSUARIO_H