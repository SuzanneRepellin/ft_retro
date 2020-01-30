/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:48:00 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntity.hpp"

class Player : public AEntity {
    public:
    Player(void);
    Player(Player const & src);
    ~Player();

    Player& operator=(Player const & rhs);

    void    hpUp(unsigned int);
    void    action(Command com);
    void	update(Command com, unsigned int curr);
};

#endif
