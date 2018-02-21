#pragma once
#ifndef HIGH_CONTRAST_EFFECT_H
#define HIGH_CONTRAST_EFFECT_H
#include "ImageEffect.h"

// this image effect will perform a high contrast by either maxing out
// the pixel to 255 if the color is greater than half of 255, and setting 
// other pixel values to zero
class HighContrastImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel *p = &doc.getPixel(i, j);

				// store pixels within variables
				double RedPixel = p->getRed();
				double GreenPixel = p->getGreen();
				double BluePixel = p->getBlue();

				// store the result for half of 255 into
				// a variable
				double limit_pix = 255 / 2;

				// compare the red pixel to half of 255 and 
				// if it is over limit_pix, set to 255 and if 
				// it is under limit_pix, set to 0
				if (RedPixel > limit_pix)
				{
					p->setRed(255);
				}
				else
				{
					p->setRed(0);
				}

				// does same output as RedPixel if statements, but is applied
				// to GreenPixel
				if (GreenPixel > limit_pix)
				{
					p->setGreen(255);
				}
				else
				{
					p->setGreen(0);
				}

				// does the same as the if statements for RedPixel and
				// GreenPixle, but is applied to BluePixel
				if (BluePixel > limit_pix)
				{
					p->setBlue(255);
				}
				else
				{
					p->setBlue(0);
				}

			}
		}
	}
};

#endif