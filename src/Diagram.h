#ifndef SORTVISUALIZER_DIAGRAM_H
#define SORTVISUALIZER_DIAGRAM_H

#include <functional>
#include "SFML/Graphics.hpp"
#include "Dispatcher.h"
#include <mutex>
class IntWrapper;

class Diagram : public sf::Drawable {
    std::vector<int> _values;
    std::vector<sf::RectangleShape> _bars;
    sf::Vector2f _position;
    sf::Vector2f _size;

    float _margin = 1;
    float max_bar_width = 50;

    void _resize();

public:
    Dispatcher dispatcher;
    bool is_alive = true;
    sf::Color bars_default_color = sf::Color(218, 83, 44);
    int wait_time_ms = 1000;
    float max_value = 100;

    Diagram(sf::Vector2f size);

    void swap(int idA, int idB, bool showBlue = false);

    void set_element(int idFrom, int val);

    int compare_elements(int id1, int id2);

    void set_position(sf::Vector2f pos);

    sf::Vector2f get_position();

    std::vector<IntWrapper> set_values(std::vector<int> &values);

    int get_value(int pos);

    void set_size(sf::Vector2f size);

    sf::Vector2f get_size();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void update();
    void handle_event(sf::Event e);

};

#endif //SORTVISUALIZER_DIAGRAM_H
