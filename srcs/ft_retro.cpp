/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:59:18 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:00:45 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void    runGame(CurrentGame* cr)
{
    while (cr->update()){
    }
    if (cr->endScreen())
    {
        delete cr;
        CurrentGame* cr = new CurrentGame();
        runGame(cr);
    }
    else {
        delete cr;
    }
}

int     main(void)
{
    initscr();
    cbreak();
    noecho();
    attron(A_BOLD);
    start_color();
    init_pair(1, COLOR_BLUE , 0);
    init_pair(2, COLOR_RED, 0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    CurrentGame* cr = new CurrentGame();

    runGame(cr);

    endwin();
    return 0;
}