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
include(libraries/QExtserialport/qextserialport.pri)
include(libraries/CompleteLineEdit/CompleteLineEdit.pri)

INCLUDEPATH += src \
	libraries \
	src/GraphicFramework/Item \
	src/GraphicFramework/Scene \
	src/GraphicFramework/View \
	src/Other \
	src/Other/Data \
	src/Uploader

SOURCES += src/main.cpp\
	src/WidgetShowScene.cpp \
	src/WidgetMain.cpp \
	src/ListWidget.cpp \
	src/ListWidgetItem.cpp \
	src/FunctionArea.cpp \
	src/GraphicFramework/Item/RootItem.cpp \
	src/GraphicFramework/Item/ParameterItem.cpp \
	src/GraphicFramework/Item/FlowLine.cpp \
	src/GraphicFramework/Item/BehaviourItem.cpp \
	src/GraphicFramework/Item/StartItem.cpp\
	src/GraphicFramework/Scene/EditScene.cpp \
	src/GraphicFramework/View/OperationsManagement.cpp \
	src/Other/Data/DatabaseEditComponent.cpp \
	src/Other/Data/DataBaseCreateComponent.cpp \
	src/UploadSettingForm.cpp \
	src/FunctionAreaWidget.cpp \
	src/ListWidgetItemWidget_Component.cpp \
	src/ListWidgetItemWidget_UploadSetting.cpp \
	src/UploadWaitForm.cpp \
	src/GraphicFramework/Item/GraphicsItemBase.cpp \
	src/GraphicFramework/Item/GraphicsItermGroup.cpp \
	src/PushButtonDone.cpp \
	src/Animation.cpp \
	src/FileInforForm.cpp \
	src/ListWidgetItemWidget_Photo.cpp \
	src/Label.cpp \
	src/Parameter_Time_Form.cpp \
	src/Parameter_Integer_Form.cpp \
	src/GraphicFramework/Item/LockIconItem.cpp \
	src/WidgetBackgroundRight.cpp \
	src/Parameter_String_Form.cpp \
	src/AllBlocksForm.cpp \
	src/PushButtonBlock.cpp \
	src/MindKitForm.cpp \
	src/PushButtonMindKit.cpp \
	src/Parameter_LED8x8_Form.cpp \
	src/CustomFont.cpp \
	src/PushButtonBase.cpp \
	src/Other/Data/DataBaseHandle.cpp \
	src/Other/Data/ResultsetBase.cpp \
	src/Uploader/Uploader.cpp \
	src/Uploader/Translate.cpp \
	src/Uploader/ToolFactory.cpp \
	src/Uploader/ToolBase.cpp \
	src/Uploader/ArduinoUploader.cpp \
	src/Uploader/DFRobotUploader.cpp \
	src/Sleep.cpp \
	src/LoginInforWidget.cpp \
	src/IntroduceForm.cpp \
	src/Parameter_AnalogPin_Form.cpp \
	src/Parameter_DigitalPin_Form.cpp \
	src/Parameter_operator_Form.cpp \
	src/IntroduceFromRight.cpp \
	src/MindKitPushButton.cpp \
	src/UploadParameterWidget.cpp \
	src/AffirmForm.cpp \
	src/CallUpdateProgram.cpp \
	src/Parameter_CurveProgression_Form.cpp \
	src/CurveProgressionWidget.cpp \
    src/SerialSettingWidget.cpp \
    src/Other/Data/GetBlockData.cpp \
    src/BlockMenuWidget.cpp \
    src/ListWidgetAdvanceBlock.cpp \
    src/WidgetForListWidgetBegin.cpp \
    src/SerialPortToolForm.cpp \
    src/SerialDataThread.cpp \
    src/Param.cpp

HEADERS  += \
	src/WidgetShowScene.h \
	src/WidgetMain.h \
	src/ListWidget.h \
	src/ListWidgetItem.h \
	src/FunctionArea.h \
	src/GraphicFramework/Item/RootItem.h \
	src/GraphicFramework/Item/ParameterItem.h \
	src/GraphicFramework/Item/FlowLine.h \
	src/GraphicFramework/Item/BehaviourItem.h \
	src/GraphicFramework/Item/StartItem.h\
	src/GraphicFramework/Scene/EditScene.h \
	src/GraphicFramework/View/OperationsManagement.h \
	src/Other/Data/DataStruct.h \
	src/Other/Data/DatabaseEditComponent.h \
	src/Other/Data/DataBaseCreateComponent.h \
	src/UploadSettingForm.h \
	src/FunctionAreaWidget.h \
	src/ListWidgetItemWidget_Component.h \
	src/ListWidgetItemWidget_UploadSetting.h \
	src/UploadWaitForm.h \
	src/GraphicFramework/Item/GraphicsItemBase.h \
	src/GraphicFramework/Item/GraphicsItermGroup.h \
	src/PushButtonDone.h \
	src/Animation.h \
	src/FileInforForm.h \
	src/ListWidgetItemWidget_Photo.h \
	src/Label.h \
	src/Parameter_Time_Form.h \
	src/Parameter_Integer_Form.h \
	src/GraphicFramework/Item/LockIconItem.h \
	src/WidgetBackgroundRight.h \
	src/Parameter_String_Form.h \
	src/AllBlocksForm.h \
	src/PushButtonBlock.h \
	src/MindKitForm.h \
	src/PushButtonMindKit.h \
	src/Parameter_LED8x8_Form.h \
	src/CustomFont.h \
	src/PushButtonBase.h \
	src/Other/Data/DataBaseHandle.h \
	src/Other/Data/ResultsetBase.h \
	src/Uploader/Uploader.h \
	src/Uploader/Translate.h \
	src/Uploader/ToolsFactory.h \
	src/Uploader/ToolBase.h \
	src/Uploader/ArduinoUploader.h \
	src/Uploader/DFRobotUploader.h \
	src/Sleep.h \
	src/LoginInforWidget.h \
	src/IntroduceForm.h \
	src/dptr.h \
	src/Parameter_AnalogPin_Form.h \
	src/Parameter_DigitalPin_Form.h \
	src/Parameter_operator_Form.h \
	src/IntroduceFromRight.h \
	src/MindKitPushButton.h \
	src/UploadParameterWidget.h \
	src/AffirmForm.h \
	src/CallUpdateProgram.h \
	src/Parameter_CurveProgression_Form.h \
	src/CurveProgressionWidget.h \
    src/Common.h \
    src/SerialSettingWidget.h \
    src/Other/Data/GetBlockData.h \
    src/BlockMenuWidget.h \
    src/ListWidgetAdvanceBlock.h \
    src/WidgetForListWidgetBegin.h \
    src/SerialPortToolForm.h \
    src/SerialDataThread.h \
    src/Param.h

FORMS    += \
	ui/WidgetMain.ui \
	ui/FunctionArea.ui \
	ui/UploadSettingForm.ui \
	ui/FunctionAreaWidget.ui \
	ui/ListWidgetItemWidget_UploadSetting.ui \
	ui/ListWidgetItemWidget_Component.ui \
	ui/UploadWaitForm.ui \
	ui/FileInforForm.ui \
	ui/ListWidgetItemWidget_Photo.ui \
	ui/Parameter_Time_Form.ui \
	ui/Parameter_Integer_Form.ui \
	ui/Parameter_String_Form.ui \
	ui/AllBlocksForm.ui \
	ui/MindKitForm.ui \
	ui/Parameter_LED8x8_Form.ui \
	ui/LoginInforWidget.ui \
	ui/IntroduceForm.ui \
	ui/Parameter_AnalogPin_Form.ui \
	ui/Parameter_DigitalPin_Form.ui \
	ui/Parameter_operator_Form.ui \
	ui/UploadParameterWidget.ui \
	ui/AffirmForm.ui \
	ui/Parameter_CurveProgression_Form.ui \
    ui/SerialSettingWidget.ui \
    ui/BlockMenuWidget.ui \
    ui/WidgetForListWidgetBegin.ui \
    ui/SerialPortToolForm.ui


RESOURCES += \
	resource/images.qrc

OTHER_FILES += \
	大略文档.txt

#现在不需要图标了
#win32:RC_FILE = extra/ico.rc

#macx:ICON = ./resource/images/icon/v095_logo_macx.icns
#macx:ICON = v095_logo_macx.icns
#linux:
win32{
MOC_DIR = _moc
OBJECTS_DIR = _obj
RCC_DIR = _rcc
UI_DIR = _ui
UI_HEADERS_DIR = _ui
UI_SOURCES_DIR = _ui
}else{
#mac{
#	QMAKE_INFO_PLIST = BBMaker.plist
#	ICON = blockmaker.icns
#}
MOC_DIR = .moc
OBJECTS_DIR = .obj
RCC_DIR = .rcc
UI_DIR = .ui
UI_HEADERS_DIR = .ui
UI_SOURCES_DIR = .ui
}
