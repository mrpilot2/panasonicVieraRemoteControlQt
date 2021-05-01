
#include "connecttotv.hpp"

#include <QNetworkReply>
#include <QXmlSimpleReader>

#include <aide/loggerinterface.hpp>

using viera::core::ConnectToTv;

ConnectToTv::ConnectToTv(aide::LoggerPtr loggerInterface)
    : logger{loggerInterface}
{}

void ConnectToTv::receiveTvInformation()
{
    constexpr auto connectionPort{55000};
    constexpr auto tvIPAddress{"10.0.0.96"};
    networkAccessManager.connectToHost(tvIPAddress, connectionPort);

    QNetworkRequest request(QUrl(QString::fromStdString(
        "http://" + std::string(tvIPAddress) + ":" +
        std::to_string(connectionPort) + "/nrc/ddd.xml")));
    auto* reply = networkAccessManager.get(request);

    connect(&networkAccessManager, &QNetworkAccessManager::finished, this,
            &ConnectToTv::networkRequestIsFinished);
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
