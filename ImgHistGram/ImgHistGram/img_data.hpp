#ifndef img_data_h__
#define img_data_h__
#include <QString>
#include <QImage>
#include <vector>
#include <QColor>
// 
#include <highgui.h>
#include <cv.h>
#include <QFileDialog>
#include <QFile>

class CImageData
{
public:
	CImageData(){}
	~CImageData(){}
public:
	static bool LoadFile(QString file_name, QImage & img)
	{
		if (!img.load(file_name))
		{
			return false;
		}
		return true;
	}
	static bool Load16TifToGray16(QString file_name, std::vector<unsigned short> & v_gray, int &rows, int &cols)
	{
		std::string str = file_name.toStdString();

		IplImage* image;
		image = cvLoadImage(str.c_str(), CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
		if (!image)
		{
			return false;
		}
		int depth = image->depth;

		v_gray.resize(image->height*image->width);
		for (int i = 0; i < image->height; ++i)
		{
			for (int j = 0; j < image->width; ++j)
			{
				v_gray[i*image->width + j] = *(unsigned short*)(&image->imageData[i*image->widthStep + j*sizeof(unsigned short)]);
			}
		}
		rows = image->height;
		cols = image->width;

		return true;
	}
	static bool Load12TifToGray16(QString file_name, std::vector<unsigned short> & v_gray, int &rows, int &cols)
	{
		std::string str = file_name.toStdString();

		IplImage* image;
		image = cvLoadImage(str.c_str(), CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
		if (!image)
		{
			return false;
		}
		int depth = image->depth; 

		v_gray.resize(image->height*image->width);
		for (int i = 0; i < image->height;++i)
		{
			for (int j = 0; j < image->width;++j)
			{
				v_gray[i*image->width + j] = *(unsigned short*)(&image->imageData[i*image->widthStep + j*sizeof(unsigned short)]);
				v_gray[i*image->width + j] = v_gray[i*image->width + j] << 4;
			}
		}
		rows = image->height;
		cols = image->width;
		return true;
	}
	static bool LoadDatToGray16(QString file_name, std::vector<unsigned short> & v_gray, int &rows, int &cols)
	{
		QFile file(file_name);
		if (file.open(QIODevice::ReadOnly))
		{
			qint64 file_size = file.size();
			file.seek(0);
			QByteArray arr_rows = file.read(4);
			rows = *((long*)(arr_rows.begin()));
			file.seek(sizeof(int));
			QByteArray arr_cols = file.read(4);
			cols = *((long*)(arr_cols.begin()));
			if (file_size < rows*cols*sizeof(unsigned short) + 2 * (sizeof(int)))
			{
				return false;
			}
			v_gray.resize(rows*cols);
			file.seek(sizeof(int)*2);
			file.read((char*)(&v_gray[0]), rows*cols*sizeof(unsigned short));
			return true;
		}
		return false;
	}

	static bool ImageToColor(QImage & img, std::vector<QRgb> & v_color,int &rows,int &cols)
	{
		if (img.isNull())
			return false;

		//QImage rgb_img = img.convertToFormat(QImage::Format_RGBX8888); 
		rows = img.height();
		cols = img.width();
		v_color.resize(rows*cols);
		for (int i = 0; i < rows;++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				v_color[i*cols + j] = img.pixel(j, i);
			}
		}
		return true;
	}

	static bool ImageToGray8(QImage & img, std::vector<unsigned char> & v_gray, int &rows, int &cols)
	{
		if (img.isNull())
			return false;

		//QImage rgb_img = img.convertToFormat(QImage::Format_RGBX8888);
		rows = img.height();
		cols = img.width();
		v_gray.resize(rows*cols);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				v_gray[i*cols + j] = qBlue(img.pixel(j, i));
			}
		}
		return true;
	}
	static bool ImageToGray16(QImage & img, std::vector<unsigned short> & v_gray, int &rows, int &cols)
	{
		if (img.isNull())
			return false;

		//QImage rgb_img = img.convertToFormat(QImage::Format_RGBX8888);
		rows = img.height();
		cols = img.width();
		v_gray.resize(rows*cols);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				v_gray[i*cols + j] = qBlue(img.pixel(j, i))<<8;
			}
		}
		return true;
	}

	static bool ColorToGray8(std::vector<QRgb> & v_color, int &rows, int &cols,
							std::vector<unsigned char> & v_gray)
	{
		for (int i = 0; i < rows*cols; ++i)
		{
			v_gray[i] = qBlue(v_color[i]);
		}
		return true;
	}
	static bool Gray8ToColor(std::vector<unsigned char> & v_gray, int &rows, int &cols,
		std::vector<QRgb> & v_color)
	{
		for (int i = 0; i < rows*cols; ++i)
		{
			v_color[i] = qRgb(v_gray[i], v_gray[i], v_gray[i]);
		}
		return true;
	}

	static bool Gray8ToGray16(std::vector<unsigned char> & v_gray8, int &rows, int &cols,
		std::vector<unsigned short> & v_gray16)
	{
		v_gray16.resize(rows*cols);
		for (int i = 0; i < rows*cols; ++i)
		{
			v_gray16[i] = v_gray8[i]<<8;
		}
		return true;
	}
	static bool Gray16ToGray8(std::vector<unsigned short> & v_gray16, int &rows, int &cols,
		std::vector<unsigned char> & v_gray8)
	{
		v_gray8.resize(rows*cols);
		for (int i = 0; i < rows*cols; ++i)
		{
			v_gray8[i] = v_gray16[i] >> 8;
		}
		return true;
	}
	static bool ColorToImage(unsigned long * p_color, int rows, int cols, QImage & img)
	{
		img = QImage(cols, rows, QImage::Format_RGB32);

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				img.setPixel(j, i, p_color[i*cols + j]);
			}
		}
		return true;
	}
	static bool Gray8ToImage(std::vector<unsigned char> &v_gray, int rows, int cols, QImage & img)
	{
		img = QImage(cols, rows, QImage::Format_RGB32);

		int index = 0;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				img.setPixel(j, i, qRgb(v_gray[index], v_gray[index], v_gray[index]));
				++index;
			}
			
		}
		return true;
	}
	static bool Gray16ToImage(std::vector<unsigned short> &v_gray, int rows, int cols, QImage & img)
	{
		img = QImage(cols, rows, QImage::Format_RGB32);

		int index = 0;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				img.setPixel(j, i, qRgb(v_gray[index] >> 8, v_gray[index] >> 8, v_gray[index] >> 8));
				++index;
			}

		}
		return true;
	}

	static void SaveImg(unsigned char *p_img,int rows,int cols)
	{
		std::vector<unsigned char> v_img;
		v_img.resize(rows*cols);
		memcpy(&v_img[0], p_img, rows*cols);

		QImage img;
		Gray8ToImage(v_img, rows, cols, img);

		QString fileName = QFileDialog::getSaveFileName(NULL,
			("Save Image"),
			".",
			("Image Files (*.bmp)"));

		if (!fileName.isNull() && !img.isNull())
		{
			img.save(fileName);
		}
	}
	static void SaveImg(unsigned short *p_img, int rows, int cols)
	{
		QString fileName = QFileDialog::getSaveFileName(NULL,
			("Save Image"),
			".",
			("Image Files (*.tif)"));

		if (!fileName.isNull())
		{
			IplImage* image = cvCreateImage(cvSize(cols, rows), 16, 1);
			memcpy(image->imageData, p_img, image->width*image->height * sizeof(unsigned short));
			std::string str = fileName.toStdString();
			cvSaveImage(str.c_str(), image);
		}
	}

	static void LoadColorImg(unsigned short *p_img, int rows, int cols)
	{

	}

};
#endif // img_data_h__
