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

#include "qumlactioninputpin.h"
#include "qumlactioninputpin_p.h"

#include <QtUml/QUmlAction>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlActionInputPinPrivate::QUmlActionInputPinPrivate() :
    fromAction(0)
{
}

QUmlActionInputPinPrivate::~QUmlActionInputPinPrivate()
{
}

/*!
    \class QUmlActionInputPin

    \inmodule QtUml

    \brief An action input pin is a kind of pin that executes an action to determine the values to input to another.
 */

QUmlActionInputPin::QUmlActionInputPin(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlInputPin(*new QUmlActionInputPinPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlActionInputPin::QUmlActionInputPin(QUmlActionInputPinPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlInputPin(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlActionInputPin::~QUmlActionInputPin()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QUmlActionInputPin
// ---------------------------------------------------------------

/*!
    The action used to provide values.
 */
QUmlAction *QUmlActionInputPin::fromAction() const
{
    // This is a read-write association end

    Q_D(const QUmlActionInputPin);
    return d->fromAction;
}

void QUmlActionInputPin::setFromAction(QUmlAction *fromAction)
{
    // This is a read-write association end

    Q_D(QUmlActionInputPin);
    if (d->fromAction != fromAction) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QUmlElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QUmlElement *>(d->fromAction));

        d->fromAction = fromAction;

        // Adjust subsetted property(ies)
        if (fromAction) {
            (qwrappedobject_cast<QUmlElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QUmlElement *>(fromAction));
        }
    }
}

void QUmlActionInputPin::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlActionInputPin")][QString::fromLatin1("fromAction")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlActionInputPin")][QString::fromLatin1("fromAction")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlActionInputPin")][QString::fromLatin1("fromAction")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The action used to provide values.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlActionInputPin")][QString::fromLatin1("fromAction")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlActionInputPin")][QString::fromLatin1("fromAction")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QUmlElement::ownedElements");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlActionInputPin")][QString::fromLatin1("fromAction")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QUmlInputPin::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumlactioninputpin.cpp"
