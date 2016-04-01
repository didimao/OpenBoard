/*
 * Copyright (C) 2013 Open Education Foundation
 *
 * Copyright (C) 2010-2013 Groupement d'Intérêt Public pour
 * l'Education Numérique en Afrique (GIP ENA)
 *
 * This file is part of OpenBoard.
 *
 * OpenBoard is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * OpenBoard is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenBoard. If not, see <http://www.gnu.org/licenses/>.
 */




#ifndef UBGRAPHICSSTROKE_H_
#define UBGRAPHICSSTROKE_H_

#include <QtGui>

#include "core/UB.h"
#include "frameworks/UBInterpolator.h"



class UBGraphicsPolygonItem;

class UBGraphicsStroke
{
    friend class UBGraphicsPolygonItem;

    public:
        UBGraphicsStroke();
        virtual ~UBGraphicsStroke();

        bool hasPressure();

        QList<UBGraphicsPolygonItem*> polygons() const;

        void remove(UBGraphicsPolygonItem* polygonItem); 

        UBGraphicsStroke *deepCopy();

        bool hasAlpha() const;

        void clear();

        QList<QPointF> addPoint(const QPointF& point, UBInterpolator::InterpolationMethod interpolationMethod = UBInterpolator::NoInterpolation);

        UBGraphicsStroke* smoothe();

        const QList<QPointF>& points() { return mAllPoints; }

    protected:
        void addPolygon(UBGraphicsPolygonItem* pol);

    private:

        QList<UBGraphicsPolygonItem*> mPolygons;

        QList<QPointF> mDrawnPoints;
        QList<QPointF> mAllPoints;

};

#endif /* UBGRAPHICSSTROKE_H_ */
