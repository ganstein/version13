#include <SFML/Graphics.hpp>
#include "MODELO.h"
#include "JugadorVista.h"
#include "MapaModelo.h"
#include "MapaVista.h"
#include "FondoVista.h"
#include "MenuVista.h"
#include "CONTROLADOR.h"

int main()
{
  

    MODELO modelo(100.0f, 350.0f);
    VISTA vis(modelo);
    CONTROLADOR controlador(modelo,vis  );
    controlador.ejecutarMenu("map.txt");
    controlador.ejecutarJuego();

    return 0;
}
