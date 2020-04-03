// copyright (c) 2017-2020 hors<horsicq@gmail.com>
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
#include "relocsheaderwidget.h"
#include "ui_relocsheaderwidget.h"

RelocsHeaderWidget::RelocsHeaderWidget(QWidget *parent):
    FormatWidget(parent),
    ui(new Ui::RelocsHeaderWidget)
{
    ui->setupUi(this);
}

RelocsHeaderWidget::RelocsHeaderWidget(QIODevice *pDevice, FW_DEF::OPTIONS *pOptions, quint32 nNumber, qint64 nOffset, QWidget *parent)
{

}

RelocsHeaderWidget::~RelocsHeaderWidget()
{
    delete ui;
}

void RelocsHeaderWidget::clear()
{

}

void RelocsHeaderWidget::setData(QIODevice *pDevice, FW_DEF::OPTIONS *pOptions, quint32 nNumber, qint64 nOffset)
{
    FormatWidget::setData(pDevice,pOptions,nNumber,nOffset);
}

void RelocsHeaderWidget::reload()
{

}

bool RelocsHeaderWidget::_setValue(QVariant vValue, int nStype, int nNdata, int nVtype, int nPosition, qint64 nOffset)
{
    Q_UNUSED(nVtype)
    Q_UNUSED(nOffset)

    bool bResult=false;

    quint64 nValue=vValue.toULongLong();
    QString sValue=vValue.toString();

    if(getDevice()->isWritable())
    {
        XPE pe(getDevice(),getOptions()->bIsImage,getOptions()->nImageBase);

        if(pe.isValid())
        {
            bResult=true;
        }
    }

    return bResult;
}

void RelocsHeaderWidget::setReadonly(bool bState)
{

}

void RelocsHeaderWidget::blockSignals(bool bState)
{

}

void RelocsHeaderWidget::adjustHeaderTable(int type, QTableWidget *pTableWidget)
{

}

void RelocsHeaderWidget::on_checkBoxReadonly_toggled(bool checked)
{

}

void RelocsHeaderWidget::reloadData()
{

}

void RelocsHeaderWidget::widgetValueChanged(quint64 nValue)
{

}

void RelocsHeaderWidget::on_tableWidget_RELOCS_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{

}
