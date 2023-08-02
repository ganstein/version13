#ifndef JUGADORVISTA_H
#define JUGADORVISTA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MODELO.h"

class JugadorVista {
public:
    sf::Sprite jugadorSprite;
    sf::Texture texturaJugador;

public:
    JugadorVista();

    void actualizar(float jugadorX, float jugadorY, const sf::View& camara);

    sf::Sprite& getSprite();
    const sf::Sprite& getSprite() const;
    bool colisionaCon(const sf::Sprite& otroSprite) const;
};

#endif // JUGADORVISTA_H
