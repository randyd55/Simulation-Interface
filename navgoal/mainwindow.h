#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <vector>
#include "robot.h"
#include <QComboBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addRobot(float x, float y, float z, float xO, float yO, float zO, float wO);


private:
    Ui::MainWindow *ui;
    std::vector<Robot> robots;
    std::string world_file;
    std::string occupancy_file;
    std::string tb_model;
    QWidget *display;
    //QVBoxLayout display;


private slots:
    void displayAddRobot();
    void addWorldFile();
    void addOccupancyMap();
    void selectTBModel(QString);
    void outputTextFile();
    void runSimulation();
};

#endif // MAINWINDOW_H
