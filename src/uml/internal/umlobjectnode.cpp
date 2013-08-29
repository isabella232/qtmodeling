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
#include "umlobjectnode_p.h"

#include "private/umlbehavior_p.h"
#include "private/umlstate_p.h"
#include "private/umlvaluespecification_p.h"

/*!
    \class UmlObjectNode

    \inmodule QtUml

    \brief An object node is an abstract activity node that is part of defining object flow in an activity.Object nodes have support for token selection, limitation on the number of tokens, specifying the state required for tokens, and carrying control values.
 */

UmlObjectNode::UmlObjectNode() :
    _isControlType(false),
    _ordering(QtUml::ObjectNodeOrderingKindFIFO),
    _selection(0),
    _upperBound(0)
{
}

// OWNED ATTRIBUTES

/*!
    The required states of the object available at this point in the activity.
 */
const QSet<UmlState *> UmlObjectNode::inState() const
{
    // This is a read-write association end

    return _inState;
}

void UmlObjectNode::addInState(UmlState *inState)
{
    // This is a read-write association end

    if (!_inState.contains(inState)) {
        _inState.insert(inState);
    }
}

void UmlObjectNode::removeInState(UmlState *inState)
{
    // This is a read-write association end

    if (_inState.contains(inState)) {
        _inState.remove(inState);
    }
}

/*!
    Tells whether the type of the object node is to be treated as control.
 */
bool UmlObjectNode::isControlType() const
{
    // This is a read-write property

    return _isControlType;
}

void UmlObjectNode::setControlType(bool isControlType)
{
    // This is a read-write property

    if (_isControlType != isControlType) {
        _isControlType = isControlType;
    }
}

/*!
    Tells whether and how the tokens in the object node are ordered for selection to traverse edges outgoing from the object node.
 */
QtUml::ObjectNodeOrderingKind UmlObjectNode::ordering() const
{
    // This is a read-write property

    return _ordering;
}

void UmlObjectNode::setOrdering(QtUml::ObjectNodeOrderingKind ordering)
{
    // This is a read-write property

    if (_ordering != ordering) {
        _ordering = ordering;
    }
}

/*!
    Selects tokens for outgoing edges.
 */
UmlBehavior *UmlObjectNode::selection() const
{
    // This is a read-write association end

    return _selection;
}

void UmlObjectNode::setSelection(UmlBehavior *selection)
{
    // This is a read-write association end

    if (_selection != selection) {
        _selection = selection;
    }
}

/*!
    The maximum number of tokens allowed in the node. Objects cannot flow into the node if the upper bound is reached.
 */
UmlValueSpecification *UmlObjectNode::upperBound() const
{
    // This is a read-write association end

    return _upperBound;
}

void UmlObjectNode::setUpperBound(UmlValueSpecification *upperBound)
{
    // This is a read-write association end

    if (_upperBound != upperBound) {
        // Adjust subsetted properties
        removeOwnedElement(_upperBound);

        _upperBound = upperBound;

        // Adjust subsetted properties
        if (upperBound) {
            addOwnedElement(upperBound);
        }
    }
}
