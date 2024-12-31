#include "QGCQGeoCoordinate.h"
#include <QUrl>

class QDetectedObject : public QGCQGeoCoordinate
{
    Q_OBJECT

public:
    QDetectedObject(const QGeoCoordinate& coord, const QString& name, const QUrl& url, QObject* parent = nullptr);

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)

    QString name() const;
    void setName(const QString& name);

    QUrl url() const;
    void setUrl(const QUrl& url);

signals:
    void nameChanged();
    void urlChanged();


private:
    QString _name;
    QUrl _url;
};