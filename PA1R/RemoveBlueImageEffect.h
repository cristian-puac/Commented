#pragma once
#ifndef REMOVE_BLUE_EFFECT_H
#define REMOVE_BLUE_EFFECT_H
#include "ImageEffect.h"

//this image effect will remove all blue from a picture
class RemoveBlueImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				//changes the current blue pixel and 
			    // sets the blue pixel to 0
				Pixel *p = &doc.getPixel(i, j);
				p->setBlue(0);
			}
		}
	}
};

#endif 