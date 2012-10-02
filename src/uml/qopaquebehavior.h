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
#ifndef QTUML_QOPAQUEBEHAVIOR_H
#define QTUML_QOPAQUEBEHAVIOR_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QBehavior>

// Qt includes
#include <QtCore/QString>
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QOpaqueBehaviorPrivate;

class Q_UML_EXPORT QOpaqueBehavior : public QBehavior
{
    Q_OBJECT

    // From QBehavior
    Q_PROPERTY(bool isReentrant READ isReentrant WRITE setReentrant)
    Q_PROPERTY(const QBehavioredClassifier * context READ context)
    Q_PROPERTY(QList<QParameter *> * ownedParameter READ ownedParameter)
    Q_PROPERTY(QList<QParameterSet *> * ownedParameterSet READ ownedParameterSet)
    Q_PROPERTY(QList<QConstraint *> * postcondition READ postcondition)
    Q_PROPERTY(QList<QConstraint *> * precondition READ precondition)
    Q_PROPERTY(QList<QBehavior *> * redefinedBehavior READ redefinedBehavior)
    Q_PROPERTY(QBehavioralFeature * specification READ specification WRITE setSpecification)

    // From QOpaqueBehavior
    Q_PROPERTY(QList<QString *> body READ body)
    Q_PROPERTY(QList<QString *> language READ language)

public:
    explicit QOpaqueBehavior(QObject *parent = 0);
    virtual ~QOpaqueBehavior();

    // Attributes (except those derived && !derivedUnion)
    QList<QString *> body();
    QList<QString *> language();

private:
    Q_DISABLE_COPY(QOpaqueBehavior)
    Q_DECLARE_PRIVATE(QOpaqueBehavior)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QOpaqueBehavior *>)
Q_DECLARE_METATYPE(QList<QtUml::QOpaqueBehavior *> *)

QT_END_HEADER

#endif // QTUML_QOPAQUEBEHAVIOR_H

