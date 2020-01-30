/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:53:22 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_retro.hpp"

AEnemy::AEnemy(void) {}

AEnemy::~AEnemy(void) {}

AEnemy::AEnemy(unsigned int hp, char skin, unsigned int enemyNb, unsigned int speed, int horizMove, int vertiMove) : AEntity(hp, skin, speed) {
	int rand = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
	.time_since_epoch())
	.count();
	_direction = rand % 2 == 0 ? 1 : -1;
	rand = rand < 0 ? rand * -1 : rand;
	int x = rand % MAX_X;
	int y = 0;
	int z = enemyNb;
	_coordo = new Coordo(x, y, z);
	_horizMove = horizMove;
	_vertiMove = vertiMove;
	_nb = enemyNb;
}

AEnemy::AEnemy(AEnemy const & src) {
	*this = src;
}

void	AEnemy::update(unsigned int curr) {
	if (_hp == 0) {
		_skin = DEATH_CHAR;
	}
	else if (curr != _prev && curr % _speed == 0) {
		_prev = curr;
		this->move();
	}
}

void	AEnemy::move() {
	int x = _coordo->getx();
	int y = _coordo->gety();
	int	newX = x + _horizMove * _direction;
	if (newX <= 0)
	{
		newX = 0 +  (_horizMove - x);
		_direction *= -1;
	}
	else if (newX >= MAX_X)
	{
		newX = MAX_X - (_horizMove - (MAX_X - x));
		_direction *= -1;
	}
	_coordo->setx(newX);
	_coordo->sety(y + _vertiMove);
}

std::string	AEnemy::getName(void) const {
	return _name;
}

char		AEnemy::getSkin(void) const {
	return _skin;
}

AEnemy&  AEnemy::operator=(AEnemy const & rhs) {
	_name = rhs._name;
	_hp = rhs._hp;
	_direction = rhs._direction;
	_horizMove = rhs._horizMove;
	_vertiMove = rhs._vertiMove;
	_direction = rhs._direction;
	_nb = rhs._nb;
	_coordo = rhs._coordo;
	return *this;
}

void	AEnemy::setSkin(char c) {
	_skin = c;
}