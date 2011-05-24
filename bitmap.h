/* The MIT License

Copyright (c) 2011 Sahab Yazdani

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef BITMAP_H
#define BITMAP_H

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>

#include <string>

#include "picopng.h"

class Bitmap {
public:
	Bitmap( std::string &filename );
	~Bitmap();

	double getIntensity( unsigned int x, unsigned int y );
	unsigned char getDiscreteIntensity( unsigned int x, unsigned int y );

	void getColour( unsigned int x, unsigned int y, unsigned char &r, unsigned char &g, unsigned char &b );

	unsigned int getWidth();
	unsigned int getHeight();

	unsigned int getGLWidth();
	unsigned int getGLHeight();

	GLuint createGLTexture();
private:
	PNG::PNGFile *file;
	unsigned int glWidth, glHeight;
	GLuint glTex;
};

#endif // BITMAP_H