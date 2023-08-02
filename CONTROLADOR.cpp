#include "CONTROLADOR.h"



CONTROLADOR::CONTROLADOR(MODELO& modelo, VISTA& visual)
    : modelo(modelo), mapaModelo(), mapaVista(), enJuego(false), visual(visual), evento(evento), enem() //, ventana(sf::VideoMode(800, 600), "Mi Ventana") ,fondoVista(),
{
    EnemigosVistaModelo(enem);
    //visual.setenemigos1(std::move(enemigos));
}



void CONTROLADOR::procesarEventosMenu(MenuVista& menu)
{
    Evento evento;
    while (evento.pollEvent(visual.ventana))
    {
        if (evento.esCerrado())
            visual.ventana.close();
        else if (evento.esBotonSoltado())
        {
            if (evento.estaEnOpcionJugar(menu, visual.ventana))
            {
                enJuego = true;
            }
            else if (evento.estaEnOpcionSalir(menu, visual.ventana))
            {
                visual.ventana.close();
            }
        }
    }
}

void CONTROLADOR::procesarEventosJuego()
{
    Evento evento;
    while (evento.pollEvent(visual.ventana))
    {
        if (evento.esCerrado())
            visual.ventana.close();
        
    }
}



void CONTROLADOR::actualizarMenu(float deltaTime, MenuVista& menu)
{
    // No se realiza ninguna actualización en el menú
}


void CONTROLADOR::actualizarJuego(float deltaTime)
{
   AudioJ* AudioJ = AudioJ::getInstance();

    float desplazamientoX = 0.0f;
    if (evento.isAPressed())//meterlo a la vista
    {
        desplazamientoX -= 200.0f;
    }
    else if (evento.isDPressed())
    {
        desplazamientoX += 200.0f;
    }
    if (evento.isSpacePressed())
    {
       
        AudioJ->playSound();
       
        modelo.saltar(-300.0f);
    }
    
    modelo.mover(desplazamientoX, deltaTime, mapaModelo);
    modelo.verificarColisiones();
    modelo.aplicarGravedad(500.0f, deltaTime);
}

void CONTROLADOR::ejecutarMenu(const std::string& archivoMapa)
{
    AudioJ* AudioJ1 = AudioJ::getInstance();
    AudioJ1->playMusic("supercuy.wav");

    visual.cargarMapaDesdeArchivo(archivoMapa);
    std::cout << enemigos.size();
    MenuVista menu;
    while (visual.ventana.isOpen() && !enJuego)
    {
        float deltaTime = 0.016f;

        procesarEventosMenu(menu);
        actualizarMenu(deltaTime, menu);
        visual.dibujarMenu(menu);
    }
}

void CONTROLADOR::ejecutarJuego()
{
   AudioJ* AudioJ1 = AudioJ::getInstance();
   std::thread musicaThread([AudioJ1]() {
        AudioJ1->playMusic("selva.wav");
        });

    musicaThread.detach();
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    while (visual.ventana.isOpen() && enJuego)
    {
        std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - startTime).count();
        startTime = currentTime;


        procesarEventosJuego();
        actualizarJuego(deltaTime);
        visual.dibujarJuego();
    }
}


void CONTROLADOR::EnemigosVistaModelo(EnemigosModelo enemy) {
    enemigos = enemy.obtenerEntidades();
        std::cout << enemigos.size();
        visual.setenemigos1(std::move(enemigos));
}


