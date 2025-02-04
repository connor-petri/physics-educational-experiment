#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <optional>
#include <variant>

#include "PeeTest/PeeTest.h"
#include "vectors/tests/Vector3Test.h"

int main() {
    using peeTest::Vector3Test;
    Vector3Test t0(1,1,1,1,1,1);
    Vector3Test t1(1,0,0,2,0,0); // Parallel
    Vector3Test t2(1,0,0,0,1,0); // Orthogonal

    peeTest::PeeTest::runAll();

    // Test SFML
    sf::Window window(sf::VideoMode({800, 600}), "Test Window");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }

    return 0;
}

