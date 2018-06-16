#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream> //debug purposes
#include <thread>

const float SCALING(0.7);
/* NEW YORK I LOVE YOU, BUT YOU'RE BRINGING ME DOWN */

namespace{
    sf::Image GetNewScreenshot(){
	sf::Image screenshot;
	std::system("adb shell screencap -p /sdcard/scraam.png");
	std::system("adb pull /sdcard/scraam.png");
	std::system("adb shell rm /sdcard/scraam.png");
	
	screenshot.loadFromFile("scraam.png");
	return screenshot;
    }

    void RefreshImage(sf::Texture& yes, sf::Sprite& sprite){
        if(!yes.loadFromImage(GetNewScreenshot()))
	    exit(EXIT_FAILURE);
	sprite.setTexture(yes);
    }
}

int main(void){
    sf::Texture yes;
    if(!yes.loadFromImage(GetNewScreenshot()))
	exit(EXIT_FAILURE);

    sf::RenderWindow app(sf::VideoMode(350,350), "Honeyko's cheat");
    sf::RenderWindow appX;
    
    sf::Sprite sprite(yes);
    sprite.setPosition(0.0f, 0.0f);
    sprite.setScale(SCALING, SCALING);

    int test{0};
    
    while(app.isOpen()){
	sf::Event e;
        while(app.pollEvent(e)){
            if(e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		app.close();
	    
	    if(e.type == sf::Event::MouseButtonReleased){
		if(!appX.isOpen())
		    appX.create(sf::VideoMode(yes.getSize().x*SCALING, yes.getSize().y*SCALING), "Honey screen");
		RefreshImage(yes, sprite);

		//std::thread(RefreshImage, yes, sprite);
		//TRY TO PASS POINTERS : create pSprite and pYes pass them
	    }
        }
	while(appX.isOpen() && appX.pollEvent(e)){
	    if(e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		appX.close();
	}
	
	appX.clear();
	appX.draw(sprite);
	appX.display();
	
        app.clear(sf::Color(test%256,0,0));
        app.display();
	++test;
    }
    return 0;
}

/*                Please notice me
 *
 *                   ***  *** 
 *                  *   **   *
 *                   *      *
 *                    *    *
 *                     *  *
 *                      **
 *                      *
 *                  *  *
 *                   **                   
 *
 */
