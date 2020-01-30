/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:43:57 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AEntity.hpp"

AEntity::AEntity(void) {}

AEntity::AEntity(Coordo* coordo, unsigned int hp, char skin, unsigned int speed) :
_coordo(coordo),
_hp(hp),
_speed(speed),
_skin(skin),
_prev(0),
_timeOfDeath(0)
{}

AEntity::AEntity(unsigned int hp, char skin, unsigned int speed) :
_coordo(new Coordo(0, 0, 0)),
_hp(hp),
_speed(speed),
_skin(skin),
_prev(0),
_timeOfDeath(0)
{}

AEntity::AEntity(AEntity const & src) {
	*this = src;
}

AEntity::~AEntity() {}

AEntity&  AEntity::operator=(AEntity const & rhs) {
	_hp = rhs._hp;
	_coordo = rhs._coordo;
	_speed = rhs._speed;
	_skin = rhs._skin;
	_prev = rhs._prev;
	_timeOfDeath = rhs._timeOfDeath;
	return *this;
}

Coordo*	AEntity::getCoordo(void) const {
	return _coordo;
}

unsigned int	AEntity::getTimeOfDeath(void) const {
	return _timeOfDeath;
}

void	AEntity::takeDamage(unsigned int damage, unsigned int time) {
	if (_timeOfDeath != time)
	{
		if (_hp <= damage)
		{
			_timeOfDeath = time;
			_hp = 0;
		}
		else
		{
			_hp -= damage;
		}
		_timeOfDeath = time;
	}
}

char	AEntity::getSkin(void) const {
	return _skin;
}

unsigned int		AEntity::getHP(void) const {
	return _hp;
}