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


void ImgHistGram::ImgHistgramPro()
{
	Histogram1D hist;
	Mat histImg;
	//ͨ���ļ��Ի����ͼ��

	QString fileName = QFileDialog::getOpenFileName(this, tr("Select Image"),
		tr("."),
		tr("Images(*.tif *.jpg *.png)"));
	std::string str;
	if (fileName.isEmpty())
	{
		return;
	}
	else
	{
		str = fileName.toStdString();
		QImage* img = new QImage;
		if(!( img->load(fileName) ) ) //����ͼ��
		{
			QMessageBox::information(this,
				tr("��ͼ��ʧ��"),
				tr("��ͼ��ʧ��!"));
			delete img;
			return;
		}
		ui.imgLabel->setPixmap(QPixmap::fromImage(*img));
	}
	 

	//Mat image = imread(str);
	//histImg = hist.getHistogramImage(image);

	//imshow("Image", image);
	//imshow("Histogram", histImg);
}