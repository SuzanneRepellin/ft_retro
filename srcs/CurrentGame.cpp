/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CurrentGame.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srepelli <srepelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:02:32 by srepelli          #+#    #+#             */
/*   Updated: 2020/01/19 18:48:30 by srepelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CurrentGame.hpp"

CurrentGame::CurrentGame(void) {
	_curr = 0;
	for (size_t i = 0; i < MAX_ENEMY ; i++)
	{
		_enemies[i] = NULL;
	}
	for (size_t i = 0; i < MAX_SHOTS ; i++)
	{
		_shots[i] = NULL;
	}
	_player = new Player();
	_map = new Map();
	_enemyNb = 0;
	_score = 0;
    _start = std::clock();
	_prevSpawn = 0;
	_timeOfEnd = 0;
	_level = 1;
}

CurrentGame::CurrentGame(CurrentGame const & src) {
	*this = src;
}

CurrentGame::~CurrentGame() {
	delete _player;
	for (size_t i = 0; i < MAX_ENEMY ; i++)
	{
		delete _enemies[i];
	}
	for (size_t i = 0; i < MAX_SHOTS ; i++)
	{
		delete _shots[i];
	}
}

CurrentGame&  CurrentGame::operator=(CurrentGame const & rhs) {
	for (size_t i = 0; i < MAX_ENEMY ; i++)
	{
		_enemies[i] = rhs._enemies[i];
	}
	for (size_t i = 0; i < MAX_SHOTS ; i++)
	{
		_shots[i] = rhs._shots[i];
	}
	_player = rhs._player;
	return *this;
}

unsigned int CurrentGame::getScore(void) const {
	return _score;
}

unsigned int CurrentGame::getTimeOfEnd(void) const {
	return _timeOfEnd;
}

void		CurrentGame::checkPlayer(void) {
	if (_player->getHP() == 0)
	{
		delete this;
	}
}

void		CurrentGame::checkShots(AEnemy* e, unsigned int time) {
	for (size_t j = 0; j < MAX_SHOTS ; j++)
	{
		if (_shots[j] && (*_shots[j]->getCoordo() == *e->getCoordo() 
		|| Coordo(_shots[j]->getCoordo()->getx(), _shots[j]->getCoordo()->gety() - 1) == *e->getCoordo()))
		{
			e->takeDamage(1, time);
			delete _shots[j];
			_shots[j] = NULL;
		}
	}
}

void		CurrentGame::checkShots(void) {
	for (size_t j = 0; j < MAX_SHOTS ; j++)
	{
		if (_shots[j] && _shots[j]->getCoordo()->gety() <= 0)
		{
			delete _shots[j];
			_shots[j] = NULL;
		}
	}
}

void		CurrentGame::checkEnemies(unsigned int time) {
	for (size_t i = 0; i < MAX_ENEMY ; i++)
	{
		if (_enemies[i])
		{
			if (_enemies[i]->getHP() == 0)
			{
				if (_enemies[i]->getTimeOfDeath() != time)
				{
					_score += 1254;
					delete _enemies[i];
					_enemies[i] = NULL;
				}
			}
			else if (*_player->getCoordo() == *_enemies[i]->getCoordo())
			{
				_score -= 500;
				delete _enemies[i];
				_enemies[i] = NULL;
				_player->takeDamage(1, time);
			}
			else if (_enemies[i]->getCoordo()->gety() > MAX_Y)
			{
				delete _enemies[i];
				_enemies[i] = NULL;
				_score -= 100;
			}
			else
				this->checkShots(_enemies[i], time);
		}
	}
}

AEnemy*		CurrentGame::spawnCapitalism(void) {
	return new Capitalism(_enemyNb);
}

AEnemy*		CurrentGame::spawnPatriarchy(void) {
	return new Patriarchy(_enemyNb);
}

AEnemy*		CurrentGame::spawnWorldHunger(void) {
	return new WorldHunger(_enemyNb);
}

void		CurrentGame::spawnEnemies(unsigned int duration) {
	typedef AEnemy* (CurrentGame::*spawnRandEnemy)(void);
	spawnRandEnemy spawn[3] = 
	{
		&CurrentGame::spawnCapitalism,
		&CurrentGame::spawnPatriarchy,
		&CurrentGame::spawnWorldHunger
	};
	if (_prevSpawn != duration && duration % _enemySpawn[_level - 1] == 0)
	{
		_prevSpawn = duration;
		for (size_t i = 0 ; i < MAX_ENEMY ; i++)
		{
			if (_enemies[i] == NULL)
			{
				AEnemy* newEnemy;
				int rand = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
				.time_since_epoch())
				.count();
				rand = rand < 0 ? rand * -1 : rand;
				newEnemy = (this->*spawn[rand % 3])();
				_enemies[i] = newEnemy;
				_enemyNb++;
				return;
			}
		}
	}
}

void		CurrentGame::spawnShot(void) {
	for (size_t i = 0 ; i < MAX_SHOTS ; i++)
	{
		if (_shots[i] == NULL)
		{
			Coordo* pos = new Coordo(_player->getCoordo()->getx(), MAX_Y, 0);
			Shot* shot = new Shot(pos);
			_shots[i] = shot;
			return;
		}
	}
}

void			CurrentGame::updateLevel(void) {
	if (_level != DIFFICULTY_LEVELS && _score > (_level * PROGRESSION_SPEED))
	{
		_player->hpUp(1);
		_level++;
	}
}

bool		CurrentGame::update(void) {

    unsigned int duration;

	duration = ( std::clock() - _start ) / (double) (CLOCKS_PER_SEC / 10);
	this->updateLevel();
	this->checkPlayer();
	this->checkEnemies(duration);
	this->checkShots();

	if (_player->getHP() == 0) {
		_timeOfEnd = duration;
		return false;
	}
	this->spawnEnemies(duration);

	Command com = this->_map->update(_player, _enemies, _shots, duration, _score, _player->getHP());

	if (com == Shoot)
		this->spawnShot();
	else
		_player->update(com, duration);

	for (size_t i = 0; i < MAX_ENEMY ; i++)
	{
		if (_enemies[i])
			_enemies[i]->update(duration);
	}

	for (size_t i = 0; i < MAX_SHOTS ; i++)
	{
		if (_shots[i])
			_shots[i]->update(duration);
	}
	_curr++;
	return true;
}

bool		CurrentGame::endScreen(void)
{
    Command c = _map->endScreen(_score, _timeOfEnd);
	return c == Restart;
}

unsigned int CurrentGame::_enemySpawn[] = { 30, 20, 10, 5, 4, 3, 2, 1 };