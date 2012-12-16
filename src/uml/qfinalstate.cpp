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

#include "qfinalstate.h"
#include "qfinalstate_p.h"

QT_BEGIN_NAMESPACE_QTUML

QFinalStatePrivate::QFinalStatePrivate()
{
}

QFinalStatePrivate::~QFinalStatePrivate()
{
}

/*!
    \class QFinalState

    \inmodule QtUml

    \brief A special kind of state signifying that the enclosing region is completed. If the enclosing region is directly contained in a state machine and all other regions in the state machine also are completed, then it means that the entire state machine is completed.
 */

QFinalState::QFinalState(QWrappedObject *parent, QWrappedObject *wrapper) :
    QState(*new QFinalStatePrivate, parent, wrapper)
{
}

QFinalState::QFinalState(QFinalStatePrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QState(dd, parent, wrapper)
{
}

QFinalState::~QFinalState()
{
}

void QFinalState::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QFinalState) *>("QT_PREPEND_NAMESPACE_QTUML(QFinalState) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QFinalState) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QFinalState) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QFinalState) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QFinalState) *> *");
    qRegisterMetaType<QFinalState *>("QFinalState *");
    qRegisterMetaType<const QSet<QFinalState *> *>("const QSet<QFinalState *> *");
    qRegisterMetaType<const QList<QFinalState *> *>("const QList<QFinalState *> *");


    QState::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qfinalstate.cpp"

QT_END_NAMESPACE_QTUML

