#pragma once
#ifndef NEGATE_RED_EFFECT_H
#define NEGATE_RED_EFFECT_H
#include "ImageEffect.h"

// this image effect will negate all red from an image
class NegateRedImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				// subtract 255 by current red pixel and set
				// the difference as the new red pixel
				Pixel *p = &doc.getPixel(i, j);
				//int RedPixel = p->getRed();
				p->setRed(255 - p->getRed());
			}
		}
	}
};

#endif 