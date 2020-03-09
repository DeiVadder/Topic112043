#ifndef IDLEFILTER_H
#define IDLEFILTER_H

#include <QObject>
#include <QTimer>

class IdleFilter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool appIsActive READ appIsActive WRITE setAppIsActive NOTIFY appIsActiveChanged)

public:
    explicit IdleFilter(QObject *parent = nullptr);

    inline bool appIsActive() const {return m_appIsActive;}
public slots:
    void setAppIsActive(bool appIsActive);

private slots:
    void appNowInactive();

signals:
    void appIsActiveChanged(bool appIsActive);
    void signalAppIsActive();
    void signalAppIsInactive();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

    QTimer m_idelTimer;
    bool m_appIsActive = true;


};

#endif // IDLEFILTER_H
