// Copyright 2019 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <QWidget>

namespace Ui {
class ConfigureEnhancements;
}

class ConfigureEnhancements : public QWidget {
    Q_OBJECT

public:
    explicit ConfigureEnhancements(QWidget* parent = nullptr);
    ~ConfigureEnhancements();

    void ApplyConfiguration();
    void SetConfiguration();

    void UpdateBackgroundColorButton(const QColor& color);

private:
    void updateShaders(bool anaglyph);

    Ui::ConfigureEnhancements* ui;
    QColor bg_color;
};
