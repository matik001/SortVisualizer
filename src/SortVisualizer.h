#ifndef SORTVISUALIZER_SORTVISUALIZER_H
#define SORTVISUALIZER_SORTVISUALIZER_H
#include "Diagram.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "IntWrapper.h"
#include <thread>
#include <memory>
class SortVisualizer
{
    std::unique_ptr<sf::RenderWindow> _window;
    std::thread _thread_worker;
    void _create_window();
    void _work();
    std::shared_ptr<Diagram> _diagram;

public:
    SortVisualizer(int WaitTimeMs = 500, int MaxValue = 100);
    void show_window();
    std::vector<IntWrapper> init_values(std::vector<int> &values);
    ~SortVisualizer();

};




#endif //SORTVISUALIZER_SORTVISUALIZER_H
