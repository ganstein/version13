#include "JugadorVista.h"

JugadorVista::JugadorVista()
    : jugadorSprite(), texturaJugador()
{
    if (!texturaJugador.loadFromFile("cuy.png")) {
        std::cout << "Error al cargar la textura del jugador." << std::endl;
    }

    jugadorSprite.setTexture(texturaJugador);
    jugadorSprite.setScale(0.2f, 0.2f);
}

void JugadorVista::actualizar(float jugadorX, float jugadorY, const sf::View& camara)
{
    jugadorSprite.setPosition(jugadorX, jugadorY);
}
bool JugadorVista::colisionaCon(const sf::Sprite& otroSprite) const {
    return jugadorSprite.getGlobalBounds().intersects(otroSprite.getGlobalBounds());
}

sf::Sprite& JugadorVista::getSprite() {
    return jugadorSprite;
}

const sf::Sprite& JugadorVista::getSprite() const {
    return jugadorSprite;
}