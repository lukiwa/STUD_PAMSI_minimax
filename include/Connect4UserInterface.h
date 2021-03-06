//
// Created by Lukasz-Lap on 19.05.2020.
//

#pragma once

#include "Connect4AI.h"
#include "SFML/Graphics.hpp"

enum class TerminalGameState {
    TIE, PLAYER_WINS, AI_WINS, PLAYER2_WINS
};

class Connect4UserInterface {
private:
    Connect4AI &_game;
    sf::RenderWindow &_window;
    sf::Event _event;
    TerminalGameState _state;
    bool _player_vs_player;

    //------
    std::array<std::array<sf::CircleShape, 6>, 7> _coins;

    sf::RectangleShape _board_picture;
    float _board_height;
    float _coin_radius;
    sf::CircleShape _to_drop_coin; //coin at the top - follow player mouse


    sf::Color _player_color, _ai_color;
    sf::Color _background_color;
    sf::Color _border_color;


    void Start();

    void DisplayGame();

    void End();

    void DrawEndText();

    void TakeTurn();

    void UpdateCoinsColors();

    int ColumnSelector(const sf::Color &player_color);

    int ConvertMousePositionToColumn(const sf::Vector2i &mouse_position);

    static void SetText(sf::Text &text, const sf::Font &font, const sf::Color &color, int font_size,
                 const sf::Vector2i &position) ;

    void DifficultySelector();

public:
    Connect4UserInterface(Connect4AI &game, sf::RenderWindow &window);

    void Run();
};




