
#include "connecttotv.hpp"

#include <utility>

#include <QNetworkReply>
#include <QXmlSimpleReader>

#include <aide/loggerinterface.hpp>

using viera::core::ConnectToTv;
using viera::core::VieraProtocol;

ConnectToTv::ConnectToTv(aide::LoggerPtr loggerInterface)
    : logger{std::move(loggerInterface)}
{
    VieraProtocol::setIpAddress("10.0.0.96");
}

void ConnectToTv::receiveTvInformation()
{
    networkAccessManager.connectToHost(
        QString::fromStdString(VieraProtocol::getIpAddress()),
        static_cast<quint16>(VieraProtocol::getPort()));

    QNetworkRequest request(VieraProtocol::createBasicTVInformationRequest());
    [[maybe_unused]] auto* reply = networkAccessManager.get(request);

    connect(&networkAccessManager, &QNetworkAccessManager::finished, this,
            &ConnectToTv::networkRequestIsFinished);
}

void ConnectToTv::sendSelectedKey(const QString& key)
{
    auto [request, body] = VieraProtocol::createSendKeyRequest(key);

    logger->trace("Prepared body to send {}", body);

    [[maybe_unused]] auto* reply =
        networkAccessManager.post(request, QByteArray(body.c_str()));
}

void ConnectToTv::networkRequestIsFinished(QNetworkReply* reply)
{
    logger->trace("Network request is finished");

    if (reply->error() != QNetworkReply::NoError) {
        logger->error("Network request finished with error: {}",
                      reply->errorString().toStdString());
    } else {
        QString data = reply->readAll();

        logger->trace("{}", data.toStdString());
    }
}
