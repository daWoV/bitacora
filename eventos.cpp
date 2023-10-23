//Este programa le da funcionalidad a la clase Eventos.

//Autores:
//Dael Chávez Ferryera A01771963
//Carlos Iván Fonseca Mondragón A01771689
//César Castro Martínez A01771970

//Fecha de creación: 15/10/2023

#include "eventos.hpp"

// Eventos::Eventos(int numEventos)
// Orden de complejidad: O(1) - constante, ya que solo se redimensiona el vector.
Eventos::Eventos(int numEventos) {
    eventos.resize(numEventos);
}

// Eventos::agregarEvento(const std::string& evento)
// Orden de complejidad: O(1) - constante, ya que se agrega un elemento al final del vector.
void Eventos::agregarEvento(const std::string& evento) {
    eventos.push_back(evento);
}

// Eventos::obtenerEventos() const
// Orden de complejidad: O(1) - constante, ya que solo se devuelve el vector directamente.
std::vector<std::string> Eventos::obtenerEventos() const {
    return eventos;
}