#pragma once
#ifndef REMOVE_GREEN_EFFECT_H
#define REMOVE_GREEN_EFFECT_H

//this image effect will remove all green from a picture
class RemoveGreenImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				//set the current green pixel to 0
				// to remove all green from the image
				Pixel *p = &doc.getPixel(i, j);
				p->setGreen(0);
			}
		}
	}
};

#endif // !REMOVE_GREEN_EFFECT_H

#include "ImageEffect.h"

