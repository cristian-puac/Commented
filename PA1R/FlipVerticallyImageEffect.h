#pragma once
#ifndef FLIP_VERTICALLY_EFFECT_H
#define FLIP_VERTICALLY_EFFECT_H
#include "Pixel.h"
#include "ImageEffect.h"

// this image effect will vertically flip the image to mirror the
// original ppm document
class FlipVerticallyImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		//only first half of pixel rows will be used within
		// the outside for loop
		for (int i = 0; i < doc.getHeight() / 2; i++)
		{
			//traverse through the pixel row to mainputlate
			// the pixels
			for (int j = 0; j < doc.getWidth(); j++)
			{
				//receives the rows at end and works its
				// way towards the middle 
				int column_num = doc.getHeight() - i - 1;
				//pixel that hold the pixels from the start of the 
				// ppm document 
				Pixel& p = doc.getPixel(i, j);
				// temporary pixel that holds pixels from the bottom
				// rows of the ppm document
				Pixel& temp = doc.getPixel(column_num, j);
				// pixels are swapped to make the image flip
				// vertically
				swap(p, temp);
			}

		}
	}
};

#endif