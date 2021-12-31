#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputPushButton_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Input Image", QDir::currentPath(), "Images (*.jpg *.png *.bmp)");
    if(QFile::exists(fileName))
    {
        ui->inputLineEdit->setText(fileName);
    }
}

void MainWindow::on_outputPushButton_pressed()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Select Output Image", QDir::currentPath(), "*.jpg;;*.png;;*.bmp");
    if(!fileName.isEmpty())
    {
        ui->outputLineEdit->setText(fileName);
        using namespace cv;
        using namespace std;
        Mat inpImg, outImg, out_gray;
        int ddepth = CV_16S;
        int ksize = 1;
        int scale = 1;
        int delta = 0;
        Mat gauss;
        QImage qimage;
        inpImg = imread(ui->inputLineEdit->text().toStdString());

        if(ui->Sobel->isChecked())
        {
            cv::GaussianBlur(inpImg, gauss, Size(5, 5), 1.25);
             // Convert the image to grayscale
            cv::cvtColor(gauss, out_gray, COLOR_BGR2GRAY);
            Mat grad_x, grad_y;
            Mat abs_grad_x, abs_grad_y;
            Sobel(out_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);
            Sobel(out_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);
            // converting back to CV_8U
            convertScaleAbs(grad_x, abs_grad_x);
            convertScaleAbs(grad_y, abs_grad_y);
            addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, outImg);
            qimage = QImage(outImg.data, outImg.cols, outImg.rows, QImage::Format_Grayscale8);
            cout<<"hey ayoub"<<outImg.data;

        }
        else if(ui->medianBlurRadioButton->isChecked())
        {
            cv::medianBlur(inpImg, outImg, 5);
            qimage = QImage(outImg.data, outImg.cols, outImg.rows, QImage::Format_RGB888).rgbSwapped();

        }

        else if(ui->gaussianBlurRadioButton->isChecked())
        {
            cv::GaussianBlur(inpImg, outImg, Size(5, 5), 1.25);
            qimage = QImage(outImg.data, outImg.cols, outImg.rows, QImage::Format_RGB888).rgbSwapped();

        }
        imwrite(fileName.toStdString(), outImg);
        ui->Image->setPixmap(QPixmap::fromImage(qimage.scaled(400,400)));
        //imshow("Output Image", outImg);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::warning(this, "Exit", "Are you sure you want to close this program?", QMessageBox::Yes, QMessageBox::No);
    if(result == QMessageBox::Yes)
    {
        saveSettings();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::loadSettings()
{
    QSettings settings("Packt", "Hello_OpenCV_Qt", this);
    ui->inputLineEdit->setText(settings.value("inputLineEdit", "").toString());
    ui->outputLineEdit->setText(settings.value("outputLineEdit", "").toString());
    ui->medianBlurRadioButton->setChecked(settings.value("medianBlurRadioButton", true).toBool());
    ui->gaussianBlurRadioButton->setChecked(settings.value("gaussianBlurRadioButton", false).toBool());
    //ui->displayImageCheckBox->setChecked(settings.value("displayImageCheckBox", false).toBool());
}

void MainWindow::saveSettings()
{
    QSettings settings("Packt", "Hello_OpenCV_Qt", this);
    settings.setValue("inputLineEdit", ui->inputLineEdit->text());
    settings.setValue("outputLineEdit", ui->outputLineEdit->text());
    settings.setValue("medianBlurRadioButton", ui->medianBlurRadioButton->isChecked());
    settings.setValue("gaussianBlurRadioButton", ui->gaussianBlurRadioButton->isChecked());
    //settings.setValue("displayImageCheckBox", ui->displayImageCheckBox->isChecked());
}
