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

#include "qumlreadlinkobjectendaction.h"
#include "qumlreadlinkobjectendaction_p.h"

#include <QtUml/QUmlProperty>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlOutputPin>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlReadLinkObjectEndActionPrivate::QUmlReadLinkObjectEndActionPrivate() :
    end(0),
    object(0),
    result(0)
{
}

QUmlReadLinkObjectEndActionPrivate::~QUmlReadLinkObjectEndActionPrivate()
{
}

/*!
    \class QUmlReadLinkObjectEndAction

    \inmodule QtUml

    \brief A read link object end action is an action that retrieves an end object from a link object.
 */

QUmlReadLinkObjectEndAction::QUmlReadLinkObjectEndAction(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlAction(*new QUmlReadLinkObjectEndActionPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlReadLinkObjectEndAction::QUmlReadLinkObjectEndAction(QUmlReadLinkObjectEndActionPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlAction(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlReadLinkObjectEndAction::~QUmlReadLinkObjectEndAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QUmlReadLinkObjectEndAction
// ---------------------------------------------------------------

/*!
    Link end to be read.
 */
QUmlProperty *QUmlReadLinkObjectEndAction::end() const
{
    // This is a read-write association end

    Q_D(const QUmlReadLinkObjectEndAction);
    return d->end;
}

void QUmlReadLinkObjectEndAction::setEnd(QUmlProperty *end)
{
    // This is a read-write association end

    Q_D(QUmlReadLinkObjectEndAction);
    if (d->end != end) {
        d->end = end;
    }
}

/*!
    Gives the input pin from which the link object is obtained.
 */
QUmlInputPin *QUmlReadLinkObjectEndAction::object() const
{
    // This is a read-write association end

    Q_D(const QUmlReadLinkObjectEndAction);
    return d->object;
}

void QUmlReadLinkObjectEndAction::setObject(QUmlInputPin *object)
{
    // This is a read-write association end

    Q_D(QUmlReadLinkObjectEndAction);
    if (d->object != object) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QUmlActionPrivate *>(d))->removeInput(qwrappedobject_cast<QUmlInputPin *>(d->object));

        d->object = object;

        // Adjust subsetted property(ies)
        if (object) {
            (qwrappedobject_cast<QUmlActionPrivate *>(d))->addInput(qwrappedobject_cast<QUmlInputPin *>(object));
        }
    }
}

/*!
    Pin where the result value is placed.
 */
QUmlOutputPin *QUmlReadLinkObjectEndAction::result() const
{
    // This is a read-write association end

    Q_D(const QUmlReadLinkObjectEndAction);
    return d->result;
}

void QUmlReadLinkObjectEndAction::setResult(QUmlOutputPin *result)
{
    // This is a read-write association end

    Q_D(QUmlReadLinkObjectEndAction);
    if (d->result != result) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QUmlActionPrivate *>(d))->removeOutput(qwrappedobject_cast<QUmlOutputPin *>(d->result));

        d->result = result;

        // Adjust subsetted property(ies)
        if (result) {
            (qwrappedobject_cast<QUmlActionPrivate *>(d))->addOutput(qwrappedobject_cast<QUmlOutputPin *>(result));
        }
    }
}

void QUmlReadLinkObjectEndAction::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("end")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("end")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("end")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Link end to be read.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("end")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("end")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("end")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("object")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("object")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("object")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Gives the input pin from which the link object is obtained.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("object")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("object")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QUmlAction::inputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("object")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("result")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("result")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("result")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Pin where the result value is placed.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("result")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("result")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QUmlAction::outputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlReadLinkObjectEndAction")][QString::fromLatin1("result")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QUmlAction::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumlreadlinkobjectendaction.cpp"
