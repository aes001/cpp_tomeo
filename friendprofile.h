#ifndef FRIENDPROFILE_H
#define FRIENDPROFILE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class FriendProfile;
}
QT_END_NAMESPACE

class FriendProfile : public QMainWindow
{
    Q_OBJECT

public:
    FriendProfile(QWidget *parent = nullptr);
    ~FriendProfile();

private:
    Ui::FriendProfile *ui;
};
#endif // FRIENDPROFILE_H
