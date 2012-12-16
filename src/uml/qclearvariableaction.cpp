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

#include "qclearvariableaction.h"
#include "qclearvariableaction_p.h"

QT_BEGIN_NAMESPACE_QTUML

QClearVariableActionPrivate::QClearVariableActionPrivate()
{
}

QClearVariableActionPrivate::~QClearVariableActionPrivate()
{
}

/*!
    \class QClearVariableAction

    \inmodule QtUml

    \brief A clear variable action is a variable action that removes all values of a variable.
 */

QClearVariableAction::QClearVariableAction(QWrappedObject *parent, QWrappedObject *wrapper) :
    QVariableAction(*new QClearVariableActionPrivate, parent, wrapper)
{
}

QClearVariableAction::QClearVariableAction(QClearVariableActionPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QVariableAction(dd, parent, wrapper)
{
}

QClearVariableAction::~QClearVariableAction()
{
}

void QClearVariableAction::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QClearVariableAction) *>("QT_PREPEND_NAMESPACE_QTUML(QClearVariableAction) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QClearVariableAction) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QClearVariableAction) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QClearVariableAction) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QClearVariableAction) *> *");
    qRegisterMetaType<QClearVariableAction *>("QClearVariableAction *");
    qRegisterMetaType<const QSet<QClearVariableAction *> *>("const QSet<QClearVariableAction *> *");
    qRegisterMetaType<const QList<QClearVariableAction *> *>("const QList<QClearVariableAction *> *");


    QVariableAction::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qclearvariableaction.cpp"

QT_END_NAMESPACE_QTUML

