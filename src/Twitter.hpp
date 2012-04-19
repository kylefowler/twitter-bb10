#ifndef TUMBLR_H
#define TUMBLR_H

#include <QtCore/QObject>
#include <QSettings>
#include <QtNetwork/qnetworkreply.h>
#include <bb/cascades/Application>
#include <bb/cascades/Container>
#include <bb/cascades/NavigationControl>
#include "AbstractObjectBase.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Button;
        class TextField;
        class SequentialAnimation;
    }
}
class Twitter : public QObject
{
    Q_OBJECT

public:
    Twitter();
    ~Twitter();
    static Twitter* instance();
    NavigationControl* nav;
private:
    static Twitter* appInstance;
private slots:
};

#endif // ifndef HELLOCASCADESAPP_H
