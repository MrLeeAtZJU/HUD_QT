#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include "data_types.h"
#include "setwidget.h"

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = 0);
	void setFlags(int value);
    ~Dialog3();

private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
