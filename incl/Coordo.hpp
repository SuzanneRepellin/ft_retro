/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coordo.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:54:05 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDO_HPP
# define COORDO_HPP

# include <iostream>

class Coordo {
    public:
    Coordo(void);
    Coordo(int x, int y, int z);
    Coordo(int x, int y);
    Coordo(Coordo const & src);
    ~Coordo(void);

    Coordo& operator=(Coordo const & rhs);
    bool    operator==(Coordo const & rhs);

	int	getx(void) const;
	int	gety(void) const;
	int	getz(void) const;

	void	setx(int x);
	void	sety(int y);
	void	setz(int z);
	void	setxyz(int x, int y, int z);
	void	setxy(int x, int y);


    private:
    int   _x;
    int   _y;
    int   _z;

};

#endif
