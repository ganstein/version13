#include "MenuVista.h"

void MenuVista::configurarTexto(sf::Text& texto, const std::string& contenido, const sf::Font& fuente, int tamano, const sf::Vector2f& posicion)
{
    texto = sf::Text(contenido, fuente, tamano);
    texto.setFillColor(sf::Color::White);
    texto.setOutlineColor(sf::Color::Black);
    texto.setOutlineThickness(2);
    texto.setPosition(posicion);
}

MenuVista::MenuVista()
    : font(), titulo(), opcionJugar(), opcionSalir(), fondo(), texturaFondo()
{
    if (!font.loadFromFile("aldo.ttf")) {
        std::cout << "Error al cargar la fuente." << std::endl;
    }

    configurarTexto(titulo, "Las Aventuras de Super Cuy", font, 50, sf::Vector2f(160, 150));
    configurarTexto(opcionJugar, "Jugar", font, 30, sf::Vector2f(380, 300));
    configurarTexto(opcionSalir, "Salir", font, 30, sf::Vector2f(385, 350));

    if (!texturaFondo.loadFromFile("cuysito.png")) {
        std::cout << "Error al cargar la textura de fondo del menú." << std::endl;
    }

    fondo.setTexture(texturaFondo);
    // Obtener el tamaño de la ventana
    sf::Vector2u tamanoVentana = sf::Vector2u(800, 600); // Reemplaza esto con el tamaño real de la ventana

    // Obtener el tamaño de la imagen
    sf::Vector2u tamanoImagen = texturaFondo.getSize();

    // Calcular la escala para ajustar la imagen dentro de la ventana
    float escalaX = static_cast<float>(tamanoVentana.x) / tamanoImagen.x;
    float escalaY = static_cast<float>(tamanoVentana.y) / tamanoImagen.y;
    float escala = std::min(escalaX, escalaY) * 0.9f;

    fondo.setScale(escala, escala);

    // Calcular la posición para centrar la imagen
    sf::Vector2f posicion((tamanoVentana.x - (tamanoImagen.x * escala)) / 2.0f, (tamanoVentana.y - (tamanoImagen.y * escala)) / 2.0f);

    // Establecer la posición para la imagen
    fondo.setPosition(posicion);

}
void MenuVista::dibujar(sf::RenderWindow& ventana) const
{
    ventana.draw(fondo); // Dibujar el fondo del menú
    ventana.draw(titulo);
    ventana.draw(opcionJugar);
    ventana.draw(opcionSalir);
}
