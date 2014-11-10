#ifndef MINDKITFORM_H
#define MINDKITFORM_H

#include "ui_MindKitForm.h"
class MindKitPushButton;

class MindKitForm : public QWidget, private Ui::MindKitForm
{
	Q_OBJECT

public:
	explicit MindKitForm(QWidget *parent = 0);

signals:
	void signalMindKitPushButtonPointer(MindKitPushButton *pointer);

protected:
	void changeEvent(QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void showEvent(QShowEvent *);

private slots:
	void on_pushButtonReturn_clicked();
	void slotInitPushbutton();

private:
	void initGui();

private:
	QPoint offset_;
	QWidget *pParent_;
};

#endif // MINDKITFORM_H
