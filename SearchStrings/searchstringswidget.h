// copyright (c) 2019-2020 hors<horsicq@gmail.com>
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
#ifndef SEARCHSTRINGSWIDGET_H
#define SEARCHSTRINGSWIDGET_H

#include <QWidget>
#include <QFile>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QFileDialog>
#include <QMenu>
#include <QApplication>
#include <QClipboard>
#include <QFutureWatcher>
#include <QtConcurrent>
#include "dialogsearchstringsprocess.h"

namespace Ui
{
class SearchStringsWidget;
}

class SearchStringsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchStringsWidget(QWidget *pParent=nullptr);
    ~SearchStringsWidget();
    void setData(QIODevice *pDevice, SearchStrings::OPTIONS *pOptions, bool bAuto=false);
    void reload();
    bool getInitStatus();

private slots:
    void on_pushButtonSave_clicked();
    void on_pushButtonSearch_clicked();
    void on_lineEditFilter_textChanged(const QString &sText);
    void filter(QString sString);
    void on_tableViewResult_customContextMenuRequested(const QPoint &pos);
    void _copyString();
    void _copyAddress();
    void _copySize();
    void search();
    void deleteOldModel();

private:
    Ui::SearchStringsWidget *ui;
    QIODevice *pDevice;
    QSortFilterProxyModel *pFilter;
    SearchStrings::OPTIONS options;
    QStandardItemModel *pModel;
    bool bInit;
    QStandardItemModel *pOldModel;
    QFutureWatcher<void> watcher;
};

#endif // SEARCHSTRINGSWIDGET_H
