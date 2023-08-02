#ifndef TEXTURA_MANAGER_H
#define TEXTURA_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class TexturaManager {
private:
    std::vector<std::shared_ptr<sf::Texture>> texturas;

public:
    TexturaManager();
    void cargarTextura(const std::string& ruta);
    const std::vector<std::shared_ptr<sf::Texture>>& getTexturas() const;
};

#endif // TEXTURA_MANAGER_H
