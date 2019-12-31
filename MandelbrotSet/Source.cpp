#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

//Количество пикселей
float width = 2000;
float height = 2000;

void createImage();
int getPoint(int x, int y);


int main()
{
	createImage();

	return 0;
}

void createImage()
{
	ofstream fout;
	fout.open("mandelbrot.ppm");
	if (fout.is_open())
	{
		cout << "File is opened!" << endl;
		fout << "P3" << endl << width << " " << height << endl << 255 << endl;
		for (size_t i = 0; i < height; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				int value = getPoint(i, j);
				fout << value << " 0 0" << endl;  // Разукрашиваем текущий пиксель в цвет "value 0 0"
			}
		}
		fout.close();
	}
	else
	{
		cout << "Could not open the file!" << endl;
	}
}

int getPoint(int a, int b)
{
	float x = static_cast<float>(b);
	float y = static_cast<float>(a);
	x = (x - width / 2 - width/4)/(width/3);
	y = (height / 2 - y)/(width/3);

	//Переводим пиксель в координату точки, масштабируем плоскость

	complex<float> c (x,y);

	complex <float> z(0, 0);
	size_t iter = 0;
	while (abs(z) < 2 && iter <= 35)
	{
		z = z * z + c;
		iter++;
	}
	if (iter < 34) return iter*255/33;
	else return 0;
}