//
// Created by User on 6/10/2025.
//

#include "usuario.h"

usuario::usuario(string nombre) {
    this->nombre = nombre;
    partidasGanadas = 0;
    partidasPerdidas = 0;
}
usuario::usuario() {}

void usuario::agregarRondaGanada(int intentos) {
    partidasGanadas++;
    cantidadIntentos.push_back(intentos);
}

void usuario::agregarRondaPerdida() {
    partidasPerdidas++;
}

int usuario::getPorcentajeGanado() {
    return (partidasGanadas*100)/(partidasGanadas+partidasPerdidas);
}

int usuario::getPromedioIntentos() {
    int sum = 0;

    if (cantidadIntentos.size() == 0) {
        return 0;
    }

    for (int n: cantidadIntentos) {
        sum += n;
    }

    return sum/cantidadIntentos.size();
}


void usuario::mostrarDatosUsuario() {
    cout << "Nombre de usuario: " << nombre << endl;
    cout << "Cantidad de partidas ganadas: " << to_string(partidasGanadas) << endl;
    cout << "Cantidad de partidas perdidas: " << to_string(partidasPerdidas) << endl;
    cout << "Porcentaje de victoria: " << to_string(getPorcentajeGanado()) << "%" << endl;
    cout << "Promedio de intentos por ronda ganada: " << to_string(getPromedioIntentos()) << endl;
}

string usuario::getNombre() {
    return nombre;
}

vector<int> usuario::getCantidadIntentos() {
    return cantidadIntentos;
}

int usuario::getPartidasGanadas() {
    return partidasGanadas;
}

int usuario::getPartidasPerdidas() {
    return partidasPerdidas;
}

void usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

void usuario::setPartidasGanadas(int ganadas) {
    partidasGanadas = ganadas;
}

void usuario::setPartidasPerdidas(int perdidas) {
    partidasPerdidas = perdidas;
}

void usuario::setCantidadIntentos(vector<int> intentos) {
    cantidadIntentos = intentos;
}


