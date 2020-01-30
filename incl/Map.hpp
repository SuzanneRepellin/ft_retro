/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:42:14 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <ncurses.h>
# include "ft_retro_macro.hpp"
# include "AEnemy.hpp"
# include "Player.hpp"
# include "Shot.hpp"

class Map {
    public:
    Map(void);
    Map(void *data);
    Map(Map const & src);
    ~Map(void);

    Map&  operator=(Map const & rhs);


	void printAll(void);

    Command endScreen(unsigned int, unsigned int);   
	void    printPlan(unsigned int time, unsigned int score, unsigned int hp);
	Command update(Player *player, AEnemy** aEnemy, Shot** shot, unsigned int time, unsigned int score, unsigned int hp);
	void    printEntity(void);

    private:
    void*   _data;
};

#endif
