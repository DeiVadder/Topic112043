#ifndef IDLEFILTER_H
#define IDLEFILTER_H

#include <QObject>
#include <QTimer>

class IdleFilter : public QObject
{
    Q_OBJECT
public:
    explicit IdleFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    QTimer m_idelTimer;
};

#endif // IDLEFILTER_H
