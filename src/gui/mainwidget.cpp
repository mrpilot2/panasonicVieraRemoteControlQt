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

    connect(&signalMapper, qOverload<const QString&>(&QSignalMapper::mapped),
            controller.get(), &MainWidgetController::onUserClickedAKey);

    const std::map<QPushButton*, QString> buttonKeyMap{
        {ui->buttonOnOff, "NRC_POWER-ONOFF"},
        {ui->button3D, "NRC_3D-ONOFF"},
        {ui->buttonTV, "NRC_AD_CHANGE-ONOFF"},
        {ui->buttonAV, "NRC_CHG_INPUT-ONOFF"},
        {ui->buttonMenu, "NRC_MENU-ONOFF"},
        {ui->buttonText, "NRC_TEXT-ONOFF"},
        {ui->buttonSTL, "NRC_STTL-ONOFF"},
        {ui->buttonAspect, "NRC_DISP_MODE-ONOFF"},
        {ui->buttonInfo, "NRC_INFO-ONOFF"},
        {ui->buttonExit, "NRC_CANCEL-ONOFF"},
        {ui->buttonApps, "NRC_APPS-ONOFF"},
        {ui->buttonHome, "NRC_HOME-ONOFF"},
        {ui->buttonOK, "NRC_ENTER-ONOFF"},
        {ui->buttonUp, "NRC_UP-ONOFF"},
        {ui->buttonLeft, "NRC_LEFT-ONOFF"},
        {ui->buttonRight, "NRC_RIGHT-ONOFF"},
        {ui->buttonDown, "NRC_DOWN-ONOFF"},
        {ui->buttonOption, "NRC_SUBMENU-ONOFF"},
        {ui->buttonBackReturn, "NRC_RETURN-ONOFF"},
        {ui->buttonRed, "NRC_RED-ONOFF"},
        {ui->buttonGreen, "NRC_GREEN-ONOFF"},
        {ui->buttonYellow, "NRC_YELLOW-ONOFF"},
        {ui->buttonBlue, "NRC_BLUE-ONOFF"},
        {ui->buttonVolumeUp, "NRC_VOLUP-ONOFF"},
        {ui->buttonVolumeDown, "NRC_VOLDOWN-ONOFF"},
        {ui->buttonMute, "NRC_MUTE-ONOFF"},
        {ui->buttonChannelUp, "NRC_CH_UP-ONOFF"},
        {ui->buttonChannelDown, "NRC_CH_DOWN-ONOFF"},
        {ui->button1, "NRC_D1-ONOFF"},
        {ui->button2, "NRC_D2-ONOFF"},
        {ui->button3, "NRC_D3-ONOFF"},
        {ui->button4, "NRC_D4-ONOFF"},
        {ui->button5, "NRC_D5-ONOFF"},
        {ui->button6, "NRC_D6-ONOFF"},
        {ui->button7, "NRC_D7-ONOFF"},
        {ui->button8, "NRC_D8-ONOFF"},
        {ui->button9, "NRC_D9-ONOFF"},
        {ui->button0, "NRC_D0-ONOFF"},
        {ui->buttonHelp, "NRC_GUIDE-ONOFF"},
        {ui->buttonLastView, "NRC_R_TUNE-ONOFF"},
        {ui->buttonRewind, "NRC_REW-ONOFF"},
        {ui->buttonPlay, "NRC_PLAY-ONOFF"},
        {ui->buttonFastForward, "NRC_FF-ONOFF"},
        {ui->buttonPrevious, "NRC_SKIP_PREV-ONOFF"},
        {ui->buttonPause, "NRC_PAUSE-ONOFF"},
        {ui->buttonNext, "NRC_SKIP_NEXT-ONOFF"},
        {ui->buttonStop, "NRC_STOP-ONOFF"},
        {ui->buttonRecord, "NRC_REC-ONOFF"},
    };

    for (const auto& p : buttonKeyMap) {
        signalMapper.setMapping(p.first, p.second);

        connect(p.first, SIGNAL(clicked()), &signalMapper, SLOT(map()));
    }
}
