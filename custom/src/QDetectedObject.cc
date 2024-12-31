#include "QDetectedObject.h"

QDetectedObject::QDetectedObject(const QGeoCoordinate& coord, const QString& name, const QUrl& url, QObject* parent)
    : QGCQGeoCoordinate(coord, parent)
    , _name(name)
    , _url(url)
{
}

QString QDetectedObject::name() const {
    return _name;
}

void QDetectedObject::setName(const QString& name) {
    if (_name != name) {
        _name = name;
        emit nameChanged();
    }
}

QUrl QDetectedObject::url() const {
    return _url;
}

void QDetectedObject::setUrl(const QUrl& url) {
    if (_url != url) {
        _url = url;
        emit urlChanged();
    }
}