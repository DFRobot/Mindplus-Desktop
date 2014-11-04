#-------------------------------------------------
#
# Project created by QtCreator 2012-09-27T11:06:49
#
#-------------------------------------------------

QT += core gui
QT += sql
QT += network
#QT += opengl

CONFIG(release, debug|release){
DEFINES += USE_RELEASE
DEFINES += QT_NO_DEBUG_OUTPUT
DEFINES += QT_NO_WARNING_OUTPUT
}

CONFIG(debug, debug|release){
DEFINES += USE_DEBUG
}

greaterThan(QT_MAJOR_VERSION, 4){
QT += widgets
QT += serialport
CONFIG += c++11
}
equals(QT_MAJOR_VERSION, 4){
QMAKE_CXXFLAGS += -std=c++0x
}

TARGET = mp
TEMPLATE = app

#lessThan(QT_MAJOR_VERSION, 5):
include(QExtserialport/qextserialport.pri)
include(CompleteLineEdit.pri)

INCLUDEPATH += . \
GraphicFramework/Item \
GraphicFramework/Scene \
GraphicFramework/View \
Other \
Other/Data \
Uploader

SOURCES += main.cpp\
	WidgetShowScene.cpp \
	WidgetMain.cpp \
	ListWidget.cpp \
	ListWidgetItem.cpp \
	FunctionArea.cpp \
	GraphicFramework/Item/RootItem.cpp \
	GraphicFramework/Item/ParameterItem.cpp \
	GraphicFramework/Item/FlowLine.cpp \
	GraphicFramework/Item/BehaviourItem.cpp \
	GraphicFramework/Item/StartItem.cpp\
	GraphicFramework/Scene/EditScene.cpp \
	GraphicFramework/View/OperationsManagement.cpp \
	Other/Data/DatabaseEditComponent.cpp \
	Other/Data/DataBaseCreateComponent.cpp \
	UploadSettingForm.cpp \
	FunctionAreaWidget.cpp \
	ListWidgetItemWidget_Component.cpp \
	ListWidgetItemWidget_UploadSetting.cpp \
	UploadWaitForm.cpp \
	GraphicFramework/Item/GraphicsItemBase.cpp \
	GraphicFramework/Item/GraphicsItermGroup.cpp \
	PushButtonDone.cpp \
	Animation.cpp \
	FileInforForm.cpp \
	ListWidgetItemWidget_Photo.cpp \
	Label.cpp \
	Parameter_Time_Form.cpp \
	Parameter_Integer_Form.cpp \
	GraphicFramework/Item/LockIconItem.cpp \
	WidgetBackgroundRight.cpp \
	Parameter_String_Form.cpp \
	AllBlocksForm.cpp \
	PushButtonBlock.cpp \
	MindKitForm.cpp \
	PushButtonMindKit.cpp \
	Parameter_LED8x8_Form.cpp \
	CustomFont.cpp \
	PushButtonBase.cpp \
	Other/Data/DataBaseHandle.cpp \
	Other/Data/ResultsetBase.cpp \
	Uploader/Uploader.cpp \
	Uploader/Translate.cpp \
	Uploader/ToolFactory.cpp \
	Uploader/ToolBase.cpp \
	Uploader/ArduinoUploader.cpp \
	Uploader/DFRobotUploader.cpp \
	Sleep.cpp \
	LoginInforWidget.cpp \
	IntroduceForm.cpp \
	Parameter_AnalogPin_Form.cpp \
	Parameter_DigitalPin_Form.cpp \
	Parameter_operator_Form.cpp \
	IntroduceFromRight.cpp \
	MindKitPushButton.cpp \
	UploadParameterWidget.cpp \
	AffirmForm.cpp \
	CallUpdateProgram.cpp \
	Parameter_CurveProgression_Form.cpp \
	CurveProgressionWidget.cpp \
    SerialSettingWidget.cpp \
    Other/Data/GetBlockData.cpp \
    BlockMenuWidget.cpp \
    ListWidgetAdvanceBlock.cpp \
    WidgetForListWidgetBegin.cpp \
    SerialPortToolForm.cpp \
    SerialDataThread.cpp \
    Param.cpp

HEADERS  += \
	WidgetShowScene.h \
	WidgetMain.h \
	ListWidget.h \
	ListWidgetItem.h \
	FunctionArea.h \
	GraphicFramework/Item/RootItem.h \
	GraphicFramework/Item/ParameterItem.h \
	GraphicFramework/Item/FlowLine.h \
	GraphicFramework/Item/BehaviourItem.h \
	GraphicFramework/Item/StartItem.h\
	GraphicFramework/Scene/EditScene.h \
	GraphicFramework/View/OperationsManagement.h \
	Other/Data/DataStruct.h \
	Other/Data/DatabaseEditComponent.h \
	Other/Data/DataBaseCreateComponent.h \
	UploadSettingForm.h \
	FunctionAreaWidget.h \
	ListWidgetItemWidget_Component.h \
	ListWidgetItemWidget_UploadSetting.h \
	UploadWaitForm.h \
	GraphicFramework/Item/GraphicsItemBase.h \
	GraphicFramework/Item/GraphicsItermGroup.h \
	PushButtonDone.h \
	Animation.h \
	FileInforForm.h \
	ListWidgetItemWidget_Photo.h \
	Label.h \
	Parameter_Time_Form.h \
	Parameter_Integer_Form.h \
	GraphicFramework/Item/LockIconItem.h \
	WidgetBackgroundRight.h \
	Parameter_String_Form.h \
	AllBlocksForm.h \
	PushButtonBlock.h \
	MindKitForm.h \
	PushButtonMindKit.h \
	Parameter_LED8x8_Form.h \
	CustomFont.h \
	PushButtonBase.h \
	Other/Data/DataBaseHandle.h \
	Other/Data/ResultsetBase.h \
	Uploader/Uploader.h \
	Uploader/Translate.h \
	Uploader/ToolsFactory.h \
	Uploader/ToolBase.h \
	Uploader/ArduinoUploader.h \
	Uploader/DFRobotUploader.h \
	Sleep.h \
	LoginInforWidget.h \
	IntroduceForm.h \
	dptr.h \
	Parameter_AnalogPin_Form.h \
	Parameter_DigitalPin_Form.h \
	Parameter_operator_Form.h \
	IntroduceFromRight.h \
	MindKitPushButton.h \
	UploadParameterWidget.h \
	AffirmForm.h \
	CallUpdateProgram.h \
	Parameter_CurveProgression_Form.h \
	CurveProgressionWidget.h \
    Common.h \
    SerialSettingWidget.h \
    Other/Data/GetBlockData.h \
    BlockMenuWidget.h \
    ListWidgetAdvanceBlock.h \
    WidgetForListWidgetBegin.h \
    SerialPortToolForm.h \
    SerialDataThread.h \
    Param.h

FORMS    += \
	WidgetMain.ui \
	FunctionArea.ui \
	UploadSettingForm.ui \
	FunctionAreaWidget.ui \
	ListWidgetItemWidget_UploadSetting.ui \
	ListWidgetItemWidget_Component.ui \
	UploadWaitForm.ui \
	FileInforForm.ui \
	ListWidgetItemWidget_Photo.ui \
	Parameter_Time_Form.ui \
	Parameter_Integer_Form.ui \
	Parameter_String_Form.ui \
	AllBlocksForm.ui \
	MindKitForm.ui \
	Parameter_LED8x8_Form.ui \
	LoginInforWidget.ui \
	IntroduceForm.ui \
	Parameter_AnalogPin_Form.ui \
	Parameter_DigitalPin_Form.ui \
	Parameter_operator_Form.ui \
	UploadParameterWidget.ui \
	AffirmForm.ui \
	Parameter_CurveProgression_Form.ui \
    SerialSettingWidget.ui \
    BlockMenuWidget.ui \
    WidgetForListWidgetBegin.ui \
    SerialPortToolForm.ui


RESOURCES += \
	src.qrc

OTHER_FILES += \
	大略文档.txt

#现在不需要图标了
#win32:RC_FILE = ico.rc

#macx:ICON = ./resource/images/icon/v095_logo_macx.icns
#macx:ICON = v095_logo_macx.icns


MOC_DIR = build/moc
OBJECTS_DIR = build/obj
RCC_DIR = build/rcc
UI_DIR = build/ui
UI_HEADERS_DIR = build/ui
UI_SOURCES_DIR = build/ui
