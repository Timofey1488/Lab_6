#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::printTree() {
    ui->bt_list->clear();
    while(!tree.mas.isEmpty()) {
        Node<User*> *node = tree.mas.dequeue();
        User *user = node->data;
        QListWidgetItem *item = new QListWidgetItem();
        QString itemText = "";
        itemText.append(user->getName());
        itemText.append("  ");
        itemText.append(QString::number(user->getNumber()));
        item->setText(itemText);
        ui->bt_list->addItem(item);
    }
}

void MainWindow::pushToTreeWidget(Node<User*> *node, QTreeWidgetItem *item) {
    if(node != nullptr) {
        QTreeWidgetItem *newItem;
        if(item == nullptr) {
            newItem = new QTreeWidgetItem(ui->tree_widget);
            newItem->setText(0, QString::number(node->data->getNumber()));
            newItem->setText(1, node->data->getName());
            ui->tree_widget->addTopLevelItem(newItem);
        }
        else {
            newItem = new QTreeWidgetItem();
            newItem->setText(0, QString::number(node->data->getNumber()));
            newItem->setText(1, node->data->getName());
            item->addChild(newItem);
        }
        pushToTreeWidget(node->left, newItem);
        pushToTreeWidget(node->right, newItem);
    }
}

void MainWindow::on_init_btn_clicked()
{
    if(startArrAdded)
        return;
    ui->listWidget->clear();
    UsersList.append(new User("Jack Richer", 3));
    UsersList.append(new User("Martin Scorcesa", 7));
    UsersList.append(new User("Ilon Mask", 9));
    UsersList.append(new User("Leonardo De Caprio", 6));
    UsersList.append(new User("James Roberts", 10));
    UsersList.append(new User("Andrew Tarkovsky", 8));
    UsersList.append(new User("Garry Gansler", 1));
    UsersList.append(new User("Robert De Niro", 4));
    for(int i = 0; i < UsersList.length(); i++) {
        QListWidgetItem *item = new QListWidgetItem();
        QString itemText = "";
        itemText.append(UsersList[i]->getName());
        itemText.append("  ");
        itemText.append(QString::number(UsersList[i]->getNumber()));
        item->setText(itemText);
        ui->listWidget->addItem(item);
    }
    startArrAdded = true;
}

void MainWindow::on_push_to_bt_btn_clicked()
{
    if(tree.length()) {
        return;
    }
    for(int i = 0; i < UsersList.length(); i++) {
        tree.Add(UsersList[i], UsersList[i]->getNumber(), tree.getRoot());
    }
    startArrAdded = true;
    ui->direct_btn->click();

    ui->tree_widget->setColumnCount(2);
    QStringList headerLabels;
    headerLabels << "Numbers" << "Names";
    ui->tree_widget->setHeaderLabels(headerLabels);
    pushToTreeWidget(tree.getRoot());
}

void MainWindow::on_direct_btn_clicked()
{
    if(!tree.length())
        return;
    tree.DirectNLR(tree.getRoot());
    this->printTree();
}

void MainWindow::on_inorder_btn_clicked()
{
    if(!tree.length())
        return;
    tree.InOrderLNR(tree.getRoot());
    this->printTree();
}

void MainWindow::on_reverse_btn_clicked()
{
    if(!tree.length())
        return;
    tree.ReverseLRN(tree.getRoot());
    this->printTree();
}

void MainWindow::on_find_btn_clicked()
{
    if(!ui->lineEdit->text().toLong()) {
        return;
    }
    tree.searchByKey(ui->lineEdit->text().toLong(), tree.getRoot());
    printTree();
}

void MainWindow::on_delete_btn_clicked()
{
    long int key = ui->lineEdit->text().toLong();
    if(!tree.length())
        return;
    tree.DirectNLR(tree.getRoot());
    tree.preBalance();
    tree.Delete(key);
    ui->tree_widget->clear();
    pushToTreeWidget(tree.getRoot());
}

void MainWindow::on_add_to_tree_btn_clicked()
{
    if(!ui->name_edit->text().count())
        return;
    if(!ui->number_edit->text().toLong())
        return;
    long int key = ui->number_edit->text().toLong();
    tree.mas.clear();
    tree.searchByKey(key, tree.getRoot());
    if(!tree.mas.isEmpty())
        return;
    tree.mas.clear();
    User *user = new User(ui->name_edit->text(), key);
    tree.Add(user, ui->number_edit->text().toLong(), tree.getRoot());
    ui->tree_widget->clear();
    pushToTreeWidget(tree.getRoot());
}

void MainWindow::on_balance_btn_clicked()
{
    if(!tree.length())
        return;
    tree.InOrderLNR(tree.getRoot());
    tree.preBalance();
    tree.balance(0, tree.mas.length()-1);
    tree.mas.clear();
    ui->tree_widget->clear();
    pushToTreeWidget(tree.getRoot());
}

void MainWindow::on_lists_count_btn_clicked()
{
    if(!tree.length())
        return;
    QList<int> listsCount = tree.countLists();
    QString listsCountStr = "";
    for(int i = 0; i < listsCount.length(); i++) {
        if(i>tree.Levels())
            break;
        listsCountStr.append(QString::number(i+1)+"L = ");
        listsCountStr.append(QString::number(listsCount[i]));
        listsCountStr.append(" ; ");
    }
    ui->label_7->setText(listsCountStr);
}
