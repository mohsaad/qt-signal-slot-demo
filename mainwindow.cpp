#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    count_(0)
{
    ui->setupUi(this);

    // UI to code signals.
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(add(bool)));
    connect(ui->subtractButton, SIGNAL(clicked(bool)), this, SLOT(subtract(bool)));

    // Code to code signals/slots.
    // This connects the increment signal to the updateComment slot, so whenever we emit
    // increment, we will call updateComment.
    connect(this, SIGNAL(increment(int)), this, SLOT(updateComment(int)));
}

void MainWindow::add(bool) {
    count_++;
    updateWindow();

    emit increment(1);
}

void MainWindow::subtract(bool) {
    count_--;
    updateWindow();

    emit increment(-1);
}

void MainWindow::updateComment(int status) {
    if (status > 0) {
        ui->commentLabel->setText("Added 1!");
    } else if (status < 0) {
        ui->commentLabel->setText("Subtracted 1!");
    }
}

void MainWindow::updateWindow() {
    ui->countLabel->setText(QString::fromStdString(std::to_string(count_)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
