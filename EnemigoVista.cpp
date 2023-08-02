#include "EnemigoVista.h"

// Define the static member variable texturasCompartidas
std::vector<std::shared_ptr<sf::Texture>> EnemigoVista::texturasCompartidas;

EnemigoVista::EnemigoVista(float size, float centerX, float centerY)
    : centro_x(centerX), centro_y(centerY), frame(0), contador(0),
    direccion(Direction::Right), velocidad_x(-2.0f),
    distancia_recorrida_neg(centerX - 100), distancia_recorrida_pos(centerX + 100) {
    if (texturasCompartidas.empty()) {
        for (int i = 1; i <= 3; i++) {
            std::string rutaIzq = "enemigo/izq" + std::to_string(i) + ".png";
            std::string rutaDer = "enemigo/der" + std::to_string(i) + ".png";

            auto textureIzq = std::make_shared<sf::Texture>();
            auto textureDer = std::make_shared<sf::Texture>();

            textureIzq->loadFromFile(rutaIzq);
            textureDer->loadFromFile(rutaDer);

            texturasCompartidas.push_back(textureIzq);
            texturasCompartidas.push_back(textureDer);
        }
    }

    for (size_t i = 0; i < texturasCompartidas.size(); i += 2) {
        auto sprite = std::make_shared<sf::Sprite>(); // Use shared pointers here
        sprite->setTexture(*texturasCompartidas[i]);
        moverIzq.push_back(sprite);
    }

    for (size_t i = 1; i < texturasCompartidas.size(); i += 2) {
        auto sprite = std::make_shared<sf::Sprite>(); // Use shared pointers here
        sprite->setTexture(*texturasCompartidas[i]);
        moverDer.push_back(sprite);
    }

    //seleccionarActualImagen();
}


void EnemigoVista::actualizarAnimacion() {
    frame++;
    if (frame % FRAME_DELAY == 0) {
        seleccionarDireccion();
        seleccionarActualImagen();
        siguienteImagen();

        if (direccion == Direction::Left)
        {
            centro_x += velocidad_x;
            //std::cout << "padre";
        }
            
        else if (direccion == Direction::Right)
            centro_x += velocidad_x;

        if (centro_x <= distancia_recorrida_neg || centro_x >= distancia_recorrida_pos)
            velocidad_x *= -1;
    }
}


void EnemigoVista::seleccionarDireccion() {
    if (velocidad_x > 0)
        direccion = Direction::Right;
    else if (velocidad_x < 0)
        direccion = Direction::Left;
}

void EnemigoVista::seleccionarActualImagen() {
    if (direccion == Direction::Right)
        sprite = moverDer[contador];
    else if (direccion == Direction::Left)
        sprite = moverIzq[contador];
    if (auto s = sprite.lock()) // Check if the sprite still exists
        s->setPosition(centro_x, centro_y);
}

void EnemigoVista::siguienteImagen() {
    if (frame % IMAGE_SWITCH_DELAY == 0)
        contador = (contador + 1) % moverIzq.size();
}



std::shared_ptr<sf::Sprite> EnemigoVista::getSprite() const {
    return sprite.lock(); // Convert weak pointer to shared pointer
}
