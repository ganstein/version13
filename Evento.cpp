#include "Evento.h"

Evento::Evento() : evento_() {}

bool Evento::pollEvent(sf::RenderWindow& ventana)
{
    return ventana.pollEvent(evento_);
}

bool Evento::esCerrado()
{
    return evento_.type == sf::Event::Closed;
}

bool Evento::esBotonSoltado()
{
    return evento_.type == sf::Event::MouseButtonReleased && evento_.mouseButton.button == sf::Mouse::Left;
}

bool Evento::estaEnOpcionJugar(const MenuVista& menu, const sf::RenderWindow& ventana)
{
    sf::Vector2f mousePos(static_cast<float>(evento_.mouseButton.x), static_cast<float>( evento_.mouseButton.y));
            
    return menu.opcionJugar.getGlobalBounds().contains(mousePos);
}

bool Evento::estaEnOpcionSalir(const MenuVista& menu, const sf::RenderWindow& ventana)
{
    sf::Vector2f mousePos(static_cast<float>(evento_.mouseButton.x), static_cast<float>(evento_.mouseButton.y));
    return menu.opcionSalir.getGlobalBounds().contains(mousePos);

}

bool Evento::isKeyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

bool Evento::isSpacePressed()
{
    return isKeyPressed(sf::Keyboard::Space);
}

bool Evento::isAPressed()
{
    return isKeyPressed(sf::Keyboard::A);
}

bool Evento::isDPressed()
{
    return isKeyPressed(sf::Keyboard::D);
}

