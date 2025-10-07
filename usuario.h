//
// Created by User on 6/10/2025.
//

#ifndef PUNTOYFAMA_USUARIO_H
#define PUNTOYFAMA_USUARIO_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class usuario {
public:
    usuario(string nombre);
    usuario();

    void agregarRondaGanada(int intentos);
    void agregarRondaPerdida();
    void mostrarDatosUsuario();

    string getNombre();
    int getPartidasGanadas();
    int getPartidasPerdidas();
    vector<int> getCantidadIntentos();
    int getPorcentajeGanado();
    int getPromedioIntentos();
    void setNombre(string nombre);
    void setPartidasGanadas(int ganadas);
    void setPartidasPerdidas(int perdidas);
    void setCantidadIntentos(vector<int> intentos);

private:
    string nombre;
    int partidasGanadas;
    int partidasPerdidas;
    vector<int> cantidadIntentos;
};


#endif //PUNTOYFAMA_USUARIO_H