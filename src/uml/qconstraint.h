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
#ifndef QTUML_QCONSTRAINT_H
#define QTUML_QCONSTRAINT_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QPackageableElement>

// Qt includes
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QConstraintPrivate;
class QElement;
class QNamespace;
class QValueSpecification;

class Q_UML_EXPORT QConstraint : public QObject, public QPackageableElement
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(QList<QComment *> * ownedComment READ ownedComment)
    Q_PROPERTY(const QList<QElement *> * ownedElement READ ownedElement)
    Q_PROPERTY(const QElement * owner READ owner)

    // From QParameterableElement
    Q_PROPERTY(QTemplateParameter * owningTemplateParameter READ owningTemplateParameter WRITE setOwningTemplateParameter)
    Q_PROPERTY(QTemplateParameter * templateParameter READ templateParameter WRITE setTemplateParameter)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QList<QDependency *> * clientDependency READ clientDependency)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(const QNamespace * namespace_ READ namespace_)

    // From QPackageableElement
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)

    // From QConstraint
    Q_PROPERTY(QList<QElement *> * constrainedElement READ constrainedElement)
    Q_PROPERTY(QNamespace * context READ context WRITE setContext)
    Q_PROPERTY(QValueSpecification * specification READ specification WRITE setSpecification)

public:
    explicit QConstraint(QObject *parent = 0);
    virtual ~QConstraint();

    // Association-ends (except those derived && !derivedUnion)
    QList<QElement *> *constrainedElement();
    QNamespace *context() const;
    void setContext(QNamespace *context);
    QValueSpecification *specification() const;
    void setSpecification(QValueSpecification *specification);

private:
    Q_DISABLE_COPY(QConstraint)
    Q_DECLARE_PRIVATE(QConstraint)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QConstraint *>)
Q_DECLARE_METATYPE(QList<QtUml::QConstraint *> *)

QT_END_HEADER

#endif // QTUML_QCONSTRAINT_H
