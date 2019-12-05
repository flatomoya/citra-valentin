// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <QDialog>

class HotkeyRegistry;

namespace Ui {
class ConfigureDialog;
} // namespace Ui

class ConfigureDialog : public QDialog {
    Q_OBJECT

public:
    explicit ConfigureDialog(QWidget* parent, HotkeyRegistry& registry, const bool goto_web,
                             bool enable_web_config = true);
    ~ConfigureDialog() override;

    void ApplyConfiguration();

private:
    void SetConfiguration();
    void UpdateVisibleTabs();
    void PopulateSelectionList();

    std::unique_ptr<Ui::ConfigureDialog> ui;
    HotkeyRegistry& registry;
};
