#include <iostream>

#include "configuracion.h"
#include "persistenciaUsuario.h"
#include "usuario.h"
#include "utilidades.h"

// Aún falta añadir la funcionalidad de estadisticas, para la persistencia de los datos del usuario

using namespace std;

string nombreConfig = "config.txt";
string nombreUsers = "usuarios.csv";

configuracion mConfig(nombreConfig);
persistenciaUsuario mUsers(nombreUsers);
usuario jugador;

void empezarJuego(int intentosMax, bool nAleatorio) {

    array<int, 4> nGanador;
    int n = 0;
    bool juegoAcabado = false;
    int nIntento, famas, puntos;
    array<int, 4> nJugador;
    int i = 0;
    int numeroGanador;

    char opcionVerStats;

    if (nAleatorio == true) {
        nGanador = utilidades::generarNumero();
    } else if (nAleatorio == false) {
        cout << "Escriba el número a adivinar: ";
        cin >> n;
        nGanador = utilidades::obtenerArreglo(n);
    }

    while (!juegoAcabado) {
        cout << "Intento " << to_string(++i) << ": ";
        cin >> nIntento;
        nJugador = utilidades::obtenerArreglo(nIntento);

        famas = utilidades::confirmarFama(nGanador, nJugador);
        puntos = utilidades::confirmarPunto(nGanador, nJugador);

        cout << "Obtuviste el siguiente puntaje" << endl;
        cout << "Famas: " << to_string(famas) << endl;
        cout << "Puntos: " << to_string(puntos) << endl;
        cout << "" << endl;

        if (famas == 4) {
            cout << "Felicidades, ganaste." << endl;
            cout << "Te tomo " << to_string(i) << " intentos." << endl;
            jugador.agregarRondaGanada(i);
            cout << "Deseas ver tus estadisticas? (S/N) ";
            cin >> opcionVerStats;
            if (tolower(opcionVerStats) == 's') {
                jugador.mostrarDatosUsuario();
            }
            juegoAcabado = true;
        }

        if (i == intentosMax) {
            cout << "Perdiste, ya no tienes mas intentos disponibles." << endl;
            numeroGanador = utilidades::obtenerNumero(nGanador);
            cout << "El numero era " << to_string(numeroGanador) << endl;
            jugador.agregarRondaPerdida();
            cout << "Deseas ver tus estadisticas? (S/N) ";
            cin >> opcionVerStats;
            if (tolower(opcionVerStats) == 's') {
                jugador.mostrarDatosUsuario();
            }
            juegoAcabado = true;
        }

    }

    mUsers.guardarUsuario(jugador);

}

int main() {
    // Sistema de persistencia de datos para la configuración del juego
    cout << "Cargando datos..." << endl;
    mConfig.cargarConfig();
    int intentos = mConfig.cargarIntentos();
    bool nGeneradoAleat = mConfig.CargarGeneradoAleat();

    // Iniciar sesion por tu nombre de usuario
    string nombre;
    cout << "Dame tu nombre de usuario: ";
    cin >> nombre;

    jugador = mUsers.cargarUsuarios(nombre);

    // Variables de control de menús
    int opcion = -1;

    cout << "Bienvenido a punto y fama" << endl;

    while (opcion != 0) {
        int opcionMenuConfig = -1;
        char opcionAleat;

        cout << "" << endl;
        cout << "Menu principal" << endl;
        cout << "1. Empezar a jugar" << endl;
        cout << "2. Aprender a jugar" << endl;
        cout << "3. Ver estadisticas de juego" << endl;
        cout << "4. Configuracion del juego" << endl;
        cout << "Ingresa 0 para salir del programa" << endl;
        cout << "" << endl;
        cout << "Selecciona una opcion: ";

        cin >> opcion;

        if (opcion == 1) {
            cout << "Comencemos el juego..." << endl;
            cout << "" << endl;
            empezarJuego(intentos, nGeneradoAleat);

        } else if (opcion == 2) {
            cout << "Guia del juego:" << endl;
            cout << "1. El programa puede generar un numero de 4 cifras sin repetir digitos, o puedes elegir el numero a adivinar." << endl;
            cout << "2. Tu objetivo es adivinar ese numero." << endl;
            cout << "3. Ingresa un numero de 4 cifras en cada intento." << endl;
            cout << "4. 'Fama' significa que acertaste el digito y su posicion." << endl;
            cout << "5. 'Punto' significa que acertaste el digito pero esta en otra posicion." << endl;
            cout << "6. Ganas cuando obtienes 4 famas." << endl;

        } else if (opcion == 3) {
            cout << "Tus estadisticas:" << endl;
            jugador.mostrarDatosUsuario();

        } else if (opcion == 4){

            while (opcionMenuConfig != 0) {
                cout << "Configuracion del juego:" << endl;

                if (intentos == -1) {
                    cout << "1. Cantidad maxima de intentos por ronda: Sin limite" << endl;
                } else {
                    cout << "1. Cantidad maxima de intentos por ronda: " << to_string(intentos) << endl;
                }
                if (nGeneradoAleat == true) {
                    cout << "2. Numero generado aleatoriamente: Si" << endl;
                } else if (nGeneradoAleat == false) {
                    cout << "2. Numero generado aleatoriamente: No" << endl;
                }
                cout << "Ingresa 0 para volver al menu anterior" << endl;
                cout << "" << endl;
                cout << "Seleccione la configuracion que desee cambiar: ";
                cin >> opcionMenuConfig;

                if (opcionMenuConfig == 1) {
                    cout << "Si desea que no haya limite, escriba 0" << endl;
                    cout << "Ingrese la cantidad maxima de intentos por ronda: ";
                    cin >> intentos;
                    if (intentos == 0) {
                        intentos = -1;
                    }

                } else if (opcionMenuConfig == 2) {
                    cout << "Desea que el numero a adivinar se genere aleatoriamente? (S/N) ";
                    cin >> opcionAleat;
                    if (tolower(opcionAleat) == 's') {
                        nGeneradoAleat = true;
                    } else if (tolower(opcionAleat) == 'n') {
                        nGeneradoAleat = false;
                    } else {
                        cout << "Opcion invalida" << endl;
                    }
                } else if (opcionMenuConfig == 0) {
                } else {
                    cout << "Opcion invalida" << endl;
                }

                mConfig.guardarConfig(intentos, nGeneradoAleat);
            }

        } else if (opcion == 0) {
            cout << "Saliendo del programa..." << endl;

        } else {
            cout << "Opcion invalida" << endl;
        }

    }

    return 0;
}
