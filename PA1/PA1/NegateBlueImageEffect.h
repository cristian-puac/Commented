#pragma once
#ifndef NEGATE_BLUE_EFFECT_H
#define NEGATE_BLUE_EFFECT_H
#include "ImageEffect.h"

// this image effect will negate all blue from an image
class NegateBlueImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				// subtract 255 by current blue pixel and set
				// the difference as the new blue pixel
				Pixel *p = &doc.getPixel(i, j);
				p->setBlue(255 - p->getBlue());
			}
		}
	}
};

#endif 