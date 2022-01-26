#include <QMainWindow>
#include <QImageReader>
#include <QLabel>
#include <QMouseEvent>

class ImageViewer : public QMainWindow
{
	Q_OBJECT

public:
	ImageViewer(QWidget *parent = nullptr);

protected:
	void mousePressEvent(QMouseEvent *event) override;

private:
	QImage image;
	QLabel *imageLabel;
	QLabel *text;
	double scaleFactor = 1.0;
};

