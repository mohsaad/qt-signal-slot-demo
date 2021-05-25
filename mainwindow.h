#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    // Tell our compiler that this is a QT program.
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

// Declare our QT slots. Whenever a signal that is connected to this slot is
// emitted, we will call these functions.
public Q_SLOTS:
    void add(bool);
    void subtract(bool);
    void updateComment(int status);

// Create a dummy signal that updates the comment whenever we change the value
// of our counter.
signals:
    // Update the coment in our QT widget.
    void increment(int status);


private:
    Ui::MainWindow *ui;

    // Update the counter in our QT widget.
    void updateWindow();

    // Actual counter.
    int count_;
};

#endif // MAINWINDOW_H
