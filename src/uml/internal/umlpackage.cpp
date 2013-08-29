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
#include "umlpackage_p.h"

#include "private/umlnamedelement_p.h"
#include "private/umlpackagemerge_p.h"
#include "private/umlprofile_p.h"
#include "private/umlprofileapplication_p.h"
#include "private/umlstereotype_p.h"
#include "private/umltype_p.h"

/*!
    \class UmlPackage

    \inmodule QtUml

    \brief A package can have one or more profile applications to indicate which profiles have been applied. Because a profile is a package, it is possible to apply a profile not only to packages, but also to profiles.Package specializes TemplateableElement and PackageableElement specializes ParameterableElement to specify that a package can be used as a template and a PackageableElement as a template parameter.A package is used to group elements, and provides a namespace for the grouped elements.
 */

UmlPackage::UmlPackage() :
    _nestingPackage(0)
{
}

// OWNED ATTRIBUTES

/*!
    Provides an identifier for the package that can be used for many purposes. A URI is the universally unique identification of the package following the IETF URI specification, RFC 2396 http://www.ietf.org/rfc/rfc2396.txt and it must comply with those syntax rules.
 */
QString UmlPackage::URI() const
{
    // This is a read-write property

    return _URI;
}

void UmlPackage::setURI(QString URI)
{
    // This is a read-write property

    if (_URI != URI) {
        _URI = URI;
    }
}

/*!
    References the packaged elements that are Packages.
 */
const QSet<UmlPackage *> UmlPackage::nestedPackage() const
{
    // This is a read-write derived association end

    qWarning("UmlPackage::nestedPackage(): to be implemented (this is a derived association end)");

    return QSet<UmlPackage *>();
}

void UmlPackage::addNestedPackage(UmlPackage *nestedPackage)
{
    // This is a read-write derived association end

    qWarning("UmlPackage::nestedPackage(): to be implemented (this is a derived association end)");
    Q_UNUSED(nestedPackage);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        addPackagedElement(nestedPackage);
    }
}

void UmlPackage::removeNestedPackage(UmlPackage *nestedPackage)
{
    // This is a read-write derived association end

    qWarning("UmlPackage::nestedPackage(): to be implemented (this is a derived association end)");
    Q_UNUSED(nestedPackage);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        removePackagedElement(nestedPackage);
    }
}

/*!
    References the Package that owns this Package.
 */
UmlPackage *UmlPackage::nestingPackage() const
{
    // This is a read-write association end

    return _nestingPackage;
}

void UmlPackage::setNestingPackage(UmlPackage *nestingPackage)
{
    // This is a read-write association end

    if (_nestingPackage != nestingPackage) {
        _nestingPackage = nestingPackage;
    }
}

/*!
    References the Stereotypes that are owned by the Package
 */
const QSet<UmlStereotype *> UmlPackage::ownedStereotype() const
{
    // This is a read-only derived association end

    qWarning("UmlPackage::ownedStereotype(): to be implemented (this is a derived association end)");

    return QSet<UmlStereotype *>();
}

void UmlPackage::addOwnedStereotype(UmlStereotype *ownedStereotype)
{
    // This is a read-only derived association end

    qWarning("UmlPackage::ownedStereotype(): to be implemented (this is a derived association end)");
    Q_UNUSED(ownedStereotype);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        addPackagedElement(ownedStereotype);
    }
}

void UmlPackage::removeOwnedStereotype(UmlStereotype *ownedStereotype)
{
    // This is a read-only derived association end

    qWarning("UmlPackage::ownedStereotype(): to be implemented (this is a derived association end)");
    Q_UNUSED(ownedStereotype);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        removePackagedElement(ownedStereotype);
    }
}

/*!
    References the packaged elements that are Types.
 */
const QSet<UmlType *> UmlPackage::ownedType() const
{
    // This is a read-write derived association end

    qWarning("UmlPackage::ownedType(): to be implemented (this is a derived association end)");

    return QSet<UmlType *>();
}

void UmlPackage::addOwnedType(UmlType *ownedType)
{
    // This is a read-write derived association end

    qWarning("UmlPackage::ownedType(): to be implemented (this is a derived association end)");
    Q_UNUSED(ownedType);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        addPackagedElement(ownedType);

        // Adjust opposite properties
        if (ownedType) {
            ownedType->setPackage(this);
        }
    }
}

void UmlPackage::removeOwnedType(UmlType *ownedType)
{
    // This is a read-write derived association end

    qWarning("UmlPackage::ownedType(): to be implemented (this is a derived association end)");
    Q_UNUSED(ownedType);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust subsetted properties
        removePackagedElement(ownedType);

        // Adjust opposite properties
        if (ownedType) {
            ownedType->setPackage(0);
        }
    }
}

/*!
    References the PackageMerges that are owned by this Package.
 */
const QSet<UmlPackageMerge *> UmlPackage::packageMerge() const
{
    // This is a read-write association end

    return _packageMerge;
}

void UmlPackage::addPackageMerge(UmlPackageMerge *packageMerge)
{
    // This is a read-write association end

    if (!_packageMerge.contains(packageMerge)) {
        _packageMerge.insert(packageMerge);

        // Adjust subsetted properties
        addOwnedElement(packageMerge);

        // Adjust opposite properties
        if (packageMerge) {
            packageMerge->setReceivingPackage(this);
        }
    }
}

void UmlPackage::removePackageMerge(UmlPackageMerge *packageMerge)
{
    // This is a read-write association end

    if (_packageMerge.contains(packageMerge)) {
        _packageMerge.remove(packageMerge);

        // Adjust subsetted properties
        removeOwnedElement(packageMerge);

        // Adjust opposite properties
        if (packageMerge) {
            packageMerge->setReceivingPackage(0);
        }
    }
}

/*!
    Specifies the packageable elements that are owned by this Package.
 */
const QSet<UmlPackageableElement *> UmlPackage::packagedElement() const
{
    // This is a read-write association end

    return _packagedElement;
}

void UmlPackage::addPackagedElement(UmlPackageableElement *packagedElement)
{
    // This is a read-write association end

    if (!_packagedElement.contains(packagedElement)) {
        _packagedElement.insert(packagedElement);

        // Adjust subsetted properties
        addOwnedMember(packagedElement);
    }
}

void UmlPackage::removePackagedElement(UmlPackageableElement *packagedElement)
{
    // This is a read-write association end

    if (_packagedElement.contains(packagedElement)) {
        _packagedElement.remove(packagedElement);

        // Adjust subsetted properties
        removeOwnedMember(packagedElement);
    }
}

/*!
    References the ProfileApplications that indicate which profiles have been applied to the Package.
 */
const QSet<UmlProfileApplication *> UmlPackage::profileApplication() const
{
    // This is a read-write association end

    return _profileApplication;
}

void UmlPackage::addProfileApplication(UmlProfileApplication *profileApplication)
{
    // This is a read-write association end

    if (!_profileApplication.contains(profileApplication)) {
        _profileApplication.insert(profileApplication);

        // Adjust subsetted properties
        addOwnedElement(profileApplication);

        // Adjust opposite properties
        if (profileApplication) {
            profileApplication->setApplyingPackage(this);
        }
    }
}

void UmlPackage::removeProfileApplication(UmlProfileApplication *profileApplication)
{
    // This is a read-write association end

    if (_profileApplication.contains(profileApplication)) {
        _profileApplication.remove(profileApplication);

        // Adjust subsetted properties
        removeOwnedElement(profileApplication);

        // Adjust opposite properties
        if (profileApplication) {
            profileApplication->setApplyingPackage(0);
        }
    }
}

// OPERATIONS

/*!
    The query allApplicableStereotypes() returns all the directly or indirectly owned stereotypes, including stereotypes contained in sub-profiles.
 */
QSet<UmlStereotype *> UmlPackage::allApplicableStereotypes(
    ) const
{
    qWarning("UmlPackage::allApplicableStereotypes(): to be implemented (operation)");

    return QSet<UmlStereotype *> ();
}

/*!
    The query containingProfile() returns the closest profile directly or indirectly containing this package (or this package itself, if it is a profile).
 */
UmlProfile *UmlPackage::containingProfile(
    ) const
{
    qWarning("UmlPackage::containingProfile(): to be implemented (operation)");

    return 0;
}

/*!
    The query makesVisible() defines whether a Package makes an element visible outside itself. Elements with no visibility and elements with public visibility are made visible.
 */
bool UmlPackage::makesVisible(
    UmlNamedElement *el) const
{
    qWarning("UmlPackage::makesVisible(): to be implemented (operation)");

    Q_UNUSED(el);
    return bool ();
}

/*!
    The query mustBeOwned() indicates whether elements of this type must have an owner.
 */
bool UmlPackage::mustBeOwned(
    ) const
{
    qWarning("UmlPackage::mustBeOwned(): to be implemented (operation)");

    return bool ();
}

/*!
    The query visibleMembers() defines which members of a Package can be accessed outside it.
 */
QSet<UmlPackageableElement *> UmlPackage::visibleMembers(
    ) const
{
    qWarning("UmlPackage::visibleMembers(): to be implemented (operation)");

    return QSet<UmlPackageableElement *> ();
}
