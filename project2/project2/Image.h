#pragma once
#include <string>
#include <vector>
using namespace std;

struct Pixel {
	unsigned char _blue;
	unsigned char _green;
	unsigned char _red;

public:
	Pixel(unsigned char blue, unsigned char green, unsigned char red);
	unsigned char GetBlue();
	unsigned char GetGreen();
	unsigned char GetRed();
	
};

struct Header
{
	char _idLength;
	char _colorMapType;
	char _dataTypeCode;
	short _colorMapOrigin;
	short _colorMapLength;
	char _colorMapDepth;
	short _xOrigin;
	short _yOrigin;
	short _width;
	short _height;
	char _bitsPerPixel;
	char _imageDescriptor;
	
public:
	Header();
	Header(char idLength, char colorMapType, char dataTypeCode, short colorMapOrigin, short colorMapLength, char colorMapDepth, short xOrigin, short yOrigin, short width, short height, char bitsPerPixel, char imageDescriptor);
	short GetWidth();
	short GetHeight();
	int GetPixels();
	char GetIdLength();
	char GetColorMapType();
	char GetDataTypeCode();
	short GetColorMapOrigin();
	short GetColorMapLength();
	char GetColorMapDepth();
	short GetXOrigin();
	short GetYOrigin();
	char GetBitsPerPixel();
	char GetImageDescriptor();
};

class Image {
	vector <Pixel> _pixels;
	Header _header;

public:
	Image(Header header, vector <Pixel> pixels);
	vector <Pixel> GetPixels();
};







