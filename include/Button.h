#ifndef BUTTON_H
#define BUTTON_H


class Button
{
    public:
        Button();
        virtual ~Button();
        void focus(bool b=true);
    private:
        sf::Sprite _active;
        sf::Texture _texture;
};

#endif // BUTTON_H
