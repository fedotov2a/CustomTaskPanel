#include "Panel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Panel panel;
    panel.show();

    return app.exec();
}
