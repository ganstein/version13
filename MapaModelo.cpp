#include "MapaModelo.h"

void MapaModelo::cargarMapaDesdeArchivo(const std::string& archivo) {
    std::ifstream inputFile(archivo);
    if (!inputFile) {
        std::cerr << "Error al abrir el archivo " << archivo << std::endl;
        return;
    }

    std::string linea;
    int fila = 0;
    while (std::getline(inputFile, linea)) {
        std::istringstream iss(linea);
        int valor;
        int columna = 0;

        while (iss >> valor) {
            mapa[fila][columna] = valor;
            ++columna;
        }

        ++fila;
    }

    inputFile.close();
}

int MapaModelo::getValorCasilla(int fila, int columna) const {
   return mapa[fila][columna];
}
