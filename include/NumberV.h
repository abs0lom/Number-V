#ifndef NUMBERV_H
#define NUMBERV_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Cherry.h"
#include "Tile.h"
#include "Level.h"

class Level;

class NumberV
{
    public:
        NumberV(Level* lvl);
        virtual ~NumberV();
        void teleport(sf::Vector2f pos);
        void hurt();
        sf::Sprite getSprite();
        sf::Vector2f getCenter();
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _size;
        int _life;
        Level* _level;
};

#endif // NUMBERV_H
