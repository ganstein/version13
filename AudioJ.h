#ifndef AudioJ_H
#define AudioJ_H

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <SFML/System/Clock.hpp>



class AudioJ {
public:
    // Funci�n est�tica para obtener la �nica instancia del AudioJ
    static AudioJ* getInstance();

    // Inicializaci�n del AudioJ (cargar sonidos, etc.)
    void initAudio(const std::string& filename);
    

    // Reproducir un sonido por su nombre de archivo
    void playSound();
    void playMusic(const std::string& filename);
    // Otras funciones de audio que puedas necesitar...

    // Eliminamos el constructor y el operador de asignaci�n para evitar duplicaci�n de instancias
    AudioJ(const AudioJ&) = delete;
    void operator=(const AudioJ&) = delete;

    static const std::string RESOURCES_PATH;

public:
    // Constructor privado para evitar la creaci�n de instancias directamente
    AudioJ();

    // Destructor privado para asegurar que no se pueda eliminar la instancia desde fuera de la clase
    ~AudioJ();

    // Agregar aqu� cualquier otro miembro necesario para gestionar los sonidos y la m�sica
    sf::SoundBuffer buffer; // Ejemplo de buffer para almacenar un sonido
    sf::Music music;
    sf::Sound* sound ;// Ejemplo de objeto para la m�sica
    sf::Clock clock;


    static AudioJ* instance; // Pointer to the AudioJ instance
};

#endif // AudioJ_H
