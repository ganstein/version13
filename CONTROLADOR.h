#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <SFML/Graphics.hpp>
#include "MODELO.h"
#include "JugadorVista.h"
#include "MapaModelo.h"
#include "MapaVista.h"
#include "FondoVista.h"
#include "MenuVista.h"
#include "VISTA.h"
#include <string>
#include "Evento.h"
#include <chrono>
#include "EnemigosModelo.h"
#include "EnemigoVista.h"
#include "AudioJ.h"
#include <thread>

class CONTROLADOR {
private:
    MODELO& modelo;
    //JugadorVista& vista;
    MapaModelo mapaModelo;
    MapaVista mapaVista;
    VISTA& visual;
    Evento& evento;
    //AudioJ* AudioJ;
    EnemigosModelo enem;
   // EnemigoVista enev;
    //FondoVista fondoVista; // Agrega un objeto de la clase FondoVista

    //sf::View camara;
   // sf::RenderWindow ventana;
    bool enJuego;
    std::vector<std::shared_ptr<EnemigoVista>> enemigos;

public:
    CONTROLADOR(MODELO& modelo,  VISTA& visual);//, sf::RenderWindow& ventana

    //void cargarMapaDesdeArchivo(const std::string& archivo);
    void procesarEventosMenu(MenuVista& menu);
    void procesarEventosJuego();// dejarlo en el controlador
    void actualizarMenu(float deltaTime, MenuVista& menu);
    void actualizarJuego(float deltaTime);//dejarlo en controlador
    //void dibujarMenu(const MenuVista& menu);
    //void dibujarJuego();
    void ejecutarMenu(const std::string& archivoMapa);//dejarlo en el control
    void ejecutarJuego();//dejarlo en el control
    //void setventana(sf::RenderWindow& ventana);

    void EnemigosVistaModelo(EnemigosModelo enemy);
    //std::vector<EnemigoVista> devolverEmigos1();
};

#endif // CONTROLADOR_H
