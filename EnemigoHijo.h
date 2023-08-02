#ifndef ENEMIGO_HIJO_H
#define ENEMIGO_HIJO_H

#include "EnemigoVista.h"

class EnemigoHijo : public EnemigoVista {
private:
    float velocidad_y; // Nueva variable específica de la clase hija

public:
    // Constructor de la clase hija (puedes agregar más parámetros si es necesario).
    EnemigoHijo(float size, float centerX, float centerY);

    // Se sobrescribe la función actualizarAnimacion de la clase padre
    void actualizarAnimacion() override;
};

#endif // ENEMIGO_HIJO_H
