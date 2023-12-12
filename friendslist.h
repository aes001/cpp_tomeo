#ifndef FRIENDSLIST_H
#define FRIENDSLIST_H

#include <QWidget>
#include "constants.h"

namespace Ui {
class FriendsList;
}

class FriendsList : public QWidget
{
    Q_OBJECT

public:
    explicit FriendsList(QWidget *parent = nullptr);
    ~FriendsList();

private:
    Ui::FriendsList *ui;

signals:
    void backButtonClicked();

private slots:
    void on_backButton_clicked();
};

#endif // FRIENDSLIST_H
