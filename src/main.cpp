#include "include.h"

int main()
{
    std::cout << "INITIALISATION..." << std::endl;
    std::srand(std::time(NULL));
    sf::RenderWindow app(
                         sf::VideoMode::getFullscreenModes()[0],
                         "Number V",
                         sf::Style::Fullscreen);
    Tree tree(&app);
    //BOUCLE GLOBALE
    while (app.isOpen())
    {
        switch(tree.getNode())
        {
        case MENU:
            std::cout << "- LOAD MENU" << std::endl;
            tree.menu();
            break;
        case GAME:
            std::cout << "- LOAD LEVEL <" << tree.getNameLevel() << ">" << std::endl;
            tree.game();
            break;
        case QUITTER:
            app.close();
            break;
        }
    }
    return EXIT_SUCCESS;
}
