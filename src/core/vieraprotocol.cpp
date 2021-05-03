
#include "vieraprotocol.hpp"

using viera::core::VieraProtocol;

constexpr auto VIERA_PORT{55000};

constexpr auto BASIC_TV_INFORMATION_ENDPOINT{"/nrc/ddd.xml"};

constexpr auto COMMAND_ENDPOINT{"/nrc/control_0"};
constexpr auto COMMAND_URN{"urn:panasonic-com:service:p00NetworkControl:1"};

std::string VieraProtocol::m_ipAddress = "0.0.0.0";

void VieraProtocol::setIpAddress(const std::string& ipAddress)
{
    m_ipAddress = ipAddress;
}

std::string VieraProtocol::getIpAddress()
{
    return m_ipAddress;
}

int VieraProtocol::getPort()
{
    return VIERA_PORT;
}

QNetworkRequest VieraProtocol::createBasicTVInformationRequest()
{
    const QUrl url{QString::fromStdString(createBasicURL() +
                                          BASIC_TV_INFORMATION_ENDPOINT)};
    return QNetworkRequest(url);
}

std::tuple<QNetworkRequest, std::string> VieraProtocol::createSendKeyRequest(
    const QString key)
{
    const QUrl url{QString::fromStdString(createBasicURL() + COMMAND_ENDPOINT)};

    QNetworkRequest request{url};
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      R"(text/xml;charset="utf-8")");
    request.setRawHeader(
        "SOAPACTION",
        QByteArray(std::string(std::string("\"") + COMMAND_URN + "#X_SendKey\"")
                       .c_str()));

    const std::string body{R"(<?xml version="1.0" encoding="utf-8"?>
  <s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/" s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
    <s:Body>
      <u:X_SendKey xmlns:u=")" +
                           std::string(COMMAND_URN) + R"(">
        <X_KeyEvent>)" + key.toStdString() +
                           R"(</X_KeyEvent>
      </u:X_SendKey>
    </s:Body>
 </s:Envelope>)"};

    return std::make_tuple(request, body);
}

std::string VieraProtocol::createBasicURL()
{
    return "http://" + m_ipAddress + ":" + std::to_string(VIERA_PORT);
}
