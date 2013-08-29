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
#include "umlredefinabletemplatesignature_p.h"

#include "private/umlclassifier_p.h"
#include "private/umltemplateparameter_p.h"

/*!
    \class UmlRedefinableTemplateSignature

    \inmodule QtUml

    \brief A redefinable template signature supports the addition of formal template parameters in a specialization of a template classifier.
 */

UmlRedefinableTemplateSignature::UmlRedefinableTemplateSignature() :
    _classifier(0)
{
}

// OWNED ATTRIBUTES

/*!
    The classifier that owns this template signature.
 */
UmlClassifier *UmlRedefinableTemplateSignature::classifier() const
{
    // This is a read-write association end

    return _classifier;
}

void UmlRedefinableTemplateSignature::setClassifier(UmlClassifier *classifier)
{
    // This is a read-write association end

    if (_classifier != classifier) {
        // Adjust subsetted properties
        removeRedefinitionContext(_classifier);

        _classifier = classifier;

        // Adjust subsetted properties
        if (classifier) {
            addRedefinitionContext(classifier);
        }
    }
}

/*!
    The template signature that is extended by this template signature.
 */
const QSet<UmlRedefinableTemplateSignature *> UmlRedefinableTemplateSignature::extendedSignature() const
{
    // This is a read-write association end

    return _extendedSignature;
}

void UmlRedefinableTemplateSignature::addExtendedSignature(UmlRedefinableTemplateSignature *extendedSignature)
{
    // This is a read-write association end

    if (!_extendedSignature.contains(extendedSignature)) {
        _extendedSignature.insert(extendedSignature);

        // Adjust subsetted properties
        addRedefinedElement(extendedSignature);
    }
}

void UmlRedefinableTemplateSignature::removeExtendedSignature(UmlRedefinableTemplateSignature *extendedSignature)
{
    // This is a read-write association end

    if (_extendedSignature.contains(extendedSignature)) {
        _extendedSignature.remove(extendedSignature);

        // Adjust subsetted properties
        removeRedefinedElement(extendedSignature);
    }
}

/*!
    The formal template parameters of the extendedSignature.
 */
const QSet<UmlTemplateParameter *> UmlRedefinableTemplateSignature::inheritedParameter() const
{
    // This is a read-only derived association end

    qWarning("UmlRedefinableTemplateSignature::inheritedParameter(): to be implemented (this is a derived association end)");

    return QSet<UmlTemplateParameter *>();
}

void UmlRedefinableTemplateSignature::addInheritedParameter(UmlTemplateParameter *inheritedParameter)
{
    // This is a read-only derived association end

    qWarning("UmlRedefinableTemplateSignature::inheritedParameter(): to be implemented (this is a derived association end)");
    Q_UNUSED(inheritedParameter);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        addParameter(inheritedParameter);
    }
}

void UmlRedefinableTemplateSignature::removeInheritedParameter(UmlTemplateParameter *inheritedParameter)
{
    // This is a read-only derived association end

    qWarning("UmlRedefinableTemplateSignature::inheritedParameter(): to be implemented (this is a derived association end)");
    Q_UNUSED(inheritedParameter);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        removeParameter(inheritedParameter);
    }
}

// OPERATIONS

/*!
    The query isConsistentWith() specifies, for any two RedefinableTemplateSignatures in a context in which redefinition is possible, whether redefinition would be logically consistent. A redefining template signature is always consistent with a redefined template signature, since redefinition only adds new formal parameters.
 */
bool UmlRedefinableTemplateSignature::isConsistentWith(
    UmlRedefinableElement *redefinee) const
{
    qWarning("UmlRedefinableTemplateSignature::isConsistentWith(): to be implemented (operation)");

    Q_UNUSED(redefinee);
    return bool ();
}
