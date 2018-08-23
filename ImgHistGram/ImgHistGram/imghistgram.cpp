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
	QString StrWidth, StrHeigth;

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
		QImage* scaledImg = new QImage;//�洢���ź��ͼ��
		if(!( img->load(fileName) ) ) //����ͼ��
		{
			QMessageBox::information(this,
				tr("��ͼ��ʧ��"),
				tr("��ͼ��ʧ��!"));
			delete img;
			return;
		}
		

		ui.imgLabel->resize(img->width(), img->height());

		ui.label_text->setText(QString("width: ") + StrWidth.setNum(img->width())
			+ QString("\nheight: ") + StrHeigth.setNum(img->height()));
		ui.imgLabel->setPixmap(QPixmap::fromImage(*img));

		
		//int imgWidth = img->width();
		//int imgHeight = img->height();
		////���ź��ͼƬ��С
		//int scaleImgWidth;
		//int scaleImgHeight;

		//ui.imgLabel->setGeometry(0,0,400,300);
		//int Mul;            //��¼ͼƬ��label��С�ı�������������ͼƬ
		//if(imgWidth/400 >= imgHeight/300)
		//	Mul = imgWidth/400;
		//else
		//	Mul = imgHeight/300;
		//scaleImgWidth = imgWidth/Mul;
		//scaleImgHeight = imgHeight/Mul;
		//*scaledImg = img->scaled(scaleImgWidth, scaleImgHeight , Qt::KeepAspectRatio);
		//ui.imgLabel->setText(QString("width: ") + StrWidth.setNum(scaleImgWidth)
		//	+ QString("\nheight: ") + StrHeigth.setNum(scaleImgHeight));
		//ui.imgLabel->setPixmap(QPixmap::fromImage(*scaledImg));
	}
	//�޸�label�Ĵ�С
	
	 

	//Mat image = imread(str);
	//histImg = hist.getHistogramImage(image);

	//imshow("Image", image);
	//imshow("Histogram", histImg);
}