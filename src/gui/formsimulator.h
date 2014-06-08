#ifndef FORMSIMULATOR_H
#define FORMSIMULATOR_H

#include <QDialog>

#include "ui_formsimulator.h"


namespace Ui {
  class FormSimulator;
}

class FormMain;
class QCloseEvent;

/// \brief Separate window which contains active simulator.
/// \remarks This window can be sticked to main window.
class FormSimulator : public QDialog {
    Q_OBJECT

  public:
    // Constructors and destructors.
    explicit FormSimulator(FormMain *parent = 0);
    virtual ~FormSimulator();

    ///
    /// \brief Indicates whether simulator window is sticked to
    /// main window or not.
    /// \return Returns true if window is sticked
    /// or false when it is not.
    inline bool isSticked() const {
      return m_isSticked;
    }

    /// \brief Sticks or unsticks window.
    /// \param is_sticked Do we want to stick window?
    void setIsSticked(bool is_sticked);

  public slots:
    /// \brief Forces this window to align itself next to its parent window.
    void attachToParent();

  protected:
    void closeEvent(QCloseEvent *e);

  signals:
    void closed();

  private:
    void setupPhoneWidget();
    void setupIcons();

  private:
    Ui::FormSimulator *m_ui;
    FormMain *m_mainWindow;
    bool m_isSticked;
};

#endif // FORMSIMULATOR_H
