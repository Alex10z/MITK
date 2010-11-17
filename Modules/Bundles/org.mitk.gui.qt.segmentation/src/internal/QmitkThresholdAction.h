#ifndef QMITK_THRESHOLDACTION_H
#define QMITK_THRESHOLDACTION_H

#include <berryISelectionListener.h>
#include "berryQtViewPart.h"

#include "mitkIContextMenuAction.h"

#include "mitkDataStorage.h"
#include "mitkToolManager.h"

#include "mitkQtSegmentationDll.h"

#include <QObject>
#include <QDialog>

class MITK_QT_SEGMENTATION QmitkThresholdAction: public QObject, public mitk::IContextMenuAction
{
  Q_OBJECT

  public:

    QmitkThresholdAction();
    virtual ~QmitkThresholdAction();

    //interface methods
    void Run( const std::vector<mitk::DataNode*>& selectedNodes );
    void SetDataStorage(mitk::DataStorage* dataStorage);
    void SetSmoothed(bool smoothed);
    void SetDecimated(bool decimated);
    void SetFunctionality(berry::QtViewPart* functionality);

    // for receiving messages
    void OnThresholdingToolManagerToolModified();

  protected:

     typedef std::vector<mitk::DataNode*> NodeList;

     mitk::DataStorage::Pointer m_DataStorage;
     mitk::ToolManager::Pointer m_ThresholdingToolManager;

     QDialog* m_ThresholdingDialog;

  protected slots:

    // class internal slot
    void ThresholdingDone(int);
};

#endif // QMITK_THRESHOLDACTION_H