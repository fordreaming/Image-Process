#include "imghistgram.h"
#include "Histogram1D.hpp"
#include <QFileDialog>
#include <QString>

static vector<unsigned short> g_imgData;
static int imgRows;
static int imgCols;

ImgHistGram::ImgHistGram(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.actionHistgram_Equlization, SIGNAL(triggered()), this, SLOT(ImgHistgramPro()));
}

ImgHistGram::~ImgHistGram()
{

}

bool ImgHistGram::ReadImg()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
		tr("."),
		tr("Images(*.tif *.jpg *.png)"));
	if (!fileName.isEmpty())
	{
		//加载图像数据
		CImageData::Load16TifToGray16(fileName, g_imgData, imgRows, imgCols);
	}
	return true;
}

void ImgHistGram::ImgHistgramPro()
{
	Histogram1D hist;
	Mat histImg;
	//通过文件对话框打开图像

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
		tr("."),
		tr("Images(*.tif *.jpg *.png)"));
	std::string str = fileName.toStdString();

	Mat image = imread(str);
	histImg = hist.getHistogramImage(image);

	imshow("Image", image);
	imshow("Histogram", histImg);
}