#include <QMainWindow>

#include <aide/application.hpp>

#include "mainwidget.hpp"

using aide::Application;

int main(int argc, char* argv[])
{
    aide::Application::setOrganizationName("mrpilot");
    aide::Application::setApplicationName("vieraRemoteControl");
    aide::Application::setApplicationDisplayName("Viera Remote Control");

    aide::Application app(argc, argv);

    auto mainWidget = std::make_shared<viera::gui::MainWidget>();

    auto mainController =
        std::make_shared<viera::gui::MainWidgetController>(app.logger());

    mainWidget->setController(mainController, app.actionRegistry());
    app.mainWindow()->setCentralWidget(mainWidget.get());

    return aide::Application::exec();
}
