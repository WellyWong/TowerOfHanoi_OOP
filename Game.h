#pragma once

#include <vector>
#include "Stack.h"
#include "HSLAPixel.h"

//move cubes from stacks_[0] to stacks_[2]
class Game
{
private:
	std::vector<Stack> stacks_;

	void _move(unsigned index1, unsigned index2);
	void _legalMove(unsigned index1, unsigned index2);

public:
	Game() {
		for (int i = 0; i < 4; ++i)
		{
			Stack stackOfCubes;
			stacks_.push_back(stackOfCubes);
		}
		// Create the four cubes, placing each on the [0]th stack:
		// - A blue cube of length=4, on the bottom
		// - A orange cube of length=3
		// - A purple cube of length=2
		// - A yellow cube of length=1 at the very top
		Cube four(4, HSLAPixel::BLUE);
		stacks_[0].push_back(four);

		Cube three(3, HSLAPixel::ORANGE);
		stacks_[0].push_back(three);

		Cube two(2, HSLAPixel::PURPLE);
		stacks_[0].push_back(two);

		Cube one(1, HSLAPixel::YELLOW);
		stacks_[0].push_back(one);
	}

	friend std::ostream& operator<<(std::ostream& os, const Game& game)
	{
		for (int i = 0; i < 3; ++i)
		{
			os << "Stack [" << i << "]: " << game.stacks_[i];
		}
		return os;
	}

	void solve();
	void solve2();
	void Towers(int n, unsigned indexFr, unsigned indexTo, unsigned indexSpare);
};

void Game::_move(unsigned index1, unsigned index2)
{
	Cube cube = stacks_[index1].removeTop();
	stacks_[index2].push_back(cube);
	std::cout << *this << std::endl;
}

void Game::_legalMove(unsigned index1, unsigned index2)
{
	if (stacks_[index1].size() == 0 && stacks_[index2].size() > 0)
	{
		_move(index2, index1);
	}
	else if (stacks_[index1].size() > 0 && stacks_[index2].size() == 0)
	{
		_move(index1, index2);
	}
	else if (stacks_[index1].size() > 0 && stacks_[index2].size() > 0)
	{
		if (stacks_[index1].peekTop().getLength() < stacks_[index2].peekTop().getLength())
		{
			_move(index1, index2);
		}
		else
		{
			_move(index2, index1);
		}
	}
	std::cout << *this << std::endl;
}

//solve the game iteratively
void Game::solve()
{
	while (stacks_[1].size() != 4)
	{
		//move cubes from stacks_[0] to stacks_[2]
		/*_legalMove(0, 1);
		_legalMove(0, 2);
		_legalMove(1, 2);*/
		//move cubes from stacks_[0] to stacks_[1]
		_legalMove(0, 2);
		_legalMove(0, 1);
		_legalMove(2, 1);
	}
}

//solve the game recursively
void Game::solve2()
{
	Towers(4, 0, 1, 2);

}

void Game::Towers(int n, unsigned indexFr, unsigned indexTo, unsigned indexSpare)
{
	if (n == 1)
	{
		_move(indexFr, indexTo);
		return;
	}

	Towers(n - 1, indexFr, indexSpare, indexTo);
	Towers(1, indexFr, indexTo, indexSpare);
	Towers(n - 1, indexSpare, indexTo, indexFr);
}
