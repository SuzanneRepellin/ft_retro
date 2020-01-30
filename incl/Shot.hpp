/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 17:54:27 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOT_HPP
# define SHOT_HPP

# include "AEntity.hpp"

class Shot : public AEntity {
    public:
    Shot(Coordo* coordo);
    Shot(Shot const & src);
    ~Shot(void);

    Shot&   operator=(Shot const & rhs);
    void    update(unsigned int curr);
    int i;
    private:
    Shot(void);

};

#endif
