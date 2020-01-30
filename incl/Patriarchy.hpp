/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patriarchy.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:54:20 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATRIARCHY_HPP
# define PATRIARCHY_HPP

# include "AEnemy.hpp"

class Patriarchy : public AEnemy {
    public:
    Patriarchy(unsigned int enemyNb);
    Patriarchy(Patriarchy const & src);
    ~Patriarchy(void);

    Patriarchy&  operator=(Patriarchy const & rhs);

    private:
    Patriarchy(void);

};

#endif
