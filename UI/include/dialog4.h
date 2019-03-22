#ifndef DIALOG4_H
#define DIALOG4_H

#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include "data_types.h"
#include "setwidget.h"

namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = 0);
	void setFlags(int value);
    ~Dialog4();

private:
    Ui::Dialog4 *ui;

private:
    void paintEvent(QPaintEvent *event);
};

#endif // DIALOG4_H
