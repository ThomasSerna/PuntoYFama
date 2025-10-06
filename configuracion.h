//
// Created by User on 6/10/2025.
//

#ifndef PUNTOYFAMA_GUARDARCONFIGURACION_H
#define PUNTOYFAMA_GUARDARCONFIGURACION_H
#include <array>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class configuracion {
public:
    configuracion(string nombreArchivo);

    void cargarConfig();
    void guardarConfig(int intentos, bool genAleatorio);
    int cargarIntentos();
    bool CargarGeneradoAleat();

private:
    string nombreArchivo;
    array<int, 2> configuraciones;
};


#endif //PUNTOYFAMA_GUARDARCONFIGURACION_H