#ifndef LEVEL_H
#define LEVEL_H

#include "include.h"

class Tile;

class Level
{
    public:
        Level(std::string file);
        std::vector<Tile> getTiles();
        sf::Vector2f getStarter();
        int collision(sf::Vector2f pos);
        bool completed();
        void complete();
        virtual ~Level();
    private:
        sf::Vector2f _size;
        int _sizeTile;
        std::vector<Tile> _tiles;
        sf::Texture _texture;
        sf::Vector2f _start;
        sf::Vector2f _end;
        bool _completed;
};

#endif // LEVEL_H
