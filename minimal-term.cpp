#include <QApplication>

// Add QDesktopServices
#include <QDesktopServices>
#include <QKeySequence>
#include <QMainWindow>

#include "qtermwidget.h"


// Here we define the activateUrl method
void activateUrl(const QUrl &url, bool fromContextMenu) {
  if (QApplication::keyboardModifiers() & Qt::ControlModifier ||
      fromContextMenu) {
    QDesktopServices::openUrl(url);
  }
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QMainWindow *mainWindow = new QMainWindow();
  setenv("TERM", "konsole-256color", 1);

  QTermWidget *console = new QTermWidget();

  QFont font = QApplication::font();
  font.setFamily("Monospace");
  font.setPointSize(12);

  console->setTerminalFont(font);
  console->setColorScheme("Solarized");
  console->setTerminalOpacity(0.9);

  // Here we connect it all together
  QObject::connect(console, &QTermWidget::urlActivated, mainWindow,
                   activateUrl);

  QObject::connect(console, &QTermWidget::termKeyPressed, mainWindow,
                   [=](const QKeyEvent *key) -> void {
                     if (key->matches(QKeySequence::Copy)) {
                       console->copyClipboard();
                     } else if (key->matches(QKeySequence::Paste)) {
                       console->pasteClipboard();
                     }
                   });

  QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));


  mainWindow->setCentralWidget(console);
  console->setTerminalOpacity(0.7);
  mainWindow->show();
  return app.exec();
}
