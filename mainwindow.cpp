#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <vector>
#include <QComboBox>
#include <QMessageBox>
#include <QPlainTextEdit>
#include "Int_Set.h"
#include "String_Set.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setGeometry(60,30, 120, 30);
    ui->comboBox->addItem("Choose Set");
    ui->comboBox->addItem("Integer");
    ui->comboBox->addItem("String");

    //Text under LineEdits
    QLabel * to_set1 = new QLabel("TO SET1", this);
    to_set1->move(200, 0);

    QLabel * to_set2 = new QLabel("TO SET2", this);
    to_set2->move(350, 0);

    //LineEdits
    QLineEdit *set1 = new QLineEdit(this);
    set1->move(200, 30);

    QLineEdit *set2 = new QLineEdit(this);
    set2->move(350, 30);

    //Buttons
    QPushButton *add_butt = new QPushButton(this);
    add_butt->move(200, 100);
    add_butt->setText("Add");

    QPushButton *union_butt = new QPushButton(this);
    union_butt->move(60, 100);
    union_butt->setText("Union");

    QPushButton *intersect_butt = new QPushButton(this);
    intersect_butt->move(60, 150);
    intersect_butt->setText("Intersect");

    QPushButton *sim_sub = new QPushButton(this);
    sim_sub->move(60, 200);
    sim_sub->setText("Sim Sub");

    QPushButton *clear_set1 = new QPushButton(this);
    clear_set1->move(505, 545);
    clear_set1->setText("Clear");

    QPushButton *clear_set2 = new QPushButton(this);
    clear_set2->move(665, 545);
    clear_set2->setText("Clear");

    QPushButton *clear_result = new QPushButton(this);
    clear_result->move(835, 545);
    clear_result->setText("Clear");

    //outputs
     QLabel * output_set1 = new QLabel(this);
     output_set1->setGeometry(10,300, 500, 40);
     QLabel * output_set2 = new QLabel(this);
     output_set2->setGeometry(10,400, 500, 40);
     QLabel * output_result = new QLabel(this);
     output_result->setGeometry(10,500, 500, 40);


     QLabel * text_set1_res = new QLabel("SET 1", this);
     text_set1_res->move(535, 0);
     QPlainTextEdit* set1_line = new QPlainTextEdit(this);
     set1_line->setReadOnly(true);
     set1_line->setGeometry(500,30, 110, 500);

     QLabel * text_set2_res = new QLabel("SET 2", this);
     text_set2_res->move(695, 0);
     QPlainTextEdit* set2_line = new QPlainTextEdit(this);
     set2_line->setReadOnly(true);
     set2_line->setGeometry(660,30, 110, 500);

     QLabel * text_result_res = new QLabel("RESULT", this);
     text_result_res->move(855, 0);
     QPlainTextEdit* result_line = new QPlainTextEdit(this);
     result_line->setReadOnly(true);
     result_line->setGeometry(830,30, 110, 500);

     QString *set1_result = new QString("");
     QString *set2_result = new QString("");
     QString *final_result = new QString("");


     // тут векторы
     std::vector<int> *first_set = new std::vector<int>();
     std::vector<int> *second_set = new std::vector<int>();

     std::vector<std::string> *first_sset = new std::vector<std::string>();
     std::vector<std::string> *second_sset = new std::vector<std::string>();


    connect(add_butt, &QPushButton::clicked, [=](){
        if(ui->comboBox->currentText() == "Choose the Set"){
            QMessageBox::warning(this,"Error!","Please, choose the set");
        } else {
        int tmp;
        std::string tmp_s;
        bool flag = false;
        if(set1->text() != ""){
        if(ui->comboBox->currentText() == "Integer"){
        tmp = set1->text().toInt();
        if(tmp == 0) QMessageBox::warning(this,"Error!","Please, choose another set");
        else{
        for (size_t var = 0; var < first_set->size(); ++var) {
            if(tmp==first_set->at(var))
                flag = true;
        }
        if(!flag){
        *set1_result += set1->text() + "\n";
        first_set->push_back(tmp);
        set1_line->setPlainText(*set1_result);
        }
        }
        }
        else if(ui->comboBox->currentText() == "String") {
            tmp_s = set1->text().toStdString();
            for (size_t var = 0; var < first_sset->size(); ++var) {
                if(tmp_s==first_sset->at(var))
                    flag = true;
            }
            if(!flag){
            *set1_result += set1->text() + "\n";
            first_sset->push_back(tmp_s);
            set1_line->setPlainText(*set1_result);
            }
        }
        }
        if(set2->text() != ""){
        if(ui->comboBox->currentText() == "Integer"){
        tmp = set2->text().toInt();
        if(tmp == 0) QMessageBox::warning(this,"Error!","Please, choose another set");
        else {
            flag = false;
        for (size_t var = 0; var < second_set->size(); ++var) {
            if(tmp==second_set->at(var))
                flag = true;
        }
        if(!flag){
        *set2_result += set2->text() + "\n";
        second_set->push_back(tmp);
        set2_line->setPlainText(*set2_result);
        }
        }
        }
        else if(ui->comboBox->currentText() == "String") {
            tmp_s = set2->text().toStdString();
            for (size_t var = 0; var < second_sset->size(); ++var) {
                if(tmp_s==second_sset->at(var))
                    flag = true;
            }
            if(!flag){
            *set2_result += set2->text() + "\n";
            second_sset->push_back(tmp_s);
            set2_line->setPlainText(*set2_result);
            }
        }
        }
        }
    });

    connect(union_butt, &QPushButton::clicked, [=](){
        if(ui->comboBox->currentText() == "Choose the Set"){
            QMessageBox::warning(this,"Error!","Please, choose another set");
        } else {
        if(ui->comboBox->currentText() == "Integer") {
        *final_result = "";
        Int_Set s1(*first_set);
        Int_Set s2(*second_set);
        if(!(s1.IsEmpty())&&!(s2.IsEmpty())){
        Int_Set s3;
        s3 = s1.add(s2);
        for (int i = 0;i<s3.getSize(); ++i) {
            *final_result+=QString::number(s3[i]) + "\n";
        }
                }
        result_line->setPlainText(*final_result);
        } else
        if(ui->comboBox->currentText() == "String") {
        *final_result = "";
        String_Set s1(*first_sset);
        String_Set s2(*second_sset);
        if(!(s1.IsEmpty())&&!(s2.IsEmpty())){
        String_Set s3;
        s3 = s1.add(s2);
        for (int i = 0;i<s3.getSize(); ++i) {
            *final_result+=QString::fromStdString(s3[i]) + "\n";
        }
                }
        result_line->setPlainText(*final_result);
        }
        }
    });
    connect(intersect_butt, &QPushButton::clicked, [=](){
        if(ui->comboBox->currentText() == "Choose the Set"){
            QMessageBox::warning(this,"Error!","Please, choose another set");
        } else {
        if(ui->comboBox->currentText() == "Integer") {
        *final_result = "";
        Int_Set s1(*first_set);
        Int_Set s2(*second_set);
        if(!(s1.IsEmpty())&&!(s2.IsEmpty())){
        Int_Set s3;
        s3 = s1.mult(s2);
        for (int i = 0;i<s3.getSize(); ++i) {
            *final_result+=QString::number(s3[i]) + "\n";
        }}
        result_line->setPlainText(*final_result);
        } else
        if(ui->comboBox->currentText() == "String") {
        *final_result = "";
        String_Set s1(*first_sset);
        String_Set s2(*second_sset);
        if(!(s1.IsEmpty())&&!(s2.IsEmpty())){
        String_Set s3;
        s3 = s1.mult(s2);
        for (int i = 0;i<s3.getSize(); ++i) {
            *final_result+=QString::fromStdString(s3[i]) + "\n";
        }
                }
        result_line->setPlainText(*final_result);
        }
        }
    });
    connect(sim_sub, &QPushButton::clicked, [=](){
        if(ui->comboBox->currentText() == "Choose the Set"){
            QMessageBox::warning(this,"Error!","Please, choose another set");
        } else {
        if(ui->comboBox->currentText() == "Integer") {
        *final_result = "";
        Int_Set s1(*first_set);
        Int_Set s2(*second_set);
        if(!(s1.IsEmpty())&&!(s2.IsEmpty())){
        Int_Set s3;
        s3 = s1.sim_sub(s2);
        for (int i = 0;i<s3.getSize(); ++i) {
            *final_result+=QString::number(s3[i]) + "\n";
        }}
        result_line->setPlainText(*final_result);
        }
        else
        if(ui->comboBox->currentText() == "String") {
        *final_result = "";
        String_Set s1(*first_sset);
        String_Set s2(*second_sset);
        if(!(s1.IsEmpty())&&!(s2.IsEmpty())){
        String_Set s3;
        s3 = s1.sim_sub(s2);
        for (int i = 0;i<s3.getSize(); ++i) {
            *final_result+=QString::fromStdString(s3[i]) + "\n";
        }
                }
        result_line->setPlainText(*final_result);
        }
        }
    });

    connect(clear_set1, &QPushButton::clicked, [=](){
        *set1_result = "";
        first_set->clear();
        set1_line->setPlainText("");
    });

    connect(clear_set2, &QPushButton::clicked, [=](){
        *set2_result = "";
        second_set->clear();
        set2_line->setPlainText("");
    });

    connect(clear_result, &QPushButton::clicked, [=](){
        *final_result = "";
        result_line->setPlainText(*final_result);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

