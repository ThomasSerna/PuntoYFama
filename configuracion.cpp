// Sistema de persistencia de datos para las configuraciones preferidas por el usuario

#include "configuracion.h"

configuracion::configuracion(string nArchivo) {
    nombreArchivo = nArchivo;
}

void configuracion::guardarConfig(int intentos, bool genAleatorio) {
    ofstream archivoGuardarConfig(nombreArchivo);
    if (!archivoGuardarConfig.is_open()) {
        cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
    }

    archivoGuardarConfig << to_string(intentos) << endl;
    archivoGuardarConfig << to_string(genAleatorio) << endl;
    archivoGuardarConfig.close();
}

void configuracion::cargarConfig() {
    ifstream archivoCargarConfig(nombreArchivo);
    int i = 0;
    string linea;

    if (!archivoCargarConfig.is_open()) {
        cerr << "Error: No se pudo abrir el archivo para leer." << endl;
    }

    while (getline(archivoCargarConfig, linea)) {
        configuraciones[i++] = stoi(linea);
    }

    archivoCargarConfig.close();
}

int configuracion::cargarIntentos() {
    return configuraciones[0];
}

bool configuracion::CargarGeneradoAleat() {
    int nGenAleat = configuraciones[1];

    if (nGenAleat == 0) {
        return false;
    }

    return true;
}





