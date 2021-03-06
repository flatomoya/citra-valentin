// Copyright 2019 Citra Valentin Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QSettings>
#include "citra_qt/configuration/config.h"

void Config::ReadDataStorageValues() {
    qt_config->beginGroup(QStringLiteral("Data Storage"));
    Settings::values.use_virtual_sd = ReadSetting(QStringLiteral("use_virtual_sd"), true).toBool();
    qt_config->endGroup();
}

void Config::SaveDataStorageValues() {
    qt_config->beginGroup(QStringLiteral("Data Storage"));
    WriteSetting(QStringLiteral("use_virtual_sd"), Settings::values.use_virtual_sd, true);
    qt_config->endGroup();
}
