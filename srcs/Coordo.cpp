/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coordo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:54:38 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Coordo.hpp"

Coordo::Coordo(void) : _x(0), _y(0), _z(0) {}

Coordo::Coordo(int x, int y, int z) :
_x(x),
_y(y),
_z(z)
{}

Coordo::Coordo(int x, int y) :
_x(x),
_y(y),
_z(0)
{}

Coordo::Coordo(Coordo const & src) {
	*this = src;
}

Coordo::~Coordo(void) {}

int	Coordo::getx(void) const {
	return _x;
}

int	Coordo::gety(void) const {
	return _y;
}

int	Coordo::getz(void) const {
	return _z;
}

void	Coordo::setx(int x) {
	_x = x;
}

void	Coordo::sety(int y) {
	_y = y;
}

void	Coordo::setz(int z) {
	_z = z;
}

void	Coordo::setxyz(int x, int y, int z) {
	_x = x;
	_y = y;
	_z = z;
}

void	Coordo::setxy(int x, int y) {
	_x = x;
	_y = y;
}

Coordo&  Coordo::operator=(Coordo const & rhs) {
	_x = rhs.getx();
	_y = rhs.gety();
	_z = rhs.getz();
	return *this;
}

bool  Coordo::operator==(Coordo const & rhs) {
	bool ret = (_x == rhs.getx()) && (_y == rhs.gety());
	return ret;
}
