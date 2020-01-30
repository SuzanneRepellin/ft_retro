/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:48:15 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Map.hpp"
#include "ft_retro_macro.hpp"

Map::Map(void) {}

Map::Map(Map const & src) {
	*this = src;
}

Map::~Map(void) {}

Map&  Map::operator=(Map const & rhs) {
    _data = rhs._data;
	return *this;
}

Command Map::endScreen(unsigned int score, unsigned int time) {
    erase();
    move(5, MAX_X / 2 - 7);
    printw("END OF THE GAME");
    move(7, MAX_X / 2 - 5);
    printw("TIME  : ");
    printw("%d", time / 10);
    move(8, MAX_X / 2 - 5);
    printw("SCORE : ");
    printw("%d", score);
    move(15, MAX_X / 2 - 7);
    printw("Restart press 'r' ");
    move(16, MAX_X / 2 - 5);
    printw("Quit press 'q' ");
    int ch = getch();
    while(ch != 113 && ch != 114){
        ch = getch();
    }
    if (ch == 113)
        return Quit;
    else
        return Restart;
}

void Map::printPlan(unsigned int time, unsigned int score, unsigned int hp){
    erase();
    move(0, 0);
    attron(COLOR_PAIR(3));
    printw("\n"
           "            *          .\n"
           "                   *       '\n"
           "              *                *\n"
           "   *   '*\n"
           "                *\n"
           "           *\n"
           "                *\n"
           "                       *\n"
           "               *\n"
           "                     *\n        *\n"
           "                       *\n"
           "               *\n"
           "                     *\n"
           "         .                      .\n"
           "         .                      ;\n"
           "         :                  - --+- -\n"
           "         !           .          !\n"
           "         |        .             .\n"
           "         |_         +\n"
           "      ,  | `.\n"
           "--- --+-<#>-+- ---  --  -\n"
           "      `._|_,'\n"
           "         T\n"
           "         |\n"
           "         !\n"
           "         :         . : \n"
           "         .       *");
    attroff(COLOR_PAIR(3));

    int y = MAX_Y +1;
    int x = MAX_X + COLUMN + 1;
    while (x >= 0){
        mvaddch(y, x, ACS_S1);
        x--;
    }
    x = MAX_X + COLUMN;
    y--;
    while (y >= 0){
        mvaddch(y, x +1, ACS_VLINE);
        mvaddch(y, x -COLUMN + 1, ACS_VLINE);
        y--;
    }
    move(3, MAX_X + 3);
    printw("SCORE");
    move(4, MAX_X + 3);
    printw("%d", score);
    move(7,  MAX_X + 3);
    printw("TIME");
    move(8,  MAX_X + 3);
    printw("%d", time / 10);
    move(11,  MAX_X + 3);
    printw("HP");
    move(12,  MAX_X + 3);
    printw("%d", hp);
}

Command Map::update(Player * player, AEnemy** aEnemy, Shot** shot, unsigned int time, unsigned int score, unsigned int hp){
    int ch = 0;
    ch = getch();
    printPlan(time, score, hp);
    mvaddch(player->getCoordo()->gety(), player->getCoordo()->getx(), player->getSkin());

    for (size_t i = 0; i < MAX_ENEMY ; i++) {
        if (aEnemy[i]){
            if (aEnemy[i]->getSkin() == '*')
                mvaddch(aEnemy[i]->getCoordo()->gety(), aEnemy[i]->getCoordo()->getx(), aEnemy[i]->getSkin() | COLOR_PAIR(2));
            else
                mvaddch(aEnemy[i]->getCoordo()->gety(), aEnemy[i]->getCoordo()->getx(), aEnemy[i]->getSkin());
        }
    }
    for (size_t j = 0; j < MAX_SHOTS ; j++) {
        if (shot[j]){
            mvaddch(shot[j]->getCoordo()->gety(), shot[j]->getCoordo()->getx(), shot[j]->getSkin() | COLOR_PAIR(1));
            mvaddch(shot[j]->getCoordo()->gety() - 1, shot[j]->getCoordo()->getx(), shot[j]->getSkin() | COLOR_PAIR(1));
        }
    }

    if (ch == KEY_LEFT){
        return (Command)1;
    }
    else if (ch == KEY_RIGHT){
        return (Command)2;
    }
    else if (ch == KEY_UP){
        return (Command)3;
    }
    else
    return (Command)0;
}