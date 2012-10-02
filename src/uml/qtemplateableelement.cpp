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

#include "qtemplateableelement.h"
//#include "qtemplateableelement_p.h"

QT_BEGIN_NAMESPACE_QTUML

/*!
    \class QTemplateableElement

    \inmodule QtUml

    \brief A templateable element is an element that can optionally be defined as a template and bound to other templates.
 */

QTemplateableElement::QTemplateableElement()
{
}

QTemplateableElement::~QTemplateableElement()
{
}

/*!
    The optional template signature specifying the formal template parameters.
 */
QTemplateSignature *QTemplateableElement::ownedTemplateSignature() const
{
}

void QTemplateableElement::setOwnedTemplateSignature(QTemplateSignature *ownedTemplateSignature)
{
}

/*!
    The optional bindings from this element to templates.
 */
QList<QTemplateBinding *> *QTemplateableElement::templateBinding()
{
}

/*!
    The query isTemplate() returns whether this templateable element is actually a template.
 */
bool QTemplateableElement::isTemplate() const
{
}

/*!
    The query parameterableElements() returns the set of elements that may be used as the parametered elements for a template parameter of this templateable element. By default, this set includes all the owned elements. Subclasses may override this operation if they choose to restrict the set of parameterable elements.
 */
const QList<QParameterableElement *> *QTemplateableElement::parameterableElements() const
{
}

QT_END_NAMESPACE_QTUML
