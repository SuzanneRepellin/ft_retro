/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patriarchy.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:28:28 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:17:35 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Patriarchy.hpp"

Patriarchy::Patriarchy(unsigned enemyNb) : AEnemy(1, 'P', enemyNb, 2, 1, 1) {
	_name = "Patriarchy";
}

Patriarchy::Patriarchy(Patriarchy const & src) : AEnemy(src) {
	*this = src;
}

Patriarchy::~Patriarchy(void) {
	delete _coordo;
}

Patriarchy&  Patriarchy::operator=(Patriarchy const & rhs) {
	_name = rhs._name;
	_hp = rhs._hp;
	_direction = rhs._direction;
	_horizMove = rhs._horizMove;
	_vertiMove = rhs._vertiMove;
	_direction = rhs._direction;
	_nb = rhs._nb;
	return *this;
}
