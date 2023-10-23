//Este programa declara los metodos de la clase Eventos.

//Autores:
//Dael Chávez Ferryera A01771963
//Carlos Iván Fonseca Mondragón A01771689
//César Castro Martínez A01771970

//Fecha de creación: 15/10/2023

#pragma once

#include <vector>
#include <string>

class Eventos {
public:
    std::vector<std::string> eventos;
public:
     // Constructor de la clase Eventos
    Eventos(int numEventos);

    // Agrega un evento a la lista de eventos
    void agregarEvento(const std::string& evento);

    // Obtiene la lista de eventos 
    std::vector<std::string> obtenerEventos() const;
};