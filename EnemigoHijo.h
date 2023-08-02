#ifndef ENEMIGO_HIJO_H
#define ENEMIGO_HIJO_H

#include "EnemigoVista.h"

class EnemigoHijo : public EnemigoVista {
private:
    float velocidad_y; // Nueva variable espec�fica de la clase hija

public:
    // Constructor de la clase hija (puedes agregar m�s par�metros si es necesario).
    EnemigoHijo(float size, float centerX, float centerY);

    // Se sobrescribe la funci�n actualizarAnimacion de la clase padre
    void actualizarAnimacion() override;
};

#endif // ENEMIGO_HIJO_H
