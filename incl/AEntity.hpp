/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:43:45 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

# include "ft_retro_macro.hpp"
# include "Coordo.hpp"

class AEntity {
    public:
    AEntity(Coordo*, unsigned int, char, unsigned int);
    AEntity(unsigned int, char, unsigned int);
    AEntity(unsigned int, char);
    AEntity(AEntity const & src);
    virtual ~AEntity() = 0;

    AEntity&    operator=(AEntity const & rhs);

	Coordo*         getCoordo(void) const;
	unsigned int    getHP(void) const;
    char            getSkin(void) const;
	virtual void    takeDamage(unsigned int, unsigned int);
    unsigned int    getTimeOfDeath(void) const;

    protected:
    AEntity(void);
    Coordo*         _coordo;
    unsigned int    _hp;
    unsigned int    _speed;
    char            _skin;
    unsigned int    _prev;
    unsigned int    _timeOfDeath;

};

#endif
