#include "Tree.h"

Tree::Tree(sf::RenderWindow* a)
{
    _app = a;
    _node = MENU;
    _namelevel = "NONE";
}

std::string Tree::getNameLevel()
{
    return _namelevel;
}

Node Tree::getNode()
{
    return _node;
}

Tree::~Tree()
{
    //dtor
}

void Tree::menu()
{
    while(_node == MENU)
    {
        sf::Event event;
        while(_app->pollEvent(event))
        {

            //Bouton : sprite active, sprite défaut,
            //1 bouton activé
            //1 action pour chaque boutton
            switch(event.type)
            {
            case sf::Event::Closed :
                _node = QUITTER;
                return;
            case sf::Event::MouseButtonPressed :
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    for(int i(0); i <)
                }
            }
        }
        _app->clear(sf::Color(100,100,100));
        _app->display();
    }
    return;
}

void Tree::game()
{
    //WINDOWS
    sf::View view(_app->getView());
    //_app->setMouseCursorVisible(false);
    //LEVEL
    Level level(_namelevel);
    Cherry cherry(&level);
    NumberV numberv(&level);
    //VIEW
    view.setCenter(level.getStarter());
    _app->setView(view);
    //INIT FPS
    sf::Clock fps;
    //LOOP
    while(!level.completed() && _node == GAME)
    {
        // EVENT GESTION
        sf::Event event;
        while (_app->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed :
                    _node = QUITTER;
                    return;
                case sf::Event::MouseButtonPressed :
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        numberv.teleport(cherry.getCenter());
                        //std::cout << level.collision(cherry.getPosition()) << std::endl;
                    }
                    break;
                default: break;
            }
        }
        // UPDATE VIEW
        sf::Vector2f vn(numberv.getCenter()-view.getCenter());
        if(vn!=sf::Vector2f(0,0))
        {
            float normeVn(std::sqrt(vn.x*vn.x+vn.y*vn.y));
            float k(50/normeVn);
            if(normeVn>normeVn*k)
                vn*=k;
            view.move(vn);
            _app->setView(view);
        }
        // UPDATE ENV
        cherry.move(_app->mapPixelToCoords(sf::Mouse::getPosition(*_app)));
        // DRAWING GESTION
        _app->clear(sf::Color(100,100,100));
        for(unsigned int i(0); i<level.getTiles().size(); i++)
            _app->draw(*level.getTiles()[i].getSprite());
        _app->draw(numberv.getSprite());
        _app->draw(cherry.getSprite());
        _app->display();
        // UPDATE FPS
        // std::cout<< 1000/(fps.restart().asMilliseconds()) <<std::endl;
    }
    _app->setMouseCursorVisible(true);
    _node = MENU;
    return;
}


