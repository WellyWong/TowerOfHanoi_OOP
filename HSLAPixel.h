#pragma once

class HSLAPixel
{
public:
	double h, s, l, a=1.0;

	HSLAPixel(): h(0), s(0), l(1.0), a(1.0) {}
	HSLAPixel(double hue, double saturation, double luminance) : h(hue), s(saturation), l(luminance) {}
	HSLAPixel(double hue, double saturation, double luminance, double alpha): h(hue), s(saturation), l(luminance), a(alpha) {}

	static HSLAPixel BLUE;
	static HSLAPixel ORANGE;
	static HSLAPixel YELLOW;
	static HSLAPixel PURPLE;
};


HSLAPixel HSLAPixel::BLUE = HSLAPixel(240, 1, 0.5);
HSLAPixel HSLAPixel::ORANGE = HSLAPixel(30, 1, 0.5);
HSLAPixel HSLAPixel::YELLOW = HSLAPixel(60, 1, 0.5);
HSLAPixel HSLAPixel::PURPLE = HSLAPixel(270, 1, 0.5);
