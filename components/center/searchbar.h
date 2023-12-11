#include <SFML/Graphics.hpp>

class SearchBar {
private:
    sf::RectangleShape inputField;
    sf::Vector2f size;
    sf::Text text;
    sf::Font font;
    std::string inputText;
    std::string originalText;
    sf::Clock blinkClock;
    bool showBlinker;
    bool doSearch;
public:
    SearchBar(float resolutionX,float resolutionY);
    void handleEvent(sf::Event event);
    void update();
    void draw(sf::RenderWindow& window);
    std::string getEnteredText();
    void setDoSearch(bool doSearch);
    bool getDoSearch();
};
