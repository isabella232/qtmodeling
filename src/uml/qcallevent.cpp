/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qcallevent.h"
#include "qcallevent_p.h"

#include <QtUml/QOperation>

QT_BEGIN_NAMESPACE_QTUML

QCallEventPrivate::QCallEventPrivate() :
    operation(0)
{
}

QCallEventPrivate::~QCallEventPrivate()
{
}

/*!
    \class QCallEvent

    \inmodule QtUml

    \brief A call event models the receipt by an object of a message invoking a call of an operation.
 */

QCallEvent::QCallEvent(QWrappedObject *parent, QWrappedObject *wrapper) :
    QMessageEvent(*new QCallEventPrivate, parent, wrapper)
{
}

QCallEvent::QCallEvent(QCallEventPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QMessageEvent(dd, parent, wrapper)
{
}

QCallEvent::~QCallEvent()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QCallEvent
// ---------------------------------------------------------------

/*!
    Designates the operation whose invocation raised the call event.
 */
QOperation *QCallEvent::operation() const
{
    // This is a read-write association end

    Q_D(const QCallEvent);
    return d->operation;
}

void QCallEvent::setOperation(QOperation *operation)
{
    // This is a read-write association end

    Q_D(QCallEvent);
    if (d->operation != operation) {
        d->operation = operation;
    }
}

void QCallEvent::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QCallEvent) *>("QT_PREPEND_NAMESPACE_QTUML(QCallEvent) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QCallEvent) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QCallEvent) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QCallEvent) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QCallEvent) *> *");
    qRegisterMetaType<QCallEvent *>("QCallEvent *");
    qRegisterMetaType<const QSet<QCallEvent *> *>("const QSet<QCallEvent *> *");
    qRegisterMetaType<const QList<QCallEvent *> *>("const QList<QCallEvent *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QOperation) *>("QT_PREPEND_NAMESPACE_QTUML(QOperation) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QOperation) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QOperation) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QOperation) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QOperation) *> *");
    qRegisterMetaType<QOperation *>("QOperation *");
    qRegisterMetaType<const QSet<QOperation *> *>("const QSet<QOperation *> *");
    qRegisterMetaType<const QList<QOperation *> *>("const QList<QOperation *> *");


    QMessageEvent::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qcallevent.cpp"

QT_END_NAMESPACE_QTUML

