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
#include "umlstate_p.h"

#include "private/umlbehavior_p.h"
#include "private/umlclassifier_p.h"
#include "private/umlconnectionpointreference_p.h"
#include "private/umlconstraint_p.h"
#include "private/umlpseudostate_p.h"
#include "private/umlregion_p.h"
#include "private/umlstatemachine_p.h"
#include "private/umltrigger_p.h"

/*!
    \class UmlState

    \inmodule QtUml

    \brief A state models a situation during which some (usually implicit) invariant condition holds.The states of protocol state machines are exposed to the users of their context classifiers. A protocol state represents an exposed stable situation of its context classifier: when an instance of the classifier is not processing any operation, users of this instance can always know its state configuration.
 */

UmlState::UmlState() :
    _doActivity(0),
    _entry(0),
    _exit(0),
    _redefinedState(0),
    _stateInvariant(0),
    _submachine(0)
{
}

// OWNED ATTRIBUTES

/*!
    The entry and exit connection points used in conjunction with this (submachine) state, i.e. as targets and sources, respectively, in the region with the submachine state. A connection point reference references the corresponding definition of a connection point pseudostate in the statemachine referenced by the submachinestate.
 */
const QSet<UmlConnectionPointReference *> UmlState::connection() const
{
    // This is a read-write association end

    return _connection;
}

void UmlState::addConnection(UmlConnectionPointReference *connection)
{
    // This is a read-write association end

    if (!_connection.contains(connection)) {
        _connection.insert(connection);

        // Adjust subsetted properties
        addOwnedMember(connection);

        // Adjust opposite properties
        if (connection) {
            connection->setState(this);
        }
    }
}

void UmlState::removeConnection(UmlConnectionPointReference *connection)
{
    // This is a read-write association end

    if (_connection.contains(connection)) {
        _connection.remove(connection);

        // Adjust subsetted properties
        removeOwnedMember(connection);

        // Adjust opposite properties
        if (connection) {
            connection->setState(0);
        }
    }
}

/*!
    The entry and exit pseudostates of a composite state. These can only be entry or exit Pseudostates, and they must have different names. They can only be defined for composite states.
 */
const QSet<UmlPseudostate *> UmlState::connectionPoint() const
{
    // This is a read-write association end

    return _connectionPoint;
}

void UmlState::addConnectionPoint(UmlPseudostate *connectionPoint)
{
    // This is a read-write association end

    if (!_connectionPoint.contains(connectionPoint)) {
        _connectionPoint.insert(connectionPoint);

        // Adjust subsetted properties
        addOwnedMember(connectionPoint);

        // Adjust opposite properties
        if (connectionPoint) {
            connectionPoint->setState(this);
        }
    }
}

void UmlState::removeConnectionPoint(UmlPseudostate *connectionPoint)
{
    // This is a read-write association end

    if (_connectionPoint.contains(connectionPoint)) {
        _connectionPoint.remove(connectionPoint);

        // Adjust subsetted properties
        removeOwnedMember(connectionPoint);

        // Adjust opposite properties
        if (connectionPoint) {
            connectionPoint->setState(0);
        }
    }
}

/*!
    A list of triggers that are candidates to be retained by the state machine if they trigger no transitions out of the state (not consumed). A deferred trigger is retained until the state machine reaches a state configuration where it is no longer deferred.
 */
const QSet<UmlTrigger *> UmlState::deferrableTrigger() const
{
    // This is a read-write association end

    return _deferrableTrigger;
}

void UmlState::addDeferrableTrigger(UmlTrigger *deferrableTrigger)
{
    // This is a read-write association end

    if (!_deferrableTrigger.contains(deferrableTrigger)) {
        _deferrableTrigger.insert(deferrableTrigger);

        // Adjust subsetted properties
        addOwnedElement(deferrableTrigger);
    }
}

void UmlState::removeDeferrableTrigger(UmlTrigger *deferrableTrigger)
{
    // This is a read-write association end

    if (_deferrableTrigger.contains(deferrableTrigger)) {
        _deferrableTrigger.remove(deferrableTrigger);

        // Adjust subsetted properties
        removeOwnedElement(deferrableTrigger);
    }
}

/*!
    An optional behavior that is executed while being in the state. The execution starts when this state is entered, and stops either by itself, or when the state is exited, whichever comes first.
 */
UmlBehavior *UmlState::doActivity() const
{
    // This is a read-write association end

    return _doActivity;
}

void UmlState::setDoActivity(UmlBehavior *doActivity)
{
    // This is a read-write association end

    if (_doActivity != doActivity) {
        // Adjust subsetted properties
        removeOwnedElement(_doActivity);

        _doActivity = doActivity;

        // Adjust subsetted properties
        if (doActivity) {
            addOwnedElement(doActivity);
        }
    }
}

/*!
    An optional behavior that is executed whenever this state is entered regardless of the transition taken to reach the state. If defined, entry actions are always executed to completion prior to any internal behavior or transitions performed within the state.
 */
UmlBehavior *UmlState::entry() const
{
    // This is a read-write association end

    return _entry;
}

void UmlState::setEntry(UmlBehavior *entry)
{
    // This is a read-write association end

    if (_entry != entry) {
        // Adjust subsetted properties
        removeOwnedElement(_entry);

        _entry = entry;

        // Adjust subsetted properties
        if (entry) {
            addOwnedElement(entry);
        }
    }
}

/*!
    An optional behavior that is executed whenever this state is exited regardless of which transition was taken out of the state. If defined, exit actions are always executed to completion only after all internal activities and transition actions have completed execution.
 */
UmlBehavior *UmlState::exit() const
{
    // This is a read-write association end

    return _exit;
}

void UmlState::setExit(UmlBehavior *exit)
{
    // This is a read-write association end

    if (_exit != exit) {
        // Adjust subsetted properties
        removeOwnedElement(_exit);

        _exit = exit;

        // Adjust subsetted properties
        if (exit) {
            addOwnedElement(exit);
        }
    }
}

/*!
    A state with isComposite=true is said to be a composite state. A composite state is a state that contains at least one region.
 */
bool UmlState::isComposite() const
{
    // This is a read-only derived property

    qWarning("UmlState::isComposite(): to be implemented (this is a derived property)");

    return bool();
}

void UmlState::setComposite(bool isComposite)
{
    // This is a read-only derived property

    qWarning("UmlState::isComposite(): to be implemented (this is a derived property)");
    Q_UNUSED(isComposite);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    A state with isOrthogonal=true is said to be an orthogonal composite state. An orthogonal composite state contains two or more regions.
 */
bool UmlState::isOrthogonal() const
{
    // This is a read-only derived property

    qWarning("UmlState::isOrthogonal(): to be implemented (this is a derived property)");

    return bool();
}

void UmlState::setOrthogonal(bool isOrthogonal)
{
    // This is a read-only derived property

    qWarning("UmlState::isOrthogonal(): to be implemented (this is a derived property)");
    Q_UNUSED(isOrthogonal);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    A state with isSimple=true is said to be a simple state. A simple state does not have any regions and it does not refer to any submachine state machine.
 */
bool UmlState::isSimple() const
{
    // This is a read-only derived property

    qWarning("UmlState::isSimple(): to be implemented (this is a derived property)");

    return bool();
}

void UmlState::setSimple(bool isSimple)
{
    // This is a read-only derived property

    qWarning("UmlState::isSimple(): to be implemented (this is a derived property)");
    Q_UNUSED(isSimple);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    A state with isSubmachineState=true is said to be a submachine state. Such a state refers to a state machine (submachine).
 */
bool UmlState::isSubmachineState() const
{
    // This is a read-only derived property

    qWarning("UmlState::isSubmachineState(): to be implemented (this is a derived property)");

    return bool();
}

void UmlState::setSubmachineState(bool isSubmachineState)
{
    // This is a read-only derived property

    qWarning("UmlState::isSubmachineState(): to be implemented (this is a derived property)");
    Q_UNUSED(isSubmachineState);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    The state of which this state is a redefinition.
 */
UmlState *UmlState::redefinedState() const
{
    // This is a read-write association end

    return _redefinedState;
}

void UmlState::setRedefinedState(UmlState *redefinedState)
{
    // This is a read-write association end

    if (_redefinedState != redefinedState) {
        // Adjust subsetted properties
        removeRedefinedElement(_redefinedState);

        _redefinedState = redefinedState;

        // Adjust subsetted properties
        if (redefinedState) {
            addRedefinedElement(redefinedState);
        }
    }
}

/*!
    References the classifier in which context this element may be redefined.
 */
UmlClassifier *UmlState::redefinitionContext() const
{
    // This is a read-only derived association end

    qWarning("UmlState::redefinitionContext(): to be implemented (this is a derived association end)");

    return 0;
}

void UmlState::setRedefinitionContext(UmlClassifier *redefinitionContext)
{
    // This is a read-only derived association end

    qWarning("UmlState::redefinitionContext(): to be implemented (this is a derived association end)");
    Q_UNUSED(redefinitionContext);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    The regions owned directly by the state.
 */
const QSet<UmlRegion *> UmlState::region() const
{
    // This is a read-write association end

    return _region;
}

void UmlState::addRegion(UmlRegion *region)
{
    // This is a read-write association end

    if (!_region.contains(region)) {
        _region.insert(region);

        // Adjust subsetted properties
        addOwnedMember(region);

        // Adjust opposite properties
        if (region) {
            region->setState(this);
        }
    }
}

void UmlState::removeRegion(UmlRegion *region)
{
    // This is a read-write association end

    if (_region.contains(region)) {
        _region.remove(region);

        // Adjust subsetted properties
        removeOwnedMember(region);

        // Adjust opposite properties
        if (region) {
            region->setState(0);
        }
    }
}

/*!
    Specifies conditions that are always true when this state is the current state. In protocol state machines, state invariants are additional conditions to the preconditions of the outgoing transitions, and to the postcondition of the incoming transitions.
 */
UmlConstraint *UmlState::stateInvariant() const
{
    // This is a read-write association end

    return _stateInvariant;
}

void UmlState::setStateInvariant(UmlConstraint *stateInvariant)
{
    // This is a read-write association end

    if (_stateInvariant != stateInvariant) {
        // Adjust subsetted properties
        removeOwnedRule(_stateInvariant);

        _stateInvariant = stateInvariant;

        // Adjust subsetted properties
        if (stateInvariant) {
            addOwnedRule(stateInvariant);
        }
    }
}

/*!
    The state machine that is to be inserted in place of the (submachine) state.
 */
UmlStateMachine *UmlState::submachine() const
{
    // This is a read-write association end

    return _submachine;
}

void UmlState::setSubmachine(UmlStateMachine *submachine)
{
    // This is a read-write association end

    if (_submachine != submachine) {
        _submachine = submachine;
    }
}

// OPERATIONS

/*!
    The query containingStateMachine() returns the state machine that contains the state either directly or transitively.
 */
UmlStateMachine *UmlState::containingStateMachine(
    ) const
{
    qWarning("UmlState::containingStateMachine(): to be implemented (operation)");

    return 0;
}

/*!
    The query isConsistentWith() specifies that a redefining state is consistent with a redefined state provided that the redefining state is an extension of the redefined state: A simple state can be redefined (extended) to become a composite state (by adding a region) and a composite state can be redefined (extended) by adding regions and by adding vertices, states, and transitions to inherited regions. All states may add or replace entry, exit, and 'doActivity' actions.
 */
bool UmlState::isConsistentWith(
    UmlRedefinableElement *redefinee) const
{
    qWarning("UmlState::isConsistentWith(): to be implemented (operation)");

    Q_UNUSED(redefinee);
    return bool ();
}

/*!
    The query isRedefinitionContextValid() specifies whether the redefinition contexts of a state are properly related to the redefinition contexts of the specified state to allow this element to redefine the other. The containing region of a redefining state must redefine the containing region of the redefined state.
 */
bool UmlState::isRedefinitionContextValid(
    UmlState *redefined) const
{
    qWarning("UmlState::isRedefinitionContextValid(): to be implemented (operation)");

    Q_UNUSED(redefined);
    return bool ();
}
