#pragma once
#ifndef NEGATE_GREEN_EFFECT_H
#define NEGATE_GREEN_EFFECT_H
#include "ImageEffect.h"

// this image effect will negate all green from an image
class NegateGreenImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				//subtract 255 by current green pixel and 
				// set the difference to be the new green
				// pixel value
				Pixel *p = &doc.getPixel(i, j);
				p->setGreen(255 - p->getGreen());
			}
		}
	}
};

#endif 