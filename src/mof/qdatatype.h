/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtMof module of the Qt Toolkit.
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
#ifndef QTMOF_QDATATYPE_H
#define QTMOF_QDATATYPE_H

#include <QtMof/QtMofGlobal>

// Base class includes
#include <QtMof/QClassifier>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTMOF

QT_MODULE(QtMof)

// Forward decls for function parameters
class QProperty;
class QOperation;
class QNamedElement;

class QDataTypePrivate;

class Q_MOF_EXPORT QDataType : public QClassifier
{
    Q_OBJECT

    Q_PROPERTY(const QList<QOperation *> * ownedOperations READ ownedOperations)
    Q_PROPERTY(const QList<QProperty *> * ownedAttributes READ ownedAttributes)

    Q_DISABLE_COPY(QDataType)
    Q_DECLARE_PRIVATE(QDataType)

public:
    Q_INVOKABLE explicit QDataType(QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);
    virtual ~QDataType();

    // Association ends from QDataType
    Q_INVOKABLE const QList<QOperation *> *ownedOperations() const;
    Q_INVOKABLE void addOwnedOperation(QOperation *ownedOperation);
    Q_INVOKABLE void removeOwnedOperation(QOperation *ownedOperation);
    Q_INVOKABLE const QList<QProperty *> *ownedAttributes() const;
    Q_INVOKABLE void addOwnedAttribute(QProperty *ownedAttribute);
    Q_INVOKABLE void removeOwnedAttribute(QProperty *ownedAttribute);

    // Operations
    Q_INVOKABLE const QSet<QNamedElement *> *inherit(const QSet<QNamedElement *> *inhs) const;
    virtual void registerMetaTypes() const;

protected:
    explicit QDataType(QDataTypePrivate &dd, QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);
};

QT_END_NAMESPACE_QTMOF

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTMOF(QDataType) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTMOF(QDataType) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTMOF(QDataType) *> *)

QT_END_HEADER

#endif // QTMOF_QDATATYPE_H

