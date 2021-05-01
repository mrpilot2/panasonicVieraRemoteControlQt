#include "mainwidget.hpp"

#include <aide/hierarchicalid.hpp>

#include "ui_mainwidget.h"

using viera::gui::MainWidget;

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
    , ui(std::make_unique<Ui::MainWidget>())
{
    ui->setupUi(this);
}
MainWidget::~MainWidget() = default;

void MainWidget::setController(
    viera::gui::MainWidgetControllerPtr ctrl,
    const aide::ActionRegistryInterfacePtr& actionRegistry)
{
    controller = std::move(ctrl);

    registerActions(actionRegistry);
}

void MainWidget::registerActions(
    const aide::ActionRegistryInterfacePtr& actionRegistry)
{
    actionConnect = std::make_shared<QAction>(tr("Connect"), this);
    connect(actionConnect.get(), &QAction::triggered, controller.get(),
            &MainWidgetController::onUserWantsToConnectToIpAddress);
    connect(ui->pushButtonConnect, &QPushButton::clicked, actionConnect.get(),
            &QAction::trigger);

    actionRegistry->registerAction(
        actionConnect, aide::HierarchicalId("TV Remote")("Connect"),
        tr("Connect to the given IP address").toStdString(),
        {QKeySequence(Qt::ALT + Qt::Key_C)});
}
