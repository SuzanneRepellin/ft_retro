/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro_macro.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:38:49 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:37:55 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACRO_HPP
# define FT_MACRO_HPP

# define MAX_Y 30
# define MAX_X 50
# define COLUMN 10
# define MAX_ENEMY 101
# define MAX_SHOTS MAX_Y - 1
# define PROGRESSION_SPEED 10000
# define DIFFICULTY_LEVELS 8
# define DEATH_CHAR '*'
# define SHOT_SPEED 1

enum Command {
    Echap = -1,
    None = 0,
    Left = 1,
    Right = 2,
    Shoot = 3,
    Restart = 4,
    Quit = 5
};

#endif