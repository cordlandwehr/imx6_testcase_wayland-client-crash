#include <QObject>
#include <QStack>

class QQuickView;

class Proxy : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void spawnWindow();
    Q_INVOKABLE void killLatestWindow();
    
private:
    QStack<QQuickView*> windows;
};
