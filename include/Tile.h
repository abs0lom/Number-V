#ifndef TILE_H
#define TILE_H

#include "include.h"

class Tile
{
    public:
        Tile(sf::Sprite sprite, int id);
        virtual ~Tile();
        sf::Sprite* getSprite();
        int getId();
    private:
        sf::Sprite _sprite;
        int _id;
};

enum TileId
{
    PLAFOND,
    SOL,
    VIDE,
    DEPART,
    ARRIVEE,
    PIQUE
};

#endif // TILE_H
