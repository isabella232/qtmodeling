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
#include "umlconnectorend_p.h"

#include "private/umlconnectableelement_p.h"
#include "private/umlproperty_p.h"

/*!
    \class UmlConnectorEnd

    \inmodule QtUml

    \brief A connector end is an endpoint of a connector, which attaches the connector to a connectable element. Each connector end is part of one connector.
 */

UmlConnectorEnd::UmlConnectorEnd() :
    _partWithPort(0),
    _role(0)
{
}

// OWNED ATTRIBUTES

/*!
    A derived association referencing the corresponding association end on the association which types the connector owing this connector end. This association is derived by selecting the association end at the same place in the ordering of association ends as this connector end.
 */
UmlProperty *UmlConnectorEnd::definingEnd() const
{
    // This is a read-only derived association end

    qWarning("UmlConnectorEnd::definingEnd(): to be implemented (this is a derived association end)");

    return 0;
}

void UmlConnectorEnd::setDefiningEnd(UmlProperty *definingEnd)
{
    // This is a read-only derived association end

    qWarning("UmlConnectorEnd::definingEnd(): to be implemented (this is a derived association end)");
    Q_UNUSED(definingEnd);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    Indicates the role of the internal structure of a classifier with the port to which the connector end is attached.
 */
UmlProperty *UmlConnectorEnd::partWithPort() const
{
    // This is a read-write association end

    return _partWithPort;
}

void UmlConnectorEnd::setPartWithPort(UmlProperty *partWithPort)
{
    // This is a read-write association end

    if (_partWithPort != partWithPort) {
        _partWithPort = partWithPort;
    }
}

/*!
    The connectable element attached at this connector end. When an instance of the containing classifier is created, a link may (depending on the multiplicities) be created to an instance of the classifier that types this connectable element.
 */
UmlConnectableElement *UmlConnectorEnd::role() const
{
    // This is a read-write association end

    return _role;
}

void UmlConnectorEnd::setRole(UmlConnectableElement *role)
{
    // This is a read-write association end

    if (_role != role) {
        _role = role;
    }
}
