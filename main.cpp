//Este programa tiene el proposito de ordenar una bitacora de eventos, 
//la cual puede ser ingresada por el usuario o por medio de un archivo de texto, 
//y posteriormente ordenarla por fecha o por orden alfabetico, tambien se puede buscar un evento en especifico o un rango de eventos, 
//y por ultimo se puede guardar la bitacora ordenada en un archivo de texto.

//Autores:
//Dael Chávez Ferryera A01771963
//Carlos Iván Fonseca Mondragón A01771689
//César Castro Martínez A01771970

//Fecha de creación: 15/10/2023

#include <iostream>
#include <map>
#include "bitacora.cpp"
#include "eventos.cpp"

int main() {
    Bitacora bitacora;

    std::map<std::string, int> mesAMesNumerico = {
        {"Jan", 1},
        {"Feb", 2},
        {"Mar", 3},
        {"Apr", 4},
        {"May", 5},
        {"Jun", 6},
        {"Jul", 7},
        {"Aug", 8},
        {"Sep", 9},
        {"Oct", 10},
        {"Nov", 11},
        {"Dec", 12}
    };

    std::cout << "Bienvenido a la Bitácora" << std::endl;
    while (true) {
        std::cout << "\n" << std::endl;
        std::cout << "--------- Menú de Bitácora: ---------" << std::endl;
        std::cout << "1. Agregar evento" << std::endl;
        std::cout << "2. Agregar eventos desde archivo" << std::endl;
        std::cout << "3. Consultar eventos" << std::endl;
        std::cout << "4. Consultar eventos por rango" << std::endl;
        std::cout << "5. Ordenar Bitácora" << std::endl;
        std::cout << "6. Ordenar Bitácora por fecha" << std::endl;
        std::cout << "7. Limpiar Bitácora" << std::endl;
        std::cout << "8. Almacenar ordenamiento en archivo" << std::endl;
        std::cout << "0. Salir" << std::endl;

        int opcion;
        std::cout << "\n" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 0) {
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        }

        switch (opcion) {
            case 1: {
                std::string evento;
                std::cout << "\n" << std::endl;
                std::cout << "Ingrese el evento: ";
                std::cin.ignore();
                std::getline(std::cin, evento);
                bitacora.agregarEvento(evento);
                break;
            }
            case 2: {
                std::string archivo;
                std::cout << "\n" << std::endl;
                std::cout << "Ingrese el nombre del archivo: ";
                std::cin >> archivo;
                bitacora.agregarEventoPorLote(archivo);
                std::cout << "\n" << std::endl;
                std::cout << "Eventos agregados desde el archivo." << std::endl;
                break;
            }
            case 3: {
                std::string busqueda;
                std::cout << "\n" << std::endl;
                std::cout << "Ingrese la cadena de búsqueda: ";
                std::cin.ignore();
                std::getline(std::cin, busqueda);
                std::vector<std::string> resultados = bitacora.consultarEvento(busqueda);
                std::cout << "\n" << std::endl;
                std::cout << "Eventos encontrados:" << std::endl;
                for (const std::string& evento : resultados) {
                    std::cout << evento << std::endl;
                }
                break;
            }
            case 4: {
                std::string inicio, fin;
                std::cout << "\n" << std::endl;
                std::cout << "Ingrese el rango de eventos (inicio): ";
                std::cin.ignore();
                std::getline(std::cin, inicio);
                std::cout << "Ingrese el rango de eventos (fin): ";
                std::getline(std::cin, fin);
                std::vector<std::string> resultados = bitacora.consultarPorRango(inicio, fin);
                std::cout << "\n" << std::endl;
                std::cout << "Eventos encontrados en el rango:" << std::endl;
                for (const std::string& evento : resultados) {
                    std::cout << evento << std::endl;
                }
                break;
            }            
            case 5:
                bitacora.ordenarBitacora();
                std::cout << "\n" << std::endl;
                std::cout << "Bitácora ordenada." << std::endl;
                break;
            case 6:{
                std::vector<std::string> eventosCopia = bitacora.eventosVector[0].obtenerEventos();
                auto compararFechas = [&](const std::string& a, const std::string& b) {
                    std::string fechaA = a.substr(0, 6); //posicion 0, 6 caracteres
                    std::string fechaB = b.substr(0, 6);
                    int mesA = mesAMesNumerico[fechaA.substr(0, 3)]; //posicion 0, 3 caracteres
                    int diaA = std::stoi(fechaA.substr(4, 2)); //posicion 4, 2 caracteres        
                    int mesB = mesAMesNumerico[fechaB.substr(0, 3)]; //posicion 0, 3 caracteres
                    int diaB = std::stoi(fechaB.substr(4, 2)); //posicion 4, 2 caracteres
                    if (mesA == mesB) {
                        if (diaA == diaB) {
                            return a < b; // Si los días son iguales, conservar el orden original
                        }
                        return diaA < diaB;
                    }
                    return mesA < mesB;
                };
                std::sort(eventosCopia.begin(), eventosCopia.end(), compararFechas); //Orden de complejidad: O(N * log(N)), donde N es el número de eventos en el vector. Esto es debido a que std::sort es generalmente eficiente y tiene un tiempo de ejecución logarítmico.
                bitacora.eventosVector[0].eventos = eventosCopia; // Copiar el vector ordenado al vector original
                std::cout << "\n" << std::endl;
                std::cout << "Bitácora ordenada por fecha." << std::endl;
                break;               
            }
            case 7:
                bitacora.limpiarBitacora();
                std::cout << "\n" << std::endl;
                std::cout << "Bitácora limpiada." << std::endl;
                break;
            case 8: {
                std::string archivo;
                std::cout << "\n" << std::endl;
                std::cout << "Ingrese el nombre del archivo de salida: ";
                std::cin >> archivo;
                bitacora.almacenarOrdenamiento(archivo);
                std::cout << "\n" << std::endl;
                std::cout << "Ordenamiento almacenado en " << archivo << std::endl;
                break;
            }
            default:
                std::cout << "Opción no válida. Intente nuevamente." << std::endl;
        }
    }

    return 0;
}