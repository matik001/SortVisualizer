#include "SortVisualizer.h"
#include "Config.h"
#include "SFML/Graphics.hpp"
#include <memory>
#include "IntWrapper.h"


void SortVisualizer::_create_window() {
    _window = std::unique_ptr<sf::RenderWindow>(
            new sf::RenderWindow(
                    sf::VideoMode(Config::WINDOW_SIZE.x, Config::WINDOW_SIZE.y),
                    Config::WINDOW_TITLE, sf::Style::Default
            )
    );
    _window->setFramerateLimit(60);
    _window->setKeyRepeatEnabled(false);
}


void SortVisualizer::_work() {
    _create_window();
    while (_window->isOpen()) {
        sf::Event event;
        if (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window->close();
            if (event.type == sf::Event::Resized) {
                _window->setView(sf::View(sf::FloatRect(0, 0, (float) event.size.width, (float) event.size.height)));
                _diagram->set_size(_window->getView().getSize());
            }
            _diagram->handle_event(event);
        }
        _diagram->update();

        _window->clear(sf::Color(23, 23, 23));
        _window->draw(*_diagram);
        _window->display();
    }
    _window.reset();
    _diagram->is_alive = false;
}


SortVisualizer::SortVisualizer(int WaitTimeMs, int MaxValue) {
    _diagram = std::shared_ptr<Diagram>(new Diagram(sf::Vector2f(Config::WINDOW_SIZE.x, Config::WINDOW_SIZE.y)));
    _diagram->wait_time_ms = WaitTimeMs;
    _diagram->max_value = MaxValue;
}

void SortVisualizer::show_window() {
    _thread_worker = std::thread(&SortVisualizer::_work, this);
}

std::vector<IntWrapper> SortVisualizer::init_values(std::vector<int> &values) {
    return _diagram->set_values(values);
}


SortVisualizer::~SortVisualizer() {
    if (_thread_worker.joinable())
        _thread_worker.join();
}
