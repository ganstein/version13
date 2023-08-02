#include "EnemigosModelo.h"

EnemigosModelo::EnemigosModelo() {
    std::cout << "constructor enemigomodelo";
    crearEnemigosDesdeCSV("mapa0.csv", 70.0);
}

void EnemigosModelo::crearEnemigosDesdeCSV(const std::string& nombreArchivo, float spriteTama�o) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;
    int fila = 0;

    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string valor;
        int col = 0;

        while (std::getline(iss, valor, ',')) {
            if (valor == "10") {
                float posX = col * spriteTama�o;
                float posY = fila * spriteTama�o;
                if (fila % 2 == 0) {
                    addEntity(std::make_shared<EnemigoHijo>(spriteTama�o, posX, posY));
                }
                else {
                    addEntity(std::make_shared<EnemigoVista>(spriteTama�o, posX, posY));
                }
               
            }

            col++;
        }

        fila++;
    }
}

void EnemigosModelo::addEntity(const std::shared_ptr<EnemigoVista>& entity) {
    entities.push_back(entity);
}

std::vector<std::shared_ptr<EnemigoVista>> EnemigosModelo::obtenerEntidades() {
    return entities; // No necesitas std::move en este caso
}