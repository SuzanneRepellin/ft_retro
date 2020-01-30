/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:49:00 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Player.hpp"

Player::Player(void) : AEntity(new Coordo(MAX_X / 2, MAX_Y, 0), 1, '^', 1) {}

Player::Player(Player const & src) {
	*this = src;
}

Player::~Player() {
	delete _coordo;
}

Player&  Player::operator=(Player const & rhs) {
	_hp = rhs._hp;
	_coordo = rhs._coordo;
	return *this;
}

void	Player::hpUp(unsigned int up) {
	_hp+= up;
}

void	Player::action(Command com) {
	if ((com == Left && _coordo->getx() == 0) || (com == Right && _coordo->getx() == MAX_X))
		return;
	else if (com == Left)
		_coordo->setx(_coordo->getx() - 1);
	else if (com == Right)
		_coordo->setx(_coordo->getx() + 1);
}

void	Player::update(Command com, unsigned int curr) {
	if (_hp == 0)
		_skin = DEATH_CHAR;
	else if (curr % _speed == 0 &&  com != None && com != Shoot)
		this->action(com);
}