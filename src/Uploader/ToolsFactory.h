#ifndef TOOLSFACTORY_H
#define TOOLSFACTORY_H

#include <QObject>

class ToolBase;

/*!
 * \brief ToolFactory 是负责实例化ToolBase的派生类的工厂
 */
class ToolFactory : public QObject
{
    Q_OBJECT
public:
    explicit ToolFactory(const QString &serialNumber, const QString &boardType, QObject *parent = 0);

    /*!
     * \brief ToolType是编译烧写工具的类型
     */
    enum ToolType
    {
        SillustaniUploader,//! 某大神写的
        SeiferUploader//! seifer兄写的
    };

    ToolBase* createTool(ToolType toolType);

private:
    QString serial_;
    QString board_;
};

#endif // TOOLSFACTORY_H
