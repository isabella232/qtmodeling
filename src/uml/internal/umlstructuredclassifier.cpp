/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "umlstructuredclassifier_p.h"

#include "private/umlconnectableelement_p.h"
#include "private/umlconnector_p.h"
#include "private/umlproperty_p.h"

/*!
    \class UmlStructuredClassifier

    \inmodule QtUml

    \brief A structured classifier is an abstract metaclass that represents any classifier whose behavior can be fully or partly described by the collaboration of owned or referenced instances.
 */

UmlStructuredClassifier::UmlStructuredClassifier()
{
}

// OWNED ATTRIBUTES

/*!
    References the properties owned by the classifier.
 */
const QList<UmlProperty *> UmlStructuredClassifier::ownedAttribute() const
{
    // This is a read-write association end

    return _ownedAttribute;
}

void UmlStructuredClassifier::addOwnedAttribute(UmlProperty *ownedAttribute)
{
    // This is a read-write association end

    if (!_ownedAttribute.contains(ownedAttribute)) {
        _ownedAttribute.append(ownedAttribute);

        // Adjust subsetted properties
        addAttribute(ownedAttribute);
        addOwnedMember(ownedAttribute);
        addRole(ownedAttribute);
    }
}

void UmlStructuredClassifier::removeOwnedAttribute(UmlProperty *ownedAttribute)
{
    // This is a read-write association end

    if (_ownedAttribute.contains(ownedAttribute)) {
        _ownedAttribute.removeAll(ownedAttribute);

        // Adjust subsetted properties
        removeAttribute(ownedAttribute);
        removeOwnedMember(ownedAttribute);
        removeRole(ownedAttribute);
    }
}

/*!
    References the connectors owned by the classifier.
 */
const QSet<UmlConnector *> UmlStructuredClassifier::ownedConnector() const
{
    // This is a read-write association end

    return _ownedConnector;
}

void UmlStructuredClassifier::addOwnedConnector(UmlConnector *ownedConnector)
{
    // This is a read-write association end

    if (!_ownedConnector.contains(ownedConnector)) {
        _ownedConnector.insert(ownedConnector);

        // Adjust subsetted properties
        addFeature(ownedConnector);
        addOwnedMember(ownedConnector);
    }
}

void UmlStructuredClassifier::removeOwnedConnector(UmlConnector *ownedConnector)
{
    // This is a read-write association end

    if (_ownedConnector.contains(ownedConnector)) {
        _ownedConnector.remove(ownedConnector);

        // Adjust subsetted properties
        removeFeature(ownedConnector);
        removeOwnedMember(ownedConnector);
    }
}

/*!
    References the properties specifying instances that the classifier owns by composition. This association is derived, selecting those owned properties where isComposite is true.
 */
const QSet<UmlProperty *> UmlStructuredClassifier::part() const
{
    // This is a read-only derived association end

    qWarning("UmlStructuredClassifier::part(): to be implemented (this is a derived association end)");

    return QSet<UmlProperty *>();
}

void UmlStructuredClassifier::addPart(UmlProperty *part)
{
    // This is a read-only derived association end

    qWarning("UmlStructuredClassifier::part(): to be implemented (this is a derived association end)");
    Q_UNUSED(part);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void UmlStructuredClassifier::removePart(UmlProperty *part)
{
    // This is a read-only derived association end

    qWarning("UmlStructuredClassifier::part(): to be implemented (this is a derived association end)");
    Q_UNUSED(part);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    References the roles that instances may play in this classifier.
 */
const QSet<UmlConnectableElement *> UmlStructuredClassifier::role() const
{
    // This is a read-only derived union association end

    return _role;
}

void UmlStructuredClassifier::addRole(UmlConnectableElement *role)
{
    // This is a read-only derived union association end

    if (!_role.contains(role)) {
        _role.insert(role);

        // Adjust subsetted properties
        addMember(role);
    }
}

void UmlStructuredClassifier::removeRole(UmlConnectableElement *role)
{
    // This is a read-only derived union association end

    if (_role.contains(role)) {
        _role.remove(role);

        // Adjust subsetted properties
        removeMember(role);
    }
}
