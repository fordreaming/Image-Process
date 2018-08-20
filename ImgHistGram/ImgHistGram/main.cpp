#include "imghistgram.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImgHistGram w;
	w.show();
	return a.exec();
}
