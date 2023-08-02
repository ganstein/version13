#ifndef VISTA_H
#define VISTA_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MODELO.h"
#include "JugadorVista.h"
#include "MapaModelo.h"
#include "MapaVista.h"
#include "FondoVista.h"
#include "MenuVista.h"
#include <string>
#include <SFML/System/Vector2.hpp>
#include "EnemigoVista.h"
#include "TexturaManager.h"



class VISTA {
private:
    MODELO& modelo;
    JugadorVista vista;
    MapaModelo mapaModelo;
    //MapaVista mapaVista;
    FondoVista fondoVista; // Agrega un objeto de la clase FondoVista
    std::vector<std::shared_ptr<EnemigoVista>> enemigo1;

    sf::SoundBuffer buffer;
    sf::Sound sound;
    
   // sf::RenderWindow ventana;
    bool enJuego;


public:
    sf::RenderWindow ventana;
    sf::View camara;

    VISTA(MODELO& modelo);//, sf::RenderWindow& ventana

    void cargarMapaDesdeArchivo(const std::string& archivo);
   // void procesarEventosMenu(MenuVista& menu);
    //void procesarEventosJuego();// dejarlo en el controlador
   // void actualizarMenu(float deltaTime, MenuVista& menu);
  //  void actualizarJuego(float deltaTime);//dejarlo en controlador
    void dibujarMenu(const MenuVista& menu);
    void dibujarJuego();
    //sf::Vector2f crearVector2f(float x, float y);

    //void ejecutarMenu(const std::string& archivoMapa);//dejarlo en el control
    //void ejecutarJuego();//dejarlo en el control
    //void setventana(sf::RenderWindow& ventana);
    MapaVista mapaVista;

    void setenemigos1(std::vector<std::shared_ptr<EnemigoVista>>&& enemy1);
    void actAnEn();
    void dibujarEn(sf::RenderWindow& ventana) const;
    void ColisioEnemigo();

};

#endif // VISTA_H
