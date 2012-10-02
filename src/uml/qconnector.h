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
#ifndef QTUML_QCONNECTOR_H
#define QTUML_QCONNECTOR_H

#include <QtUml/QtUmlGlobal>

// QtUml includes
#include <QtUml/QtUmlEnumerations>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QFeature>

// Qt includes
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QConnectorPrivate;
class QBehavior;
class QConnectorEnd;
class QAssociation;

class Q_UML_EXPORT QConnector : public QObject, public QFeature
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(QList<QComment *> * ownedComment READ ownedComment)
    Q_PROPERTY(const QList<QElement *> * ownedElement READ ownedElement)
    Q_PROPERTY(const QElement * owner READ owner)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QList<QDependency *> * clientDependency READ clientDependency)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(const QNamespace * namespace_ READ namespace_)

    // From QRedefinableElement
    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf)
    Q_PROPERTY(const QList<QRedefinableElement *> * redefinedElement READ redefinedElement)
    Q_PROPERTY(const QList<QClassifier *> * redefinitionContext READ redefinitionContext)

    // From QFeature
    Q_PROPERTY(bool isStatic READ isStatic WRITE setStatic)
    Q_PROPERTY(const QList<QClassifier *> * featuringClassifier READ featuringClassifier)

    // From QConnector
    Q_PROPERTY(QtUml::ConnectorKind kind READ kind)
    Q_PROPERTY(QList<QBehavior *> * contract READ contract)
    Q_PROPERTY(QList<QConnectorEnd *> * end READ end)
    Q_PROPERTY(QList<QConnector *> * redefinedConnector READ redefinedConnector)
    Q_PROPERTY(QAssociation * type READ type WRITE setType)

public:
    explicit QConnector(QObject *parent = 0);
    virtual ~QConnector();

    // Attributes (except those derived && !derivedUnion)

    // Association-ends (except those derived && !derivedUnion)
    QList<QBehavior *> *contract();
    QList<QConnectorEnd *> *end();
    QList<QConnector *> *redefinedConnector();
    QAssociation *type() const;
    void setType(QAssociation *type);

    // Operations (including accessors for derived && !derivedUnion attributes and association-ends)
    QtUml::ConnectorKind kind() const;

private:
    Q_DISABLE_COPY(QConnector)
    Q_DECLARE_PRIVATE(QConnector)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QConnector *>)
Q_DECLARE_METATYPE(QList<QtUml::QConnector *> *)

QT_END_HEADER

#endif // QTUML_QCONNECTOR_H
