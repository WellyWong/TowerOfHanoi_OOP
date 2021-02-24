#pragma once
#include "HSLAPixel.h"

class Cube
{
private:
	double length_;
	HSLAPixel color_;
public:
	Cube(double length, HSLAPixel color): length_(length), color_(color) {}
	double getLength() const { return length_; }
	void setLength(double l) { length_ = l; }

	double getVolume() const { return length_ * length_ * length_; }
	double getSurfaceArea() const { return 6 * length_ * length_; }

};
