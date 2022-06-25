#include "Diagram.h"
#include "IntWrapper.h"
#include <mutex>
#include <iostream>
#include <thread>



void Diagram::_resize() {
    _margin = 1;
    float barXWithMargin = (this->_size.x - _margin * (_values.size() - 1)) / (float) _values.size();
    if (barXWithMargin < 1.f)
        _margin = 0;
    else
        _margin = 1;

    float barX = (this->_size.x - _margin * (_values.size() - 1)) / (float) _values.size();
    barX = std::min(barX, max_bar_width);
    float factorY = this->_size.y / max_value;
    for (int i = 0; i < _values.size(); i++) {
        _bars[i].setFillColor(bars_default_color);
        _bars[i].setSize(sf::Vector2f(barX, factorY * _values[i]));
        _bars[i].setPosition(sf::Vector2f(i * (_margin + barX), _size.y - _bars[i].getSize().y));
    }
}

Diagram::Diagram(sf::Vector2f size) {
    this->_size = size;
}

void Diagram::swap(int idA, int idB, bool showBlue) {
    int tmp = _values[idB];
    set_element(idB, _values[idA]);
    set_element(idA, tmp);

    if (showBlue) {
        dispatcher.execute([this, idA, idB] {
            _bars[idA].setFillColor(sf::Color::Blue);
            _bars[idB].setFillColor(sf::Color::Blue);
        });

        std::this_thread::sleep_for(std::chrono::milliseconds(wait_time_ms));


        dispatcher.execute([this, idA, idB] {
            _bars[idA].setFillColor(bars_default_color);
            _bars[idB].setFillColor(bars_default_color);
        });
    }
}

void Diagram::set_element(int idFrom, int val) {
    _values[idFrom] = val;

    float factorY = this->_size.y / max_value;

    dispatcher.execute([this, idFrom, factorY] {
        _bars[idFrom].setSize(sf::Vector2f(_bars[idFrom].getSize().x, _values[idFrom] * factorY));
        _bars[idFrom].setPosition(
                sf::Vector2f(_bars[idFrom].getPosition().x, this->_size.y - _bars[idFrom].getSize().y));
    });
}

int Diagram::compare_elements(int id1, int id2) {
    int idSmaller = (_values[id1] < _values[id2] ? id1 : id2);
    int idBigger = (_values[id1] >= _values[id2] ? id1 : id2);
    if (_values[idSmaller] == _values[idBigger]) {
        dispatcher.execute([this, id1, id2] {
            _bars[id1].setFillColor(sf::Color::Yellow);
            _bars[id2].setFillColor(sf::Color::Yellow);
        });

        std::this_thread::sleep_for(std::chrono::milliseconds(wait_time_ms));
    } else {

        dispatcher.execute([this, idBigger, idSmaller] {
            _bars[idBigger].setFillColor(sf::Color::Red);
            _bars[idSmaller].setFillColor(sf::Color::Green);
        });

        std::this_thread::sleep_for(std::chrono::milliseconds(wait_time_ms));
    }

    dispatcher.execute([this, id1, id2] {
        _bars[id1].setFillColor(bars_default_color);
        _bars[id2].setFillColor(bars_default_color);
    });


    if (_values[id1] < _values[id2])
        return -1;
    if (_values[id1] > _values[id2])
        return 1;
    return 0;

}

void Diagram::set_position(sf::Vector2f pos) {
    this->_position = pos;
}

sf::Vector2f Diagram::get_position() {
    return this->_position;
}

std::vector<IntWrapper> Diagram::set_values(std::vector<int> &values) {
    this->_values = values;
    _bars.assign(values.size(), sf::RectangleShape());
    _resize();

    std::vector<IntWrapper> result(values.size());
    for (int i = 0; i < result.size(); i++) {
        result[i].copy(IntWrapper::create(*this, i));
    }
    return result;
}

int Diagram::get_value(int pos) {
    return _values[pos];
}


void Diagram::set_size(sf::Vector2f size) {
    this->_size = size;
    _resize();
}

sf::Vector2f Diagram::get_size() {
    return this->_size;
}

void Diagram::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform = states.transform.translate(_position);
    for (auto b: _bars)
        target.draw(b, states);
}

void Diagram::handle_event(sf::Event e) {
    if (e.type == e.KeyPressed && e.key.code == sf::Keyboard::Up) {
        wait_time_ms *= (5.0 / 6);
        if (wait_time_ms <= 0)
            wait_time_ms = 1;
    } else if (e.type == e.KeyPressed && e.key.code == sf::Keyboard::Down) {
        wait_time_ms += 50;
    } else if (e.type == e.KeyPressed && e.key.code == sf::Keyboard::LControl)
        wait_time_ms = 0;

}

void Diagram::update() {
    dispatcher.update();
}

