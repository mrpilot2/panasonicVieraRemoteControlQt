
#include "mainwidgetcontroller.hpp"

#include <aide/loggerinterface.hpp>

using viera::gui::MainWidgetController;

MainWidgetController::MainWidgetController(aide::LoggerPtr loggerInterface)
    : logger{loggerInterface}
{}

void viera::gui::MainWidgetController::onUserWantsToConnectToIpAddress()
{
    logger->info("User requests to connect to TV");
}
