//
// Created by User on 3/10/2025.
//

#include "utilidades.h"

// Genera el número aleatorio sin repetir número
array<int, 4> utilidades::generarNumero() {
    array<int, 4>listaJuego = {-1, -1, -1, -1};
    int min = 0;
    int max = 9;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    for (int i = 0; i < listaJuego.size(); i++) {
        int nAleatorio = distrib(gen);

        for (int j = 0; j < listaJuego.size(); j++) {
            while (listaJuego[j] == nAleatorio) {
                nAleatorio = distrib(gen);
                j = 0;
            }

        }

        listaJuego[i] = nAleatorio;
    }

    return listaJuego;
}

// Convertir un número entrado por el usuario (integer) en un arreglo usando sus cifras
array<int, 4> utilidades::obtenerNumero(int numeroUsuario) {
    array<int, 4> nUsuario = {0,0,0,0};
    int cifra;

    for (int i = nUsuario.size()-1; i >= 0; i--) {
        cifra = numeroUsuario%10;
        numeroUsuario = numeroUsuario/10;

        nUsuario[i] = cifra;
    }

    return nUsuario;
}

// Obtener las famas, comparando el número del usuario con el del programa
int utilidades::confirmarFama(array<int, 4> nGanador, array<int, 4> nUsuario) {
    int famas = 0;

    for (int i = 0; i < nGanador.size(); i++) {

        if (nGanador[i] == nUsuario[i]) {
            famas++;
        }

    }

    return famas;
}

// Obtener los puntos, comparando el número del usuario con el del programa
int utilidades::confirmarPunto(array<int, 4> nGanador, array<int, 4> nUsuario) {
    int puntos = 0;

    for (int i = 0; i < nGanador.size(); i++) {
        for (int j = 0; j < nUsuario.size(); j++) {

            if (nGanador[i] == nUsuario[j]) {
                puntos++;
            }
        }
    }

    return puntos;
}


