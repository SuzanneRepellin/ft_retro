/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Capitalism.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:28:28 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:17:20 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Capitalism.hpp"

Capitalism::Capitalism(unsigned enemyNb) : AEnemy(1, 'C', enemyNb, 5, 2, 1) {
	_name = "Capitalism";
}

Capitalism::Capitalism(Capitalism const & src) : AEnemy(src) {
	*this = src;
}

Capitalism::~Capitalism(void) {
	delete _coordo;
}

Capitalism&  Capitalism::operator=(Capitalism const & rhs) {
	_name = rhs._name;
	_hp = rhs._hp;
	_direction = rhs._direction;
	_horizMove = rhs._horizMove;
	_vertiMove = rhs._vertiMove;
	_direction = rhs._direction;
	_nb = rhs._nb;
	return *this;
}
