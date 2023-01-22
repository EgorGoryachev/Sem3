#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGTH 1080

using namespace sf;


int main()
{
    int clipingWidth = 300;
    int clipingHeigth = 130;
    float logoXoffset = 2.0f;
    float logoYoffset = 2.0f;
    bool Game = false;

    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), "Logo", Style::Fullscreen);
    RectangleShape logo(Vector2f(306.0f, 138.0f));
    Texture logoTexture;
    logoTexture.loadFromFile("pngegg.PNG");
    logo.setTexture(&logoTexture);
    logo.setPosition(50, 50);

    RectangleShape Anime(Vector2f(100.0f, 100.0f));
    Texture AnimeT;
    AnimeT.loadFromFile("f.PNG");
    Anime.setTexture(&AnimeT);
    Anime.setPosition(100, 100);

    SoundBuffer soundBuff;
    soundBuff.loadFromFile("0ee26c7ba49bf25.OGG");
    Sound hit(soundBuff);

    SoundBuffer soundBuffA;
    soundBuffA.loadFromFile("Syper.OGG");
    Sound surprise(soundBuffA);

    while (window.isOpen()) {
        int logoX = logo.getPosition().x;
        int logoY = logo.getPosition().y;
        Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.key.code == Keyboard::G) {
                Game = true;
            }
            if (evnt.key.code == Keyboard::Escape) {
                window.close();
            }
            if (evnt.key.code == Keyboard::D) {
                if (logoXoffset < 6.0f) {
                    logoXoffset += 2.0f;
                }
            }
            if (evnt.key.code == Keyboard::A) {
                if (logoXoffset > -6.0f) {
                    logoXoffset -= 2.0f;
                }
            }
            if (evnt.key.code == Keyboard::S) {
                if (logoYoffset < 6.0f) {
                    logoYoffset += 2.0f;
                }
            }
            if (evnt.key.code == Keyboard::W) {
                if (logoYoffset > -6.0f) {
                    logoYoffset -= 2.0f;
                }
            }
            if (evnt.key.code == Keyboard::Tab) {
                logoXoffset = 2.0f;
                logoYoffset = 2.0f;
                logo.setScale(1, 1);
                logo.setPosition(logoX,logoY);
                clipingWidth = 300;
                clipingHeigth = 130;
                Game = false;
            }
        }
        if (Game == true) {
            if (Anime.getPosition().x <= logoX + logo.getSize().x * logo.getScale().x && Anime.getPosition().x >= logoX && Anime.getPosition().y <= logoY + logo.getSize().y * logo.getScale().y && Anime.getPosition().y >= logoY) {
                Anime.setPosition(rand() % 1700, rand() % 800);
                logo.scale(1.05, 1.05);
                clipingWidth *= 1.05f;
                clipingHeigth *= 1.05f;
                surprise.play();
            }
        }
        if (logoY >= WINDOW_HEIGTH - clipingHeigth || logoY < 0) {
            logoYoffset = -logoYoffset;
            hit.play();
        }
        if (logoX >= WINDOW_WIDTH - clipingWidth || logoX < 0) {
            logoXoffset = -logoXoffset;
            hit.play();
        }
        logo.move(logoXoffset, logoYoffset);
        window.clear();
        if (Game == true) {
            window.draw(Anime);
        }
        window.draw(logo);
        window.display();
        window.setFramerateLimit(60);
    }
    return 0;
}