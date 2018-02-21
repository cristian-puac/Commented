#pragma once
#ifndef RANDOM_NOISE_EFFECT_H
#define RANDOM_NOISE_EFFECT_H
#include "ImageEffect.h"
#include <cstdlib>
//#include <time.h>

// this image effect will randomly add noise to an image
class RandomNoiseImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				// stores each pixel into a variable
				Pixel* p = &doc.getPixel(i, j);
				int RedPixel = p->getRed();
				int GreenPixel = p->getGreen();
				int BluePixel = p->getBlue();

				// I receive a random number to add to 
				// the pixel between -10 to 10
				int RandomInt = (rand() % (20 + 1)) - 10;

				// I add the the random number to each pixel
				RedPixel = RedPixel + RandomInt;
				GreenPixel = GreenPixel + RandomInt;
				BluePixel = BluePixel + RandomInt;

				// Checks to see if RedPixel is over 255, to set red pixel
				// to 255 or under 0, to set red pixel to 0. Otherwise, it is left 
				// as is.
				if (RedPixel > 255)
				{
					p->setRed(255);
				}
				else if (RedPixel < 0)
				{
					p->setRed(0);					
				}
				else
				{
					p->setRed(RedPixel);
				}
			
				// Checks to see if GreenPixel is over 255, to set green pixel
				// to 255, or under 0, to set green pixel to 0. Otherwise, it is 
				// left as is.
				if (GreenPixel > 255)
				{
					p->setGreen(255);
				}
				else if (GreenPixel < 0)
				{
					p->setGreen(0);
				}
				else
				{
					p->setGreen(GreenPixel);
				}

				// Checks to see if BluePixel is over 255, to set blue pixel
				// to 255, or under 0, to set blue pixel to 0. Otherwise, it is 
				// left as is.

				if (BluePixel > 255)
				{
						p->setBlue(255);
				}
				else if(BluePixel < 0)
				{
					p->setBlue(0);
				}
				else
				{
					p->setBlue(BluePixel);
				}
			}
		}
	}
};

#endif 