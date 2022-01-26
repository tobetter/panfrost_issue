#include <QApplication>

#include "main.h"

ImageViewer::ImageViewer(QWidget *parent)
	: QMainWindow(parent)
	  , imageLabel(new QLabel)
	  , scaleFactor(1.0)
{
	QImageReader reader("NumbersGrid.png");
	reader.setAutoTransform(true);

	image = reader.read();

	imageLabel->setScaledContents(true);
	imageLabel->setPixmap(QPixmap::fromImage(image));

	text = new QLabel(imageLabel);

	QFont font = text->font();
	font.setPointSize(40);
	font.setBold(true);

	text->move(0, 0);
	text->setFont(font);
	text->setAlignment(Qt::AlignCenter);

	setCentralWidget(imageLabel);
}

void ImageViewer::mousePressEvent(QMouseEvent *event)
{
	double current = scaleFactor;

	if (event->button() == Qt::LeftButton) {
		if (scaleFactor > 1.0)
			scaleFactor -= 1.0;
	} else if (event->button() == Qt::RightButton) {
		scaleFactor += 1.0;
	}

	if (current != scaleFactor) {
		imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

		text->setNum(scaleFactor);

		QFontMetrics metrics(text->font());
		text->setFixedWidth(metrics.width(text->text()));
		text->setFixedHeight(metrics.height());
	}
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	ImageViewer imageViewer;
	imageViewer.setWindowState(Qt::WindowFullScreen);
	imageViewer.showFullScreen();

	return app.exec();
}
