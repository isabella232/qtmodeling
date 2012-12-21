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
** rights. These rights are described in the Nokia Qt LGPL Exception
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

#include "qredefinableelement.h"
#include "qredefinableelement_p.h"

#include <QtMof/QClassifier>

QT_BEGIN_NAMESPACE_QTMOF

QRedefinableElementPrivate::QRedefinableElementPrivate() :
    isLeaf(false),
    redefinedElements(new QSet<QRedefinableElement *>),
    redefinitionContexts(new QSet<QClassifier *>)
{
}

QRedefinableElementPrivate::~QRedefinableElementPrivate()
{
    delete redefinedElements;
    delete redefinitionContexts;
}

void QRedefinableElementPrivate::addRedefinedElement(QRedefinableElement *redefinedElement)
{
    // This is a read-only derived-union association end

    if (!this->redefinedElements->contains(redefinedElement)) {
        this->redefinedElements->insert(redefinedElement);
    }
}

void QRedefinableElementPrivate::removeRedefinedElement(QRedefinableElement *redefinedElement)
{
    // This is a read-only derived-union association end

    if (this->redefinedElements->contains(redefinedElement)) {
        this->redefinedElements->remove(redefinedElement);
    }
}

void QRedefinableElementPrivate::addRedefinitionContext(QClassifier *redefinitionContext)
{
    // This is a read-only derived-union association end

    if (!this->redefinitionContexts->contains(redefinitionContext)) {
        this->redefinitionContexts->insert(redefinitionContext);
    }
}

void QRedefinableElementPrivate::removeRedefinitionContext(QClassifier *redefinitionContext)
{
    // This is a read-only derived-union association end

    if (this->redefinitionContexts->contains(redefinitionContext)) {
        this->redefinitionContexts->remove(redefinitionContext);
    }
}

/*!
    \class QRedefinableElement

    \inmodule QtMof

    \brief A redefinable element is an element that, when defined in the context of a classifier, can be redefined more specifically or differently in the context of another classifier that specializes (directly or indirectly) the context classifier.
 */

QRedefinableElement::QRedefinableElement(QWrappedObject *parent, QWrappedObject *wrapper) :
    QNamedElement(*new QRedefinableElementPrivate, parent, wrapper)
{
}

QRedefinableElement::QRedefinableElement(QRedefinableElementPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QNamedElement(dd, parent, wrapper)
{
}

QRedefinableElement::~QRedefinableElement()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QRedefinableElement
// ---------------------------------------------------------------

/*!
    Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement. Note that this property is preserved through package merge operations; that is, the capability to redefine a RedefinableElement (i.e., isLeaf=false) must be preserved in the resulting RedefinableElement of a package merge operation where a RedefinableElement with isLeaf=false is merged with a matching RedefinableElement with isLeaf=true: the resulting RedefinableElement will have isLeaf=false. Default value is false.
 */
bool QRedefinableElement::isLeaf() const
{
    // This is a read-write attribute

    Q_D(const QRedefinableElement);
    return d->isLeaf;
}

void QRedefinableElement::setLeaf(bool isLeaf)
{
    // This is a read-write attribute

    Q_D(QRedefinableElement);
    if (d->isLeaf != isLeaf) {
        d->isLeaf = isLeaf;
    }
}

void QRedefinableElement::unsetLeaf()
{
    setLeaf(false);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QRedefinableElement
// ---------------------------------------------------------------

/*!
    The redefinable element that is being redefined by this element.
 */
const QSet<QRedefinableElement *> *QRedefinableElement::redefinedElements() const
{
    // This is a read-only derived-union association end

    Q_D(const QRedefinableElement);
    return d->redefinedElements;
}

/*!
    References the contexts that this element may be redefined from.
 */
const QSet<QClassifier *> *QRedefinableElement::redefinitionContexts() const
{
    // This is a read-only derived-union association end

    Q_D(const QRedefinableElement);
    return d->redefinitionContexts;
}

/*!
    The query isConsistentWith() specifies, for any two RedefinableElements in a context in which redefinition is possible, whether redefinition would be logically consistent. By default, this is false; this operation must be overridden for subclasses of RedefinableElement to define the consistency conditions.
 */
bool QRedefinableElement::isConsistentWith(const QRedefinableElement *redefinee) const
{
    qWarning("QRedefinableElement::isConsistentWith: operation to be implemented");
    Q_UNUSED(redefinee);

    return bool(); // change here to your derived return
}

/*!
    The query isRedefinitionContextValid() specifies whether the redefinition contexts of this RedefinableElement are properly related to the redefinition contexts of the specified RedefinableElement to allow this element to redefine the other. By default at least one of the redefinition contexts of this element must be a specialization of at least one of the redefinition contexts of the specified element.
 */
bool QRedefinableElement::isRedefinitionContextValid(const QRedefinableElement *redefined) const
{
    qWarning("QRedefinableElement::isRedefinitionContextValid: operation to be implemented");
    Q_UNUSED(redefined);

    return bool(); // change here to your derived return
}

void QRedefinableElement::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTMOF(QRedefinableElement) *>("QT_PREPEND_NAMESPACE_QTMOF(QRedefinableElement) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTMOF(QRedefinableElement) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTMOF(QRedefinableElement) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTMOF(QRedefinableElement) *> *>("const QList<QT_PREPEND_NAMESPACE_QTMOF(QRedefinableElement) *> *");
    qRegisterMetaType<QRedefinableElement *>("QRedefinableElement *");
    qRegisterMetaType<const QSet<QRedefinableElement *> *>("const QSet<QRedefinableElement *> *");
    qRegisterMetaType<const QList<QRedefinableElement *> *>("const QList<QRedefinableElement *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTMOF(QClassifier) *>("QT_PREPEND_NAMESPACE_QTMOF(QClassifier) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTMOF(QClassifier) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTMOF(QClassifier) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTMOF(QClassifier) *> *>("const QList<QT_PREPEND_NAMESPACE_QTMOF(QClassifier) *> *");
    qRegisterMetaType<QClassifier *>("QClassifier *");
    qRegisterMetaType<const QSet<QClassifier *> *>("const QSet<QClassifier *> *");
    qRegisterMetaType<const QList<QClassifier *> *>("const QList<QClassifier *> *");

    QNamedElement::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qredefinableelement.cpp"

QT_END_NAMESPACE_QTMOF
