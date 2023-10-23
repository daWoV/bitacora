//Este programa declara los metodos de la clase Bitacora.

//Autores:
//Dael Chávez Ferryera A01771963
//Carlos Iván Fonseca Mondragón A01771689
//César Castro Martínez A01771970

//Fecha de creación: 15/10/2023

#pragma once

#include <vector>
#include <string>
#include "eventos.hpp"

class Bitacora {
public:
    std::vector<Eventos> eventosVector;
public:
    Bitacora();
    void agregarEvento(const std::string& evento);
    void agregarEventoPorLote(const std::string& archivo);
    std::vector<std::string> consultarEvento(const std::string& busqueda) const;
    std::vector<std::string> consultarPorRango(const std::string& inicio, const std::string& fin) const;
    void ordenarBitacora();
    void limpiarBitacora();
    void almacenarOrdenamiento(const std::string& archivo) const;
};
