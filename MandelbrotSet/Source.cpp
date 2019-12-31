#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

float width = 600;
float height = 600;

void createImage();

void createImage()
{
	ofstream fout;
	fout.open("mandelbrot.ppm");
	if (fout.is_open())
	{
		cout << "File is opened!" << endl;
		fout << "P3" << endl << width << " " << height << endl << 255 << endl;
		for (size_t i = 0; i < width; i++)
		{
			for (size_t j = 0; j < height; j++)
			{
				if (i == 0 && j < 100)
				{
					fout << "255 0 0" << endl;
				}
				else
				{
					fout << "0 100 255" << endl;
				}
			}
		}

	}
	else
	{
		cout << "Could not open the file!" << endl;
	}
}

int main()
{
	createImage();

	return 0;
}