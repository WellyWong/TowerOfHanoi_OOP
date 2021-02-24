#pragma once

#include <vector>
#include "Cube.h"
#include <iostream>
#include <exception>

class Stack
{
private:
	std::vector<Cube> cubes_;
public:
	void push_back(const Cube& cube) {
		//Ensure that we do not push a cube on top of a smaller one
		if (size() > 0 && cube.getLength() > peekTop().getLength())
		{
			std::cerr << "A larger cube can not be placed on top of a smaller one" << std::endl;
			std::cerr << "Current stack: " << *this << std::endl;
			throw std::runtime_error("A larger cube can not be placed on top of a smaller one");
		}


		cubes_.push_back(cube);
	}

	unsigned size() const {
		return cubes_.size();
	}

	Cube removeTop() {
		Cube cubeTop = peekTop();
		cubes_.pop_back();
		return cubeTop;
	}

	Cube& peekTop() {
		return cubes_[cubes_.size() - 1];
	}

	friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
		for (unsigned i = 0; i < stack.size(); ++i)
		{
			os << stack.cubes_[i].getLength() << " ";
		}
		os << std::endl;
		return os;
	}
};
