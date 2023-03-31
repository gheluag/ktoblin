#include <SFML/Graphics.hpp>
#include <sstream>



using namespace sf;
class Character {
public:
    float x, y, w, h, dx, dy, speed = 0;
    int dir = 0;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;
    Character(String F, int X, int Y, float W, float H) {
        File = F;
        w = W; h = H;
        image.loadFromFile("im/" + File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X; y = Y;
        sprite.setTextureRect(IntRect(w, h, w, h));
    }

    void update(float time) {
        switch (dir) {
        case 0: dx = speed; dy = 0; break;
        case 1: dx = -speed; dy = 0; break;
        }

        x += dx * time;

        speed = 0;
        sprite.setPosition(x, y);
    }
};

   

    //Image mainp;
    //mainp.loadFromFile("im/hh.png");

    //Texture mainptex;
    //mainptex.loadFromImage(mainp);

    //Sprite mainpsprite;
    //mainpsprite.setTexture(mainptex);
    //mainpsprite.setTextureRect(IntRect(0, 341, 134, 381/*0, 62, 91, 236*/));
    //mainpsprite.setPosition(50,150);


int main()
{

    RenderWindow window(VideoMode(1920, 1080), L"гамес", Style::Default);
    bool gamemode = true;
    
    
    Character mainchar("kk.png", 50, 150, 134, 381);
    //Image mainp;
    //mainp.loadFromFile("im/hh.png");

    //Texture mainptex;
    //mainptex.loadFromImage(mainp);

    //Sprite mainpsprite;
    //mainpsprite.setTexture(mainptex);
    //mainpsprite.setTextureRect(IntRect(0, 341, 134, 381/*0, 62, 91, 236*/));
    //mainpsprite.setPosition(50,150);

    float currentframe = 0;
    Clock clock;


    /*window.setVerticalSyncEnabled(true);*/

   

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }
        Font font;
        font.loadFromFile("SuperWebcomicBros.ttf");
        Text text("", font, 20);

        text.setString("Кошмары периодически посещали меня..");
        text.setPosition(900, 500);
        
       
       /* if (gamemode) {
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                mainchar.dir = 0; mainchar.speed = 0.1;
                currentframe += 0.005 * time;
                if (currentframe > 10) currentframe -= 10;
                mainchar.sprite.setTextureRect(IntRect(134 * int(currentframe), 341, 134, 381));

            }
            else {
                mainchar.sprite.setTextureRect(IntRect(0, 341, 134, 381));
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                mainchar.dir = 1; mainchar.speed = 0.1;
                currentframe += 0.005 * time;
                if (currentframe > 10) currentframe -= 10;
                mainchar.sprite.setTextureRect(IntRect(134 * int(currentframe) + 134, 341, -134, 381));
            }

            mainchar.update(time);
            window.draw(mainchar.sprite);
       }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            mainchar.dir = 0; mainchar.speed = 0.1;
            currentframe += 0.005 * time;
            if (currentframe > 10) currentframe -= 10;
            mainchar.sprite.setTextureRect(IntRect(134 * int(currentframe), 341, 134, 381));
        
        }
        else {
            mainchar.sprite.setTextureRect(IntRect(0,341, 134, 381));
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            mainchar.dir = 1; mainchar.speed = 0.1;
            currentframe += 0.005 * time;
            if (currentframe > 10) currentframe -= 10;
            mainchar.sprite.setTextureRect(IntRect(134 * int(currentframe) + 134, 341, -134, 381));
        }*/

        mainchar.update(time);
        

           /* if (Keyboard::isKeyPressed(Keyboard::D)) { 
            currentframe += 0.005 * time;
            if (currentframe > 10) currentframe -= 10;
            mainpsprite.setTextureRect(IntRect(134 * int(currentframe), 341, 134, 381));
            mainpsprite.move(0.1 * time, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) { 
            currentframe += 0.005 * time;
            if (currentframe > 10) currentframe -= 10;
            mainpsprite.setTextureRect(IntRect(134 * int(currentframe) +134 ,341, -134, 381));
            mainpsprite.move(-0.1 * time, 0); }*/
        window.clear();
        window.draw(text); // почему оно не работает...
       /* window.draw(mainchar.sprite);*/
        window.display();
    }
    return 0;
}