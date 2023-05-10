// Copyright (c) 2019 The cart developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLcartWIDGET_H
#define COINCONTROLcartWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlcartWidget;
}

class CoinControlcartWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlcartWidget(QWidget *parent = nullptr);
    ~CoinControlcartWidget();

private:
    Ui::CoinControlcartWidget *ui;
};

#endif // COINCONTROLcartWIDGET_H
