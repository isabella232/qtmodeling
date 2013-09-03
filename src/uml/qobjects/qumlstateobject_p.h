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
#ifndef QUMLSTATEOBJECT_H
#define QUMLSTATEOBJECT_H

#include <QtUml/QtUmlGlobal>

#include <QtCore/QObject>

#include <QtUml/QtUmlNamespace>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlState;
class Q_UML_EXPORT QUmlStateObject : public QObject
{
    Q_OBJECT

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComment READ ownedComment)
    Q_PROPERTY(QSet<QObject *> ownedElement READ ownedElement)
    Q_PROPERTY(QObject * owner READ owner)

    // Properties [NamedElement]
    Q_PROPERTY(QSet<QObject *> clientDependency READ clientDependency)
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QObject * nameExpression READ nameExpression)
    Q_PROPERTY(QObject * namespace_ READ namespace_)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility)

    // Properties [Namespace]
    Q_PROPERTY(QSet<QObject *> elementImport READ elementImport)
    Q_PROPERTY(QSet<QObject *> importedMember READ importedMember)
    Q_PROPERTY(QSet<QObject *> member READ member)
    Q_PROPERTY(QSet<QObject *> ownedMember READ ownedMember)
    Q_PROPERTY(QSet<QObject *> ownedRule READ ownedRule)
    Q_PROPERTY(QSet<QObject *> packageImport READ packageImport)

    // Properties [RedefinableElement]
    Q_PROPERTY(bool isLeaf READ isLeaf)
    Q_PROPERTY(QSet<QObject *> redefinedElement READ redefinedElement)

    // Properties [Vertex]
    Q_PROPERTY(QObject * container READ container)
    Q_PROPERTY(QSet<QObject *> incoming READ incoming)
    Q_PROPERTY(QSet<QObject *> outgoing READ outgoing)

    // Properties [State]
    Q_PROPERTY(QSet<QObject *> connection READ connection)
    Q_PROPERTY(QSet<QObject *> connectionPoint READ connectionPoint)
    Q_PROPERTY(QSet<QObject *> deferrableTrigger READ deferrableTrigger)
    Q_PROPERTY(QObject * doActivity READ doActivity)
    Q_PROPERTY(QObject * entry READ entry)
    Q_PROPERTY(QObject * exit READ exit)
    Q_PROPERTY(bool isComposite READ isComposite)
    Q_PROPERTY(bool isOrthogonal READ isOrthogonal)
    Q_PROPERTY(bool isSimple READ isSimple)
    Q_PROPERTY(bool isSubmachineState READ isSubmachineState)
    Q_PROPERTY(QObject * redefinedState READ redefinedState)
    Q_PROPERTY(QObject * redefinitionContext READ redefinitionContext)
    Q_PROPERTY(QSet<QObject *> region READ region)
    Q_PROPERTY(QObject * stateInvariant READ stateInvariant)
    Q_PROPERTY(QObject * submachine READ submachine)

public:
    Q_INVOKABLE explicit QUmlStateObject(QUmlState *qModelingObject);
    virtual ~QUmlStateObject();

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComment() const;
    Q_INVOKABLE const QSet<QObject *> ownedElement() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [NamedElement]
    Q_INVOKABLE const QSet<QObject *> clientDependency() const;
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE QObject *nameExpression() const;
    Q_INVOKABLE QObject *namespace_() const;
    Q_INVOKABLE QString qualifiedName() const;
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;

    // Owned attributes [Namespace]
    Q_INVOKABLE const QSet<QObject *> elementImport() const;
    Q_INVOKABLE const QSet<QObject *> importedMember() const;
    Q_INVOKABLE const QSet<QObject *> member() const;
    Q_INVOKABLE const QSet<QObject *> ownedMember() const;
    Q_INVOKABLE const QSet<QObject *> ownedRule() const;
    Q_INVOKABLE const QSet<QObject *> packageImport() const;

    // Owned attributes [RedefinableElement]
    Q_INVOKABLE bool isLeaf() const;
    Q_INVOKABLE const QSet<QObject *> redefinedElement() const;

    // Owned attributes [Vertex]
    Q_INVOKABLE QObject *container() const;
    Q_INVOKABLE const QSet<QObject *> incoming() const;
    Q_INVOKABLE const QSet<QObject *> outgoing() const;

    // Owned attributes [State]
    Q_INVOKABLE const QSet<QObject *> connection() const;
    Q_INVOKABLE const QSet<QObject *> connectionPoint() const;
    Q_INVOKABLE const QSet<QObject *> deferrableTrigger() const;
    Q_INVOKABLE QObject *doActivity() const;
    Q_INVOKABLE QObject *entry() const;
    Q_INVOKABLE QObject *exit() const;
    Q_INVOKABLE bool isComposite() const;
    Q_INVOKABLE bool isOrthogonal() const;
    Q_INVOKABLE bool isSimple() const;
    Q_INVOKABLE bool isSubmachineState() const;
    Q_INVOKABLE QObject *redefinedState() const;
    Q_INVOKABLE QObject *redefinitionContext() const;
    Q_INVOKABLE const QSet<QObject *> region() const;
    Q_INVOKABLE QObject *stateInvariant() const;
    Q_INVOKABLE QObject *submachine() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;

    // Operations [NamedElement]
    Q_INVOKABLE QList<QObject *> allNamespaces() const;
    Q_INVOKABLE QSet<QObject *> allOwningPackages() const;
    Q_INVOKABLE bool isDistinguishableFrom(QObject *n, QObject *ns) const;
    Q_INVOKABLE QString separator() const;

    // Operations [Namespace]
    Q_INVOKABLE QSet<QObject *> excludeCollisions(QSet<QObject *> imps) const;
    Q_INVOKABLE QSet<QString> getNamesOfMember(QObject *element) const;
    Q_INVOKABLE QSet<QObject *> importMembers(QSet<QObject *> imps) const;
    Q_INVOKABLE bool membersAreDistinguishable() const;

    // Operations [RedefinableElement]

    // Operations [Vertex]

    // Operations [State]
    Q_INVOKABLE QObject *containingStateMachine() const;
    Q_INVOKABLE bool isConsistentWith(QObject *redefinee) const;
    Q_INVOKABLE bool isRedefinitionContextValid(QObject *redefined) const;

public Q_SLOTS:

    // Slots for owned attributes [Element]
    void addOwnedComment(QObject *ownedComment);
    void removeOwnedComment(QObject *ownedComment);
    void Q_DECL_HIDDEN addOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN removeOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN setOwner(QObject *owner = 0);

    // Slots for owned attributes [NamedElement]
    void addClientDependency(QObject *clientDependency);
    void removeClientDependency(QObject *clientDependency);
    void setName(QString name);
    void setNameExpression(QObject *nameExpression = 0);
    void Q_DECL_HIDDEN setNamespace(QObject *namespace_ = 0);
    void Q_DECL_HIDDEN setQualifiedName(QString qualifiedName);
    void setVisibility(QtUml::VisibilityKind visibility);

    // Slots for owned attributes [Namespace]
    void addElementImport(QObject *elementImport);
    void removeElementImport(QObject *elementImport);
    void Q_DECL_HIDDEN addImportedMember(QObject *importedMember);
    void Q_DECL_HIDDEN removeImportedMember(QObject *importedMember);
    void Q_DECL_HIDDEN addMember(QObject *member);
    void Q_DECL_HIDDEN removeMember(QObject *member);
    void Q_DECL_HIDDEN addOwnedMember(QObject *ownedMember);
    void Q_DECL_HIDDEN removeOwnedMember(QObject *ownedMember);
    void addOwnedRule(QObject *ownedRule);
    void removeOwnedRule(QObject *ownedRule);
    void addPackageImport(QObject *packageImport);
    void removePackageImport(QObject *packageImport);

    // Slots for owned attributes [RedefinableElement]
    void setLeaf(bool isLeaf);
    void Q_DECL_HIDDEN addRedefinedElement(QObject *redefinedElement);
    void Q_DECL_HIDDEN removeRedefinedElement(QObject *redefinedElement);

    // Slots for owned attributes [Vertex]
    void setContainer(QObject *container = 0);
    void Q_DECL_HIDDEN addIncoming(QObject *incoming);
    void Q_DECL_HIDDEN removeIncoming(QObject *incoming);
    void Q_DECL_HIDDEN addOutgoing(QObject *outgoing);
    void Q_DECL_HIDDEN removeOutgoing(QObject *outgoing);

    // Slots for owned attributes [State]
    void addConnection(QObject *connection);
    void removeConnection(QObject *connection);
    void addConnectionPoint(QObject *connectionPoint);
    void removeConnectionPoint(QObject *connectionPoint);
    void addDeferrableTrigger(QObject *deferrableTrigger);
    void removeDeferrableTrigger(QObject *deferrableTrigger);
    void setDoActivity(QObject *doActivity = 0);
    void setEntry(QObject *entry = 0);
    void setExit(QObject *exit = 0);
    void Q_DECL_HIDDEN setComposite(bool isComposite);
    void Q_DECL_HIDDEN setOrthogonal(bool isOrthogonal);
    void Q_DECL_HIDDEN setSimple(bool isSimple);
    void Q_DECL_HIDDEN setSubmachineState(bool isSubmachineState);
    void setRedefinedState(QObject *redefinedState = 0);
    void Q_DECL_HIDDEN setRedefinitionContext(QObject *redefinitionContext = 0);
    void addRegion(QObject *region);
    void removeRegion(QObject *region);
    void setStateInvariant(QObject *stateInvariant = 0);
    void setSubmachine(QObject *submachine = 0);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLSTATEOBJECT_H
