#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "people_ai.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::on_pushButton_people_ai_clicked() {
    PeopleAi* people_ai = new PeopleAi();
    people_ai->show();
}
