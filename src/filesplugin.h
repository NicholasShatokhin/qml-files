
#include <QQmlExtensionPlugin>
#include <qqml.h>


#include "dir.h"


class TetheredPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<Dir>(uri, 1, 0, "Dir");
        qmlRegisterType<DirAttached>();
    };
};
