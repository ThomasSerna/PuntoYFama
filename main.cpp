#include <iostream>
#include "utilidades.h"

using namespace std;

void empezarJuego(array<int, 4> nGanador) {

    bool juegoAcabado = false;
    int nIntento, famas, puntos;
    array<int, 4> nJugador;
    int i = 0;

    while (!juegoAcabado) {
        cout << "Intento " << to_string(++i) << ": ";
        cin >> nIntento;
        nJugador = utilidades::obtenerNumero(nIntento);

        famas = utilidades::confirmarFama(nGanador, nJugador);
        puntos = utilidades::confirmarPunto(nGanador, nJugador);

        cout << "Obtuviste el siguiente puntaje" << endl;
        cout << "Famas: " << to_string(famas) << endl;
        cout << "Puntos: " << to_string(puntos) << endl;
        cout << "" << endl;

        if (famas == 4) {
            cout << "Felicidades, ganaste." << endl;
            juegoAcabado = true;
        }

    }

}

int main() {

    cout << "Bienvenido a punto y fama" << endl;

    int opcion = 0;
    int n = 0;
    int opcionEmpezarJuego = 0;
    array<int, 4> nGanador;

    while (opcion != 3) {

        cout << "" << endl;
        cout << "Menu principal" << endl;
        cout << "1. Empezar a jugar" << endl;
        cout << "2. Aprender a jugar" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "" << endl;
        cout << "Selecciona una opcion: ";

        cin >> opcion;

        if (opcion == 1) {
            cout << "Opciones de juego:" << endl;
            cout << "1. Deseas que el programa genere el numero aleatoriamente" << endl;
            cout << "2. Desea que el usuario digite el numero a adivinar" << endl;
            cout << "" << endl;
            cout << "Selecciona una opcion: ";

            cin >> opcionEmpezarJuego;

            if (opcionEmpezarJuego == 1) {
                cout << "Generando numero aleatorio de 4 cifras (sin repetir numero)" << endl;
                nGanador = utilidades::generarNumero();
                cout << "Numero generado exitosamente." << endl;
                cout << "" << endl;
                cout << "Comencemos el juego..." << endl;
                cout << "" << endl;

                empezarJuego(nGanador);
            } else if (opcionEmpezarJuego == 2) {
                cout << "Escriba el número a adivinar: ";

                cin >> n;
                nGanador = utilidades::obtenerNumero(n);

                empezarJuego(nGanador);
            } else {
                cout << "" << endl;
                cout << "Opcion invalida" << endl;
            }
        } else if (opcion == 2) {
            cout << "Guia del juego:" << endl;
            cout << "1. El programa puede generar un numero de 4 cifras sin repetir digitos, o puedes elegir el numero a adivinar." << endl;
            cout << "2. Tu objetivo es adivinar ese numero." << endl;
            cout << "3. Ingresa un numero de 4 cifras en cada intento." << endl;
            cout << "4. 'Fama' significa que acertaste el digito y su posicion." << endl;
            cout << "5. 'Punto' significa que acertaste el digito pero esta en otra posicion." << endl;
            cout << "6. Ganas cuando obtienes 4 famas." << endl;

        } else if (opcion == 3) {
            cout << "" << endl;
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "" << endl;
            cout << "Opcion invalida" << endl;
        }

    }

    return 0;
}