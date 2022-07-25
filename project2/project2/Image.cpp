#include "Image.h"
#include <iostream>

Pixel::Pixel(unsigned char blue, unsigned char green, unsigned char red){
	_blue = blue;
	_green = green;
	_red = red;
}

unsigned char Pixel::GetBlue() {
	return _blue;
}
unsigned char Pixel::GetGreen() {
	return _green;
}
unsigned char Pixel::GetRed() {
	return _red;
}


Header::Header(char idLength, char colorMapType, char dataTypeCode, short colorMapOrigin, short colorMapLength, char colorMapDepth, short xOrigin, short yOrigin, short width, short height, char bitsPerPixel, char imageDescriptor) {
	_idLength = idLength;
	_colorMapType = colorMapType;
	_dataTypeCode = dataTypeCode;
	_colorMapOrigin = colorMapOrigin;
	_colorMapLength = colorMapLength;
	_colorMapDepth = colorMapDepth;
	_xOrigin = xOrigin;
	_yOrigin = yOrigin;
	_width = width;
	_height = height;
	_bitsPerPixel = bitsPerPixel;
	_imageDescriptor = imageDescriptor;
}
Header::Header() {
	_idLength = 0;
	_colorMapType = 0;
	_dataTypeCode = 0;
	_colorMapOrigin = 0;
	_colorMapLength = 0;
	_colorMapDepth = 0;
	_xOrigin = 0;
	_yOrigin = 0;
	_width = 0;
	_height = 0;
	_bitsPerPixel = 0;
	_imageDescriptor = 0;
}

short Header::GetHeight(){
	return _height;
}
short Header::GetWidth() {
	return _width;
}
int Header::GetPixels(){
	int pixels = _width * _height;
	return pixels;
}

char Header::GetIdLength() {
	return _idLength;
}
char Header::GetColorMapType() {
	return _colorMapType;
}
char Header::GetDataTypeCode() {
	return _dataTypeCode;
}
short Header::GetColorMapOrigin() {
	return _colorMapOrigin;
}
short Header::GetColorMapLength() {
	return _colorMapLength;
}
char Header::GetColorMapDepth() {
	return _colorMapDepth;
}
short Header::GetXOrigin() {
	return _xOrigin;
}
short Header::GetYOrigin() {
	return _yOrigin;
}
char Header::GetBitsPerPixel() {
	return _bitsPerPixel;
}
char Header::GetImageDescriptor() {
	return _imageDescriptor;
}


Image::Image(Header header, vector <Pixel> pixels ) {
	_pixels = pixels;
	_header = header;
}

vector <Pixel> Image::GetPixels() {
	return _pixels;
}