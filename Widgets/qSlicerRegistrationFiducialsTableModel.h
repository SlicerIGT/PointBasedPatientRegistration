/*==============================================================================

  Program: Point-based Registration User Interface for 3D Slicer

  Copyright (c) Brigham and Women's Hospital

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Junichi Tokuda, Brigham and Women's
  Hospital. The project was supported by NIH P41EB015898.

==============================================================================*/

#ifndef __qSlicerRegistrationFiducialsTableModel_h
#define __qSlicerRegistrationFiducialsTableModel_h

//#include <QAbstractTableModel>
#include <QStandardItemModel>

#include <ctkPimpl.h>
#include <ctkVTKObject.h>

#include "qSlicerPointBasedPatientRegistrationModuleWidgetsExport.h"

class vtkObject;
class vtkMRMLNode;
class vtkMRMLScene;
class qSlicerRegistrationFiducialsTableModelPrivate;

class Q_SLICER_MODULE_POINTBASEDPATIENTREGISTRATION_WIDGETS_EXPORT qSlicerRegistrationFiducialsTableModel
//  : public QAbstractTableModel
  : public QStandardItemModel
{
  Q_OBJECT
  QVTK_OBJECT
    //Q_PROPERTY(bool noneEnabled READ noneEnabled WRITE setNoneEnabled)

public:
  typedef QAbstractTableModel Superclass;
  qSlicerRegistrationFiducialsTableModel(QObject *parent=0);
  virtual ~qSlicerRegistrationFiducialsTableModel();
  qSlicerRegistrationFiducialsTableModel(QList< QPair<QString, QString> > listofPairs, QObject *parent=0);

  enum ItemDataRole {
    NodeIDRole = Qt::UserRole,
  };
  enum CoordinateLabel {
    LABEL_RAS = 1,
    LABEL_XYZ = 2,
  };

protected:
  qSlicerRegistrationFiducialsTableModel(qSlicerRegistrationFiducialsTableModelPrivate* pimpl, QObject *parent=0);

public:  
  void setCoordinateLabel(int m); // LABEL_RAS or LABEL_XYZ
  void updateTable();
  void addPoint(double x, double y, double z);

public slots:
  void setMRMLScene(vtkMRMLScene *newScene);

protected slots:
  void setNode(vtkMRMLNode* node);
  void onItemChanged(QStandardItem * item);
  void onMRMLChildNodeAdded(vtkObject*);
  void onMRMLChildNodeRemoved(vtkObject*);
  void onMRMLChildNodeValueModified(vtkObject*);
  void onMRMLNodeRemovedEvent(vtkObject*,vtkObject*);
  
protected:
  QScopedPointer<qSlicerRegistrationFiducialsTableModelPrivate> d_ptr;
  
private:
  Q_DECLARE_PRIVATE(qSlicerRegistrationFiducialsTableModel);
  Q_DISABLE_COPY(qSlicerRegistrationFiducialsTableModel);

};

#endif // __qSlicerRegistrationFiducialsTableModel_h
