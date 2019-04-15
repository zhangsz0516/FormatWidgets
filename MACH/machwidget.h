// copyright (c) 2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef MACHWIDGET_H
#define MACHWIDGET_H

#include "../formatwidget.h"
#include "mach_defs.h"

namespace Ui {
class MACHWidget;
}

class MACHWidget : public FormatWidget
{
    Q_OBJECT

public:
    MACHWidget(QWidget *parent = nullptr);
    MACHWidget(QIODevice *pDevice, OPTIONS *pOptions, QWidget *parent = nullptr);
    ~MACHWidget();
    virtual void setData(QIODevice *pDevice,OPTIONS *pOptions);
protected:
    virtual bool _setValue(QVariant vValue,int nStype,int nNdata,int nVtype,int nPosition);
    virtual void setReadonly(bool bState);
    virtual void blockSignals(bool bState);
    virtual void adjustHeaderTable(int type,QTableWidget *pTableWidget);
private slots:
    virtual void reloadData();
    void widgetValueChanged(quint64 nValue);
    void on_treeWidgetNavi_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void on_checkBoxReadonly_toggled(bool checked);
private:
    enum CB
    {
        CB_mach_header_magic=0,
        __CB_size
    };

    Ui::MACHWidget *ui;

    XLineEditHEX *lineEdit_mach_header[N_mach_header::__data_size];
    XComboBoxEx *comboBox[__CB_size];

    bool bInit[SMACH::__TYPE_size];
};

#endif // MACHWIDGET_H