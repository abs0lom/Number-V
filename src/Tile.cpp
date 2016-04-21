#include "Tile.h"

Tile::Tile(sf::Sprite sprite, int id)
{
    _sprite = sprite;
    _id = id;
}

Tile::~Tile()
{
    //dtor
}

sf::Sprite* Tile::getSprite()
{
    return &_sprite;
}

int Tile::getId()
{
    return _id;
}
