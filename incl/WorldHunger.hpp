/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WorldHunger.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:13:26 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLDHUNGER_HPP
# define WORLDHUNGER_HPP

# include "AEnemy.hpp"

class WorldHunger : public AEnemy {
    public:
    WorldHunger(unsigned int enemyNb);
    WorldHunger(WorldHunger const & src);
    ~WorldHunger(void);

    WorldHunger&  operator=(WorldHunger const & rhs);

    void          takeDamage(unsigned int, unsigned int);

    private:
    WorldHunger(void);

};

#endif
