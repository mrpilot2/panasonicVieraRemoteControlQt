
#ifndef VIERA_REMOTE_CONTROL_QT_VIERA_PROTOCOL_HPP
#define VIERA_REMOTE_CONTROL_QT_VIERA_PROTOCOL_HPP

#include <string>

#include <QNetworkRequest>

namespace viera::core
{
    class VieraProtocol
    {
    public:
        static void setIpAddress(const std::string& ipAddress);

        static std::string getIpAddress();

        static int getPort();

        static QNetworkRequest createBasicTVInformationRequest();

        static std::tuple<QNetworkRequest, std::string> createSendKeyRequest(
            const QString key);

    private:
        static std::string createBasicURL();

        static std::string m_ipAddress;
    };
} // namespace viera::core

#endif // VIERA_REMOTE_CONTROL_QT_VIERA_PROTOCOL_HPP
