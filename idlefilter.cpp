#include "idlefilter.h"
#include <QDebug>

IdleFilter::IdleFilter(QObject *parent) : QObject(parent)
{
    m_idelTimer.setInterval(2000);//2 Sek

    connect(&m_idelTimer, &QTimer::timeout, this, []()->void{qDebug() << "App is idle";});
    connect(&m_idelTimer, &QTimer::timeout, &m_idelTimer, &QTimer::stop);
    m_idelTimer.start();
}

bool IdleFilter::eventFilter(QObject *obj, QEvent *event)
{
    if(!m_idelTimer.isActive())
        qDebug() << "App no longer idle";
    m_idelTimer.start();
    // standard event processing
    return QObject::eventFilter(obj, event);
}
