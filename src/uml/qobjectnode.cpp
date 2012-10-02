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

#include "qobjectnode.h"
//#include "qobjectnode_p.h"

QT_BEGIN_NAMESPACE_QTUML

/*!
    \class QObjectNode

    \inmodule QtUml

    \brief An object node is an abstract activity node that is part of defining object flow in an activity.Object nodes have support for token selection, limitation on the number of tokens, specifying the state required for tokens, and carrying control values.
 */

QObjectNode::QObjectNode()
{
}

QObjectNode::~QObjectNode()
{
}

/*!
    Tells whether the type of the object node is to be treated as control.
 */
bool QObjectNode::isControlType() const
{
}

void QObjectNode::setControlType(bool isControlType)
{
}

/*!
    Tells whether and how the tokens in the object node are ordered for selection to traverse edges outgoing from the object node.
 */
QtUml::ObjectNodeOrderingKind QObjectNode::ordering() const
{
}

void QObjectNode::setOrdering(QtUml::ObjectNodeOrderingKind ordering)
{
}

/*!
    The required states of the object available at this point in the activity.
 */
QList<QState *> *QObjectNode::inState()
{
}

/*!
    Selects tokens for outgoing edges.
 */
QBehavior *QObjectNode::selection() const
{
}

void QObjectNode::setSelection(QBehavior *selection)
{
}

/*!
    The maximum number of tokens allowed in the node. Objects cannot flow into the node if the upper bound is reached.
 */
QValueSpecification *QObjectNode::upperBound() const
{
}

void QObjectNode::setUpperBound(QValueSpecification *upperBound)
{
}

QT_END_NAMESPACE_QTUML

