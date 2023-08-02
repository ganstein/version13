#ifndef MAPAMODELO_H
#define MAPAMODELO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class MapaModelo {
private:
    int mapa[16][185]; // Definición del arreglo para almacenar el mapa

public:
    void cargarMapaDesdeArchivo(const std::string& archivo);
    int getValorCasilla(int fila, int columna) const;
};

#endif // MAPAMODELO_H
