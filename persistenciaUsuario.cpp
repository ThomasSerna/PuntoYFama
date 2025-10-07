//
// Created by User on 6/10/2025.
//

#include "persistenciaUsuario.h"

persistenciaUsuario::persistenciaUsuario(string archivo) {
    nArchivo = archivo;
}

vector<string> persistenciaUsuario::dividirString(string linea, char delimitador) {
    vector<string> sDividido;
    string division;
    stringstream sLinea(linea);

    while (getline(sLinea, division, delimitador)) {
        sDividido.push_back(division);
    }

    return sDividido;
}

usuario persistenciaUsuario::encontrarUsuario(vector<usuario> listaUsuarios, string nombre) {
    for (usuario u: listaUsuarios) {
        if (u.getNombre() == nombre) {
            return u;
        }
    }

    usuario uNuevo(nombre);
    return uNuevo;
}

int persistenciaUsuario::indiceUsuario(usuario user) {
    bool usuarioEncontrado = false;
    int iUsuario;

    for (int i; i < listaUsuarios.size(); i++) {
        if (user.getNombre() == listaUsuarios[i].getNombre()) {
            usuarioEncontrado = true;
            iUsuario = i;
            i = listaUsuarios.size();
        }
    }
    if (usuarioEncontrado == true) {
        return iUsuario;
    }
    return -1;

}

void persistenciaUsuario::guardarUsuario(usuario jugador) {
    ofstream archivoGuardarUsuario(nArchivo);
    if (!archivoGuardarUsuario.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de usuarios. (ofstream)" << endl;
    }

    // Actualizar usuario dentro del vector o añadirlo
    int iUsuario = indiceUsuario(jugador);
    if (iUsuario == -1) {
        listaUsuarios.push_back(jugador);
    } else {
        listaUsuarios[iUsuario] = jugador;
    }

    // Escribir en el archivo de texto
    for (usuario jUser: listaUsuarios) {
        // Error al sumar la cantidad de intentos
        string lCantIntentos = "";
        for (int n: jUser.getCantidadIntentos()) {
            lCantIntentos += to_string(n) + "/";
        }
        // hasta aca va el error

        string infoJugador = jUser.getNombre() + "," + to_string(jUser.getPartidasGanadas()) + "," + to_string(jUser.getPartidasPerdidas()) + "," + lCantIntentos;


        archivoGuardarUsuario << infoJugador << endl;
    }

    archivoGuardarUsuario.close();

}

usuario persistenciaUsuario::cargarUsuarios(string nombre) {

    ifstream archivoCargarUsuario(nArchivo);
    string linea;

    if (!archivoCargarUsuario.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de usuarios. (ifstream)" << endl;
    }

    while (getline(archivoCargarUsuario, linea)) {
        vector<int> cIntentos;
        vector<string> stringUsuario = dividirString(linea, ',');

        for (string p: dividirString(stringUsuario[3], '/')) {
            if (!p.empty()) {
                cIntentos.push_back(stoi(p));
            }
        }

        usuario u(stringUsuario[0]);
        u.setPartidasGanadas(stoi(stringUsuario[1]));
        u.setPartidasPerdidas(stoi(stringUsuario[2]));
        u.setCantidadIntentos(cIntentos);

        listaUsuarios.push_back(u);
    }

    archivoCargarUsuario.close();

    return encontrarUsuario(listaUsuarios, nombre);
}


