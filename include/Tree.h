#ifndef TREE_H
#define TREE_H

#include "include.h"

enum Node
{
    MENU,
    GAME,
    LEVELS,
    CONFIG,
    QUITTER
};

class Tree
{
    public:
        Tree(sf::RenderWindow* a);
        virtual ~Tree();
        void menu();
        void game();
        Node getNode();
        std::string getNameLevel();
    private:
        Node _node;
        sf::RenderWindow* _app;
        std::string _namelevel;
};

#endif // TREE_H
