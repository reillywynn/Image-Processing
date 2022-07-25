#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Image.h"

using namespace std;

void GetDataFromFile(string filepath, vector <Header>& Headers, vector <Pixel>& Pixels, vector <Image>& Images) {
	ifstream inFile(filepath, ios_base::binary);

	if (inFile.is_open()) {
		
		char idLength;
		inFile.read((char*)&idLength, sizeof(idLength));

		char colorMapType;
		inFile.read((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode;
		inFile.read((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin;
		inFile.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength;
		inFile.read((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth;
		inFile.read((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin;
		inFile.read((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin;
		inFile.read((char*)&yOrigin, sizeof(yOrigin));

		short width;
		inFile.read((char*)&width, sizeof(width));

		short height;
		inFile.read((char*)&height, sizeof(height));

		char bitsPerPixel;
		inFile.read((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor;
		inFile.read((char*)&imageDescriptor, sizeof(imageDescriptor));

		Header h(idLength, colorMapType, dataTypeCode, colorMapOrigin, colorMapLength, colorMapDepth, xOrigin, yOrigin, width, height, bitsPerPixel, imageDescriptor);
		Headers.push_back(h);
		
		int pixels = h.GetPixels();

		for (int i = 0; i < pixels; i++) {
			unsigned char blue;
			inFile.read((char*)&blue, sizeof(blue));
			unsigned char green;
			inFile.read((char*)&green, sizeof(green));
			unsigned char red;
			inFile.read((char*)&red, sizeof(red));
			Pixel p(blue, green, red);
			Pixels.push_back(p);
			
		}
		Image o(h, Pixels);
		Images.push_back(o);
	}
	inFile.close();
	//if (!inFile.is_open()) {
		//cout << "boo" << endl;
	//}
}

void WriteDataToFile(vector <Header>& Headers, vector <Pixel>& Pixels) {
	ofstream tgaFile("copyCar.tga", ios_base::binary);
	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}
	for (unsigned int i = 0; i < Pixels.size(); i++) {
		unsigned char blue = Pixels[i].GetBlue();
		tgaFile.write((char*)&blue, sizeof(blue));

		unsigned char green = Pixels[i].GetGreen();
		tgaFile.write((char*)&green, sizeof(green));

		unsigned char red = Pixels[i].GetRed();
		tgaFile.write((char*)&red, sizeof(red));
	}
}

void Multiply(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}

	int j = 0;
	for (unsigned int i = Pixels.size()/2; i < Pixels.size(); i++) {
		
		float temp;
		temp = ((((float)Pixels[j].GetBlue() * (float)Pixels[i].GetBlue()) / 255) + 0.5f);
		if (temp > 255) {
			temp = 255;
		}
		if (temp < 0) {
			temp = 0;
		}
		unsigned char blue = temp;
		tgaFile.write((char*)&blue, sizeof(blue));

		temp = ((((float)Pixels[j].GetGreen() * (float)Pixels[i].GetGreen()) / 255) + 0.5f);
		if (temp > 255) {
			temp = 255;
		}
		if (temp < 0) {
			temp = 0;
		}
		unsigned char green = temp;
		tgaFile.write((char*)&green, sizeof(green));

		temp = (((float)Pixels[j].GetRed() * (float)Pixels[i].GetRed()) / 255 + 0.5f);
		if (temp > 255) {
			temp = 255;
		}
		if (temp < 0) {
			temp = 0;
		}
		unsigned char red = temp;
		tgaFile.write((char*)&red, sizeof(red));
		
		j++;
	}

}

void Subtract(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}
	int j = 0;
	
	for (unsigned int i = Pixels.size() / 2; i < Pixels.size(); i++) {
		unsigned char blue;
		if (Pixels[j].GetBlue() > Pixels[i].GetBlue()) {
			blue = 0;
		}
		else {
			blue = Pixels[i].GetBlue() - Pixels[j].GetBlue();
		}
		tgaFile.write((char*)&blue, sizeof(blue));

		unsigned char green;
		if (Pixels[j].GetGreen() > Pixels[i].GetGreen()) {
			green = 0;
		}
		else {
			green = Pixels[i].GetGreen() - Pixels[j].GetGreen();
		}
		tgaFile.write((char*)&green, sizeof(green));

		unsigned char red;
		if (Pixels[j].GetRed() > Pixels[i].GetRed()) {
			red = 0;
		}
		else {
			red = Pixels[i].GetRed() - Pixels[j].GetRed();
		}
		tgaFile.write((char*)&red, sizeof(red));
		j++;
	}
}

void MultScreen(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}

	int j = 0;

	for (int i = Pixels.size() / 2; i < Pixels.size(); i++) {
		
		float temp;
		temp = ((255 - (255 - (float)Pixels[j].GetBlue()) * (255 - (float)Pixels[i].GetBlue()) / 255) + 0.5f);
		if (temp > 255) {
			temp = 255;
		}
		if (temp < 0) {
			temp = 0;
		}
		unsigned char blue = temp;
		
		tgaFile.write((char*)&blue, sizeof(blue));

		temp = ((255 - (255 - (float)Pixels[j].GetGreen()) * (255 - (float)Pixels[i].GetGreen()) / 255) + 0.5f);
		if (temp > 255) {
			temp = 255;
		}
		if (temp < 0) {
			temp = 0;
		}
		unsigned char green = temp;
		
		tgaFile.write((char*)&green, sizeof(green));

		temp = ((255 - (255 - (float)Pixels[j].GetRed()) * (255 - (float)Pixels[i].GetRed()) / 255) + 0.5f);
		if (temp > 255) {
			temp = 255;
		}
		if (temp < 0) {
			temp = 0;
		}
		unsigned char red = temp;
		
		tgaFile.write((char*)&red, sizeof(red));

		j++;
	}
}

void Overlay(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}

	int j = 0;

	for (unsigned int i = Pixels.size() / 2; i < Pixels.size(); i++) {
		float temp;
		temp = (float)Pixels[i].GetBlue() / 255;
		if (temp <= 0.5) {
			temp = 2 * ((float)Pixels[i].GetBlue() * (float)Pixels[j].GetBlue() / 255) + 0.5f;
			if (temp > 255) {
				temp = 255;
			}
			if (temp < 0) {
				temp = 0;
			}
		}
		else {
			temp = (255 - 2 * ((255 - (float)Pixels[i].GetBlue()) * (255 - (float)Pixels[j].GetBlue()) / (255)) + 0.5f);
			if (temp > 255) {
				temp = 255;
			}
			if (temp < 0) {
				temp = 0;
			}
		}
		unsigned char blue = temp;
		tgaFile.write((char*)&blue, sizeof(blue));

		temp = (float)Pixels[i].GetGreen() / 255;
		if (temp <= 0.5) {
			temp = 2 * ((float)Pixels[i].GetGreen() * (float)Pixels[j].GetGreen() / 255) + 0.5f;
			if (temp > 255) {
				temp = 255;
			}
			if (temp < 0) {
				temp = 0;
			}
		}
		else {
			temp = (255 - 2 * ((255 - (float)Pixels[i].GetGreen()) * (255 - (float)Pixels[j].GetGreen()) / (255)) + 0.5f);
			if (temp > 255) {
				temp = 255;
			}
			if (temp < 0) {
				temp = 0;
			}
		}
		unsigned char green = temp;
		tgaFile.write((char*)&green, sizeof(blue));

		temp = (float)Pixels[i].GetRed() / 255;
		if (temp <= 0.5) {
			temp = 2 * ((float)Pixels[i].GetRed() * (float)Pixels[j].GetRed() / 255) + 0.5f;
			if (temp > 255) {
				temp = 255;
			}
			if (temp < 0) {
				temp = 0;
			}
		}
		else {
			temp = (255 - 2 * ((255 - (float)Pixels[i].GetRed()) * (255 - (float)Pixels[j].GetRed()) / (255)) + 0.5f);
			if (temp > 255) {
				temp = 255;
			}
			if (temp < 0) {
				temp = 0;
			}
		}
		unsigned char red = temp;
		tgaFile.write((char*)&red, sizeof(red));






		j++;
	}
}

void Add(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}

	
	for (int i = 0; i < Pixels.size(); i++) {
		int temp;

		unsigned char blue = Pixels[i].GetBlue();
		tgaFile.write((char*)&blue, sizeof(blue));

		temp = Pixels[i].GetGreen() + 200;
		if (temp > 255) {
			temp = 255;
		}
		unsigned char green = temp;

		tgaFile.write((char*)&green, sizeof(green));

		unsigned char red = Pixels[i].GetRed();
		tgaFile.write((char*)&red, sizeof(red));
	}
}

void Scale(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}

	for (unsigned int i = 0; i < Pixels.size(); i++) {
		float temp;
		unsigned char blue = 0;
		tgaFile.write((char*)&blue, sizeof(blue));

		unsigned char green = Pixels[i].GetGreen();
		tgaFile.write((char*)&green, sizeof(green));

		temp = Pixels[i].GetRed() * 4;
		if (temp > 255) {
			temp = 255;
		}
		unsigned char red = temp;
		tgaFile.write((char*)&red, sizeof(red));
	}
}

void Seperate(char color, string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}
	for (int i = 0; i < Pixels.size(); i++) {
		if (color == 'r') {
			unsigned char blue = Pixels[i].GetRed();
			tgaFile.write((char*)&blue, sizeof(blue));

			unsigned char green = Pixels[i].GetRed();
			tgaFile.write((char*)&green, sizeof(green));

			unsigned char red = Pixels[i].GetRed();
			tgaFile.write((char*)&red, sizeof(red));

		}

		if (color == 'g') {
			unsigned char blue = Pixels[i].GetGreen();
			tgaFile.write((char*)&blue, sizeof(blue));

			unsigned char green = Pixels[i].GetGreen();
			tgaFile.write((char*)&green, sizeof(green));

			unsigned char red = Pixels[i].GetGreen();
			tgaFile.write((char*)&red, sizeof(red));
		}

		if (color == 'b') {
			unsigned char blue = Pixels[i].GetBlue();
			tgaFile.write((char*)&blue, sizeof(blue));

			unsigned char green = Pixels[i].GetBlue();
			tgaFile.write((char*)&green, sizeof(green));

			unsigned char red = Pixels[i].GetBlue();
			tgaFile.write((char*)&red, sizeof(red));
		}
	}
}

void Combine(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}

	int j = 0;
	int h = Pixels.size() / 3;
	//cout << j << " " << h << " " << Pixels.size() << endl;
	
	for (int i = (Pixels.size() / 3) * 2; i < Pixels.size(); i++) {
		unsigned char blue = Pixels[j].GetBlue();
		tgaFile.write((char*)&blue, sizeof(blue));

		unsigned char green = Pixels[h].GetGreen();
		tgaFile.write((char*)&green, sizeof(green));

		unsigned char red = Pixels[i].GetRed();
		tgaFile.write((char*)&red, sizeof(red));

		j++;
		h++;
	}
}

void Rotate(string filepath, vector <Header>& Headers, vector < Pixel>& Pixels) {
	ofstream tgaFile(filepath, ios_base::binary);

	for (unsigned int i = 0; i < 1; i++) {
		char idLength = Headers[i].GetIdLength();
		tgaFile.write((char*)&idLength, sizeof(idLength));

		char colorMapType = Headers[i].GetColorMapType();
		tgaFile.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = Headers[i].GetDataTypeCode();
		tgaFile.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = Headers[i].GetColorMapOrigin();
		tgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = Headers[i].GetColorMapLength();
		tgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = Headers[i].GetColorMapDepth();
		tgaFile.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = Headers[i].GetXOrigin();
		tgaFile.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = Headers[i].GetYOrigin();
		tgaFile.write((char*)&yOrigin, sizeof(yOrigin));

		short width = Headers[i].GetWidth();
		tgaFile.write((char*)&width, sizeof(width));

		short height = Headers[i].GetHeight();
		tgaFile.write((char*)&height, sizeof(height));

		char bitsPerPixel = Headers[i].GetBitsPerPixel();
		tgaFile.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = Headers[i].GetImageDescriptor();
		tgaFile.write((char*)&imageDescriptor, sizeof(imageDescriptor));
	}
	
	for (unsigned int i = 0; i < Pixels.size(); i++) {
		unsigned char blue = Pixels[Pixels.size() - 1 - i].GetBlue();
		tgaFile.write((char*)&blue, sizeof(blue));

		unsigned char green = Pixels[Pixels.size() - 1 - i].GetGreen();
		tgaFile.write((char*)&green, sizeof(green));

		unsigned char red = Pixels[Pixels.size() - 1 - i].GetRed();
		tgaFile.write((char*)&red, sizeof(red));
	}
}

bool Test(vector < Pixel>& Pixels) {
	int j = 0;
	for (unsigned int i = Pixels.size()/2; i < Pixels.size(); i++) {
		if (Pixels[i].GetBlue() != Pixels[j].GetBlue()) {
			return false;
		}
		if (Pixels[i].GetGreen() != Pixels[j].GetGreen()) {
			return false;
		}
		if (Pixels[i].GetRed() != Pixels[j].GetRed()) {
			return false;
		}
		j++;
	}

	return true;
}

void Test2(vector < Pixel>& Pixels) {
	int j = 0;
	for (unsigned int i = Pixels.size() / 2; i < Pixels.size(); i++) {
		cout << "blue " << +Pixels[j].GetBlue() << " " << +Pixels[i].GetBlue() << endl;
		cout << "green " << +Pixels[j].GetGreen() << " " << +Pixels[i].GetGreen() << endl;
		cout << "red " << +Pixels[j].GetRed() << " " << +Pixels[i].GetRed() << endl;
		cout << endl;
		j++;
	}
}


int main() {
	string filepath = "input/layer1.tga";
	string filepath2 = "input/pattern1.tga";
	string filepathLayer = "input/layer2.tga";
	string filepathCar = "input/car.tga";
	string filepathPattern2 = "input/pattern2.tga";
	string filepathtext1 = "input/text.tga";
	string filepathCircles = "input/circles.tga";
	string filepathText2 = "input/text2.tga";
	string filepathlb = "input/layer_blue.tga";
	string filepathlg = "input/layer_green.tga";
	string filepathlr = "input/layer_red.tga";
	string test1 = "examples/EXAMPLE_part1.tga";
	string test2 = "examples/EXAMPLE_part2.tga";
	string test3 = "examples/EXAMPLE_part3.tga";
	string test4 = "examples/EXAMPLE_part4.tga";
	string test5 = "examples/EXAMPLE_part5.tga";
	string test6 = "examples/EXAMPLE_part6.tga";
	string test7 = "examples/EXAMPLE_part7.tga";
	string test8g = "examples/EXAMPLE_part8_g.tga";
	string test8r = "examples/EXAMPLE_part8_r.tga";
	string test8b = "examples/EXAMPLE_part8_b.tga";
	string test9 = "examples/EXAMPLE_part9.tga";
	string test10 = "examples/EXAMPLE_part10.tga";

	vector <Header> Headers;
	vector <Pixel> Pixels;
	vector <Image> Images;
	vector <Pixel> TempPixels;
	
	int option1 = 1;
	int option2 = 2;
	int option3 = 3;
	int option4 = 4;
	int option5 = 5;
	int option6 = 6;
	int option7 = 7;
	int option8 = 8;
	int option9 = 9;
	int option10 = 10;
	
	if (option1 == 1) {
		GetDataFromFile(filepath, Headers, Pixels, Images);
		GetDataFromFile(filepath2, Headers, Pixels, Images);
		Multiply("output/part1.tga", Headers, Pixels);

		Pixels.clear();
	}
	
	
	// task 2
	if (option2 == 2) {
		GetDataFromFile(filepathLayer, Headers, Pixels, Images);
		GetDataFromFile(filepathCar, Headers, Pixels, Images);
		Subtract("output/part2.tga", Headers, Pixels);

		Pixels.clear();
	}
	// task 3
	if (option3 == 3) {
		GetDataFromFile(filepath, Headers, Pixels, Images);
		GetDataFromFile(filepathPattern2, Headers, Pixels, Images);
		Multiply("Temp.tga", Headers, Pixels);

		Pixels.clear();
		string Temp1 = "Temp.tga";
		GetDataFromFile(Temp1, Headers, Pixels, Images);
		GetDataFromFile(filepathtext1, Headers, Pixels, Images);
		WriteDataToFile(Headers, Pixels);
		remove("copyCar.tga");
		MultScreen("output/part3.tga", Headers, Pixels);
		remove("Temp.tga");

		Pixels.clear();
	}
	// task 4
	if (option4 == 4) {
		GetDataFromFile(filepathLayer, Headers, Pixels, Images);
		GetDataFromFile(filepathCircles, Headers, Pixels, Images);
		Multiply("tempMultiply.tga", Headers, Pixels);

		Pixels.clear();
		string Temp2 = "tempMultiply.tga";
		GetDataFromFile(filepathPattern2, Headers, Pixels, Images);
		GetDataFromFile(Temp2, Headers, Pixels, Images);
		Subtract("output/part4.tga", Headers, Pixels);
		remove("tempMultiply.tga");

		Pixels.clear();
	}
	

	// task 5
	if (option5 == 5) {
		GetDataFromFile(filepath, Headers, Pixels, Images);
		GetDataFromFile(filepath2, Headers, Pixels, Images);
		Overlay("output/part5.tga", Headers, Pixels);

		Pixels.clear();
	}

	// task 6
	if (option6 == 6) {
		GetDataFromFile(filepathCar, Headers, Pixels, Images);
		Add("output/part6.tga", Headers, Pixels);
		Pixels.clear();
	}
		

	// task 7
	if (option7 == 7) {

		GetDataFromFile(filepathCar, Headers, Pixels, Images);
		Scale("output/part7.tga", Headers, Pixels);

		Pixels.clear();
	}

	// task 8
	if (option8 == 8) {
		GetDataFromFile(filepathCar, Headers, Pixels, Images);
		Seperate('r', "output/part8_r.tga", Headers, Pixels);
		Seperate('g', "output/part8_g.tga", Headers, Pixels);
		Seperate('b', "output/part8_b.tga", Headers, Pixels);

		Pixels.clear();
	}
	
	// task 9
	if (option9 == 9) {
		Pixels.clear();
		Headers.clear();
		GetDataFromFile(filepathlb, Headers, Pixels, Images);
		GetDataFromFile(filepathlg, Headers, Pixels, Images);
		GetDataFromFile(filepathlr, Headers, Pixels, Images);
		Combine("output/part9.tga", Headers, Pixels);

		Pixels.clear();
	}
		// task 10
	if (option10 == 10) {
		Pixels.clear();
		Headers.clear();
		GetDataFromFile(filepathText2, Headers, Pixels, Images);
		Rotate("output/part10.tga", Headers, Pixels);

		Pixels.clear();
	}
		

	






	return 0;
}