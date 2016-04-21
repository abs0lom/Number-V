#include "Level.h"

Level::Level(std::string file)
{
    //CHARGEMENT TEXTURE & SPRITES :
    _completed = false;
    _texture.loadFromFile("tiles.png");
    _sizeTile = 70;
    std::vector<Tile> tiles;
    tiles.push_back(Tile(sf::Sprite(_texture, sf::IntRect(0,0,70,70)), SOL));
    tiles.push_back(Tile(sf::Sprite(_texture, sf::IntRect(0,70,70,70)), PLAFOND));
    tiles.push_back(Tile(sf::Sprite(_texture, sf::IntRect(70,0,70,70)), VIDE));
    tiles.push_back(Tile(sf::Sprite(_texture, sf::IntRect(70,70,70,70)), ARRIVEE));
    tiles.push_back(Tile(sf::Sprite(_texture, sf::IntRect(140,70,70,70)), DEPART));
    tiles.push_back(Tile(sf::Sprite(_texture, sf::IntRect(140,0,70,70)), PIQUE));
    //CHARGEMENT FICHIER :
    std::ifstream stream(file.c_str(), std::ios::in);
    _start = sf::Vector2f(-1,-1);
    _end = sf::Vector2f(-1,-1);
    if(!stream)
        std::cout<<"Chargement lvl echoue"<<std::endl;
    else{
        stream >> _size.x >> _size.y;
        int tile;
        for(int i(0); i<_size.x*_size.y; i++)
        {
            stream >> tile;
            _tiles.push_back(tiles[tile]);
            _tiles[i].getSprite()->setPosition(sf::Vector2f((i%(int)_size.x),(i/(int)_size.x))*(float)_sizeTile);
            switch(tile)
            {
                case 4:
                    if(_start == sf::Vector2f(-1,-1))
                        _start = _tiles[i].getSprite()->getPosition()+sf::Vector2f(35,35);
                    else
                        std::cout<<"Le niveau contient plus d'une entree !" << std::endl;
                    break;
                case 5:
                    if(_end == sf::Vector2f(-1,-1))
                        _end = _tiles[i].getSprite()->getPosition()+sf::Vector2f(35,35);
                    else
                        std::cout<<"Le niveau contient plus d'une sortie !"<< std::endl;
                    break;
            }
        }
    }
}

Level::~Level()
{
    //dtor
}

std::vector<Tile> Level::getTiles()
{
    return _tiles;
}

sf::Vector2f Level::getStarter()
{
    return _start;
}

int Level::collision(sf::Vector2f pos)
{
    int x = pos.x/_sizeTile;
    int y = pos.y/_sizeTile;
    int id = y*_size.x+x;
    /* RACCOMODAGE */if(id < 0) return SOL;
    return _tiles[id].getId();
}

bool Level::completed()
{
    return _completed;
}

void Level::complete()
{
    _completed = true;
}
