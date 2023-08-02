#include "AudioJ.h"

// Initialize the static pointer to nullptr
AudioJ* AudioJ::instance = nullptr;

//const std::string AudioJ::RESOURCES_PATH = "../resources/";

// Implementaci�n de la funci�n est�tica para obtener la �nica instancia del AudioJ
AudioJ* AudioJ::getInstance() {
    if (instance==nullptr) {
        instance = new AudioJ();
    }
    return instance;
}

// Implementaci�n del constructor privado para evitar la creaci�n de instancias directamente
AudioJ::AudioJ()  {
    AudioJ::initAudio("sonido_salto.wav");
    sound = new sf::Sound();
        sound->setBuffer(buffer);
    std::cout << "Se construye el audio" << std::endl;
    // Inicializa aqu� los miembros necesarios para el manejo de sonidos y m�sica
}


// Implementaci�n del destructor privado para asegurar que no se pueda eliminar la instancia desde fuera de la clase
AudioJ::~AudioJ() {
    std::cout << "Se destruye el audio" << std::endl;
    // Realiza aqu� cualquier limpieza necesaria
}




// Implementaci�n de la funci�n para inicializar el AudioJ (cargar sonidos, etc.)
void AudioJ::initAudio(const std::string& filename) {
    buffer.loadFromFile( filename);
        
   }

 // Implementaci�n de la funci�n para reproducir un sonido por su nombre de archivo
void AudioJ::playSound() {
           sound->play();
   }


void AudioJ::playMusic(const std::string& filemusic) {

    if (!music.openFromFile(filemusic)) {
        std::cout << "Error al cargar el archivo selva.wav" << std::endl;
    }
    std::cout << "Se carga el audio" << std::endl;
    music.play();
    std::cout << "Se reproduce el audio" << std::endl;
    }
