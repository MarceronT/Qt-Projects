#ifndef SIGNAL_H
#define SIGNAL_H

#include <QWidget>

class signal : public QWidget
{
    Q_OBJECT

public:
    signal(QWidget *parent = nullptr);
    ~signal();
};
#endif // SIGNAL_H
