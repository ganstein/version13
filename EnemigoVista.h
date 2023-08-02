#ifndef ENEMIGO_VISTA_H
#define ENEMIGO_VISTA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

enum class Direction { Neutral, Left, Right };

class EnemigoVista {
    
public:
    const int FRAME_DELAY = 10;
    const int IMAGE_SWITCH_DELAY = 120;

    static std::vector<std::shared_ptr<sf::Texture>> texturasCompartidas;
    std::weak_ptr<sf::Sprite> sprite; // Change sprite to a weak pointer
    float centro_x;
    float centro_y;

    std::vector<std::shared_ptr<sf::Sprite>> moverIzq; // Change to shared pointers
    std::vector<std::shared_ptr<sf::Sprite>> moverDer; // Change to shared pointers
    int contador;
    int frame;
    Direction direccion;
    float velocidad_x;
    float distancia_recorrida_neg;
    float distancia_recorrida_pos;


public:
    EnemigoVista(float size, float centerX, float centerY);
    virtual  void actualizarAnimacion();
    virtual  void seleccionarDireccion();
    virtual  void seleccionarActualImagen();
    virtual  void siguienteImagen();

    std::shared_ptr<sf::Sprite> getSprite() const;
};

#endif // ENEMIGO_VISTA_H
