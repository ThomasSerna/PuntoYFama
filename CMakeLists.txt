cmake_minimum_required(VERSION 4.0)
project(PuntoYFama)

set(CMAKE_CXX_STANDARD 20)

add_executable(PuntoYFama main.cpp
        utilidades.cpp
        utilidades.h
        Configuracion.cpp
        Configuracion.h
        usuario.cpp
        usuario.h
        persistenciaUsuario.cpp
        persistenciaUsuario.h
)
