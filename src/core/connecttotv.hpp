
#ifndef VIERA_REMOTE_CONTROL_QT_CONNECT_TO_TV_HPP
#define VIERA_REMOTE_CONTROL_QT_CONNECT_TO_TV_HPP

#include <memory>

#include <QtNetwork/QNetworkAccessManager>

#include "vieraprotocol.hpp"

namespace aide
{
    class LoggerInterface;
    using LoggerPtr = std::shared_ptr<LoggerInterface>;
} // namespace aide

namespace viera::core
{
    class ConnectToTv : public QObject
    {
    public:
        explicit ConnectToTv(aide::LoggerPtr loggerInterface);

        void receiveTvInformation();

        void sendSelectedKey(const QString& key);

    private slots:
        void networkRequestIsFinished(QNetworkReply* reply);

    private:
        aide::LoggerPtr logger;

        QNetworkAccessManager networkAccessManager;
    };
} // namespace viera::core

#endif // VIERA_REMOTE_CONTROL_QT_CONNECT_TO_TV_HPP
