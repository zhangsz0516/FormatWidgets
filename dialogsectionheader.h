#ifndef DIALOGSECTIONHEADER_H
#define DIALOGSECTIONHEADER_H

#include <QDialog>
#include "formatwidget.h"

namespace Ui
{
class DialogSectionHeader;
}

class DialogSectionHeader : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSectionHeader(FormatWidget *pWidget,QWidget *parent);
    ~DialogSectionHeader();
    void setData(QIODevice *pDevice, FW_DEF::OPTIONS *pOptions, quint32 nNumber,QString sTitle);
    void setEdited(bool bState);

signals:
    void editState(bool bState);

private:
    Ui::DialogSectionHeader *ui;
    FormatWidget *pWidget;
};

#endif // DIALOGSECTIONHEADER_H