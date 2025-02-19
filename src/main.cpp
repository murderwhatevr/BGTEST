#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>  // For checking if the file exists
#include <cstring>  // For strerror()
#include <errno.h>  // For error numbers

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Background Test");
    window.setFramerateLimit(60);

    // Define the path to the image (with double backslashes for Windows path)
    std::string filePath = "../../assets/images/backgrounds/bg.png";

    // Check if the file exists and can be opened
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Unable to open the file: " << filePath << std::endl;
        std::cerr << "Error: " << strerror(errno) << std::endl;
        std::cout << "Press any key to close..." << std::endl;
        std::cin.get();
        return -1;
    }
    file.close();

    // Load Background Image
    sf::Texture backgroundTexture;
    std::cout << "Trying to load background from: " << filePath << std::endl;
    if (!backgroundTexture.loadFromFile(filePath)) {
        std::cerr << "Failed to load background!" << std::endl;
        std::cout << "Press any key to close..." << std::endl;
        std::cin.get();
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / static_cast<float>(backgroundTexture.getSize().x),
        window.getSize().y / static_cast<float>(backgroundTexture.getSize().y)
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }

    return 0;
}
