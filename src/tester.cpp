/*
#include <SFML/Graphics.hpp>
#include <vector>

#include "timeseries.h"
#include "dataset.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>

int main() {
  // Configuración de la ventana principal
  sf::ContextSettings settings;
  settings.antialiasingLevel = 4;  // Nivel de antialiasing

  sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SFML Ventana Principal", sf::Style::Default, settings);
  mainWindow.setFramerateLimit(60);  // Límite de frames por segundo

  Dataset<double> ds("data", ' ');


  while (mainWindow.isOpen()) {
    sf::Event event;
    while (mainWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        mainWindow.close();
      }
    }

    mainWindow.clear();

    // Dibujar puntos en la ventana principal
    for (const auto& puntos : ds.data) {
      for (const auto& punto : puntos.values) {
        sf::CircleShape circle(5);  // Tamaño del punto
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(static_cast<float>(punto.first), static_cast<float>(punto.second));
        mainWindow.draw(circle);
      }
    }

    mainWindow.display();
  }

  return 0;
}
*/

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>

int main() {
    // Configuración de la ventana principal
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Nivel de antialiasing

    sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "SFML Ventana Principal", sf::Style::Default, settings);
    mainWindow.setFramerateLimit(60);  // Límite de frames por segundo

    // Vector de vectores para almacenar puntos
    std::vector<std::vector<std::pair<double, double>>> puntosVector;

    // Ejemplo: Crear algunos conjuntos de puntos con valores double
    puntosVector.push_back({{100.0, 100.0}, {200.0, 100.0}, {150.0, 200.0}});
    puntosVector.push_back({{400.0, 300.0}, {500.0, 300.0}, {450.0, 400.0}});

    while (mainWindow.isOpen()) {
        sf::Event event;
        while (mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                mainWindow.close();
            }
        }

        mainWindow.clear();

        // Dibujar solo el primer punto de cada vector en la ventana principal
        for (const auto& puntos : puntosVector) {
            if (!puntos.empty()) {
                const auto& primerPunto = puntos.front();
                sf::CircleShape circle(5);  // Tamaño del punto
                circle.setFillColor(sf::Color::Red);
                circle.setPosition(static_cast<float>(primerPunto.first), static_cast<float>(primerPunto.second));
                mainWindow.draw(circle);
            }
        }

        mainWindow.display();
    }

    return 0;
}
