
#ifndef VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_CONTROLLER_HPP
#define VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_CONTROLLER_HPP

#include <memory>

#include <QObject>

namespace aide
{
    class LoggerInterface;
    using LoggerPtr = std::shared_ptr<LoggerInterface>;
} // namespace aide

namespace viera::gui
{
    class MainWidgetController : public QObject
    {
        Q_OBJECT
    public:
        explicit MainWidgetController(aide::LoggerPtr loggerInterface);

    public slots:
        void onUserWantsToConnectToIpAddress();

    private:
        aide::LoggerPtr logger;
    };

    using MainWidgetControllerPtr = std::shared_ptr<MainWidgetController>;

} // namespace viera::gui

#endif // VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_CONTROLLER_HPP
