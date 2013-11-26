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
#include "qumlactivityparameternode.h"

#include "private/qumlactivityparameternodeobject_p.h"

#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlBehavior>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameter>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlState>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>
#include <QtUml/QUmlType>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlActivityParameterNode

    \inmodule QtUml

    \brief An activity parameter node is an object node for inputs and outputs to activities.
 */

/*!
    Creates a new QUmlActivityParameterNode. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlActivityParameterNode::QUmlActivityParameterNode(bool createQModelingObject) :
    _parameter(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlActivityParameterNodeObject(this));
}

/*!
    Destroys the QUmlActivityParameterNode.
 */
QUmlActivityParameterNode::~QUmlActivityParameterNode()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlActivityParameterNode.
*/
QModelingElement *QUmlActivityParameterNode::clone() const
{
    QUmlActivityParameterNode *c = new QUmlActivityParameterNode;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    c->setControlType(isControlType());
    c->setOrdering(ordering());
    if (upperBound())
        c->setUpperBound(dynamic_cast<QUmlValueSpecification *>(upperBound()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The parameter the object node will be accepting or providing values for.
 */
QUmlParameter *QUmlActivityParameterNode::parameter() const
{
    // This is a read-write association end

    return _parameter;
}

/*!
    Adjusts parameter to \a parameter.
 */
void QUmlActivityParameterNode::setParameter(QUmlParameter *parameter)
{
    // This is a read-write association end

    if (_parameter != parameter) {
        _parameter = parameter;
        if (parameter && parameter->asQModelingObject() && this->asQModelingObject())
            QObject::connect(parameter->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setParameter()));
    }
}

QT_END_NAMESPACE

