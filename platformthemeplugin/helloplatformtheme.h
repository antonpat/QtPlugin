#ifndef HELLOPLATFORMTHEME_H
#define HELLOPLATFORMTHEME_H

#include <qpa/qplatformtheme.h>
#include "hintsettings.h"
#include "systemtrayicon.h"

#include <QHash>
#include <QKeySequence>

class QIconEngine;
class QWindow;
class X11Integration;

class HelloPlatformTheme : public QObject, public QPlatformTheme
{
    Q_OBJECT

public:
    HelloPlatformTheme();
    ~HelloPlatformTheme() override;

    bool usePlatformNativeDialog(DialogType type) const override;
    QPlatformDialogHelper *createPlatformDialogHelper(DialogType type) const override;

    QVariant themeHint(ThemeHint hint) const override;
    const QFont *font(Font type) const override;

    QPlatformMenuBar *createPlatformMenuBar() const override;

    QPlatformSystemTrayIcon *createPlatformSystemTrayIcon() const override {
        auto trayIcon = new SystemTrayIcon;
        if (trayIcon->isSystemTrayAvailable())
            return trayIcon;
        else {
            delete trayIcon;
            return nullptr;
        }
    }

private:
    HintsSettings *m_hints;
    QScopedPointer<X11Integration> m_x11Integration;
};

#endif // HELLOPLATFORMTHEME_H
