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

#include "qcallaction.h"
#include "qcallaction_p.h"

#include <QtUml/QOutputPin>

QT_BEGIN_NAMESPACE_QTUML

QCallActionPrivate::QCallActionPrivate() :
    isSynchronous(true),
    results(new QList<QOutputPin *>)
{
}

QCallActionPrivate::~QCallActionPrivate()
{
    delete results;
}

/*!
    \class QCallAction

    \inmodule QtUml

    \brief CallAction is an abstract class for actions that invoke behavior and receive return values.
 */

QCallAction::QCallAction(QWrappedObject *parent, QWrappedObject *wrapper) :
    QInvocationAction(*new QCallActionPrivate, parent, wrapper)
{
}

QCallAction::QCallAction(QCallActionPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QInvocationAction(dd, parent, wrapper)
{
}

QCallAction::~QCallAction()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QCallAction
// ---------------------------------------------------------------

/*!
    If true, the call is synchronous and the caller waits for completion of the invoked behavior. If false, the call is asynchronous and the caller proceeds immediately and does not expect a return values.
 */
bool QCallAction::isSynchronous() const
{
    // This is a read-write attribute

    Q_D(const QCallAction);
    return d->isSynchronous;
}

void QCallAction::setSynchronous(bool isSynchronous)
{
    // This is a read-write attribute

    Q_D(QCallAction);
    if (d->isSynchronous != isSynchronous) {
        d->isSynchronous = isSynchronous;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QCallAction
// ---------------------------------------------------------------

/*!
    A list of output pins where the results of performing the invocation are placed.
 */
const QList<QOutputPin *> *QCallAction::results() const
{
    // This is a read-write association end

    Q_D(const QCallAction);
    return d->results;
}

void QCallAction::addResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QCallAction);
    if (!d->results->contains(result)) {
        d->results->append(result);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->addOutput(qwrappedobject_cast<QOutputPin *>(result));
    }
}

void QCallAction::removeResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QCallAction);
    if (d->results->contains(result)) {
        d->results->removeAll(result);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeOutput(qwrappedobject_cast<QOutputPin *>(result));
    }
}

void QCallAction::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QCallAction) *>("QT_PREPEND_NAMESPACE_QTUML(QCallAction) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QCallAction) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QCallAction) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QCallAction) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QCallAction) *> *");
    qRegisterMetaType<QCallAction *>("QCallAction *");
    qRegisterMetaType<const QSet<QCallAction *> *>("const QSet<QCallAction *> *");
    qRegisterMetaType<const QList<QCallAction *> *>("const QList<QCallAction *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QOutputPin) *>("QT_PREPEND_NAMESPACE_QTUML(QOutputPin) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QOutputPin) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QOutputPin) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QOutputPin) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QOutputPin) *> *");
    qRegisterMetaType<QOutputPin *>("QOutputPin *");
    qRegisterMetaType<const QSet<QOutputPin *> *>("const QSet<QOutputPin *> *");
    qRegisterMetaType<const QList<QOutputPin *> *>("const QList<QOutputPin *> *");


    QInvocationAction::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qcallaction.cpp"

QT_END_NAMESPACE_QTUML

