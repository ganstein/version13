#ifndef EVENTO_H
#define EVENTO_H

#include <SFML/Graphics.hpp>
#include "MenuVista.h"

class Evento
{
public:
    Evento();

    bool pollEvent(sf::RenderWindow& ventana);
    bool esCerrado();
    bool esBotonSoltado();
    bool estaEnOpcionJugar(const MenuVista& menu, const sf::RenderWindow& ventana);
    bool estaEnOpcionSalir(const MenuVista& menu, const sf::RenderWindow& ventana);
    bool isSpacePressed();
    bool isAPressed();
    bool isDPressed();
    bool isKeyPressed(sf::Keyboard::Key key);

private:
    sf::Event evento_;
};

#endif // EVENTO_H