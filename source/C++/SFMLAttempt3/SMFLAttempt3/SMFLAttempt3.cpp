

//C++ SFML SOS game project Testing branch 

//sprint 0 Goals:
    // include text,      done 
    // lines, 
    // a check box, 
    // and radio buttons




#include <iostream>
#include <string>
#include <sstream>


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "SMFLAttempt3.h"


//text rendering-- 
//to render text first use sf::Font font("arial.ttf") to define font
//then use sf::Text text(fontname, "text to display" 
//additionally you can use .setCharacterSize(), .setStyle(), setFillColor(sf:color::Red)
//lastly call the draw object, using window.draw(text)




//Rendering Lines 
// define a grid size
// draw vertical and horizontal lines using sf::VertexArray and sf::Lines. all lines will have 2 vertices
// put draw call in main loop 




int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SOS Development");
    

    sf::Text Text;
    sf::Font font;
    if (!font.loadFromFile("include/Freedom-10eM.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }


    Text.setFont(font);
    Text.setString("Hello Im rendering text as an example");
    Text.setFillColor(sf::Color::Blue);

    // creating the rows and cols
    int gridSizeY = 10; //rows
    int gridSizeX = 10; //cols
    float cellSize = 50.f;

    //create a line
    sf::RectangleShape line(sf::Vector2f(cellSize, 1));
    line.setFillColor(sf::Color::Red);
    float gridWidth = gridSizeX * cellSize;
    float gridHeight = gridSizeY * cellSize;

    // Calculate the center of the window
    float centerX = window.getSize().x / 2.f;
    float centerY = window.getSize().y / 2.f;

    // Calculate the offset to center the grid
    float offsetX = centerX - gridWidth / 2.f;
    float offsetY = centerY - gridHeight / 2.f;


    // Set the color of the lines (white)
    class RadioButton {
    public:
        RadioButton(float x, float y, float outerRadius, float innerRadius)
            : position(x, y), outerRadius(outerRadius), innerRadius(innerRadius), isSelected(false)
        {
            // Outer circle (the radio button itself)
            outer.setRadius(outerRadius);
            outer.setPointCount(30);  // Make the circle smooth
            outer.setFillColor(sf::Color::White);
            outer.setOutlineColor(sf::Color::Black);
            outer.setOutlineThickness(2);
            outer.setPosition(x - outerRadius, y - outerRadius);

            // Inner circle (the selected part)
            inner.setRadius(innerRadius);
            inner.setPointCount(30);
            inner.setFillColor(sf::Color::Black);  // Default to unselected (no inner circle)
            inner.setPosition(x - innerRadius, y - innerRadius);
        }

        // Draw the radio button
        void draw(sf::RenderWindow& window) {
            window.draw(outer);
            window.draw(inner);
            
        }

        // Check if the radio button is clicked
        void handleClick(float x, float y) {
            if (outer.getGlobalBounds().contains(x, y)) {
                isSelected = !isSelected;  // Toggle the selection state
                if (isSelected) {
                    inner.setFillColor(sf::Color::Black);  // Fill inner circle if selected
                }
                else {
                    inner.setFillColor(sf::Color::Transparent);  // Clear inner circle if unselected
                }
            }
        }

        // Get the current selected state
        bool getSelected() const {
            return isSelected;
        }

        // Reset the button to unselected state
        void reset() {
            isSelected = false;
            inner.setFillColor(sf::Color::Transparent);
        }

    private:
        sf::CircleShape outer;
        sf::CircleShape inner;
        sf::Vector2f position;
        float outerRadius;
        float innerRadius;
        bool isSelected;
    };
     
    //class that creates a check box 
    //there is no default checkbox bc this is not a gui lib, but rather a game dev lib
    class CheckBox {
    public:
        // Constructor
        CheckBox(float x, float y, float width)
            : position(x, y), width(width), isChecked(false) {
            outerBox.setSize(sf::Vector2f(width, width));
            outerBox.setPosition(x,y);
            outerBox.setFillColor(sf::Color::White);
            outerBox.setOutlineThickness(2);
            outerBox.setOutlineColor(sf::Color::Red);


            /*checkMark.setSize(sf::Vector2f(width /2, width /2));
            checkMark.setFillColor(sf::Color::Green);*/
            checkMark.setPrimitiveType(sf::LinesStrip); // Using lines to draw a "V" shaped checkmark
            checkMark.append(sf::Vertex(sf::Vector2f(x + width / 4, y + width / 2), sf::Color::Green)); // Starting point of the check mark
            checkMark.append(sf::Vertex(sf::Vector2f(x + width / 2, y + width * 3 / 4), sf::Color::Green)); // Middle point
            checkMark.append(sf::Vertex(sf::Vector2f(x + width * 3 / 4, y + width / 4), sf::Color::Green)); // End point of the check mark
        }
        void draw(sf::RenderWindow& window) {
            //draws the outerBox
            window.draw(outerBox);
           
            if (isChecked == true) {
                /*checkMark.setPosition(position.x + width / 4, position.y + width / 4);*/
                window.draw(checkMark);

            }
        }

        void handleClick(float X, float Y) {
            if (X >= position.x && X <= position.x + width &&
                Y >= position.y && Y <= position.y + width) {
                isChecked = !isChecked; //change clicked state
            }
           

        }

    private:
        sf::RectangleShape outerBox;  // Rectangle for the outer box of the checkbox
        sf::VertexArray checkMark;  // Rectangle for the check mark
        sf::Vector2f position;  // Position of the checkbox
        float width;  // Size of the checkbox
        bool isChecked;  // State of the checkbox (checked or unchecked)
    };

    sf::CircleShape triangle(80, 3); //this creates a triangle , use this to make a triangular radiobutton 
    triangle.setFillColor(sf::Color::Cyan);

    RadioButton radiobutton(400.f, 300.f, 20.f, 10.f);
    CheckBox checkBox(200.f, 200.f, 40.f);


    while (window.isOpen()) {
     
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();


             }
            if (e.type == sf::Event::MouseButtonPressed) {
                float mouseX = e.mouseButton.x;
                float mouseY = e.mouseButton.y;
                checkBox.handleClick(mouseX, mouseY);



                if (e.mouseButton.button == sf::Mouse::Left) {
                    radiobutton.handleClick(e.mouseButton.x, e.mouseButton.y);
                       
                
                }
                
                
            }
        }

        window.clear(sf::Color::White);
        radiobutton.draw(window);
        checkBox.draw(window);

        window.draw(triangle);


        for (int i = 0; i <= gridSizeY; ++i)
        {
            // Horizontal lines have width equal to grid width and height equal to 1 pixel
            line.setSize(sf::Vector2f(gridWidth, 1.f));
            line.setPosition(offsetX, offsetY + i * cellSize); // Adjust position based on offset
            window.draw(line);
        }

        // Draw vertical lines
        for (int i = 0; i <= gridSizeX; ++i)
        {
            // Vertical lines have height equal to grid height and width equal to 1 pixel
            line.setSize(sf::Vector2f(1.f, gridHeight));
            line.setPosition(offsetX + i * cellSize, offsetY); // Adjust position based on offset
            window.draw(line);
        }
        window.draw(Text); // Draw the text
        window.display();
    }
    std::cout << "Hello World!\n";
}

