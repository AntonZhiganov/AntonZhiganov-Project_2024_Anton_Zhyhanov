#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QMainWindow>

class WorkWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();
};

#endif
