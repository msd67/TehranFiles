#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <header/Framework/CurrentDirectory.h>
#include <header/BusinessRules/DirectoryController.h>
#include <header/BusinessEntities/DirectoryInfo.h>

static QObject* CurrentDirectoryProvider(QQmlEngine *engine, QJSEngine *scriptEngine);
CurrentDirectory* currentDirectory;

int main(int argc, char *argv[])
{
    auto directoryInfo = std::make_shared<DirectoryInfo>();
    auto directoryController = std::make_unique<DirectoryController>(directoryInfo);
    currentDirectory = new CurrentDirectory(directoryInfo, std::move(directoryController));
    qmlRegisterSingletonType<CurrentDirectory>("Tehran.Files", 1, 0, "FileManager", CurrentDirectoryProvider);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

static QObject* CurrentDirectoryProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return currentDirectory;
}
