#ifndef CHERRY_H
#define CHERRY_H

#include "include.h"

class Cherry
{
    public:
        Cherry(Level* lvl);
        virtual ~Cherry();
        sf::Sprite getSprite();
        sf::Vector2f getCenter();
        void move(sf::Vector2f center);
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _size;
        Level* _level;
        float _pi;
        int _speed;
};

#endif // CHERRY_H
