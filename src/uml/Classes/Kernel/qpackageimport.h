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
** rights. These rights are described in the Nokia  LGPL Exception
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
#ifndef CLASSES_KERNEL_QPACKAGEIMPORT_H
#define CLASSES_KERNEL_QPACKAGEIMPORT_H

#include <QtUml/QtUmlGlobal>

// QtUml includes
#include <QtUml/QEnumerations>

// Base class includes
#include <QtCore/QObject>
#include <QtCore/QObject>
#include <QtUml/QDirectedRelationship>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_UML_CLASSES_KERNEL

QT_MODULE(QtUml)

class QPackageImportPrivate;

class QPackage;
class QNamespace;

class Q_UML_EXPORT QPackageImport : public QObject, public QDirectedRelationship
{
    Q_OBJECT

    Q_PROPERTY(QEnumerations::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QPackage * importedPackage READ importedPackage WRITE setImportedPackage)
    Q_PROPERTY(QNamespace * importingNamespace READ importingNamespace WRITE setImportingNamespace)

public:
    explicit QPackageImport(QObject *parent = 0);
    virtual ~QPackageImport();

    // Attributes (except those derived && !derivedUnion)
    QEnumerations::VisibilityKind visibility() const;
    void setVisibility(QEnumerations::VisibilityKind visibility);

    // Association-ends (except those derived && !derivedUnion)
    QPackage *importedPackage() const;
    void setImportedPackage(QPackage *importedPackage);
    QNamespace *importingNamespace() const;
    void setImportingNamespace(QNamespace *importingNamespace);

private:
    Q_DISABLE_COPY(QPackageImport)
    Q_DECLARE_PRIVATE(QPackageImport)
};

QT_END_NAMESPACE_UML_CLASSES_KERNEL

Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_UML_CLASSES_KERNEL(QPackageImport) *>)
Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_UML_CLASSES_KERNEL(QPackageImport) *> *)

QT_END_HEADER

#endif // CLASSES_KERNEL_QPACKAGEIMPORT_H
