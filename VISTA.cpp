#include "VISTA.h"



VISTA::VISTA(MODELO& modelo)//, sf::RenderWindow& ventana
    : modelo(modelo), vista(), mapaModelo(), fondoVista(),  ventana(sf::VideoMode(800, 600), "Mi Ventana") ,enJuego(false)
{
    camara.setSize(800, 600);
    buffer.loadFromFile("cry.wav");
    sound.setBuffer(buffer);
}

void VISTA::cargarMapaDesdeArchivo(const std::string& archivo)
{
    mapaModelo.cargarMapaDesdeArchivo(archivo);
    mapaVista.generarSprites(mapaModelo);
}



void VISTA::dibujarMenu(const MenuVista& menu)
{
    ventana.clear();
    ventana.draw(menu.fondo); // Dibujar el fondo del menú
    ventana.draw(menu.titulo);
    ventana.draw(menu.opcionJugar);
    ventana.draw(menu.opcionSalir);
    ventana.display();
}

void VISTA::dibujarJuego()
{
    ventana.clear();
    ventana.setView(camara);
    fondoVista.dibujar(ventana); // Dibujar el fondo en el juego
    mapaVista.dibujar(ventana);

    actAnEn();                  //enemigos
    dibujarEn(ventana);

    ventana.draw(vista.jugadorSprite);
    ventana.display();

    sf::Vector2f jugadorPos(modelo.getPosicionX(), modelo.getPosicionY());
    camara.setCenter(jugadorPos);

    vista.actualizar(modelo.getPosicionX(), modelo.getPosicionY(), camara);

    mapaVista.generarSprites(mapaModelo);
    ColisioEnemigo();


}


void VISTA::setenemigos1(std::vector<std::shared_ptr<EnemigoVista>>&& enemy1) {
    enemigo1 = std::move(enemy1);
    
}

void VISTA::actAnEn() {
    std::cout<<enemigo1.size();
    for (auto& entity : enemigo1) {
        entity->actualizarAnimacion();
    }
}

void VISTA::dibujarEn(sf::RenderWindow& ventana) const {
    for (const auto& entity : enemigo1) {
        if (auto sprite = entity->getSprite()) // Check if the sprite still exists
            ventana.draw(*sprite);
    }
}

void VISTA::ColisioEnemigo() {
    for (const auto& entity : enemigo1) {
        if (auto sprite = entity->getSprite()) {
            if (vista.colisionaCon(*sprite)) {
                std::cout << "yes o yes";
                
                sound.play();

            }
        }
    }
}


