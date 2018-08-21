#ifndef IMGHISTGRAM_H
#define IMGHISTGRAM_H

#include <QtGui/QMainWindow>
#include "ui_imghistgram.h"
#include "img_data.hpp"
#include <QMessageBox>



class ImgHistGram : public QMainWindow
{
	Q_OBJECT

public:
	ImgHistGram(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ImgHistGram();

	private slots:
		void ImgHistgramPro();

private:
	Ui::ImgHistGramClass ui;
};

#endif // IMGHISTGRAM_H
