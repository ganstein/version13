#ifndef MENUVISTA_H
#define MENUVISTA_H

#include <iostream>
#include <SFML/Graphics.hpp>

class MenuVista {
public:
    sf::Font font;
    sf::Text titulo;
    sf::Text opcionJugar;
    sf::Text opcionSalir;
    sf::Sprite fondo; // Nuevo sprite para el fondo del men�
    sf::Texture texturaFondo; // Nueva textura para el fondo del men�

public:
    void configurarTexto(sf::Text& texto, const std::string& contenido, const sf::Font& fuente, int tamano, const sf::Vector2f& posicion);

    MenuVista();

    void dibujar(sf::RenderWindow& ventana) const;
};

#endif // MENUVISTA_H
