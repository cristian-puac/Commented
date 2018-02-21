#pragma once
#ifndef FLIP_HORIZONTALLY_EFFECT_H
#define FLIP_HORIZONTALLY_EFFECT_H
#include "Pixel.h"
#include "ImageEffect.h"

// this image effect will horizontally flip the image to mirror the
// original ppm document
class FlipHorizontallyImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			// this for loop is cut in half since we will only need the first half
			// of the pixels. 
			for (int j = 0; j < doc.getWidth()/2; j++)
			{
				// this variable receives the column of pixel
				// from the last column and works its way towards
				// the middle
				int column_num = doc.getWidth() - j - 1;
				//this holds the current pixel from the front columns of a row
				Pixel& p = doc.getPixel(i, j);
				//this is a temporary pixel holding the pixels from
				// the end columns of a row
				Pixel& temp = doc.getPixel(i, column_num);
				//swaps pixels in order to flip the image
				swap(p, temp);
			}

			
		}
	}
};

#endif