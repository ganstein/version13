#ifndef ENEMIGOS_MODELO_H
#define ENEMIGOS_MODELO_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "EnemigoVista.h" // Asumiendo que tienes la definición de la clase EnemigoVista en su propio archivo de cabecera.
#include "EnemigoHijo.h"
class EnemigosModelo {
private:
    std::vector<std::shared_ptr<EnemigoVista>> entities; // Usar punteros compartidos (shared_ptr)

public:
    EnemigosModelo();

    virtual void crearEnemigosDesdeCSV(const std::string& nombreArchivo, float spriteTamaño);

    virtual void addEntity(const std::shared_ptr<EnemigoVista>& entity); // Usar puntero compartido (shared_ptr)

    virtual std::vector<std::shared_ptr<EnemigoVista>> obtenerEntidades(); // Usar puntero compartido (shared_ptr)
};


#endif // ENEMIGOS_MODELO_H
