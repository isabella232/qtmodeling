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

#include "qwritevariableaction.h"
#include "qwritevariableaction_p.h"

#include <QtUml/QInputPin>

QT_BEGIN_NAMESPACE_QTUML

QWriteVariableActionPrivate::QWriteVariableActionPrivate() :
    value(0)
{
}

QWriteVariableActionPrivate::~QWriteVariableActionPrivate()
{
}

/*!
    \class QWriteVariableAction

    \inmodule QtUml

    \brief WriteVariableAction is an abstract class for variable actions that change variable values.
 */

QWriteVariableAction::QWriteVariableAction(QUmlObject *parent, QUmlObject *wrapper) :
    QVariableAction(*new QWriteVariableActionPrivate, parent, wrapper)
{
}

QWriteVariableAction::QWriteVariableAction(QWriteVariableActionPrivate &dd, QUmlObject *parent, QUmlObject *wrapper) :
    QVariableAction(dd, parent, wrapper)
{
}

QWriteVariableAction::~QWriteVariableAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QWriteVariableAction
// ---------------------------------------------------------------

/*!
    Value to be added or removed from the variable.
 */
QInputPin *QWriteVariableAction::value() const
{
    // This is a read-write association end

    Q_D(const QWriteVariableAction);
    return d->value;
}

void QWriteVariableAction::setValue(QInputPin *value)
{
    // This is a read-write association end

    Q_D(QWriteVariableAction);
    if (d->value != value) {
        // Adjust subsetted property(ies)
        (qumlobject_cast<QActionPrivate *>(d))->removeInput(qumlobject_cast<QInputPin *>(d->value));

        d->value = value;

        // Adjust subsetted property(ies)
        if (value) {
            (qumlobject_cast<QActionPrivate *>(d))->addInput(qumlobject_cast<QInputPin *>(value));
        }
    }
}

#include "moc_qwritevariableaction.cpp"

QT_END_NAMESPACE_QTUML

