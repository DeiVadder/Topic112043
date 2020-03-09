#include "idlefilter.h"
#include <QDebug>

IdleFilter::IdleFilter(QObject *parent) : QObject(parent)
{
    m_idelTimer.setInterval(2000);//2 Sek

    connect(&m_idelTimer, &QTimer::timeout, this, &IdleFilter::appNowInactive);
    connect(&m_idelTimer, &QTimer::timeout, &m_idelTimer, &QTimer::stop);
    m_idelTimer.start();
}

void IdleFilter::setAppIsActive(bool appIsActive)
{
    if (m_appIsActive == appIsActive)
        return;

    m_appIsActive = appIsActive;
    emit appIsActiveChanged(m_appIsActive);
    emit m_appIsActive ? signalAppIsActive() : signalAppIsInactive();
}

void IdleFilter::appNowInactive()
{
    setAppIsActive(false);
    qDebug() << "App is idle";
}

bool IdleFilter::eventFilter(QObject *obj, QEvent *event)
{
    if(!m_idelTimer.isActive()){
        setAppIsActive(true);
        qDebug() << "App no longer idle";
    }
    m_idelTimer.start();
    // standard event processing
    return QObject::eventFilter(obj, event);
}
