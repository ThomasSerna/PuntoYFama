#ifndef PUNTOYFAMA_UTILIDADES_H
#define PUNTOYFAMA_UTILIDADES_H

#include <random>
#include <array>

using namespace std;

class utilidades {
public:

    // Funciones logicas basicas del programa
    static array<int, 4> generarNumero();
    static array<int, 4> obtenerNumero(int numeroUsuario);
    static int confirmarFama(array<int, 4> nGanador, array<int, 4> nUsuario);
    static int confirmarPunto(array<int, 4> nGanador, array<int, 4> nUsuario);
};


#endif //PUNTOYFAMA_UTILIDADES_H