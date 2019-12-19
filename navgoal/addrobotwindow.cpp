#include "addrobotwindow.h"
#include "mainwindow.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <iostream>
AddRobotWindow::AddRobotWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlag(Qt::Window);
    this->setFixedSize(500, 500);
    this->xPos = new QLineEdit();
    this->xPos->setPlaceholderText("Enter x coordinate value");
    this->yPos = new QLineEdit();
    this->yPos->setPlaceholderText("Enter y coordinate value");
    this->zPos = new QLineEdit();
    this->zPos->setPlaceholderText("Enter z coordinate value");
    this->xOrient = new QLineEdit();
    this->xOrient->setPlaceholderText("Enter x orientation value");
    this->yOrient = new QLineEdit();
    this->yOrient->setPlaceholderText("Enter y orientation value");
    this->zOrient = new QLineEdit();
    this->zOrient->setPlaceholderText("Enter z orientation value");
    this->wOrient = new QLineEdit();
    this->wOrient->setPlaceholderText("Enter w orientation value");
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *submitButton = new QPushButton("Add Robot");
    connect(submitButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    layout->addWidget(this->xPos);
    layout->addWidget(this->yPos);
    layout->addWidget(this->zPos);
    layout->addWidget(this->xOrient);
    layout->addWidget(this->yOrient);
    layout->addWidget(this->zOrient);
    layout->addWidget(this->wOrient);
    layout->addWidget(submitButton);
    this->setLayout(layout);
}

void AddRobotWindow::sendMessage(){
    //char *xx = this->xPos->text().toUtf8();
    float x = std::stof(this->xPos->text().toUtf8().toStdString());
    float y = std::stof(this->yPos->text().toUtf8().toStdString());
    float z = std::stof(this->zPos->text().toUtf8().toStdString());
    float xO = std::stof(this->xOrient->text().toUtf8().toStdString());
    float yO = std::stof(this->yOrient->text().toUtf8().toStdString());
    float zO = std::stof(this->zOrient->text().toUtf8().toStdString());
    float wO = std::stof(this->wOrient->text().toUtf8().toStdString());
    ((MainWindow *)this->parent())->addRobot(x, y, z, xO, yO, zO, wO);
    this->close();
}
