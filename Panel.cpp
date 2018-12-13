#include "Panel.h"
#include "ui_Panel.h"

#include <QDesktopWidget>
#include <QX11Info>

#include <X11/Xatom.h>
#include <X11/Xlib.h>

const int LEFT = 0;
const int RIGHT = 1;
const int TOP = 2;
const int BOTTOM = 3;
const int SIZE = 4;
const int FORMAT = 32;
int reserve[SIZE] = {0};

Panel::Panel(QWidget *parent) :
    QFrame(parent, Qt::WindowStaysOnTopHint),
    ui(new Ui::Panel)
{
    ui->setupUi(this);

    int widthPanel = QApplication::desktop()->screenGeometry().width();
    int heightPanel = height();
    setGeometry(0, 0, widthPanel, heightPanel);

    Display *display = QX11Info::display();
    Window win = winId();

    reserve[TOP] = heightPanel;
    Atom atomStrut = XInternAtom(display, "_NET_WM_STRUT", False);
    XChangeProperty(display,
                    win,
                    atomStrut,
                    XA_CARDINAL,
                    FORMAT,
                    PropModePrepend,
                    (unsigned char *) &reserve,
                    SIZE);

    Atom atomWindowType = XInternAtom(display, "_NET_WM_WINDOW_TYPE", False);
    Atom atomDock = XInternAtom(display, "_NET_WM_WINDOW_TYPE_DOCK", False);
    XChangeProperty(display,
                    win,
                    atomWindowType,
                    XA_ATOM,
                    FORMAT,
                    PropModeReplace,
                    (unsigned char *) &atomDock,
                    1);
}

Panel::~Panel()
{
    delete ui;
}
