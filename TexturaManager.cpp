#include "TexturaManager.h"
#include <iostream>

TexturaManager::TexturaManager() {
    // Cargar todas las texturas necesarias en el constructor
    cargarTextura("enemigo/izq1.png");
    cargarTextura("enemigo/izq2.png");
    cargarTextura("enemigo/izq3.png");
    cargarTextura("enemigo/der1.png");
    cargarTextura("enemigo/der2.png");
    cargarTextura("enemigo/der3.png");
}

void TexturaManager::cargarTextura(const std::string& ruta) {
    auto texture = std::make_shared<sf::Texture>();
    if (texture->loadFromFile(ruta)) {
        texturas.push_back(texture);
    }
    else {
        std::cout << "Error al cargar la textura desde " << ruta << std::endl;
    }
}

const std::vector<std::shared_ptr<sf::Texture>>& TexturaManager::getTexturas() const {
    return texturas;
}
