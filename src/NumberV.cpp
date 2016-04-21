#include "NumberV.h"

NumberV::NumberV(Level* lvl)
{
    _level = lvl;
    sf::Image img;
    if(img.loadFromFile("numberV.png"))
    {
        img.createMaskFromColor(sf::Color(0,255,0));
        std::cout<<"Chargement img reussi"<<std::endl;
    };
    if(_texture.loadFromImage(img))
        std::cout<<"Chargement txt reussi"<<std::endl;
    _sprite.setTexture(_texture);
    _size = sf::Vector2f(50,50);
    _sprite.setPosition(_level->getStarter()-_size/2.f);
}

NumberV::~NumberV()
{
    //dtor
}

sf::Sprite NumberV::getSprite()
{
    return _sprite;
}

void NumberV::teleport(sf::Vector2f pos)
{
    switch(_level->collision(pos))
    {
    case SOL:
    case DEPART:
        _sprite.setPosition(pos-_size/2.f);
        break;
    case ARRIVEE:
        _sprite.setPosition(pos-_size/2.f);
        _level->complete();
    default:
        break;
    }
}

sf::Vector2f NumberV::getCenter()
{
    return _sprite.getPosition()+_size/2.f;
}
