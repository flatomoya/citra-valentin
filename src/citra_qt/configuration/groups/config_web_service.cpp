// Copyright 2019 Citra Valentin Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QSettings>
#include "citra_qt/configuration/config.h"
#include "citra_qt/uisettings.h"

void Config::ReadWebServiceValues() {
    qt_config->beginGroup(QStringLiteral("WebService"));
    Settings::values.web_api_url =
        ReadSetting(QStringLiteral("web_api_url"), QStringLiteral("https://api.citra-emu.org"))
            .toString()
            .toStdString();
    UISettings::values.cv_web_api_url =
        ReadSetting(QStringLiteral("cv_web_api_url"), QStringLiteral("https://cv-aadb.glitch.me"))
            .toString();
    UISettings::values.cv_discord_send_jwt =
        ReadSetting(QStringLiteral("cv_discord_send_jwt")).toString().toStdString();
    Settings::values.citra_username =
        ReadSetting(QStringLiteral("citra_username")).toString().toStdString();
    Settings::values.citra_token =
        ReadSetting(QStringLiteral("citra_token")).toString().toStdString();
    qt_config->endGroup();
}

void Config::SaveWebServiceValues() {
    qt_config->beginGroup(QStringLiteral("WebService"));
    WriteSetting(QStringLiteral("web_api_url"),
                 QString::fromStdString(Settings::values.web_api_url),
                 QStringLiteral("https://api.citra-emu.org"));
    WriteSetting(QStringLiteral("cv_web_api_url"), UISettings::values.cv_web_api_url,
                 QStringLiteral("https://cv-aadb.glitch.me"));
    WriteSetting(QStringLiteral("cv_discord_send_jwt"),
                 QString::fromStdString(UISettings::values.cv_discord_send_jwt));
    WriteSetting(QStringLiteral("citra_username"),
                 QString::fromStdString(Settings::values.citra_username));
    WriteSetting(QStringLiteral("citra_token"),
                 QString::fromStdString(Settings::values.citra_token));
    qt_config->endGroup();
}
