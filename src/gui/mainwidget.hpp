
#ifndef VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_HPP
#define VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_HPP

#include <memory>

#include <QWidget>

#include <aide/actionregistryinterface.hpp>

#include "mainwidgetcontroller.hpp"

namespace Ui
{
    class MainWidget;
} // namespace Ui

namespace viera::gui
{
    class MainWidget : public QWidget
    {
    public:
        explicit MainWidget(QWidget* parent = nullptr);
        ~MainWidget() override;

        MainWidget(const MainWidget&) = delete;
        MainWidget& operator=(const MainWidget&) = delete;
        MainWidget(MainWidget&&)                 = delete;
        MainWidget& operator=(MainWidget&&) = delete;

        void setController(
            MainWidgetControllerPtr ctrl,
            const aide::ActionRegistryInterfacePtr& actionRegistry);

    private:
        void registerActions(
            const aide::ActionRegistryInterfacePtr& actionRegistry);

        MainWidgetControllerPtr controller;

        std::unique_ptr<Ui::MainWidget> ui;

        std::shared_ptr<QAction> actionConnect;
    };
} // namespace viera::gui

#endif // VIERA_REMOTE_CONTROL_QT_MAIN_WIDGET_HPP
