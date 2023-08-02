#ifndef FONDOVISTA_H
#define FONDOVISTA_H

#include <iostream>
#include <SFML/Graphics.hpp>

class FondoVista {
private:
    sf::Sprite fondoSprite;
    sf::Texture fondoTexture;

public:
    FondoVista();

    void dibujar(sf::RenderWindow& ventana) const;
};

#endif // FONDOVISTA_H
