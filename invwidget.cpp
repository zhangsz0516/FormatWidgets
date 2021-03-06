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
#include "invwidget.h"

InvWidget::InvWidget(QWidget *pParent, TYPE type) :
    QWidget(pParent)
{
    pHexPushButton=0;

    QHBoxLayout *pLayot=new QHBoxLayout(this);
    pLayot->setContentsMargins(0,0,0,0);

    if(type==TYPE_HEX)
    {
        pHexPushButton=new QPushButton(QString("Hex"),this);

        connect(pHexPushButton,SIGNAL(clicked()),this,SLOT(showHexSlot()));

        pLayot->addWidget(pHexPushButton);
    }

    setLayout(pLayot);

    nOffset=0;
    nSize=0;
}

InvWidget::~InvWidget()
{

}

void InvWidget::setOffsetAndSize(XBinary *pBinary, qint64 nOffset, qint64 nSize)
{
    if(pBinary->isAddressPhysical(nOffset))
    {
        _setEnabled(true);

        this->nOffset=nOffset;
        this->nSize=nSize;
    }
    else
    {
        _setEnabled(false);

        this->nOffset=0;
        this->nSize=0;
    }
}

void InvWidget::setAddressAndSize(XBinary *pBinary, qint64 nAddress, qint64 nSize)
{
    XBinary::_MEMORY_MAP memoryMap=pBinary->getMemoryMap();

    if(pBinary->isAddressPhysical(&memoryMap,nAddress))
    {
        _setEnabled(true);

        this->nOffset=pBinary->addressToOffset(&memoryMap,nAddress);
        this->nSize=nSize;
    }
    else
    {
        _setEnabled(false);

        this->nOffset=0;
        this->nSize=0;
    }
}

void InvWidget::_setEnabled(bool bState)
{
    if(pHexPushButton)
    {
        pHexPushButton->setEnabled(bState);
    }
}

void InvWidget::showHexSlot()
{
    emit showHex(nOffset,nSize);
}
