// Copyright (c) 2017-2019 The cart developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZcartCONTROLDIALOG_H
#define ZcartCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zcart/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZcartControlDialog;
}

class CZcartControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZcartControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZcartControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZcartControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZcartControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZcartControlDialog(QWidget *parent);
    ~ZcartControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZcartControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZcartControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZcartCONTROLDIALOG_H
