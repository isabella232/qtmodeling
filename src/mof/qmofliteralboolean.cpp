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

#include "qmofliteralboolean.h"
#include "qmofliteralboolean_p.h"

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QMofLiteralBooleanPrivate::QMofLiteralBooleanPrivate() :
    value(false)
{
}

QMofLiteralBooleanPrivate::~QMofLiteralBooleanPrivate()
{
}

/*!
    \class QMofLiteralBoolean

    \inmodule QtMof

    \brief A literal Boolean is a specification of a Boolean value.
 */

QMofLiteralBoolean::QMofLiteralBoolean(QWrappedObject *wrapper, QWrappedObject *parent) :
    QMofLiteralSpecification(*new QMofLiteralBooleanPrivate, wrapper, parent)
{
    setPropertyData();
}

QMofLiteralBoolean::QMofLiteralBoolean(QMofLiteralBooleanPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QMofLiteralSpecification(dd, wrapper, parent)
{
    setPropertyData();
}

QMofLiteralBoolean::~QMofLiteralBoolean()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QMofLiteralBoolean
// ---------------------------------------------------------------

/*!
    The specified Boolean value.
 */
bool QMofLiteralBoolean::value() const
{
    // This is a read-write attribute

    Q_D(const QMofLiteralBoolean);
    return d->value;
}

void QMofLiteralBoolean::setValue(bool value)
{
    // This is a read-write attribute

    Q_D(QMofLiteralBoolean);
    if (d->value != value) {
        d->value = value;
    }
    d->modifiedResettableProperties << QString::fromLatin1("value");
}

void QMofLiteralBoolean::unsetValue()
{
    setValue(false);
    Q_D(QMofLiteralBoolean);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("value"));
}

/*!
    The query booleanValue() gives the value.
 */
bool QMofLiteralBoolean::booleanValue() const
{
    qWarning("QMofLiteralBoolean::booleanValue: operation to be implemented");

    return bool(); // change here to your derived return
}

/*!
    The query isComputable() is redefined to be true.
 */
bool QMofLiteralBoolean::isComputable() const
{
    qWarning("QMofLiteralBoolean::isComputable: operation to be implemented");

    return bool(); // change here to your derived return
}

void QMofLiteralBoolean::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralBoolean")][QString::fromLatin1("value")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralBoolean")][QString::fromLatin1("value")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralBoolean")][QString::fromLatin1("value")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The specified Boolean value.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralBoolean")][QString::fromLatin1("value")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralBoolean")][QString::fromLatin1("value")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralBoolean")][QString::fromLatin1("value")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QMofLiteralSpecification::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qmofliteralboolean.cpp"
