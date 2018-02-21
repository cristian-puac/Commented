#pragma once
#ifndef GRAYSCALE_EFFECT_H
#define GRAYSCALE_EFFECT_H
#include "ImageEffect.h"

// this image effect will perform a high contrast by either maxing out
// the pixel to 255 if the color is greater than half of 255, and setting 
// other pixel values to zero
class GrayscaleImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				// create pixel variable 
				Pixel *p = &doc.getPixel(i, j);

				// variable that will hold the Red, Blue, and Green
				// pixel individually
				int RedPixel = p->getRed();
				int GreenPixel = p->getGreen();
				int BluePixel = p->getBlue();

				// add up all of the pixels and then find the average 
				int pixel_total = RedPixel + GreenPixel + BluePixel;
				int pixel_average = pixel_total / 3;

				// set the average of the pixels as the new value for Red, Green, and
				// and Blue
				p->setRed(pixel_average);
				p->setGreen(pixel_average);
				p->setBlue(pixel_average);
			}
		}
	}
};

#endif