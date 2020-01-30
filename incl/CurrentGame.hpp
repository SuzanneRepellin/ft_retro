/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentGame.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:18:27 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURRENTGAME_HPP
# define CURRENTGAME_HPP

# include "ft_retro.hpp"


class CurrentGame {
    public:
    CurrentGame(void);
    CurrentGame(CurrentGame const & src);
    ~CurrentGame();

    CurrentGame&    operator=(CurrentGame const & rhs);

    bool            update(void);
    void            updateLevel(void);
    unsigned int    getScore(void) const;
    unsigned int    getTimeOfEnd(void) const;
    bool            endScreen(void);

    private:
    void            checkEnemies(unsigned int);
    void            checkPlayer(void);
    void            checkShots(AEnemy*, unsigned int);
    void            checkShots(void);
    void            spawnEnemies(unsigned int);

    AEnemy*         spawnCapitalism(void);
    AEnemy*         spawnPatriarchy(void);
    AEnemy*         spawnWorldHunger(void);
    
    void            spawnShot(void);

    AEnemy*         _enemies[MAX_ENEMY];
    Shot*           _shots[MAX_SHOTS];
    Player*         _player;
    Map*            _map;
    unsigned int    _curr;
    unsigned int    _enemyNb;
    unsigned int    _score;
    std::clock_t    _start;
    unsigned int    _prevSpawn;
    unsigned int    _timeOfEnd;
    unsigned int    _level;

    static unsigned int _enemySpawn[DIFFICULTY_LEVELS];
};

#endif
