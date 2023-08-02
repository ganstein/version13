#include "FondoVista.h"

FondoVista::FondoVista() {
    if (!fondoTexture.loadFromFile("cerros.jpg")) {
        std::cerr << "Error al cargar la textura del fondo." << std::endl;
    }

    fondoSprite.setTexture(fondoTexture);
    fondoSprite.setScale(1.0f, 1.0f);
}

void FondoVista::dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(fondoSprite);
}
