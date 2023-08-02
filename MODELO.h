#ifndef MODELO_H
#define MODELO_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "MapaModelo.h"
#include "MapaVista.h"


class MODELO {
private:
    float posicionX;
    float posicionY;
    bool enElAire;
    float desplazamientoY;
  //  std::vector<sf::Sprite>& spritesMapa; // Vector de sprites del mapa
    MapaVista mapaVista;

    std::vector<sf::Sprite> spritesMapa;

public:
    MODELO(float posX, float posY);
    float getPosicionX() const;
    float getPosicionY() const;
    bool estaEnElAire() const;

    void mover(float desplazamientoX, float deltaTime);
    void saltar(float velocidadSalto);
    void aplicarGravedad(float gravedad, float deltaTime);
    void setEnElAire(bool value);

    void mover(float desplazamientoX, float deltaTime, const MapaModelo& mapaModelo);
    void verificarColisiones();
    MapaModelo mapaModelo;


};

#endif // MODELO_H
