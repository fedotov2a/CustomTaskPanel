#ifndef PANEL_H
#define PANEL_H

#include <QFrame>

namespace Ui
{
class Panel;
}

class Panel : public QFrame
{
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = 0);
    ~Panel();

private:
    Ui::Panel *ui;
};

#endif // PANEL_H
