/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Capitalism.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:53:49 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPITALISM_HPP
# define CAPITALISM_HPP

# include "AEnemy.hpp"

class Capitalism : public AEnemy {
    public:
    Capitalism(unsigned int enemyNb);
    Capitalism(Capitalism const & src);
    ~Capitalism(void);

    Capitalism&  operator=(Capitalism const & rhs);

    private:
    Capitalism(void);

};

#endif
