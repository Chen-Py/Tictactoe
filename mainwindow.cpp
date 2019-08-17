#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

jing_game game;
AI CPY;
bool xian=0,alr=0;

void MainWindow::AI_do(int at)
{
    if(!alr)
    {
        CPY.get_qipu();
        alr=1;
    }
    if(!xian)at=CPY.roll(at);
    int x=CPY.x[at];
    int y=CPY.y[at];
    if(x==0|y==0)return;
    game.modify(x,y);
    if(x==1&&y==1&&xian==1)ui->pushButton->setStyleSheet("QPushButton{background:blue}");
    if(x==1&&y==2&&xian==1)ui->pushButton_2->setStyleSheet("QPushButton{background:blue}");
    if(x==1&&y==3&&xian==1)ui->pushButton_3->setStyleSheet("QPushButton{background:blue}");
    if(x==2&&y==1&&xian==1)ui->pushButton_4->setStyleSheet("QPushButton{background:blue}");
    if(x==2&&y==2&&xian==1)ui->pushButton_5->setStyleSheet("QPushButton{background:blue}");
    if(x==2&&y==3&&xian==1)ui->pushButton_6->setStyleSheet("QPushButton{background:blue}");
    if(x==3&&y==1&&xian==1)ui->pushButton_7->setStyleSheet("QPushButton{background:blue}");
    if(x==3&&y==2&&xian==1)ui->pushButton_8->setStyleSheet("QPushButton{background:blue}");
    if(x==3&&y==3&&xian==1)ui->pushButton_9->setStyleSheet("QPushButton{background:blue}");
    if(x==1&&y==1&&xian==0)ui->pushButton->setStyleSheet("QPushButton{background:red}");
    if(x==1&&y==2&&xian==0)ui->pushButton_2->setStyleSheet("QPushButton{background:red}");
    if(x==1&&y==3&&xian==0)ui->pushButton_3->setStyleSheet("QPushButton{background:red}");
    if(x==2&&y==1&&xian==0)ui->pushButton_4->setStyleSheet("QPushButton{background:red}");
    if(x==2&&y==2&&xian==0)ui->pushButton_5->setStyleSheet("QPushButton{background:red}");
    if(x==2&&y==3&&xian==0)ui->pushButton_6->setStyleSheet("QPushButton{background:red}");
    if(x==3&&y==1&&xian==0)ui->pushButton_7->setStyleSheet("QPushButton{background:red}");
    if(x==3&&y==2&&xian==0)ui->pushButton_8->setStyleSheet("QPushButton{background:red}");
    if(x==3&&y==3&&xian==0)ui->pushButton_9->setStyleSheet("QPushButton{background:red}");
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    return;
}
void MainWindow::on_pushButton_clicked()
{
    if(game.map[1][1].zhan||game.winner)return;
    if(!game.turn)ui->pushButton->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton->setStyleSheet("QPushButton{background:red}");
    game.modify(1,1);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(game.map[1][2].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_2->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_2->setStyleSheet("QPushButton{background:red}");
    game.modify(1,2);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_3_clicked()
{
    if(game.map[1][3].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_3->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_3->setStyleSheet("QPushButton{background:red}");
    game.modify(1,3);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_4_clicked()
{
    if(game.map[2][1].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_4->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_4->setStyleSheet("QPushButton{background:red}");
    game.modify(2,1);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(game.map[2][2].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_5->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_5->setStyleSheet("QPushButton{background:red}");
    game.modify(2,2);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_6_clicked()
{
    if(game.map[2][3].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_6->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_6->setStyleSheet("QPushButton{background:red}");
    game.modify(2,3);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_7_clicked()
{
    if(game.map[3][1].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_7->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_7->setStyleSheet("QPushButton{background:red}");
    game.modify(3,1);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_8_clicked()
{
    if(game.map[3][2].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_8->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_8->setStyleSheet("QPushButton{background:red}");
    game.modify(3,2);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_9_clicked()
{
    if(game.map[3][3].zhan||game.winner)return;
    if(!game.turn)ui->pushButton_9->setStyleSheet("QPushButton{background:blue}");
    else ui->pushButton_9->setStyleSheet("QPushButton{background:red}");
    game.modify(3,3);
    if(game.winner==1)ui->textBrowser->textCursor().insertText("The blue player won!");
    if(game.winner==2)ui->textBrowser->textCursor().insertText("The red player won!");
    if(game.winner)return;
    AI_do(game.code);
    return;
}

void MainWindow::on_pushButton_10_clicked()
{
    xian=1;
    AI_do(game.code);


    return;
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->textBrowser->setText("");
    ui->pushButton->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_2->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_3->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_4->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_5->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_6->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_7->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_8->setStyleSheet("QPushButton{background:lightgray}");
    ui->pushButton_9->setStyleSheet("QPushButton{background:lightgray}");
    game.clear();
    xian=0;
    return;
}
