#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <string>
#include<QString>
//using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
struct itemPrice {
  std::string itemName;
    int itemPrice;
};
std::vector <itemPrice> v;
int total=0;

MainWindow::~MainWindow()
{
    delete ui;
}

//Navigation

void MainWindow::on_ViewCart_clicked()
{

    std::string str;
    ui->stackedWidget->setCurrentIndex(3);
    for(int i =0 ; i<v.size();i++){
        str=v[i].itemName + "\t\t" + std:: to_string(v[i].itemPrice) ;

    ui->CART->addItem(str.c_str());
    total+=v[i].itemPrice;
    str= std::to_string(total);
    }
ui->TotalPrice->setText(str.c_str());
}


void MainWindow::on_BackToSelection_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Pay_clicked()
{   std::string str=std::to_string(total);
    ui->PricePay->setText(str.c_str());
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Confirm_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_New_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//adding Items to cart

void MainWindow::on_pushButton_2_clicked()
{
 itemPrice ip;
 ip.itemName ="coke";
 ip.itemPrice=2;
 v.push_back(ip);

}


void MainWindow::on_pushButton_4_clicked()
{
    itemPrice ip;
    ip.itemName ="fanta";
    ip.itemPrice=3;
    v.push_back(ip);
}


void MainWindow::on_pushButton_3_clicked()
{
    itemPrice ip;
    ip.itemName ="Pepsi";
    ip.itemPrice=2;
    v.push_back(ip);
}


void MainWindow::on_pushButton_clicked()
{
    itemPrice ip;
    ip.itemName ="Sprite";
    ip.itemPrice=2;
    v.push_back(ip);
}

