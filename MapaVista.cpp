#include "MapaVista.h"

MapaVista::MapaVista() {
    if (!pisoTexture.loadFromFile("map/slice03_03.png")) {
        std::cerr << "Error al cargar la textura del piso." << std::endl;
        return;
    }

    if (!paredTexture.loadFromFile("map/slice16_16.png")) {
        std::cerr << "Error al cargar la textura de la pared." << std::endl;
        return;
    }

    if (!bloqueTexture.loadFromFile("map/slice01_01.png")) {
        std::cerr << "Error al cargar la textura del bloque." << std::endl;
        return;
    }
}

void MapaVista::generarSprites(const MapaModelo& modelo) {
    sprites.clear();

    const int tileSize = 70; // Tamaño de cada elemento del mapa
    const float scale = 1;

    for (int fila = 0; fila < 16; ++fila) {
        for (int columna = 0; columna < 185; ++columna) {
            sf::Sprite sprite;

            int valor = modelo.getValorCasilla(fila, columna);

            if (valor == 2) {
                sprite.setTexture(paredTexture);
            }
            else if (valor == 1) {
                sprite.setTexture(pisoTexture);
            }
            else if (valor == 3) {
                sprite.setTexture(bloqueTexture);
            }

            sprite.setPosition(columna * tileSize * scale, fila * tileSize * scale);
            sprite.setScale(scale, scale);
            sprites.push_back(sprite);
        }
    }
}

std::vector<sf::Sprite>& MapaVista::getSprites() {
    return sprites;
}

void MapaVista::dibujar(sf::RenderWindow& ventana) const {
    for (const auto& sprite : sprites) {
        ventana.draw(sprite);
    }
}
