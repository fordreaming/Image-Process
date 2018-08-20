#include "imghistgram.h"
#include "Histogram1D.hpp"

ImgHistGram::ImgHistGram(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.actionHistgram_Equlization, SIGNAL(triggered()), this, SLOT(ImgHistgramPro()));
}

ImgHistGram::~ImgHistGram()
{

}

void ImgHistGram::ImgHistgramPro()
{
	Histogram1D hist;
	Mat histImg;
	Mat image = imread("test.png");
	histImg = hist.getHistogramImage(image);

	imshow("Image", image);
	imshow("Histogram", histImg);
}