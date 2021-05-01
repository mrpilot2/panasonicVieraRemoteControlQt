
#ifndef VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_CONTROLLER_HPP
#define VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_CONTROLLER_HPP

#include <memory>

#include <QObject>

#include "../core/connecttotv.hpp"

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
        explicit MainWidgetController(viera::core::ConnectToTv& connectUseCase,
                                      aide::LoggerPtr loggerInterface);

    public slots:
        void onUserWantsToConnectToIpAddress();

        void onUserClickedAKey(const QString& key);

    private:
        viera::core::ConnectToTv& connectToTv;

        aide::LoggerPtr logger;
    };

    using MainWidgetControllerPtr = std::shared_ptr<MainWidgetController>;

} // namespace viera::gui

#endif // VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_CONTROLLER_HPP
