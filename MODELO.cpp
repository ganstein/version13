#include "MODELO.h"

MODELO::MODELO(float posX, float posY)
    : posicionX(posX), posicionY(posY), enElAire(false),mapaModelo(), desplazamientoY(0.0f), spritesMapa()
{
    mapaModelo.cargarMapaDesdeArchivo("map.txt");
    mapaVista.generarSprites(mapaModelo);
    spritesMapa = mapaVista.getSprites();
   
}

float MODELO::getPosicionX() const {
    return posicionX;
}

float MODELO::getPosicionY() const {
    return posicionY;
}

bool MODELO::estaEnElAire() const {
    return enElAire;
}

void MODELO::mover(float desplazamientoX, float deltaTime) {
    float nuevaPosX = posicionX + desplazamientoX * deltaTime;
    posicionX = nuevaPosX;
}

void MODELO::saltar(float velocidadSalto) {
    if (!enElAire) {
        desplazamientoY = velocidadSalto;
        enElAire = true;
    }
}

void MODELO::aplicarGravedad(float gravedad, float deltaTime) {
    desplazamientoY += gravedad * deltaTime;
    posicionY += desplazamientoY * deltaTime;
}

void MODELO::setEnElAire(bool value) {
    enElAire = value;
}

void MODELO::mover(float desplazamientoX, float deltaTime, const MapaModelo& mapaModelo) {
    
    float nuevaPosX = posicionX + desplazamientoX * deltaTime;
    posicionX = nuevaPosX;
    // Verificar colisiones con el mapa en dirección horizontal
    int nuevaFila = static_cast<int>(std::floor(posicionY / 70));
    if (desplazamientoX > 0) {
        int nuevaColumna = static_cast<int>(std::ceil(nuevaPosX / 70));
        if (mapaModelo.getValorCasilla(nuevaFila, nuevaColumna) != 2) {
            // Verificar colisiones con los sprites del mapa
            bool colision = false;
            for (const auto& sprite : spritesMapa) {
                if (sprite.getGlobalBounds().intersects(sf::FloatRect(nuevaPosX + 32.0f, posicionY + 32.0f, 32.0f, 32.0f))) {
                    colision = true;
                    break;
                }
            }
            if (!colision) {
                posicionX = nuevaPosX;
            }
        }
    }
    else if (desplazamientoX < 0) {
        int nuevaColumna = static_cast<int>(std::floor(nuevaPosX / 70));
        if (mapaModelo.getValorCasilla(nuevaFila, nuevaColumna) != 2) {
            // Verificar colisiones con los sprites del mapa
            bool colision = false;
            for (const auto& sprite : spritesMapa) {
                if (sprite.getGlobalBounds().intersects(sf::FloatRect(nuevaPosX + 32.0f, posicionY + 32.0f, 32.0f, 32.0f))) {
                    colision = true;
                    break;
                }
            }
            if (!colision) {
                posicionX = nuevaPosX;
            }
        }
    }

    // Verificar colisiones con el mapa en dirección vertical
    float nuevaPosY = posicionY + desplazamientoY * deltaTime;
    int nuevaColumna = static_cast<int>(std::floor(nuevaPosX / 70));

    if (desplazamientoY > 0) { // Colisión en la parte inferior
        if (mapaModelo.getValorCasilla(nuevaFila + 1, nuevaColumna) != 2) {
            // Verificar colisiones con los sprites del mapa
            bool colision = false;
            for (const auto& sprite : spritesMapa) {
                if (sprite.getGlobalBounds().intersects(sf::FloatRect(posicionX + 32.0f, nuevaPosY + 64.0f, 32.0f, 32.0f))) {
                    colision = true;
                    break;
                }
            }
            if (!colision) {
                posicionY = nuevaPosY;
                enElAire = true;
            }
        }
        else {
            enElAire = false;
            desplazamientoY = 0.0f;
            posicionY = (nuevaFila + 1) * 70.0f;
        }
    }
    else if (desplazamientoY < 0) { // Colisión en la parte superior
        if (mapaModelo.getValorCasilla(nuevaFila, nuevaColumna) != 2) {
            // Verificar colisiones con los sprites del mapa
            bool colision = false;
            for (const auto& sprite : spritesMapa) {
                if (sprite.getGlobalBounds().intersects(sf::FloatRect(posicionX + 32.0f, nuevaPosY, 32.0f, 32.0f))) {
                    colision = true;
                    break;
                }
            }
            if (!colision) {
                posicionY = nuevaPosY;
                enElAire = true;
            }
        }
        else {
            enElAire = true;
            desplazamientoY = 0.0f;
            posicionY = (nuevaFila + 1) * 70.0f;
        }
    }

}

void MODELO::verificarColisiones() {
   
    for (const auto& sprite : spritesMapa) {
        if (sprite.getGlobalBounds().intersects(sf::FloatRect(posicionX + 32.0f, posicionY + 32.0f, 32.0f, 32.0f))) {
            if (desplazamientoY > 0) { // Colisión en la parte inferior
                enElAire = false;
                desplazamientoY = 0.0f;
                posicionY = sprite.getPosition().y - 64.0f;
            }
            else if (desplazamientoY < 0) { // Colisión en la parte superior
                enElAire = true;
                desplazamientoY = 0.0f;
                posicionY = sprite.getPosition().y + 70.0f;
            }
        }
    }

}
