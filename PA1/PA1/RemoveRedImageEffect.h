#pragma once
#ifndef REMOVE_RED_IMAGE_EFFECT 
#define REMOVE_RED_IMAGE_EFFECT 

#include "ImageEffect.h"

//this image effect will remove all red from a picture
class RemoveRedImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
				// receives the current red pixel and set 
				// it to 0 to remove all red in the image
				Pixel *p = &doc.getPixel(i, j);
				p->setRed(0); 
            }
        }
    }

};

#endif // !REMOVE_RED_IMAGE_EFFECT 

