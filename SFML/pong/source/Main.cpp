#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
  window.setFramerateLimit(60);

  //Variables
  sf::Event event;
  bool play = true;
  int playerYVelocity = 0;
  int playerMovementSpeed = 10;
  int botMovementSpeed = 2;

  int xVelocityBall = -5;
  int yVelocityBall = -5;

  int botYVelocity = 0;

  int playerScore = 0;
  int botScore = 0;

  std::stringstream scoreString;
  scoreString << playerScore << " : " << botScore;
  //Font
  sf::Font font;
  if (!font.loadFromFile("resources/arial.ttf")) {
    std::cout << "Could not load font arial.ttf" << std::endl;
    return -1;
  }

  //Text
  sf::Text scoreText;
  scoreText.setFont(font);
  scoreText.setCharacterSize(30);
  scoreText.setColor(sf::Color::Blue);
  scoreText.setPosition(350, 10);
  scoreText.setString(scoreString.str());
  //Textures
  sf::Texture ballTexture;
  if (!ballTexture.loadFromFile("resources/ball.png")) {
    std::cout << "Could not load the texture pad.png" << std::endl;
    return -1;
  }

  sf::Texture padTexture;
  if (!padTexture.loadFromFile("resources/pad.png")) {
    std::cout << "Could not load the texture pad.png" << std::endl;
    return -1;
  }

  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("resources/background.png")) {
    std::cout << "Could not load the background" << std::endl;
    return -1;
  }

  //Sounds
  sf::SoundBuffer hitBuffer;
  if (!hitBuffer.loadFromFile("resources/hit.wav")) {
    std::cout << "Could not load the sound hit.wav" << std::endl;
    return -1;
  }

  sf::Sound hitSound;
  hitSound.setBuffer(hitBuffer);

  //Shapes
  sf::RectangleShape background;
  background.setSize(sf::Vector2f(800, 600));
  background.setPosition(0, 0);
  background.setTexture(&backgroundTexture);

  sf::Sprite ballSprite;
  ballSprite.setTexture(ballTexture);
  ballSprite.setPosition(350, 250);

  sf::Sprite padSprite1;
  padSprite1.setTexture(padTexture);
  padSprite1.setPosition(20, 200);

  sf::Sprite padSprite2;
  padSprite2.setTexture(padTexture);
  padSprite2.setPosition(730, 200);


  while (play) {

    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	play = false;
      }

      if (event.type == sf::Event::KeyPressed) {
	switch (event.key.code) {
	case sf::Keyboard::Up:
	  playerYVelocity = -playerMovementSpeed;
	  break;
	case sf::Keyboard::Down:
	  playerYVelocity = playerMovementSpeed;
	  break;
	}
      }

      if (event.type == sf::Event::KeyReleased) {
	switch (event.key.code) {
	case sf::Keyboard::Up:
	case sf::Keyboard::Down:
	  playerYVelocity = 0;
	  break;
	}
      }
    }


    //Logic
    padSprite1.move(0, playerYVelocity);

    if (padSprite1.getPosition().y < 0 || padSprite1.getPosition().y > 500) {
      padSprite1.move(0, -playerYVelocity);
    }

    ballSprite.move(xVelocityBall, yVelocityBall);
    if (ballSprite.getPosition().y < 0 || ballSprite.getPosition().y > 550) {
      ballSprite.move(0, -yVelocityBall);
      yVelocityBall *= -1;
    }

    //Bot
    if (ballSprite.getPosition().y > padSprite2.getPosition().y) {
      botYVelocity = botMovementSpeed;
    }

    if (ballSprite.getPosition().y < padSprite2.getPosition().y) {
      botYVelocity = -botMovementSpeed;
    }

    padSprite2.move(0, botYVelocity);

    if (padSprite2.getPosition().y < 0 || padSprite2.getPosition().y > 500) {
      padSprite2.move(0, -botMovementSpeed);
    }
    botYVelocity = 0;

    //Collisions
    if (ballSprite.getGlobalBounds().intersects(padSprite1.getGlobalBounds())) {
      xVelocityBall *= -1;
      hitSound.play();
    }

    if (ballSprite.getGlobalBounds().intersects(padSprite2.getGlobalBounds())) {
      int xP = ballSprite.getPosition().x;
      int yP = ballSprite.getPosition().y;

      if (yP >= padSprite2.getPosition().y + 100 || yP + 50 <= padSprite2.getPosition().y) {
	yVelocityBall *= -1;
	std::cout << "Hit y with ball pos: " << yP << "and pad pos: " << padSprite2.getPosition().y << std::endl;
      } else {
	std::cout << "Hit x" << std::endl;
	xVelocityBall *= -1;
      }

      ballSprite.move(xVelocityBall, yVelocityBall);

      hitSound.play();
    }

    if (ballSprite.getPosition().x < 0) {
      std::cout << "Player Loses" << std::endl;
      ballSprite.setPosition(350, 250);
      botScore++;
    }

    if (ballSprite.getPosition().x > 800) {
      std::cout << "PlayerWins" << std::endl;
      ballSprite.setPosition(350, 250);
      playerScore++;
    }

    scoreString.str("");
    scoreString << playerScore << " : " << botScore;
    scoreText.setString(scoreString.str());

    window.clear();

    window.draw(background);
    window.draw(ballSprite);
    window.draw(padSprite1);
    window.draw(padSprite2);
    window.draw(scoreText);

    window.display();
  }

  window.close();
  return 0;
}
