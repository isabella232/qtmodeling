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
#include "umlclassifiertemplateparameter_p.h"

#include "private/umlclassifier_p.h"

/*!
    \class UmlClassifierTemplateParameter

    \inmodule QtUml

    \brief A classifier template parameter exposes a classifier as a formal template parameter.
 */

UmlClassifierTemplateParameter::UmlClassifierTemplateParameter() :
    _allowSubstitutable(true),
    _parameteredElement(0)
{
}

// OWNED ATTRIBUTES

/*!
    Constrains the required relationship between an actual parameter and the parameteredElement for this formal parameter.
 */
bool UmlClassifierTemplateParameter::allowSubstitutable() const
{
    // This is a read-write property

    return _allowSubstitutable;
}

void UmlClassifierTemplateParameter::setAllowSubstitutable(bool allowSubstitutable)
{
    // This is a read-write property

    if (_allowSubstitutable != allowSubstitutable) {
        _allowSubstitutable = allowSubstitutable;
    }
}

/*!
    The classifiers that constrain the argument that can be used for the parameter. If the allowSubstitutable attribute is true, then any classifier that is compatible with this constraining classifier can be substituted; otherwise, it must be either this classifier or one of its subclasses. If this property is empty, there are no constraints on the classifier that can be used as an argument.
 */
const QSet<UmlClassifier *> UmlClassifierTemplateParameter::constrainingClassifier() const
{
    // This is a read-write association end

    return _constrainingClassifier;
}

void UmlClassifierTemplateParameter::addConstrainingClassifier(UmlClassifier *constrainingClassifier)
{
    // This is a read-write association end

    if (!_constrainingClassifier.contains(constrainingClassifier)) {
        _constrainingClassifier.insert(constrainingClassifier);
    }
}

void UmlClassifierTemplateParameter::removeConstrainingClassifier(UmlClassifier *constrainingClassifier)
{
    // This is a read-write association end

    if (_constrainingClassifier.contains(constrainingClassifier)) {
        _constrainingClassifier.remove(constrainingClassifier);
    }
}

/*!
    The parameterable classifier for this template parameter.
 */
UmlClassifier *UmlClassifierTemplateParameter::parameteredElement() const
{
    // This is a read-write association end

    return _parameteredElement;
}

void UmlClassifierTemplateParameter::setParameteredElement(UmlClassifier *parameteredElement)
{
    // This is a read-write association end

    if (_parameteredElement != parameteredElement) {
        _parameteredElement = parameteredElement;
    }
}
