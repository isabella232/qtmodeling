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
#include "umlextend_p.h"

#include "private/umlconstraint_p.h"
#include "private/umlextensionpoint_p.h"
#include "private/umlusecase_p.h"

/*!
    \class UmlExtend

    \inmodule QtUml

    \brief A relationship from an extending use case to an extended use case that specifies how and when the behavior defined in the extending use case can be inserted into the behavior defined in the extended use case.
 */

UmlExtend::UmlExtend() :
    _condition(0),
    _extendedCase(0),
    _extension(0)
{
}

// OWNED ATTRIBUTES

/*!
    References the condition that must hold when the first extension point is reached for the extension to take place. If no constraint is associated with the extend relationship, the extension is unconditional.
 */
UmlConstraint *UmlExtend::condition() const
{
    // This is a read-write association end

    return _condition;
}

void UmlExtend::setCondition(UmlConstraint *condition)
{
    // This is a read-write association end

    if (_condition != condition) {
        // Adjust subsetted properties
        removeOwnedElement(_condition);

        _condition = condition;

        // Adjust subsetted properties
        if (condition) {
            addOwnedElement(condition);
        }
    }
}

/*!
    References the use case that is being extended.
 */
UmlUseCase *UmlExtend::extendedCase() const
{
    // This is a read-write association end

    return _extendedCase;
}

void UmlExtend::setExtendedCase(UmlUseCase *extendedCase)
{
    // This is a read-write association end

    if (_extendedCase != extendedCase) {
        // Adjust subsetted properties
        removeTarget(_extendedCase);

        _extendedCase = extendedCase;

        // Adjust subsetted properties
        if (extendedCase) {
            addTarget(extendedCase);
        }
    }
}

/*!
    References the use case that represents the extension and owns the extend relationship.
 */
UmlUseCase *UmlExtend::extension() const
{
    // This is a read-write association end

    return _extension;
}

void UmlExtend::setExtension(UmlUseCase *extension)
{
    // This is a read-write association end

    if (_extension != extension) {
        // Adjust subsetted properties
        removeSource(_extension);

        _extension = extension;

        // Adjust subsetted properties
        if (extension) {
            addSource(extension);
        }
        setNamespace(extension);
    }
}

/*!
    An ordered list of extension points belonging to the extended use case, specifying where the respective behavioral fragments of the extending use case are to be inserted. The first fragment in the extending use case is associated with the first extension point in the list, the second fragment with the second point, and so on. (Note that, in most practical cases, the extending use case has just a single behavior fragment, so that the list of extension points is trivial.)
 */
const QList<UmlExtensionPoint *> UmlExtend::extensionLocation() const
{
    // This is a read-write association end

    return _extensionLocation;
}

void UmlExtend::addExtensionLocation(UmlExtensionPoint *extensionLocation)
{
    // This is a read-write association end

    if (!_extensionLocation.contains(extensionLocation)) {
        _extensionLocation.append(extensionLocation);
    }
}

void UmlExtend::removeExtensionLocation(UmlExtensionPoint *extensionLocation)
{
    // This is a read-write association end

    if (_extensionLocation.contains(extensionLocation)) {
        _extensionLocation.removeAll(extensionLocation);
    }
}
