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
#ifndef QTUML_QGENERALIZATION_H
#define QTUML_QGENERALIZATION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QDirectedRelationship>

// Qt includes
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QGeneralizationPrivate;
class QClassifier;
class QGeneralizationSet;

class Q_UML_EXPORT QGeneralization : public QObject, public QDirectedRelationship
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(QList<QComment *> * ownedComment READ ownedComment)
    Q_PROPERTY(const QList<QElement *> * ownedElement READ ownedElement)
    Q_PROPERTY(const QElement * owner READ owner)

    // From QRelationship
    Q_PROPERTY(const QList<QElement *> * relatedElement READ relatedElement)

    // From QDirectedRelationship
    Q_PROPERTY(const QList<QElement *> * source READ source)
    Q_PROPERTY(const QList<QElement *> * target READ target)

    // From QGeneralization
    Q_PROPERTY(bool isSubstitutable READ isSubstitutable WRITE setSubstitutable)
    Q_PROPERTY(QClassifier * general READ general WRITE setGeneral)
    Q_PROPERTY(QList<QGeneralizationSet *> * generalizationSet READ generalizationSet)
    Q_PROPERTY(QClassifier * specific READ specific WRITE setSpecific)

public:
    explicit QGeneralization(QObject *parent = 0);
    virtual ~QGeneralization();

    // Attributes (except those derived && !derivedUnion)
    bool isSubstitutable() const;
    void setSubstitutable(bool isSubstitutable);

    // Association-ends (except those derived && !derivedUnion)
    QClassifier *general() const;
    void setGeneral(QClassifier *general);
    QList<QGeneralizationSet *> *generalizationSet();
    QClassifier *specific() const;
    void setSpecific(QClassifier *specific);

private:
    Q_DISABLE_COPY(QGeneralization)
    Q_DECLARE_PRIVATE(QGeneralization)
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QtUml::QGeneralization *>)
Q_DECLARE_METATYPE(QList<QtUml::QGeneralization *> *)

QT_END_HEADER

#endif // QTUML_QGENERALIZATION_H
