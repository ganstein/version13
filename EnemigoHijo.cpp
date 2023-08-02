#include "EnemigoHijo.h"

EnemigoHijo::EnemigoHijo(float size, float centerX, float centerY)
    : EnemigoVista(size, centerX, centerY),  velocidad_y(-2.0f) {
    // Puedes inicializar los miembros específicos de la clase hija, si los necesitas.
    std::cout << "----------------------------------------------------------";
}

void EnemigoHijo::actualizarAnimacion() {
    frame++;
    std::cout << "hijo";
    if (frame % FRAME_DELAY == 0) {
        EnemigoVista::seleccionarDireccion();
        EnemigoVista::seleccionarActualImagen();
        EnemigoVista::siguienteImagen();

        if (direccion == Direction::Left)
        {
            centro_x += velocidad_x;
            centro_y += velocidad_y;
            //std::cout << "hijo arriba";

        }
           
        else if (direccion == Direction::Right) {
            centro_x += velocidad_x;
            centro_y += velocidad_y;

        }
            

        if (centro_x <= distancia_recorrida_neg || centro_x >= distancia_recorrida_pos)
        {
            velocidad_x *= -1;
            velocidad_y*=-1;
        }

        centro_y += velocidad_y;
    }
}
