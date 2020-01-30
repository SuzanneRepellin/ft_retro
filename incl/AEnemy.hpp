/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 14:35:59 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENEMY_HPP
# define AENEMY_HPP

# include "AEntity.hpp"

class AEnemy : public AEntity {
    public:
    AEnemy(unsigned int hp, char skin, unsigned int enemyNb, unsigned int speed, int horizMove, int vertiMove);
    AEnemy(AEnemy const & src);
    virtual ~AEnemy() = 0;

    AEnemy&         operator=(AEnemy const & rhs);
    std::string     getName(void) const;
    void            update(unsigned int);
    void            setSkin(char);
    char            getSkin(void) const;

    protected:
    std::string     _name;
    void            move(void);
    int             _direction;            
    int             _horizMove;
    int             _vertiMove;
    unsigned int    _nb;
    
    private:
    AEnemy(void);
};

#endif
