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
#ifndef QUMLINTERACTIONOPERANDOBJECT_H
#define QUMLINTERACTIONOPERANDOBJECT_H

#include <QtUml/QtUmlGlobal>

#include <QtModeling/QModelingObject>

#include <QtUml/QtUmlNamespace>

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlInteractionOperand;
class QModelingObjectPrivate;
class Q_UML_EXPORT QUmlInteractionOperandObject : public QModelingObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QUmlInteractionOperandObject)
    Q_DECLARE_PRIVATE(QModelingObject)

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComments READ ownedComments NOTIFY ownedCommentsChanged)
    Q_PROPERTY(QSet<QObject *> ownedElements READ ownedElements NOTIFY ownedElementsChanged)
    Q_PROPERTY(QObject * owner READ owner NOTIFY ownerChanged)

    // Properties [NamedElement]
    Q_PROPERTY(QSet<QObject *> clientDependencies READ clientDependencies NOTIFY clientDependenciesChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QObject * nameExpression READ nameExpression WRITE setNameExpression NOTIFY nameExpressionChanged)
    Q_PROPERTY(QObject * namespace_ READ namespace_ NOTIFY namespaceChanged)
    Q_PROPERTY(QString qualifiedName READ qualifiedName NOTIFY qualifiedNameChanged STORED false)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility NOTIFY visibilityChanged)

    // Properties [InteractionFragment]
    Q_PROPERTY(QSet<QObject *> covered READ covered NOTIFY coveredChanged)
    Q_PROPERTY(QObject * enclosingInteraction READ enclosingInteraction WRITE setEnclosingInteraction NOTIFY enclosingInteractionChanged)
    Q_PROPERTY(QObject * enclosingOperand READ enclosingOperand WRITE setEnclosingOperand NOTIFY enclosingOperandChanged)
    Q_PROPERTY(QSet<QObject *> generalOrderings READ generalOrderings NOTIFY generalOrderingsChanged)

    // Properties [Namespace]
    Q_PROPERTY(QSet<QObject *> elementImports READ elementImports NOTIFY elementImportsChanged)
    Q_PROPERTY(QSet<QObject *> importedMembers READ importedMembers NOTIFY importedMembersChanged STORED false)
    Q_PROPERTY(QSet<QObject *> members READ members NOTIFY membersChanged)
    Q_PROPERTY(QSet<QObject *> ownedMembers READ ownedMembers NOTIFY ownedMembersChanged)
    Q_PROPERTY(QSet<QObject *> ownedRules READ ownedRules NOTIFY ownedRulesChanged)
    Q_PROPERTY(QSet<QObject *> packageImports READ packageImports NOTIFY packageImportsChanged)

    // Properties [InteractionOperand]
    Q_PROPERTY(QList<QObject *> fragments READ fragments NOTIFY fragmentsChanged)
    Q_PROPERTY(QObject * guard READ guard WRITE setGuard NOTIFY guardChanged)

public:
    Q_INVOKABLE explicit QUmlInteractionOperandObject(QUmlInteractionOperand *modelingElement);

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComments() const;
    Q_INVOKABLE const QSet<QObject *> ownedElements() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [NamedElement]
    Q_INVOKABLE const QSet<QObject *> clientDependencies() const;
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE QObject *nameExpression() const;
    Q_INVOKABLE QObject *namespace_() const;
    Q_INVOKABLE QString qualifiedName() const;
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;

    // Owned attributes [InteractionFragment]
    Q_INVOKABLE const QSet<QObject *> covered() const;
    Q_INVOKABLE QObject *enclosingInteraction() const;
    Q_INVOKABLE QObject *enclosingOperand() const;
    Q_INVOKABLE const QSet<QObject *> generalOrderings() const;

    // Owned attributes [Namespace]
    Q_INVOKABLE const QSet<QObject *> elementImports() const;
    Q_INVOKABLE const QSet<QObject *> importedMembers() const;
    Q_INVOKABLE const QSet<QObject *> members() const;
    Q_INVOKABLE const QSet<QObject *> ownedMembers() const;
    Q_INVOKABLE const QSet<QObject *> ownedRules() const;
    Q_INVOKABLE const QSet<QObject *> packageImports() const;

    // Owned attributes [InteractionOperand]
    Q_INVOKABLE const QList<QObject *> fragments() const;
    Q_INVOKABLE QObject *guard() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;

    // Operations [NamedElement]
    Q_INVOKABLE QList<QObject *> allNamespaces() const;
    Q_TODO Q_INVOKABLE QSet<QObject *> allOwningPackages() const;
    Q_TODO Q_INVOKABLE bool isDistinguishableFrom(QObject *n, QObject *ns) const;
    Q_INVOKABLE QString separator() const;

    // Operations [Namespace]
    Q_TODO Q_INVOKABLE QSet<QObject *> excludeCollisions(QSet<QObject *> imps) const;
    Q_TODO Q_INVOKABLE QSet<QString> getNamesOfMember(QObject *element) const;
    Q_TODO Q_INVOKABLE QSet<QObject *> importMembers(QSet<QObject *> imps) const;
    Q_TODO Q_INVOKABLE bool membersAreDistinguishable() const;

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

    // Slots for owned attributes [InteractionFragment]
    void addCovered(QObject *covered);
    void removeCovered(QObject *covered);
    void setEnclosingInteraction(QObject *enclosingInteraction = 0);
    void setEnclosingOperand(QObject *enclosingOperand = 0);
    void addGeneralOrdering(QObject *generalOrdering);
    void removeGeneralOrdering(QObject *generalOrdering);

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

    // Slots for owned attributes [InteractionOperand]
    void addFragment(QObject *fragment);
    void removeFragment(QObject *fragment);
    void setGuard(QObject *guard = 0);

Q_SIGNALS:

    // Signals for owned attributes [Element]
    void ownedCommentsChanged(QSet<QObject *> ownedComments);
    void ownedElementsChanged(QSet<QObject *> ownedElements);
    void ownerChanged(QObject *owner);

    // Signals for owned attributes [NamedElement]
    void clientDependenciesChanged(QSet<QObject *> clientDependencies);
    void nameChanged(QString name);
    void nameExpressionChanged(QObject *nameExpression);
    void namespaceChanged(QObject *namespace_);
    void qualifiedNameChanged(QString qualifiedName);
    void visibilityChanged(QtUml::VisibilityKind visibility);

    // Signals for owned attributes [InteractionFragment]
    void coveredChanged(QSet<QObject *> covered);
    void enclosingInteractionChanged(QObject *enclosingInteraction);
    void enclosingOperandChanged(QObject *enclosingOperand);
    void generalOrderingsChanged(QSet<QObject *> generalOrderings);

    // Signals for owned attributes [Namespace]
    void elementImportsChanged(QSet<QObject *> elementImports);
    void importedMembersChanged(QSet<QObject *> importedMembers);
    void membersChanged(QSet<QObject *> members);
    void ownedMembersChanged(QSet<QObject *> ownedMembers);
    void ownedRulesChanged(QSet<QObject *> ownedRules);
    void packageImportsChanged(QSet<QObject *> packageImports);

    // Signals for owned attributes [InteractionOperand]
    void fragmentsChanged(QList<QObject *> fragments);
    void guardChanged(QObject *guard);

protected:
    virtual void setGroupProperties();
    virtual void setPropertyData();
};

QT_END_NAMESPACE

#endif // QUMLINTERACTIONOPERANDOBJECT_H

