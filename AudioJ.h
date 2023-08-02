#ifndef AudioJ_H
#define AudioJ_H

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <SFML/System/Clock.hpp>



class AudioJ {
public:
    // Función estática para obtener la única instancia del AudioJ
    static AudioJ* getInstance();

    // Inicialización del AudioJ (cargar sonidos, etc.)
    void initAudio(const std::string& filename);
    

    // Reproducir un sonido por su nombre de archivo
    void playSound();
    void playMusic(const std::string& filename);
    // Otras funciones de audio que puedas necesitar...

    // Eliminamos el constructor y el operador de asignación para evitar duplicación de instancias
    AudioJ(const AudioJ&) = delete;
    void operator=(const AudioJ&) = delete;

    static const std::string RESOURCES_PATH;

public:
    // Constructor privado para evitar la creación de instancias directamente
    AudioJ();

    // Destructor privado para asegurar que no se pueda eliminar la instancia desde fuera de la clase
    ~AudioJ();

    // Agregar aquí cualquier otro miembro necesario para gestionar los sonidos y la música
    sf::SoundBuffer buffer; // Ejemplo de buffer para almacenar un sonido
    sf::Music music;
    sf::Sound* sound ;// Ejemplo de objeto para la música
    sf::Clock clock;


    static AudioJ* instance; // Pointer to the AudioJ instance
};

#endif // AudioJ_H
