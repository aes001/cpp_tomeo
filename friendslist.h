#ifndef FRIENDSLIST_H
#define FRIENDSLIST_H

#include <QWidget>

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
};

#endif // FRIENDSLIST_H
