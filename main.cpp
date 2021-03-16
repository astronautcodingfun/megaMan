//megaman Spritesheet with 85/70 pixels

#include "SFML/Graphics.hpp"

int main() {
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "megaman running");

    sf::Event event;
    sf::Texture texture;
    texture.loadFromFile("mega.png");

    sf::IntRect rectSourceSprite(0, 0, 85, 70);
    sf::Sprite sprite(texture, rectSourceSprite);
    sf::Clock clock;

    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        if (clock.getElapsedTime().asSeconds() > .4f) {
            if (rectSourceSprite.left == 255)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 85;

            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }
        renderWindow.clear();
        renderWindow.draw(sprite);
        renderWindow.display();
    }
}