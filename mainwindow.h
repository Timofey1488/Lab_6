#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "customtree.h"
#include "customtree.cpp"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QTreeWidgetItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void pushToTreeWidget(Node<User*> *node, QTreeWidgetItem *item = nullptr);
     void printTree();

private slots:
     void on_init_btn_clicked();

     void on_push_to_bt_btn_clicked();

     void on_direct_btn_clicked();

     void on_inorder_btn_clicked();

     void on_reverse_btn_clicked();

     void on_find_btn_clicked();

     void on_delete_btn_clicked();

     void on_add_to_tree_btn_clicked();

     void on_balance_btn_clicked();

     void on_lists_count_btn_clicked();

private:
    Ui::MainWindow *ui;
    CustomTree<User*> tree;
    QList<User*> UsersList;
    bool startArrAdded = false;
};
#endif // MAINWINDOW_H
