#include <aide/application.hpp>

using aide::Application;

int main(int argc, char* argv[])
{
    aide::Application::setOrganizationName("mrpilot");
         aide::Application::setApplicationName("vieraRemoteControl");
    aide::Application::setApplicationDisplayName("Viera Remote Control");

    aide::Application app(argc, argv);
    return aide::Application::exec();
}
