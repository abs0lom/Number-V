#include "Cherry.h"

Cherry::Cherry(Level* lvl)
{
    _level = lvl;
    sf::Image img;
    if(img.loadFromFile("cherry.png"))
    {
        img.createMaskFromColor(sf::Color(0,255,0));
        std::cout<<"Chargement img reussi"<<std::endl;
    };
    if(_texture.loadFromImage(img))
        std::cout<<"Chargement txt reussi"<<std::endl;
    _sprite.setTexture(_texture);
    _sprite.setPosition(_level->getStarter()-_size/2.f);
    _size = sf::Vector2f(20,20);
    _pi = 3.141592;
    _speed = 7;
}

Cherry::~Cherry()
{
    //dtor
}

sf::Sprite Cherry::getSprite()
{
    return _sprite;
}

sf::Vector2f Cherry::getCenter()
{
    return sf::Vector2f(_sprite.getPosition()+_size/2.f);
}

void Cherry::move(sf::Vector2f center)
{
    int edistance = exp(sqrt((getCenter().x-center.x)*(getCenter().x-center.x)+(getCenter().y-center.y)*(getCenter().y-center.y)));
    int proba[101];
    for(int i(0);i < 100; i++)
    {
        sf::Vector2f pt(cos(2*_pi*i/100), -sin(2*_pi*i/100));
        pt *= (float)_speed;
        pt += getCenter();
        if(_level->collision(pt) == PLAFOND)
            proba[i] = 0;
        else
        {
            proba[i] = 1 //probabilité minimale de déplacement
                     + edistance //probabilité de rapprochement du curseur
                     + //probabilité liée à l'ancien vecteur de déplacement
        }
        proba[101] += proba[i];
    }
    if(probatot == 0)
        return;
    int alea = rand()%probatot;
    int tot(0), i(0);
    while(alea > tot)
    {
        tot+=proba[i];
        i++;
    }
    std::cout <<"nbalea[0;"<<probatot<<"]="<<alea<<";i="<<i<< std::endl;
    _sprite.move(sf::Vector2f(cos(2*_pi*i/100),-sin(2*_pi*i/100))*(float)_speed);
}
