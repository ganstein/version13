#ifndef MAPAVISTA_H
#define MAPAVISTA_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "MapaModelo.h"

class MapaVista {
private:
    std::vector<sf::Sprite> sprites;
    sf::Texture pisoTexture;
    sf::Texture paredTexture;
    sf::Texture bloqueTexture;

public:
    MapaVista();

    void generarSprites(const MapaModelo& modelo);
    std::vector<sf::Sprite>& getSprites();
    void dibujar(sf::RenderWindow& ventana) const;
};

#endif // MAPAVISTA_H
