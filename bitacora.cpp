//Este programa tiene el proposito de establecer la funcionalidad de la clase Bitacora.

//Autores:
//Dael Chávez Ferryera A01771963
//Carlos Iván Fonseca Mondragón A01771689
//César Castro Martínez A01771970

//Fecha de creación: 15/10/2023

#include "bitacora.hpp"
#include "eventos.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

// Bitacora::Bitacora()
// Orden de complejidad: O(1) - constante, ya que solo se agrega un Eventos al vector.
Bitacora::Bitacora() {
    eventosVector.push_back(Eventos(0));
}

// Bitacora::agregarEvento(const std::string& evento)
// Orden de complejidad: O(1) - constante, ya que agrega un evento al primer Eventos en el vector.
void Bitacora::agregarEvento(const std::string& evento) {
    if (!eventosVector.empty()) {
        eventosVector[0].agregarEvento(evento);
    }
}

// Bitacora::agregarEventoPorLote(const std::string& archivo)
// Orden de complejidad: O(N) - lineal, donde N es la cantidad de eventos en el archivo, ya que se lee y agrega cada evento uno por uno.
void Bitacora::agregarEventoPorLote(const std::string& archivo) {
    std::ifstream archivoLote(archivo);
    if (archivoLote.is_open()) {
        std::string line;
        while (std::getline(archivoLote, line)) {
            agregarEvento(line);
        }
        archivoLote.close();
    }
}

// Bitacora::consultarEvento(const std::string& busqueda) const
// Orden de complejidad: O(N*M) - cuadrática, donde N es la cantidad de Eventos en el vector y M es la cantidad de eventos en cada Eventos, ya que se recorre cada Eventos y cada evento en cada Eventos.
std::vector<std::string> Bitacora::consultarEvento(const std::string& busqueda) const {
    std::vector<std::string> resultados;
    if (!eventosVector.empty()) {
        for (const Eventos& eventos : eventosVector) {
            for (const std::string& evento : eventos.eventos) {
                if (evento.find(busqueda) != std::string::npos) {
                    resultados.push_back(evento);
                }
            }
        }
    }
    return resultados;
}

// Bitacora::consultarPorRango(const std::string& inicio, const std::string& fin) const
// Orden de complejidad: O(N*M) - cuadrática, donde N es la cantidad de Eventos en el vector y M es la cantidad de eventos en cada Eventos, ya que se recorre cada Eventos y cada evento en cada Eventos.
std::vector<std::string> Bitacora::consultarPorRango(const std::string& inicio, const std::string& fin) const {
    std::vector<std::string> resultados;
    if (!eventosVector.empty()) {
        for (const Eventos& eventos : eventosVector) {
            bool dentroDelRango = false;
            for (const std::string& evento : eventos.obtenerEventos()) {
                if (evento.find(inicio) != std::string::npos) {
                    dentroDelRango = true;
                }
                if (dentroDelRango) {
                    resultados.push_back(evento);
                }
                if (evento.find(fin) != std::string::npos) {
                    dentroDelRango = false;
                }
            }
        }
    }
    return resultados;
}

// Bitacora::ordenarBitacora()
// Orden de complejidad: O(N * log(N)) - donde N es el número de eventos en el primer Eventos del vector, ya que se realiza una ordenación en el primer Eventos.
void Bitacora::ordenarBitacora() {
    if (!eventosVector.empty()) {  
        std::vector<std::string> eventos = eventosVector[0].eventos;
        std::sort(eventos.begin(), eventos.end());
        eventosVector[0].eventos = eventos;
    }
}

// Bitacora::limpiarBitacora()
// Orden de complejidad: O(1) - constante, ya que se borra el vector y se agrega un nuevo Eventos.
void Bitacora::limpiarBitacora() {
    eventosVector.clear();
    eventosVector.push_back(Eventos(0));
}

// Bitacora::almacenarOrdenamiento(const std::string& archivo) const
// Orden de complejidad: O(N) - donde L es el número de eventos en el primer Eventos del vector, ya que se recorre el vector y se escribe en el archivo.
void Bitacora::almacenarOrdenamiento(const std::string& archivo) const {
    std::ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        for (const std::string& evento : eventosVector[0].eventos) {
            archivoSalida << evento << "\n";
        }
        archivoSalida.close();
    }
}
