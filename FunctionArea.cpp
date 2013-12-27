#include "FunctionArea.h"

FunctionArea::FunctionArea(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    initData();
}

void FunctionArea::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
            break;
    }
}

void FunctionArea::initData()
{
	widgetNewProject->addData(QPixmap("./resource/images/tool_area/TopToolBar_new.png"), tr("New"));
    connect(widgetNewProject, SIGNAL(signalClick()), this, SIGNAL(signalNewProjectClick()));
	widgetUpload->addData(QPixmap("./resource/images/tool_area/TopToolBar_upload.png"), tr("Upload"));
    connect(widgetUpload, SIGNAL(signalClick()), this, SIGNAL(signalUploadClick()));
	widgetOpen->addData(QPixmap("./resource/images/tool_area/TopToolBar_open.png"), tr("Open"));
    connect(widgetOpen, SIGNAL(signalClick()), this, SIGNAL(signalOpenClick()));
	widgetSave->addData(QPixmap("./resource/images/tool_area/TopToolBar_save.png"), tr("Save"));
    connect(widgetSave, SIGNAL(signalClick()), this, SIGNAL(signalSaveClick()));
}
