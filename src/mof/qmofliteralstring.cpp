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

#include "qmofliteralstring.h"
#include "qmofliteralstring_p.h"

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QMofLiteralStringPrivate::QMofLiteralStringPrivate()
{
}

QMofLiteralStringPrivate::~QMofLiteralStringPrivate()
{
}

/*!
    \class QMofLiteralString

    \inmodule QtMof

    \brief A literal string is a specification of a string value.
 */

QMofLiteralString::QMofLiteralString(QWrappedObject *wrapper, QWrappedObject *parent) :
    QMofLiteralSpecification(*new QMofLiteralStringPrivate, wrapper, parent)
{
    setPropertyData();
}

QMofLiteralString::QMofLiteralString(QMofLiteralStringPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QMofLiteralSpecification(dd, wrapper, parent)
{
    setPropertyData();
}

QMofLiteralString::~QMofLiteralString()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QMofLiteralString
// ---------------------------------------------------------------

/*!
    The specified String value.
 */
QString QMofLiteralString::value() const
{
    // This is a read-write attribute

    Q_D(const QMofLiteralString);
    return d->value;
}

void QMofLiteralString::setValue(QString value)
{
    // This is a read-write attribute

    Q_D(QMofLiteralString);
    if (d->value != value) {
        d->value = value;
    }
}

/*!
    The query isComputable() is redefined to be true.
 */
bool QMofLiteralString::isComputable() const
{
    qWarning("QMofLiteralString::isComputable: operation to be implemented");

    return bool(); // change here to your derived return
}

/*!
    The query stringValue() gives the value.
 */
QString QMofLiteralString::stringValue() const
{
    qWarning("QMofLiteralString::stringValue: operation to be implemented");

    return QString(); // change here to your derived return
}

void QMofLiteralString::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralString")][QString::fromLatin1("value")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralString")][QString::fromLatin1("value")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralString")][QString::fromLatin1("value")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The specified String value.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralString")][QString::fromLatin1("value")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralString")][QString::fromLatin1("value")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofLiteralString")][QString::fromLatin1("value")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QMofLiteralSpecification::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qmofliteralstring.cpp"
