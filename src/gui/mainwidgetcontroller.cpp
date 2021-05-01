
#include "mainwidgetcontroller.hpp"

#include <utility>

#include <aide/loggerinterface.hpp>

#include "../core/connecttotv.hpp"

using viera::gui::MainWidgetController;

MainWidgetController::MainWidgetController(
    viera::core::ConnectToTv& connectUseCase, aide::LoggerPtr loggerInterface)
    : connectToTv{connectUseCase}
    , logger{std::move(loggerInterface)}
{}

void MainWidgetController::onUserWantsToConnectToIpAddress()
{
    logger->info("User requests to connect to TV");

    connectToTv.receiveTvInformation();
}

void MainWidgetController::onUserClickedAKey(const QString& key)
{
    connectToTv.sendSelectedKey(key);
}
