# Las Aventuras de Super Cuy

## Descripción

Este proyecto es un pequeño juego de plataformas en 2D llamado "Las Aventuras de Super Cuy". El jugador asume el papel de un valiente cuy que debe superar obstáculos y enemigos para completar los niveles y alcanzar la meta.

## Requisitos

- Sistema operativo compatible (Windows, macOS o Linux).
- Compilador de C++ compatible con C++11 o superior.
- SFML (Simple and Fast Multimedia Library) instalado. Puedes descargarlo desde el sitio web oficial: https://www.sfml-dev.org/

## Instalación

1. Clona el repositorio desde GitHub: `git clone https://github.com/tu_usuario/tu_repositorio.git`
2. Navega al directorio del proyecto: `cd tu_repositorio`
3. Compila el código usando tu compilador de C++: `g++ -std=c++11 main.cpp -o juego -lsfml-graphics -lsfml-window -lsfml-system`

## Uso

1. Ejecuta el juego después de compilarlo: `./juego`
2. En el menú principal, selecciona "Jugar" para comenzar el juego o "Salir" para cerrar la ventana.
3. En el juego, usa las teclas A y D para mover al personaje hacia la izquierda y derecha, respectivamente.
4. Pulsa la tecla Espacio para que el personaje salte y evite caer en abismos o chocar con los enemigos.
5. Llega a la meta del nivel para avanzar al siguiente.

## Estructura del Proyecto

- `main.cpp`: Archivo principal que contiene la lógica principal del juego.
- `MODELO.h`, `MODELO.cpp`: Definición y código de la clase MODELO que representa el modelo del juego.
- `VISTA.h`, `VISTA.cpp`: Definición y código de la clase VISTA que maneja la visualización del juego.
- `CONTROLADOR.h`, `CONTROLADOR.cpp`: Definición y código de la clase CONTROLADOR que controla la interacción entre el modelo y la vista.
- `Evento.h`, `Evento.cpp`: Definición y código de la clase Evento que maneja los eventos del juego.
- `EnemigosModelo.h`, `EnemigosModelo.cpp`: Definición y código de la clase EnemigosModelo que representa los enemigos en el modelo del juego.
- `EnemigoVista.h`, `EnemigoVista.cpp`: Definición y código de la clase EnemigoVista que maneja la visualización de los enemigos.
- `MenuVista.h`, `MenuVista.cpp`: Definición y código de la clase MenuVista que maneja el menú principal del juego.
- `FondoVista.h`, `FondoVista.cpp`: Definición y código de la clase FondoVista que maneja la visualización del fondo del juego.
- Otros archivos: Archivos de recursos como imágenes y sonidos utilizados en el juego.

## Contribución

Si deseas contribuir al proyecto, por favor crea un "issue" para discutir los cambios propuestos o envía una "pull request" con tus mejoras.

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo LICENSE para más detalles.

## Contacto

Si tienes alguna pregunta o sugerencia, puedes contactarme a través de mi correo electrónico: jparedesma@unsa.edu.pe,kborjav@unsa.edu.pe ,jhuertasv@unsa.edu.pe
                                                                                        

## Agradecimientos

Agradezco a la comunidad de desarrolladores de C++ y SFML por proporcionar herramientas increíbles para crear juegos y aplicaciones interactivas.También quiero agradecer a nuestro profesor de teoria del curso Ciencias de la computacion 2, Alvaro Mamani, por su guía y apoyo en el desarrollo de este proyecto como al profesor Manuel Loaiza por sus observaciones en el desarrollo del juego en horas de laboratorio.
