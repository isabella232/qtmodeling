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

#include "qumltimeconstraint.h"
#include "qumltimeconstraint_p.h"

#include <QtUml/QUmlTimeInterval>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlTimeConstraintPrivate::QUmlTimeConstraintPrivate() :
    firstEvent(true),
    specification(0)
{
}

QUmlTimeConstraintPrivate::~QUmlTimeConstraintPrivate()
{
}

/*!
    \class QUmlTimeConstraint

    \inmodule QtUml

    \brief A time constraint is a constraint that refers to a time interval.
 */

QUmlTimeConstraint::QUmlTimeConstraint(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlIntervalConstraint(*new QUmlTimeConstraintPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlTimeConstraint::QUmlTimeConstraint(QUmlTimeConstraintPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlIntervalConstraint(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlTimeConstraint::~QUmlTimeConstraint()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QUmlTimeConstraint
// ---------------------------------------------------------------

/*!
    The value of firstEvent is related to constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within constrainedElement.
 */
bool QUmlTimeConstraint::firstEvent() const
{
    // This is a read-write attribute

    Q_D(const QUmlTimeConstraint);
    return d->firstEvent;
}

void QUmlTimeConstraint::setFirstEvent(bool firstEvent)
{
    // This is a read-write attribute

    Q_D(QUmlTimeConstraint);
    if (d->firstEvent != firstEvent) {
        d->firstEvent = firstEvent;
    }
    d->modifiedResettableProperties << QString::fromLatin1("firstEvent");
}

void QUmlTimeConstraint::unsetFirstEvent()
{
    setFirstEvent(true);
    Q_D(QUmlTimeConstraint);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("firstEvent"));
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QUmlTimeConstraint
// ---------------------------------------------------------------

/*!
    A condition that must be true when evaluated in order for the constraint to be satisfied.
 */
QUmlTimeInterval *QUmlTimeConstraint::specification() const
{
    // This is a read-write association end

    Q_D(const QUmlTimeConstraint);
    return d->specification;
}

void QUmlTimeConstraint::setSpecification(QUmlTimeInterval *specification)
{
    // This is a read-write association end

    Q_D(QUmlTimeConstraint);
    if (d->specification != specification) {
        if (d->specification)
            qTopLevelWrapper(d->specification)->setParent(0);
        d->specification = specification;
        qTopLevelWrapper(specification)->setParent(qTopLevelWrapper(this));

        // Adjust redefined property(ies)
        (qwrappedobject_cast<QUmlIntervalConstraint *>(this))->setSpecification(qwrappedobject_cast<QUmlInterval *>(specification));
    }
}

void QUmlTimeConstraint::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("firstEvent")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("firstEvent")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("firstEvent")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The value of firstEvent is related to constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within constrainedElement.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("firstEvent")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("firstEvent")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("firstEvent")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("specification")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("specification")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("specification")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("A condition that must be true when evaluated in order for the constraint to be satisfied.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("specification")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("QUmlIntervalConstraint::specification");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("specification")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlTimeConstraint")][QString::fromLatin1("specification")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QUmlIntervalConstraint::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumltimeconstraint.cpp"
