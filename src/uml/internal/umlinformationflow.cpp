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
#include "umlinformationflow_p.h"

#include "private/umlactivityedge_p.h"
#include "private/umlclassifier_p.h"
#include "private/umlconnector_p.h"
#include "private/umlmessage_p.h"
#include "private/umlnamedelement_p.h"
#include "private/umlrelationship_p.h"

/*!
    \class UmlInformationFlow

    \inmodule QtUml

    \brief An information flow specifies that one or more information items circulates from its sources to its targets. Information flows require some kind of information channel for transmitting information items from the source to the destination. An information channel is represented in various ways depending on the nature of its sources and targets. It may be represented by connectors, links, associations, or even dependencies. For example, if the source and destination are parts in some composite structure such as a collaboration, then the information channel is likely to be represented by a connector between them. Or, if the source and target are objects (which are a kind of instance specification), they may be represented by a link that joins the two, and so on.
 */

UmlInformationFlow::UmlInformationFlow()
{
}

// OWNED ATTRIBUTES

/*!
    Specifies the information items that may circulate on this information flow.
 */
const QSet<UmlClassifier *> UmlInformationFlow::conveyed() const
{
    // This is a read-write association end

    return _conveyed;
}

void UmlInformationFlow::addConveyed(UmlClassifier *conveyed)
{
    // This is a read-write association end

    if (!_conveyed.contains(conveyed)) {
        _conveyed.insert(conveyed);
    }
}

void UmlInformationFlow::removeConveyed(UmlClassifier *conveyed)
{
    // This is a read-write association end

    if (_conveyed.contains(conveyed)) {
        _conveyed.remove(conveyed);
    }
}

/*!
    Defines from which source the conveyed InformationItems are initiated.
 */
const QSet<UmlNamedElement *> UmlInformationFlow::informationSource() const
{
    // This is a read-write association end

    return _informationSource;
}

void UmlInformationFlow::addInformationSource(UmlNamedElement *informationSource)
{
    // This is a read-write association end

    if (!_informationSource.contains(informationSource)) {
        _informationSource.insert(informationSource);

        // Adjust subsetted properties
        addSource(informationSource);
    }
}

void UmlInformationFlow::removeInformationSource(UmlNamedElement *informationSource)
{
    // This is a read-write association end

    if (_informationSource.contains(informationSource)) {
        _informationSource.remove(informationSource);

        // Adjust subsetted properties
        removeSource(informationSource);
    }
}

/*!
    Defines to which target the conveyed InformationItems are directed.
 */
const QSet<UmlNamedElement *> UmlInformationFlow::informationTarget() const
{
    // This is a read-write association end

    return _informationTarget;
}

void UmlInformationFlow::addInformationTarget(UmlNamedElement *informationTarget)
{
    // This is a read-write association end

    if (!_informationTarget.contains(informationTarget)) {
        _informationTarget.insert(informationTarget);

        // Adjust subsetted properties
        addTarget(informationTarget);
    }
}

void UmlInformationFlow::removeInformationTarget(UmlNamedElement *informationTarget)
{
    // This is a read-write association end

    if (_informationTarget.contains(informationTarget)) {
        _informationTarget.remove(informationTarget);

        // Adjust subsetted properties
        removeTarget(informationTarget);
    }
}

/*!
    Determines which Relationship will realize the specified flow
 */
const QSet<UmlRelationship *> UmlInformationFlow::realization() const
{
    // This is a read-write association end

    return _realization;
}

void UmlInformationFlow::addRealization(UmlRelationship *realization)
{
    // This is a read-write association end

    if (!_realization.contains(realization)) {
        _realization.insert(realization);
    }
}

void UmlInformationFlow::removeRealization(UmlRelationship *realization)
{
    // This is a read-write association end

    if (_realization.contains(realization)) {
        _realization.remove(realization);
    }
}

/*!
    Determines which ActivityEdges will realize the specified flow.
 */
const QSet<UmlActivityEdge *> UmlInformationFlow::realizingActivityEdge() const
{
    // This is a read-write association end

    return _realizingActivityEdge;
}

void UmlInformationFlow::addRealizingActivityEdge(UmlActivityEdge *realizingActivityEdge)
{
    // This is a read-write association end

    if (!_realizingActivityEdge.contains(realizingActivityEdge)) {
        _realizingActivityEdge.insert(realizingActivityEdge);
    }
}

void UmlInformationFlow::removeRealizingActivityEdge(UmlActivityEdge *realizingActivityEdge)
{
    // This is a read-write association end

    if (_realizingActivityEdge.contains(realizingActivityEdge)) {
        _realizingActivityEdge.remove(realizingActivityEdge);
    }
}

/*!
    Determines which Connectors will realize the specified flow.
 */
const QSet<UmlConnector *> UmlInformationFlow::realizingConnector() const
{
    // This is a read-write association end

    return _realizingConnector;
}

void UmlInformationFlow::addRealizingConnector(UmlConnector *realizingConnector)
{
    // This is a read-write association end

    if (!_realizingConnector.contains(realizingConnector)) {
        _realizingConnector.insert(realizingConnector);
    }
}

void UmlInformationFlow::removeRealizingConnector(UmlConnector *realizingConnector)
{
    // This is a read-write association end

    if (_realizingConnector.contains(realizingConnector)) {
        _realizingConnector.remove(realizingConnector);
    }
}

/*!
    Determines which Messages will realize the specified flow.
 */
const QSet<UmlMessage *> UmlInformationFlow::realizingMessage() const
{
    // This is a read-write association end

    return _realizingMessage;
}

void UmlInformationFlow::addRealizingMessage(UmlMessage *realizingMessage)
{
    // This is a read-write association end

    if (!_realizingMessage.contains(realizingMessage)) {
        _realizingMessage.insert(realizingMessage);
    }
}

void UmlInformationFlow::removeRealizingMessage(UmlMessage *realizingMessage)
{
    // This is a read-write association end

    if (_realizingMessage.contains(realizingMessage)) {
        _realizingMessage.remove(realizingMessage);
    }
}
