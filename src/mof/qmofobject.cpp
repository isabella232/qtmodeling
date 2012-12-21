/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtMof module of the Qt Toolkit.
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

#include "qmofobject.h"
#include "qmofobject_p.h"

#include <QtMof/QArgument>
#include <QtMof/QOperation>
#include <QtMof/QProperty>

QT_BEGIN_NAMESPACE_QTMOF

QMofObjectPrivate::QMofObjectPrivate()
{
}

QMofObjectPrivate::~QMofObjectPrivate()
{
}


QMofObject::QMofObject(QWrappedObject *parent, QWrappedObject *wrapper) :
    QWrappedObject(*new QMofObjectPrivate, parent, wrapper)
{
}

QMofObject::QMofObject(QMofObjectPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QWrappedObject(dd, parent, wrapper)
{
}

QMofObject::~QMofObject()
{
}

QMofObject *QMofObject::get(const QProperty *property) const
{
    qWarning("QMofObject::get: operation to be implemented");
    Q_UNUSED(property);

    return 0; // change here to your derived return
}

bool QMofObject::equals(const QMofObject *element) const
{
    qWarning("QMofObject::equals: operation to be implemented");
    Q_UNUSED(element);

    return bool(); // change here to your derived return
}

void QMofObject::set(const QProperty *property, const QMofObject *value)
{
    qWarning("QMofObject::set: operation to be implemented");
    Q_UNUSED(property);
    Q_UNUSED(value);
}

bool QMofObject::isSet(const QProperty *property) const
{
    qWarning("QMofObject::isSet: operation to be implemented");
    Q_UNUSED(property);

    return bool(); // change here to your derived return
}

void QMofObject::unset(const QProperty *property)
{
    qWarning("QMofObject::unset: operation to be implemented");
    Q_UNUSED(property);
}

QMofObject *QMofObject::invoke(const QOperation *op, const QSet<QArgument *> *arguments)
{
    qWarning("QMofObject::invoke: operation to be implemented");
    Q_UNUSED(op);
    Q_UNUSED(arguments);

    return 0; // change here to your derived return
}

void QMofObject::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTMOF(QMofObject) *>("QT_PREPEND_NAMESPACE_QTMOF(QMofObject) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTMOF(QMofObject) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTMOF(QMofObject) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTMOF(QMofObject) *> *>("const QList<QT_PREPEND_NAMESPACE_QTMOF(QMofObject) *> *");
    qRegisterMetaType<QMofObject *>("QMofObject *");
    qRegisterMetaType<const QSet<QMofObject *> *>("const QSet<QMofObject *> *");
    qRegisterMetaType<const QList<QMofObject *> *>("const QList<QMofObject *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTMOF(QArgument) *>("QT_PREPEND_NAMESPACE_QTMOF(QArgument) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTMOF(QArgument) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTMOF(QArgument) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTMOF(QArgument) *> *>("const QList<QT_PREPEND_NAMESPACE_QTMOF(QArgument) *> *");
    qRegisterMetaType<QArgument *>("QArgument *");
    qRegisterMetaType<const QSet<QArgument *> *>("const QSet<QArgument *> *");
    qRegisterMetaType<const QList<QArgument *> *>("const QList<QArgument *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTMOF(QOperation) *>("QT_PREPEND_NAMESPACE_QTMOF(QOperation) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTMOF(QOperation) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTMOF(QOperation) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTMOF(QOperation) *> *>("const QList<QT_PREPEND_NAMESPACE_QTMOF(QOperation) *> *");
    qRegisterMetaType<QOperation *>("QOperation *");
    qRegisterMetaType<const QSet<QOperation *> *>("const QSet<QOperation *> *");
    qRegisterMetaType<const QList<QOperation *> *>("const QList<QOperation *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTMOF(QProperty) *>("QT_PREPEND_NAMESPACE_QTMOF(QProperty) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTMOF(QProperty) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTMOF(QProperty) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTMOF(QProperty) *> *>("const QList<QT_PREPEND_NAMESPACE_QTMOF(QProperty) *> *");
    qRegisterMetaType<QProperty *>("QProperty *");
    qRegisterMetaType<const QSet<QProperty *> *>("const QSet<QProperty *> *");
    qRegisterMetaType<const QList<QProperty *> *>("const QList<QProperty *> *");

    QWrappedObject::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qmofobject.cpp"

QT_END_NAMESPACE_QTMOF
