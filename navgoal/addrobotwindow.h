#ifndef ADDROBOTWINDOW_H
#define ADDROBOTWINDOW_H

#include <QWidget>
#include <QLineEdit>
class AddRobotWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AddRobotWindow(QWidget *parent = nullptr);
private:
    QLineEdit *xPos;
    QLineEdit *yPos;
    QLineEdit *zPos;
    QLineEdit *xOrient;
    QLineEdit *yOrient;
    QLineEdit *zOrient;
    QLineEdit *wOrient;
signals:

public slots:
    void sendMessage();
};

#endif // ADDROBOTWINDOW_H
