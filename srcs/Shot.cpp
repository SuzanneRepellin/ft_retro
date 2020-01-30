/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:54:54 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Shot.hpp"

Shot::Shot(void) {}

Shot::Shot(Coordo* coordo) : AEntity(coordo, SHOT_SPEED, '|', 1) {}

Shot::Shot(Shot const & src) {
	*this = src;
}

Shot::~Shot(void) {
	delete _coordo;
}

Shot&  Shot::operator=(Shot const & rhs) {
	_hp = rhs._hp;
	_coordo = rhs._coordo;
	return *this;
}

void	Shot::update(unsigned int curr) {
	if (curr % _speed == 0 && curr != _prev)
	{
		_prev = curr;
		int newy = _coordo->gety() - 1;
		_coordo->sety(newy);
	}
}
