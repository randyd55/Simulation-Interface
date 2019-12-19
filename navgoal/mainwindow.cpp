#include "mainwindow.h"
#include "addrobotwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <iostream>
#include <QFileDialog>
#include <stdio.h>
#include <fstream>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    //display(this)
{
    ui->setupUi(this);
    QPushButton *addRobot = new QPushButton("Add Robot");
    connect(addRobot, SIGNAL(clicked()), this, SLOT(displayAddRobot()));

    QPushButton *worldFile = new QPushButton("Add Gazebo world file");
    connect(worldFile, SIGNAL(clicked()), this, SLOT(addWorldFile()));
    QPushButton *occMap = new QPushButton("Add Occupancy Map");
    connect(occMap, SIGNAL(clicked()), this, SLOT(addOccupancyMap()));

    QComboBox *tbModel = new QComboBox(this);
    tbModel->addItem("Select Turtlebot Model");
    tbModel->addItem("Waffle");
    tbModel->addItem("Burger");
    connect(tbModel, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectTBModel(QString)));

    QPushButton *FinishAddingRobots = new QPushButton("Submit parameters");
    connect(FinishAddingRobots, SIGNAL(clicked()), this, SLOT(outputTextFile()));

    QPushButton *runSimulation = new QPushButton("Run Turtlebot Simulation");
    connect(runSimulation, SIGNAL(clicked()), this, SLOT(runSimulation()));

    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *buttons = new QWidget(this);
    layout->addWidget(addRobot);
    layout->addWidget(worldFile);
    layout->addWidget(occMap);
    layout->addWidget(tbModel);
    layout->addWidget(FinishAddingRobots);
    layout->addWidget(runSimulation);
    buttons->setLayout(layout);
    QHBoxLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(buttons);
    display = new QWidget(this);
    QVBoxLayout *layout2 = new QVBoxLayout;
    display->setLayout(layout2);
    centralLayout->addWidget(display);
    centralWidget()->setLayout(centralLayout);
}

void MainWindow::displayAddRobot(){
    std::cout << "add robot" << std::endl;
    AddRobotWindow *r= new AddRobotWindow(this);
    r->show();
}

void MainWindow::addRobot(float x, float y, float z, float xO, float yO, float zO, float wO){
    Robot r = Robot(x, y, z, xO, yO, zO, wO);
    robots.push_back(r);
    std::string robot = "Robot " + std::to_string(robots.size()) +":\nPosition: " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
    std::string orientation = "\nOrientation: " + std::to_string(xO) + " " + std::to_string(yO) + " " + std::to_string(zO) +
                              " " + std::to_string(wO);
    robot += orientation;
    QLabel *t = new QLabel(QString::fromStdString(robot));
    display->layout()->addWidget(t);

}

void MainWindow::addWorldFile(){
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Select World File"), "",
            tr("World File (*.world);;All Files (*)"));
    world_file = fileName.toUtf8().toStdString();
}

void MainWindow::addOccupancyMap(){
    QString dir = QFileDialog::getOpenFileName(this,
            tr("Select Occupancy Grid"), "",
            tr("Occupancy Grid File (*.yaml);;All Files (*)"));
    occupancy_file = dir.toUtf8().toStdString();
}

void MainWindow::selectTBModel(QString curr){
    tb_model = curr.toStdString();
    //convert to lower because c++ doesn't have built in string tolower...
    std::transform(tb_model.begin(), tb_model.end(), tb_model.begin(),
        [](unsigned char c){ return std::tolower(c); });

}

void MainWindow::outputTextFile(){
    std::ofstream file;
    file.open("parameters.txt");
    file << world_file << std::endl;
    file << occupancy_file << std::endl;
    file << tb_model << std::endl;
    file << robots.size() << std::endl;
    for(int i = 0; i < robots.size(); i++){
        Robot r = robots[i];
        file << r.xPos << " " << r.yPos << " " << r.zPos << " " <<  r.xOrient << " " <<
                r.yOrient << " " << r.zOrient << " " << r.wOrient << std::endl;
    }
}

void MainWindow::runSimulation(){
    char cwdArr[PATH_MAX];
    getcwd(cwdArr, sizeof(cwdArr));
    strcat(cwdArr,"/src/run.bash");
    //qDebug(cwdArr);
    std::system(cwdArr);
}

MainWindow::~MainWindow()
{
    delete ui;
}
