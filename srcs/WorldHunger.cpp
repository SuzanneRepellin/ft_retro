/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WorldHunger.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:28:28 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:14:30 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WorldHunger.hpp"

WorldHunger::WorldHunger(unsigned enemyNb) : AEnemy(2, 'H', enemyNb, 6, 0, 1) {
	_name = "WorldHunger";
}

WorldHunger::WorldHunger(WorldHunger const & src) : AEnemy(src) {
	*this = src;
}

WorldHunger::~WorldHunger(void) {
	delete _coordo;
}


void    WorldHunger::takeDamage(unsigned int damage, unsigned int time) {
	if (_hp <= damage)
	{
		_timeOfDeath = time;
		_hp = 0;
	}
	else
	{
		_hp -= damage;
		_skin = 'h';
	}
}

WorldHunger&  WorldHunger::operator=(WorldHunger const & rhs) {
	_name = rhs._name;
	_hp = rhs._hp;
	_direction = rhs._direction;
	_horizMove = rhs._horizMove;
	_vertiMove = rhs._vertiMove;
	_direction = rhs._direction;
	_nb = rhs._nb;
	return *this;
}
