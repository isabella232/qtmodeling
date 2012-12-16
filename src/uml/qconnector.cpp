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

#include "qconnector.h"
#include "qconnector_p.h"

#include <QtUml/QAssociation>
#include <QtUml/QBehavior>
#include <QtUml/QConnectorEnd>

QT_BEGIN_NAMESPACE_QTUML

QConnectorPrivate::QConnectorPrivate() :
    redefinedConnectors(new QSet<QConnector *>),
    contracts(new QSet<QBehavior *>),
    type(0),
    ends(new QList<QConnectorEnd *>)
{
}

QConnectorPrivate::~QConnectorPrivate()
{
    delete redefinedConnectors;
    delete contracts;
    delete ends;
}

/*!
    \class QConnector

    \inmodule QtUml

    \brief A delegation connector is a connector that links the external contract of a component (as specified by its ports) to the realization of that behavior. It represents the forwarding of events (operation requests and events): a signal that arrives at a port that has a delegation connector to one or more parts or ports on parts will be passed on to those targets for handling. An assembly connector is a connector between two or more parts or ports on parts that defines that one or more parts provide the services that other parts use.Specifies a link that enables communication between two or more instances. This link may be an instance of an association, or it may represent the possibility of the instances being able to communicate because their identities are known by virtue of being passed in as parameters, held in variables or slots, or because the communicating instances are the same instance. The link may be realized by something as simple as a pointer or by something as complex as a network connection. In contrast to associations, which specify links between any instance of the associated classifiers, connectors specify links between instances playing the connected parts only.
 */

QConnector::QConnector(QWrappedObject *parent, QWrappedObject *wrapper) :
    QFeature(*new QConnectorPrivate, parent, wrapper)
{
}

QConnector::QConnector(QConnectorPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QFeature(dd, parent, wrapper)
{
}

QConnector::~QConnector()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QConnector
// ---------------------------------------------------------------

/*!
    Indicates the kind of connector. This is derived: a connector with one or more ends connected to a Port which is not on a Part and which is not a behavior port is a delegation; otherwise it is an assembly.
 */
QtUml::ConnectorKind QConnector::kind() const
{
    // This is a read-only derived attribute

    qWarning("QConnector::kind: to be implemented (this is a derived attribute)");

    return QtUml::ConnectorKind(); // change here to your derived return
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QConnector
// ---------------------------------------------------------------

/*!
    A connector may be redefined when its containing classifier is specialized. The redefining connector may have a type that specializes the type of the redefined connector. The types of the connector ends of the redefining connector may specialize the types of the connector ends of the redefined connector. The properties of the connector ends of the redefining connector may be replaced.
 */
const QSet<QConnector *> *QConnector::redefinedConnectors() const
{
    // This is a read-write association end

    Q_D(const QConnector);
    return d->redefinedConnectors;
}

void QConnector::addRedefinedConnector(QConnector *redefinedConnector)
{
    // This is a read-write association end

    Q_D(QConnector);
    if (!d->redefinedConnectors->contains(redefinedConnector)) {
        d->redefinedConnectors->insert(redefinedConnector);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QRedefinableElementPrivate *>(d))->addRedefinedElement(qwrappedobject_cast<QRedefinableElement *>(redefinedConnector));
    }
}

void QConnector::removeRedefinedConnector(QConnector *redefinedConnector)
{
    // This is a read-write association end

    Q_D(QConnector);
    if (d->redefinedConnectors->contains(redefinedConnector)) {
        d->redefinedConnectors->remove(redefinedConnector);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QRedefinableElementPrivate *>(d))->removeRedefinedElement(qwrappedobject_cast<QRedefinableElement *>(redefinedConnector));
    }
}

/*!
    The set of Behaviors that specify the valid interaction patterns across the connector.
 */
const QSet<QBehavior *> *QConnector::contracts() const
{
    // This is a read-write association end

    Q_D(const QConnector);
    return d->contracts;
}

void QConnector::addContract(QBehavior *contract)
{
    // This is a read-write association end

    Q_D(QConnector);
    if (!d->contracts->contains(contract)) {
        d->contracts->insert(contract);
    }
}

void QConnector::removeContract(QBehavior *contract)
{
    // This is a read-write association end

    Q_D(QConnector);
    if (d->contracts->contains(contract)) {
        d->contracts->remove(contract);
    }
}

/*!
    An optional association that specifies the link corresponding to this connector.
 */
QAssociation *QConnector::type() const
{
    // This is a read-write association end

    Q_D(const QConnector);
    return d->type;
}

void QConnector::setType(QAssociation *type)
{
    // This is a read-write association end

    Q_D(QConnector);
    if (d->type != type) {
        d->type = type;
    }
}

/*!
    A connector consists of at least two connector ends, each representing the participation of instances of the classifiers typing the connectable elements attached to this end. The set of connector ends is ordered.
 */
const QList<QConnectorEnd *> *QConnector::ends() const
{
    // This is a read-write association end

    Q_D(const QConnector);
    return d->ends;
}

void QConnector::addEnd(QConnectorEnd *end)
{
    // This is a read-write association end

    Q_D(QConnector);
    if (!d->ends->contains(end)) {
        d->ends->append(end);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(end));
    }
}

void QConnector::removeEnd(QConnectorEnd *end)
{
    // This is a read-write association end

    Q_D(QConnector);
    if (d->ends->contains(end)) {
        d->ends->removeAll(end);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(end));
    }
}

void QConnector::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QConnector) *>("QT_PREPEND_NAMESPACE_QTUML(QConnector) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnector) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnector) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QConnector) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QConnector) *> *");
    qRegisterMetaType<QConnector *>("QConnector *");
    qRegisterMetaType<const QSet<QConnector *> *>("const QSet<QConnector *> *");
    qRegisterMetaType<const QList<QConnector *> *>("const QList<QConnector *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *>("QT_PREPEND_NAMESPACE_QTUML(QAssociation) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *");
    qRegisterMetaType<QAssociation *>("QAssociation *");
    qRegisterMetaType<const QSet<QAssociation *> *>("const QSet<QAssociation *> *");
    qRegisterMetaType<const QList<QAssociation *> *>("const QList<QAssociation *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *>("QT_PREPEND_NAMESPACE_QTUML(QBehavior) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QBehavior) *> *");
    qRegisterMetaType<QBehavior *>("QBehavior *");
    qRegisterMetaType<const QSet<QBehavior *> *>("const QSet<QBehavior *> *");
    qRegisterMetaType<const QList<QBehavior *> *>("const QList<QBehavior *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *>("QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *");
    qRegisterMetaType<QConnectorEnd *>("QConnectorEnd *");
    qRegisterMetaType<const QSet<QConnectorEnd *> *>("const QSet<QConnectorEnd *> *");
    qRegisterMetaType<const QList<QConnectorEnd *> *>("const QList<QConnectorEnd *> *");


    QFeature::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qconnector.cpp"

QT_END_NAMESPACE_QTUML

